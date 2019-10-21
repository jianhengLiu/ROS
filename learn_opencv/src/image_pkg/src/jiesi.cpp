#include <iostream>
#include <highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ros/ros.h"
#include<geometry_msgs/Twist.h>
#include "sensor_msgs/Image.h"
#include <math.h>
#include <complex.h>

#define LINEAR_X 0
using namespace std;
using namespace cv;



void Gaussian(Mat input,Mat output,double sigma)
{
    int rows = input.rows;
    int cols = input.cols;
    imshow("input",input);
    output = Mat::zeros(rows,cols,CV_8UC1);
    double arr[3][3];
    double sum = 0.0;
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            sum += arr[i][j] = exp(-((i - 1)*(i - 1) + (j - 1)*(j - 1)) / (2 * sigma*sigma));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            arr[i][j] /= sum;

    for (int i = 0; i < rows ; i++)
        for (int j = 0; j < cols ; j++){
            if((i - 1) > 0 && (i + 1) < rows && (j - 1) > 0 && (j + 1) < cols){
                for (int a = 0 ; a < 3; a++)
                    for(int b = 0; b < 3; b++)
                        output.at<uchar>(i,j) += input.at<uchar>(i - 1 + a,j - 1 + b)*arr[a][b];
            }}
    imshow("gaussian",output);

}


int main(int argc, char **argv) {

    ROS_WARN("*****START");
    ros::init(argc, argv, "trafficLaneTrack");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/smoother_cmd_vel", 5);

    VideoCapture capture;
    capture.open(0);
    if (!capture.isOpened()) {
        printf("摄像头没有正常打开,重新插拔工控机上当摄像头\n");
        return 0;
    }
//    waitKey(1000);
//    Mat frame;
//    int nFrames = 0;
    while (ros::ok()) {
        Mat frIn;
        capture.read(frIn);
        if (frIn.empty()) {
            break;
        }
//        frIn = imread("sjiaozhun.jpg");//当前帧图片
        frIn = frIn(cv::Rect(0, 0, frIn.cols / 2, frIn.rows));//截取 zed 的左目图片
        cvtColor(frIn, frIn, CV_RGB2GRAY);

        int frameWidth = frIn.cols;
        int frameHeight = frIn.rows;



        Mat gaussin(frameHeight, frameWidth, CV_8UC1);
        Gaussian(frIn, gaussin, 2.5);










        ros::spinOnce();
        waitKey(5);
//        ROS_INFO("1");
    }
    return 0;
}