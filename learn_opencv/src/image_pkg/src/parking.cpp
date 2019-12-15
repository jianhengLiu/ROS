//
// Created by chrisliu on 2019/11/25.
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
#define KP 0.5 //小车行走当比列系数
#define KI 0 //小车行走当积分系数
#define KD 0 //小车行走当微分系数

#define CAR_CENTER (370) //小车中心像素坐标

typedef struct PID_Error {
    float now;
    float last;
    float last_prev;

    float Integral_error;
} Error_pid;

ros::Publisher pub_vel;

enum CAMERA_STATE {
    OK,
    PARK_UNDETECTED,
    TURN,
    OBSTACLE_DETECTED
};

CAMERA_STATE camera_state;

Error_pid carError;

int delayFlag = 1;

void errorReset(Error_pid carError) {
    carError.now = 0;
    carError.last = 0;
    carError.last_prev = 0;
    carError.Integral_error = 0;
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
int Hmax_Value = 83;
int Hmin_Value = 22;
int Smax_Value = 255;
int Smin_Value = 43;
int Vmax_Value = 255;
int Vmin_Value = 35;

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
//    imshow("HSV_space", hsv_space);
    imshow("HSV_spilt", input_temp);
    imshow("spilt_binary", spilt_binary);
    spilt_gray = spilt_binary;
}

void velocity_control(int input) {
    if (camera_state == OK) {
        carError.now = (input - CAR_CENTER) * 3.7 / 911; //车道线坐标校正过后转换到实际距离（以m为单位）
        carError.Integral_error += carError.now;
    }
        //不停车版，自动找线
    else if (camera_state == PARK_UNDETECTED) {
        camera_state = OK;
        carError.Integral_error += carError.now;
    } else {
        errorReset(carError);
    }

    geometry_msgs::Twist cmd;

    if (camera_state == OK) {
        cmd.linear.x = LINEAR_X;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = -KP * carError.now;// + KI * carError.Integral_error + KD * (carError.now - carError.last));

        pub_vel.publish(cmd);
        ROS_INFO("ONLY TRACK  pub linear.x = %f,angular.z = %f\n", cmd.linear.x, cmd.angular.z);
    } else if (camera_state == TURN) {
        cmd.linear.x = 0;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = 1 * input;

        pub_vel.publish(cmd);
        ROS_INFO("ONLY TURN  pub linear.x = %f,angular.z = %f\n", cmd.linear.x, cmd.angular.z);
    } else {
        cmd.linear.x = 0;
        cmd.linear.y = 0;
        cmd.linear.z = 0;
        cmd.angular.x = 0;
        cmd.angular.y = 0;
        cmd.angular.z = 0;

        pub_vel.publish(cmd);
        ROS_WARN("STOP! pub linear.x = %f,angular.z = %f\n", cmd.linear.x, cmd.angular.z);

        errorReset(carError);
    }

    carError.last = carError.now; //更新上一个时刻的小车位置
    camera_state = OK;
}


float angle = 0;

