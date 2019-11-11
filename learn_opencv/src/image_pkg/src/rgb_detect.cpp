//
// Created by chrisliu on 2019/11/2.
//

#include "ros/ros.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

#include "sensor_msgs/Image.h"
#include <geometry_msgs/Twist.h>

using namespace cv;
using namespace std;

#define MAX_AREA 2400
#define MIN_AREA 1000

//仅用比例 v=0.2 kp=1.1
#define LINEAR_X (0.2) //小车行走线速度

ros::Publisher pub_vel;

enum CAMERA_STATE {
    OK,
    LINE_UNDETECTED,
    OBSTACLE_DETECTED
};

CAMERA_STATE camera_state;

cv::Point2f extra(Mat frame) {
    Mat imageYellow, morImage;
    Mat kerneal = getStructuringElement(MORPH_RECT, Size(5, 5));

    std::vector<std::vector<Point> > contours;
    std::vector<Vec4i> hireachy;

    Point2f center;
    float radius = 20;

//    inRange(frame, Scalar(0, 80, 80), Scalar(50, 255, 255), imageYellow); //提取黄色
    morphologyEx(frame, morImage, MORPH_OPEN, kerneal); //形态学开操作
    morphologyEx(frame, morImage, MORPH_CLOSE, kerneal); //形态学闭操作
    imshow("src_filter", frame);
//    findContours(imageYellow, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0)); //获取边界
//    if (contours.size() > 0) //框选目标的边界
//    {
//
//        for (int i = 0; i < contours.size(); i++) {
//            double area = contourArea(contours[static_cast<int>(i)]); //获取轮廓面积
//            printf("area=%f", area);
//            if (area > MIN_AREA && area < MAX_AREA) //筛选面积
//            {
//                camera_state = OK;
//                minEnclosingCircle(contours[static_cast<int>(i)], center, radius); //寻找包围圆形
//                break;
//            } else {
//                camera_state = LINE_UNDETECTED;
//            }
//        }
//    } else {
//        camera_state = LINE_UNDETECTED;
//    }
//    circle(frame, center, (int) radius, Scalar(0, 255, 0), 2);
//    drawContours(frame, contours, -1, Scalar(255, 255, 255));
//
//    imshow("output", frame);

    return center;
}


void filter(Mat &input) {
    Mat kerneal = getStructuringElement(MORPH_RECT, Size(3, 3));

    morphologyEx(input, input, MORPH_OPEN, kerneal); //形态学开操作
    morphologyEx(input, input, MORPH_CLOSE, kerneal); //形态学闭操作
//    imshow("src_filter", input);
}

void rgb2hsv(int input_b, int input_g, int input_r, int &output_h, int &output_s, int &output_v) {
    float b, g, r;
    float h, s, v;
    float rgb_max, rgb_min, delta;
    b = input_b / 255.0;
    g = input_g / 255.0;
    r = input_r / 255.0;

    if (r > g) {
        rgb_max = MAX(r, b);
        rgb_min = MIN(g, b);
    } else {
        rgb_max = MAX(g, b);
        rgb_min = MIN(r, b);
    }


    v = rgb_max;
    delta = rgb_max - rgb_min;
    if (rgb_max == 0)
        s = 0;
    else
        s = delta / rgb_max;

    if (delta != 0) {
        if (r == rgb_max) {
            h = 60 * (g - b) / delta;
        } else if (g == rgb_max) {
            h = 60 * (b - r) / delta + 120;
        } else {
            h = 60 * (r - g) / delta + 240;
        }
        if (h < 0)
            h = h + 360;
    } else
        h = 0;

    output_h = (int) (h + 0.5);
    output_h = (output_h > 359) ? (output_h - 360) : output_h;
    output_h = (output_h < 0) ? (output_h + 360) : output_h;
    //转到opencv的hsv范围
    output_h = output_h / 2;
    output_s = s * 255;
    output_v = v * 255;
}

int H_maxValue = 180;
int SV_maxValue = 255;
int Hmax_Value = 180;
int Hmin_Value = 0;
int Smax_Value = 255;
int Smin_Value = 0;
int Vmax_Value = 255;
int Vmin_Value = 0;

void on_Trackbar(int, void *) {
}

