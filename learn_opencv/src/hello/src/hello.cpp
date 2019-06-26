#include <ros/ros.h>
int main(int argc, char **argv)
{
    ros::init(argc,argv,"printHelloRosPK");//初始化ros系统,注意这里的printHelloRosPK是节点的名称，不要搞成别的
    ros::NodeHandle n;//创建一个ros节点
    ROS_INFO("Hello ROS");//打印信息，类似于printf，但据说强很多
    ros::spinOnce();//消息回调处理函数，也就是系统等在这里，直到有回调消息进入，当然在我们这个程序中它永远等不到，只是习惯性的写一下
}
