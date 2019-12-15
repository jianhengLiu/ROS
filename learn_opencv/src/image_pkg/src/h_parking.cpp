//
// Created by chrisliu on 2019/12/7.
//
#include "ros/ros.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>

#include "sensor_msgs/Image.h"
#include <geometry_msgs/Twist.h>

using namespace cv;

#define MAX_AREA 2400
#define MIN_AREA 1000

//仅用比例 v=0.2 kp=1.1
#define LINEAR_X (0.2) //小车行走线速度
#define KP 1.1 //小车行走当比列系数
#define KI 0 //小车行走当积分系数
#define KD 0 //小车行走当微分系数

#define CAR_CENTER (395) //小车中心像素坐标

typedef struct PID_Error {
    float now;
    float last;
    float last_prev;

    float Integral_error;
} Error_pid;

enum CAMERA_STATE
{
    OK,
    LINE_UNDETECTED,
    OBSTACLE_DETECTED
};

CAMERA_STATE camera_state;

Error_pid carError;

void errorReset(Error_pid carError)
{
    carError.now=0;
    carError.last=0;
    carError.last_prev=0;
    carError.Integral_error =0;
}

Mat project(Mat frame)
{
    Mat dst;
    //设置原图变换顶点
    Point2f AffinePoints0[4] = { Point2f(235, 355), Point2f(435, 360), Point2f(260, 130), Point2f(410, 135) };
    //设置目标图像变换顶点
    Point2f AffinePoints1[4] = { Point2f(235, 355), Point2f(435, 360), Point2f(235, 90), Point2f(435, 95) };
    //计算变换矩阵
    Mat Trans = getPerspectiveTransform(AffinePoints0, AffinePoints1);
    //矩阵仿射变换
    warpPerspective(frame, dst, Trans, Size(frame.cols, frame.rows));
    //分别显示变换先后图像进行对比
    imshow("src", frame);
    imshow("dst", dst);
    return dst;
}

cv::Point2f extractCenter(Mat frame)
{
    Mat imageYellow, morImage;
    Mat kerneal = getStructuringElement(MORPH_RECT, Size(5, 5));

    std::vector<std::vector<Point> > contours;
    std::vector<Vec4i> hireachy;

    Point2f center;
    float radius = 20;

    inRange(frame, Scalar(0, 80, 80), Scalar(50, 255, 255), imageYellow); //提取黄色
    morphologyEx(imageYellow, morImage, MORPH_OPEN, kerneal); //形态学开操作
    findContours(imageYellow, contours, hireachy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0)); //获取边界
    if (contours.size() > 0) //框选目标的边界
    {

        for (int i = 0; i < contours.size(); i++) {
            double area = contourArea(contours[static_cast<int>(i)]); //获取轮廓面积
            printf("area=%f",area);
            if (area > MIN_AREA && area < MAX_AREA) //筛选面积
            {
                camera_state = OK;
                minEnclosingCircle(contours[static_cast<int>(i)], center, radius); //寻找包围圆形
                break;
            }
            else {
                camera_state = LINE_UNDETECTED;
            }
        }
    } else {
        camera_state = LINE_UNDETECTED;
    }
    circle(frame, center, (int)radius, Scalar(0, 255, 0), 2);
    drawContours(frame, contours, -1, Scalar(255, 255, 255));

    imshow("output", frame);

    return center;
}



int main(int argc, char** argv)
{
    ros::init(argc, argv, "xunxian");
    ros::NodeHandle n;
    ros::Rate loop_rate(30);

    ros::Publisher pub_vel = n.advertise<geometry_msgs::Twist>("/cmd_vel", 5);

    VideoCapture capture(0);
    if (!capture.isOpened()) {
        printf("摄像头没有正常打开，重新插拔工控机上当摄像头\n");
        return 0;
    }

    Mat frame; //当前帧
    errorReset(carError);

    while (ros::ok()) {
        capture.read(frame);

        if (frame.empty()) {
            break;
        }

        Mat frIn = frame(cv::Rect(0, 0, frame.cols / 2, frame.rows)); //截取zed的左目图片

        frIn = project(frIn);
        Point2f center = extractCenter(frIn);

        if (camera_state == OK) {
            carError.now = (center.x - CAR_CENTER) * 3.7 / 911; //车道线坐标校正过后转换到实际距离（以m为单位）
            carError.Integral_error += carError.now;
        }
            //不停车版，自动找线
        else if(camera_state == LINE_UNDETECTED)
        {
            camera_state = OK;
            carError.Integral_error += carError.now;
        }
        else {
            errorReset(carError);
        }

        geometry_msgs::Twist cmd_yellow;

        if (camera_state == OK) {
            cmd_yellow.linear.x = LINEAR_X;
            cmd_yellow.linear.y = 0;
            cmd_yellow.linear.z = 0;
            cmd_yellow.angular.x = 0;
            cmd_yellow.angular.y = 0;
            cmd_yellow.angular.z = -(KP * carError.now + KI * carError.Integral_error + KD * (carError.now - carError.last));

            pub_vel.publish(cmd_yellow);
            ROS_INFO("ONLY TRACK  pub linear.x = %f,angular.z = %f\n", cmd_yellow.linear.x, cmd_yellow.angular.z);
        } else {
            cmd_yellow.linear.x = 0;
            cmd_yellow.linear.y = 0;
            cmd_yellow.linear.z = 0;
            cmd_yellow.angular.x = 0;
            cmd_yellow.angular.y = 0;
            cmd_yellow.angular.z = 0;

            pub_vel.publish(cmd_yellow);
            ROS_WARN("STOP! pub linear.x = %f,angular.z = %f\n", cmd_yellow.linear.x, cmd_yellow.angular.z);

            errorReset(carError);
        }

        carError.last = carError.now; //更新上一个时刻的小车位置
        camera_state = OK;

        ros::spinOnce();
        loop_rate.sleep();
        waitKey(5);
    }
}