void RGB_filter(Mat input, Mat &spilt_gray) {
    int cols = input.cols;
    int rows = input.rows;

    Mat input_temp = input.clone();
    Mat hsv_space(rows, cols, CV_8UC3);
    Mat spilt_binary = Mat::zeros(rows, cols, CV_8UC1);

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int h, s, v;
            rgb2hsv(input.at<Vec3b>(y, x)[0], input.at<Vec3b>(y, x)[1], input.at<Vec3b>(y, x)[2], h, s, v);
            hsv_space.at<Vec3b>(y, x) = Vec3b(h, s, v);
//            cout<<Vec3b(h, s, v)<<endl;
            //滤出红色到黄色
            if (Hmax_Value > Hmin_Value && Smax_Value > Smin_Value && Vmax_Value > Vmin_Value) {
                if (h >= Hmin_Value && h <= Hmax_Value && s >= Smin_Value && s <= Smax_Value && v >= Vmin_Value &&
                    v <= Vmax_Value) {
                    spilt_binary.at<uchar>(y, x) = 255;
                } else {
                    input_temp.at<Vec3b>(y, x) = Vec3b(0, 0, 0);
                }
            }

        }
    }
    imshow("HSV_space", hsv_space);
    imshow("HSV_spilt", input_temp);
    imshow("spilt_binary", spilt_binary);
    spilt_gray = spilt_binary;
}

int *colorAnalyse(Mat input) {
    int cols = input.cols;
    int rows = input.rows;

    static int Color[6];
    memset(Color, 0, sizeof(Color));
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int h, s, v;
            rgb2hsv(input.at<Vec3b>(y, x)[0], input.at<Vec3b>(y, x)[1], input.at<Vec3b>(y, x)[2], h, s, v);
            if (h >= 0 && h <= 22) {
                Color[0] += 1;//Orange
            } else if (h > 22 && h <= 38) {
                Color[1] += 1;//Yellow
            } else if (h > 38 && h <= 75) {
                Color[2] += 1;//Green
            } else if (h > 75 && h <= 130) {
                Color[3] += 1;//Blue
            } else if (h > 130 && h <= 160) {
                Color[4] += 1;//Violet
            } else if (h > 160 && h <= 179) {
                Color[5] += 1;//Red
            }
        }
    }

    vector<Scalar> colorRGB(6);
    colorRGB[0] = Scalar(0, 165, 255);
    colorRGB[1] = Scalar(0, 255, 255);
    colorRGB[2] = Scalar(0, 128, 0);
    colorRGB[3] = Scalar(255, 0, 0);
    colorRGB[4] = Scalar(211, 0, 148);
    colorRGB[5] = Scalar(0, 0, 255);


    int min = *min_element(Color, Color + 6);
    int max = *max_element(Color, Color + 6);

    int height = 400;
    Mat histogram = Mat::zeros(height, 260, CV_8UC3);
    for (int i = 0; i < 6; i++) {
        float temp = float(Color[i] - min) / (max - min);
        Scalar colorRan(random() % 255, random() % 255, random() % 255);
        line(histogram, Point(i * 40 + 30, height),
             Point(i * 40 + 30, height - temp * (height - 20)), colorRGB[i], 40);
    }
    imshow("histogram", histogram);

    return Color;
}

void velocity_control(int *Color) {
    int yellow = Color[0] + Color[1];
    int green = Color[2];
    int blue = Color[3];

    geometry_msgs::Twist cmd;

    if (yellow > 5000) {
        cmd.linear.x = LINEAR_X;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = 0;
    } else if (green > 5000) {
        cmd.linear.x = -LINEAR_X;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = 0;
    } else if (blue > 5000) {
        cmd.linear.x = 0;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = LINEAR_X;
    } else {
        cmd.linear.x = 0;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = 0;
    }

    pub_vel.publish(cmd);
}

