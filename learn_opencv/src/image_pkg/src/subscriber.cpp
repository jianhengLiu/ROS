#include<stdlib.h>
#include<cv.h>
#include<highgui.h>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include"ros/ros.h"
#include"std_msgs/String.h"
#include"std_msgs/Bool.h"
#include"std_msgs/Float32.h"

#include<geometry_msgs/Twist.h>
#include"sensor_msgs/Image.h"

#define LINEAR_X 0

using namespace cv;

int main(int argc,char **argv)
{
    VideoCapture capture;
       capture.open(0);

    ROS_WARN("*****START");
    ros::init(argc,argv,"traficLaneTrack");
       ros::NodeHandle n;

        ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/smoother_cmd_vel",5);

        if(!capture.isOpened())
{
            printf("The camera is not open.\n");
            return 0;
}
waitKey(1000);
Mat frame;
int nFrames=0;
int frameWidth = capture.get(CV_CAP_PROP_FRAME_WIDTH);
int frameHeight = capture.get(CV_CAP_PROP_FRAME_HEIGHT);

while(ros::ok())
{
    capture.read(frame);
    if(frame.empty())
    {
        break;
   }
    Mat frIn = frame(cv::Rect(0,0,frame.cols/2,frame.rows));

    Mat Grey,Out;
    cvtColor(frIn,Grey,COLOR_BGR2GRAY);
    equalizeHist(Grey,Out);  
    imshow("1",Grey);
    imshow("2",Out);
 
    geometry_msgs::Twist cmd_red;
   

    cmd_red.linear.x = LINEAR_X;
    cmd_red.linear.y = 0;
    cmd_red.linear.z = 0;
    cmd_red.angular.x = 0;
    cmd_red.angular.y = 0;
    cmd_red.angular.z = 0.2;

   pub.publish(cmd_red);

   ros::spinOnce();
  
   waitKey(5);
}

     return 0;
}
