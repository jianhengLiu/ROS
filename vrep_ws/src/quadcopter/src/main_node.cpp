//
// Created by chrisliu on 2019/12/7.
//
#include "ros/ros.h"
#include <stdio.h>

#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>

#include <sensor_msgs/Image.h>

using namespace cv;
using namespace std;

void floorCamera_cb(const sensor_msgs::ImageConstPtr &floorImage) {
    cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(floorImage, "bgr8");
    Mat img_floor = cv_ptr->image;
    /**
     * 0 means flipping around the x-axis
     * positive value (for example, 1) means flipping around y-axis.
     * Negative value (for example, -1) means flipping around both axes.
     */
    flip(img_floor, img_floor, 0);
    imshow("quadcopter", img_floor);
    waitKey(1);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "main");
    ros::NodeHandle nh;
    ros::Rate loop_rate(30);

    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub_floorCamera = it.subscribe("/floorCamera", 1, floorCamera_cb);


    while (ros::ok()) {

        ros::spin();
    }

    return 0;
}