void object_detect(Mat input) {
    Mat input_binary;
    RGB_filter(input, input_binary);

    filter(input_binary);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(input_binary, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    Mat conImage = Mat::zeros(input.size(), CV_8UC1);
    //绘制轮廓
    drawContours(conImage, contours, -1, Scalar(255));
    imshow("conImage", conImage);

    Mat interestImage = Mat::zeros(input.size(), CV_8UC1);

    Rect markRect;
    vector<Rect> boundRect(contours.size());
    Point2f center;
    float radius;
    for (int i = 0; i < contours.size(); i++) {
        if (contourArea(contours[i]) > 1000 && contourArea(contours[i]) < 6000) {
            // 获取最小外接矩形
            boundRect[i] = boundingRect(contours[i]);
            if (markRect.area() < boundRect[i].area())
                markRect = boundRect[i];

//            minEnclosingCircle(contours[i], center, radius);
//            circle(interestImage, center, radius, Scalar(255), CV_FILLED);
            // 在原图像上绘制最小外接矩形
            rectangle(interestImage, boundRect[i], Scalar(255), -1);
            rectangle(input, boundRect[i], Scalar(0, 255, 0), 1);
        }
    }
    imshow("interestImage", interestImage);
    Mat interested = Mat::zeros(input.size(), CV_8UC3);
    input.copyTo(interested, interestImage);
    imshow("interested", interested);

    int *Color;
    vector<Scalar> colorRGB(6);
    if (!markRect.empty()) {
        Mat colorAny;
        resize(input, colorAny, Size(markRect.width, markRect.height), markRect.x, markRect.y);
        Color = colorAnalyse(colorAny);
    }
    imshow("input", input);
    velocity_control(Color);
//    cout << Color[0]<< endl;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "xunxian");
    ros::NodeHandle n;
    ros::Rate loop_rate(30);

    pub_vel = n.advertise<geometry_msgs::Twist>("/cmd_vel", 5);

    VideoCapture capture(0);
    if (!capture.isOpened()) {
        printf("摄像头没有正常打开，重新插拔工控机上当摄像头\n");
        return 0;
    }

    Mat frame; //当前帧


    namedWindow("HSV_spilt");
    createTrackbar("H_max", "HSV_spilt", &Hmax_Value, H_maxValue, on_Trackbar);
    createTrackbar("H_min", "HSV_spilt", &Hmin_Value, H_maxValue, on_Trackbar);
    createTrackbar("S_max", "HSV_spilt", &Smax_Value, SV_maxValue, on_Trackbar);
    createTrackbar("S_min", "HSV_spilt", &Smin_Value, SV_maxValue, on_Trackbar);
    createTrackbar("V_max", "HSV_spilt", &Vmax_Value, SV_maxValue, on_Trackbar);
    createTrackbar("V_min", "HSV_spilt", &Vmin_Value, SV_maxValue, on_Trackbar);
    on_Trackbar(1, 0);

    while (ros::ok()) {
        capture.read(frame);

        if (frame.empty()) {
            break;
        }

//        Mat frIn = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/xiaohuangya.jpg");
        Mat frIn = frame;
//        Mat frIn = frame(cv::Rect(0, 0, frame.cols / 2, frame.rows)); //截取zed的左目图片
//        imshow("src", frIn);

        filter(frIn);

        Mat spilt_gray;

//        RGB_filter(frIn, spilt_gray);



        object_detect(frIn);


//        Mat frIn_gray;
//        cvtColor(frIn, frIn_gray, CV_RGB2GRAY);
//        Mat binaryImag = Mat::zeros(frIn.size(), CV_8UC1);
//        threshold(frIn_gray, binaryImag, 127, 255, CV_THRESH_BINARY);
//        imshow("binaryImag", binaryImag);
//
//        vector<vector<Point>> contours;
//        vector<Vec4i> hierarchy;
//        findContours(binaryImag, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
//
//        Mat conImage = Mat::zeros(binaryImag.size(), CV_8UC1);
//        //绘制轮廓
//        drawContours(conImage, contours, -1, Scalar(255));
//        imshow("conImage", conImage);
//
//        Mat interestImage = Mat::zeros(binaryImag.size(), CV_8UC1);
//
//        Rect markRect;
//        vector<Rect> boundRect(contours.size());
//        Point2f center;
//        float radius;
//        for (int i = 0; i < contours.size(); i++) {
//            if (contourArea(contours[i]) > 1000 && contourArea(contours[i]) < 6000) {
//                // 获取最小外接矩形
//                boundRect[i] = boundingRect(contours[i]);
//                markRect = boundRect[i];
//
////                minEnclosingCircle(contours[i], center, radius);
////                circle(interestImage, center, radius, Scalar(255), CV_FILLED);
//                // 在原图像上绘制最小外接矩形
//                rectangle(interestImage, boundRect[i], Scalar(255), -1);
//
//            }
//        }
//        imshow("interestImage", interestImage);
//        Mat interested = Mat::zeros(frIn.size(), CV_8UC3);
//        frIn.copyTo(interested, interestImage);
//        imshow("interested", interested);
//
//        int *Color;
//        vector<Scalar> colorRGB(6);
//        if (!markRect.empty()) {
//            Mat colorAny;
//            resize(frIn, colorAny, Size(markRect.width, markRect.height), markRect.x, markRect.y);
//            Color = colorAnalyse(colorAny);
//        }
//        cout << Color[0]<< endl;


        ros::spinOnce();
        loop_rate.sleep();
        waitKey(5);
    }

}