void object_detect(Mat input) {
    Mat input_binary;
    RGB_filter(input, input_binary);

    filter(input_binary);

//    Mat cannyMat;
//    Canny(input_binary, cannyMat, 50, 200);
//    cvtColor(cannyMat, cannyMat, CV_RGB2GRAY);

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(input_binary, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

    Mat conImage = Mat::zeros(input.size(), CV_8UC1);
    //绘制轮廓
    drawContours(conImage, contours, -1, Scalar(255), 2);
//    imshow("conImage", conImage);



//    vector<vector<Point>> hull(contours.size());
//    //to do list :1.筛选最大面积的进行寻找。
//    vector<Point> approx;
//    for (int i = 0; i < contours.size(); i++) {
//        convexHull(Mat(contours[i]), hull[i], false, true);
//        approxPolyDP(Mat(hull[i]), approx, 9, true);
//        if (approx.size() != 4 | fabs(contourArea(Mat(approx))) < 1000) {
//            approx.clear();
//            continue;
//        }
//        polylines(input, approx, true, Scalar(0, 0, 255));
//    }

////设置目标图像变换顶点
//    Point2f AffinePoints1[4] = {Point2f(235, 355), Point2f(435, 360), Point2f(235, 90), Point2f(435, 95)};
//    //计算变换矩阵
//    Mat Trans = getPerspectiveTransform(AffinePoints0, AffinePoints1);
//    //矩阵仿射变换
//    warpPerspective(frame, dst, Trans, Size(frame.cols, frame.rows));
//    //分别显示变换先后图像进行对比
//    imshow("src", frame);
//    imshow("dst", dst);

////    霍夫直线检测
    vector<Vec4f> line_data;
    HoughLinesP(conImage, line_data, 1, CV_PI / 180.0, 80, 10, 20);
    //把得到的直线显示在图中
    int sumx = 0;
    int sumy = 0;
    int maxLine = 0;
    Point2f startPoint, stopPoint;
    for (size_t i = 0; i < line_data.size(); i++) {
        Vec4f temp = line_data[i];
        line(input, Point(temp[0], temp[1]), Point(temp[2], temp[3]), Scalar(0, 255, 0), 2);
        int deltax = abs(temp[0] - temp[2]);
        int deltay = abs(temp[1] - temp[3]);
        int tempLine = deltax + deltay;
        if (tempLine > maxLine) {
            maxLine = tempLine;while (k > 0) {
                    velocity_control(CAR_CENTER);
                    k--;
                    waitKey(1);
                }
            startPoint = Point(temp[0], temp[1]);
            stopPoint = Point(temp[2], temp[3]);
        }

        sumx += temp[0] + temp[2];
        sumy += temp[1] + temp[3];
    }
    if (line_data.empty() != 1) {
        int avgx = (sumx / line_data.size()) / 2;
        int avgy = (sumy / line_data.size()) / 2;
        circle(input, Point2f(avgx, avgy), 10, Scalar(255, 0, 0), -1);
        line(input, startPoint, stopPoint, Scalar(0, 0, 255), 2);
    }
//
//    Mat interestImage = Mat::zeros(input.size(), CV_8UC1);
//
//    Rect boundRect;
    /////////////////////////////
    Point2f center;
    float radius = 0.0;
    int maxArea = 0;
    vector<Point> maxContour;

    for (int i = 0; i < contours.size(); i++) {
        int temp = contourArea(contours[i]);
        if (temp > maxArea) {
            maxArea = temp;
            maxContour = contours[i];
        }
    }
    if (maxArea != 0) {
        minEnclosingCircle(maxContour, center, radius);

//        vector<int> hull;
//        convexHull(maxContour, hull, true);
//        Point point0 = maxContour[hull[(int) hull.size() - 1]];
//        int longest = 0;
//        for (int i = 0; i < hull.size(); i++) {
//            Point point = maxContour[hull[i]];
//            line(input, point0, point, Scalar(0, 0, 255), 2);
//            point0 = point;
//            int deltax = abs(maxContour[hull[i]].x - maxContour[hull[(i + 1) % 4]].x);
//            int deltay = abs(maxContour[hull[i]].y - maxContour[hull[(i + 1) % 4]].y);
//            int temp = deltax + deltay;
//            if (temp > longest) {
//                longest = temp;
//                angle = abs((float)deltay / (deltax + 1));
//            }
//        }


//        RotatedRect box = minAreaRect(maxContour);
//        Point2f vertex[4];
//        box.points(vertex);
//        int longest = 0;
//        for (int i = 0; i < 4; i++) {
//            line(input, vertex[i], vertex[(i + 1) % 4], Scalar(255, 0, 0), 2);
//            int deltax = abs(vertex[i].x - vertex[(i + 1) % 4].x);
//            int deltay = abs(vertex[i].y - vertex[(i + 1) % 4].y);
//            int temp = deltax + deltay;
//            if (temp > longest) {
//                longest = temp;
//                angle = abs((float)deltay /(deltax+1) );
//            }
//        }
//        int area = contourArea(maxContour);
        if (radius > 60) {
            delayFlag = 0;
            circle(input, center, (int) radius, Scalar(0, 255, 0), 2);
            if (maxLine > 200)
                angle = atan((float) (startPoint.x - stopPoint.x) / ((startPoint.y - stopPoint.y + 1)/0.8));
//            cout << center << endl;
            camera_state = OK;
            cout << angle << endl;
            velocity_control(center.x);

        } else {
            if (delayFlag == 0) {
                int k = 300;
//                while (k > 0) {
//                    velocity_control(CAR_CENTER);
//                    k--;
//                    waitKey(1);
//                }

                delayFlag = 1;
                k = 1300 * abs(angle)/1;
                int temp = 0;
                if (angle > 0) {
                    temp = 1;
                } else if (angle < 0) {
                    temp = -1;
                } else
                    temp = 0;
//                cout << k << endl;
                while (k > 0) {
                    camera_state = TURN;
                    velocity_control(temp);
                    cout << angle << endl;
                    k--;
                    waitKey(1);
                }
                angle = 0;
                camera_state = PARK_UNDETECTED;
            } else {
                camera_state = PARK_UNDETECTED;
                velocity_control(1);
            }
        }
    }
//////////////////
//    imshow("interestImage", interestImage);
//    Mat interested = Mat::zeros(input.size(), CV_8UC3);
//    input.copyTo(interested, interestImage);
//    imshow("interested", interested);
    imshow("input", input);

}

int main(int argc, char **argv) {
    ros::init(argc, argv, "parking");
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

    delayFlag = 1;
    camera_state = PARK_UNDETECTED;

    while (ros::ok()) {
        capture.read(frame);

        if (frame.empty()) {
            break;
        }

//        Mat frIn = frame;
        Mat frIn = frame(cv::Rect(0, 0, frame.cols / 2, frame.rows)); //截取zed的左目图片

        filter(frIn);

        object_detect(frIn);

        ros::spinOnce();
        loop_rate.sleep();
        waitKey(5);
    }
}
