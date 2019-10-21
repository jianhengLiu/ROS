//
// Created by chrisliu on 2019/10/19.
//

#include "ros/ros.h"
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>

using namespace std;
using namespace cv;

void edgedetect_canny(Mat input) {
    int rows = input.rows;
    int cols = input.cols;
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++) {
            if (input.at<uchar>(y, x) < 125)
                input.at<uchar>(y, x) = 0;
            else
                input.at<uchar>(y, x) = 255;
        }
    imshow("chessboard", input);
    Mat gaussin_blur;
    GaussianBlur(input, gaussin_blur, Size(5, 5), 0);
    imshow("gaussin_blur", gaussin_blur);

    Mat grad_sobel;
    int sobel_x[3][3] = {{-1, 0, 1},
                         {-2, 0, 2},
                         {-1, 0, 1}};
    int sobel_y[3][3] = {{-1, -2, -1},
                         {0,  0,  0},
                         {1,  2,  1}};
    //边界扩展
    copyMakeBorder(gaussin_blur, grad_sobel, 1, 1, 1, 1, BORDER_CONSTANT, Scalar::all(255));
    Mat grad_x = Mat::zeros(rows, cols, CV_32SC1);
    Mat grad_y = Mat::zeros(rows, cols, CV_32SC1);
    Mat theta = Mat::zeros(rows, cols, CV_32FC1);
    Mat grad = Mat::zeros(rows, cols, CV_8UC1);
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++) {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++) {
                    grad_x.at<int>(y, x) += grad_sobel.at<uchar>(y + j, x + i) * sobel_x[j][i];
                    grad_y.at<int>(y, x) += grad_sobel.at<uchar>(y + j, x + i) * sobel_y[j][i];
                }
//                cout<<(int)grad_x.at<uchar>(y, x)<<endl;
            theta.at<float>(y, x) = atan2((float) grad_y.at<int>(y, x), (float) grad_x.at<int>(y, x));
            grad.at<uchar>(y, x) = abs(grad_x.at<int>(y, x)) + abs(grad_y.at<int>(y, x));
        }
//        cout<<(int)grad_x.at<uchar>(150, 197)<<endl;
    grad_x.convertTo(grad_x, CV_8UC1);
    grad_y.convertTo(grad_y, CV_8UC1);
    imshow("grad_x", grad_x);
    imshow("grad_y", grad_y);
    imshow("grad", grad);

    Mat suppresion = Mat::zeros(rows, cols, CV_8UC1);
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++) {
            float angle = theta.at<float>(y, x);
            int grad_temp = grad.at<uchar>(y, x);
            if ((angle > -1 * M_PI / 8 && angle <= M_PI / 8) || (angle > 7 * M_PI / 8 && angle <= -7 * M_PI / 8)) {
                if (grad_temp < grad.at<uchar>(y, x + 1) || grad_temp < grad.at<uchar>(y, x - 1)) {
                    suppresion.at<uchar>(y, x) = 0;
                } else
                    suppresion.at<uchar>(y, x) = grad_temp;
            } else if ((angle > M_PI / 8 && angle <= M_PI * 3 / 8) ||
                       (angle <= -1 * M_PI * 5 / 8 && angle > -7 * M_PI / 8)) {
                if (grad_temp < grad.at<uchar>(y - 1, x + 1) || grad_temp < grad.at<uchar>(y + 1, x - 1)) {
                    suppresion.at<uchar>(y, x) = 0;
                } else
                    suppresion.at<uchar>(y, x) = grad_temp;
            } else {
                if (grad_temp < grad.at<uchar>(y - 1, x) || grad_temp < grad.at<uchar>(y + 1, x)) {
                    suppresion.at<uchar>(y, x) = 0;
                } else
                    suppresion.at<uchar>(y, x) = grad_temp;
            }
        }
    imshow("suppresion", suppresion);

    int threshold_low = 85;
    int threshold_high = 170;
    Mat NH = Mat::zeros(rows, cols, CV_8UC1);
    Mat NL = Mat::zeros(rows, cols, CV_8UC1);
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++) {
            int temp = suppresion.at<uchar>(y, x);
            if (temp > threshold_low && temp <= threshold_high)
                NL.at<uchar>(y, x) = temp;
            if (temp > threshold_high)
                NH.at<uchar>(y, x) = temp;

        }

    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++) {
            if (suppresion.at<uchar>(y, x) != 0) {
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++) {
                        if (NL.at<uchar>(y - 1 + j, x - 1 + i) != 0)
                            NH.at<uchar>(y - 1 + j, x - 1 + i) = NL.at<uchar>(y - 1 + j, x - 1 + i);
                    }
            }
        }
    imshow("NH", NH);
}

