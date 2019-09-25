//
// Created by chrisliu on 2019/9/25.
//

#include "ros/ros.h"
#include <iostream>
#include <algorithm>

#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>

using namespace std;

ros::Publisher pub_leftMotorSpeed;
ros::Publisher pub_rightMotorSpeed;

void keyboard_callback(const geometry_msgs::Twist::ConstPtr &keyboard)
{
    std_msgs::Float32 speed;
    speed.data = keyboard->linear.x;
    pub_leftMotorSpeed.publish(speed);
    pub_rightMotorSpeed.publish(speed);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "BubbleRob");//初始化ROS节点
    ros::NodeHandle n;

    ros::Subscriber sub_keyboard = n.subscribe("/cmd_vel",1,keyboard_callback);

    pub_leftMotorSpeed = n.advertise<std_msgs::Float32>("/leftMotorSpeed", 1);
    pub_rightMotorSpeed = n.advertise<std_msgs::Float32>("/rightMotorSpeed", 1);

    while (ros::ok()) {
        std_msgs::Float32 speed;
        speed.data = 1;




        ros::spinOnce();
//		loop_rate.sleep();

    }
    return 0;
}