//
// Created by chrisliu on 2019/12/5.
//
#include "ros/ros.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>
#include <stdio.h>

#include <geometry_msgs/Twist.h>

using namespace cv;
using namespace std;

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

ros::Publisher pub_vel;

enum CAMERA_STATE {
    OK,
    PARK_UNDETECTED,
    OBSTACLE_DETECTED
};

CAMERA_STATE camera_state;

Error_pid carError;

void errorReset(Error_pid carError) {
    carError.now = 0;
    carError.last = 0;
    carError.last_prev = 0;
    carError.Integral_error = 0;
}

void velocity_control(int center) {
    if (camera_state == OK) {
        carError.now = (center - CAR_CENTER) * 3.7 / 911; //车道线坐标校正过后转换到实际距离（以m为单位）
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
        cmd.angular.z = -(KP * carError.now + KI * carError.Integral_error + KD * (carError.now - carError.last));

        pub_vel.publish(cmd);
        ROS_INFO("ONLY TRACK  pub linear.x = %f,angular.z = %f\n", cmd.linear.x, cmd.angular.z);
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

int main(int argc, char **argv) {
    ros::init(argc, argv, "xunxian");
    ros::NodeHandle n;
    ros::Rate loop_rate(30);

    pub_vel = n.advertise<geometry_msgs::Twist>("/cmd_vel", 5);

    VideoCapture capture(1);
    if (!capture.isOpened()) {
        printf("摄像头没有正常打开，重新插拔工控机上当摄像头\n");
        return 0;
    }
    Mat frame; //当前帧
    while (ros::ok()) {
        capture.read(frame);

        if (frame.empty()) {
            break;
        }

        Mat frIn = frame;
//        Mat frIn = frame(cv::Rect(0, 0, frame.cols / 2, frame.rows)); //截取zed的左目图片

        cvtColor(frIn, frIn, CV_RGB2GRAY);
        vector<Rect> found;
        HOGDescriptor defaultHog;
        defaultHog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
        //进行检测
        defaultHog.detectMultiScale(frIn, found);
        //画长方形，框出行人
        for (int i = 0; i < found.size(); i++) {
            Rect r = found[i];
            rectangle(frIn, r.tl(), r.br(), Scalar(0, 0, 255), 3);
        }
//    velocity_control()
        namedWindow("检测行人", CV_WINDOW_AUTOSIZE);
        imshow("检测行人", frIn);
        waitKey(1);
    }


    return 0;
}