void hough_line(Mat input) {
    int rows = input.rows;
    int cols = input.cols;
    imshow("road", input);
    Canny(input, input, 85, 170);
    int rmax = sqrt(pow(input.rows, 2) + pow(input.cols, 2));
    Mat para_space = Mat::zeros(181, 2 * rmax, CV_8UC1);
    for (int y = 0; y < rows; y++)
        for (int x = 0; x < cols; x++) {
            if (input.at<uchar>(y, x) == 255)
                for (int theta = 0; theta <= 180; theta++) {
                    int r = x * cos(theta * M_PI / 180) + y * sin(theta * M_PI / 180) + rmax;
                    if (r < 0 || r > 2 * rmax) {
                        continue;
                    }
                    para_space.at<uchar>(theta, r)++;
                }
        }
    imshow("para_space", para_space);


    //定义一下清零时的角度和极径范围
    int DisAllow = 20;
    int AngleAllow = 10;
    //定义最大值
    int MaxValue = 140;
    for (int i = 0; i <= 180; i++) {
        for (int j = 0; j < 2 * rmax; j++) {
            if (para_space.at<uchar>(i, j) > MaxValue) {
                for (int r = 1; r < AngleAllow; r++) {
                    if (para_space.at<uchar>(i, j) < para_space.at<uchar>(i - r, j) ||
                        para_space.at<uchar>(i, j) < para_space.at<uchar>(i + r, j)) {
                        para_space.at<uchar>(i, j) = 0;
                        break;
                    }
                }
                for (int r = 1; r < DisAllow; r++) {
                    if (para_space.at<uchar>(i, j) < para_space.at<uchar>(i, j - r) ||
                        para_space.at<uchar>(i, j) < para_space.at<uchar>(i, j + r)) {
                        para_space.at<uchar>(i, j) = 0;
                        break;
                    }
                }

                if (para_space.at<uchar>(i, j) > MaxValue) {
                    Point2i ps(0, (j - rmax) / sin(i * M_PI / 180));
                    Point2i pe(cols - 1,
                               ((j - rmax) - (cols - 1) * cos(i * M_PI / 180)) / sin(i * M_PI / 180));
                    line(input, ps, pe, Scalar(255), 1);
                }
            }
        }
    }
    imshow("hough", input);
    waitKey();
}

void hough_round(Mat round)
{
    int rows = round.rows;
    int cols = round.cols;
    Canny(round, round, 85, 170);
    imshow("round", round);
    int rmax = sqrt(pow(round.rows, 2) + pow(round.cols, 2));
    vector<vector<vector<int>>> para_space(cols, vector<vector<int> >(rows, vector<int>(rmax)));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            if (round.at<uchar>(i, j) == 255) {
                for (int x = 0; x < cols; x++) {
                    for (int y = 0; y < rows; y++) {
                        para_space[x][y][(int) sqrt(pow(j - x, 2) + pow(i - y, 2))]++;
                    }
                }
            }
        }

    int threshold = 350;
    for (int x = 0; x < cols; x++)
        for (int y = 0; y < rows; y++) {
            for (int r = 1; r < rmax; r++) {
                if (para_space[x][y][r] > threshold) {
                    Point2i center(x, y);
                    circle(round, center, r, Scalar(255), 5);
                }
            }
        }
    imshow("round_output", round);
    waitKey();
}

int main(int argc, char **argv) {
//    VideoCapture capture;
//    capture.open(0);//打开相机


    ROS_WARN("*****START");
    ros::init(argc, argv, "histogram");//初始化ROS节点
    ros::NodeHandle n;

//    if (!capture.isOpened())
//    {
//        printf("摄像头没有正常打开，重新插拔工控机上当摄像头\n");
//        return 0;
//    }
    //读图测试

    while (ros::ok()) {
        Mat frame;//当前帧图片
//        capture.read(frame);
//        if(frame.empty())
//        {
//            break;
//        }

//        frame = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/chessboard.jpg", IMREAD_GRAYSCALE);
//        frame = frame(cv::Rect(0, 0, frIn.cols / 2, frIn.rows));//截取 zed 的左目图片
//        edgedetect_canny(frame);

        Mat road = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/road.jpg", IMREAD_GRAYSCALE);
        hough_line(road);

//        Mat round = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/round.jpg", IMREAD_GRAYSCALE);
//        hough_round(round);
        ros::spinOnce();
//		loop_rate.sleep();
        waitKey(5);

    }
    return 0;
}

