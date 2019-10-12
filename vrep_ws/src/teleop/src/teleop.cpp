#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <boost/asio.hpp>                  //包含boost库函数
#include <boost/bind.hpp>
#include <iostream>



using namespace std;
using namespace boost::asio;
unsigned char buf[10];

io_service iosev;
serial_port sp(iosev, "/dev/ttyUSB0");

int main(int argc, char *argv[])
{
	sp.set_option(serial_port::baud_rate(115200));  //波特率
    sp.set_option(serial_port::flow_control());		//流控制(none/software/hardware)
    sp.set_option(serial_port::parity());			//奇偶校验(none/odd/even)
    sp.set_option(serial_port::stop_bits());		//停止位(one/onepointfive/two)
    sp.set_option(serial_port::character_size(8));	//字符大小



	ros::init(argc, argv, "teleop");
	ros::NodeHandle n;
	ros::Publisher teleop_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
	ros::Rate loop_rate(60);
	while (ros::ok())
	{
		 read(sp,buffer(buf));
		 geometry_msgs::Twist twist;
		 for(int i=0;i<5;++i)
		 {
			if(buf[i]==0xff)
			{
				twist.linear.x=buf[i+3]-50;
				twist.linear.x*=5;
				twist.linear.y=buf[i+2]-50;
				twist.linear.y*=-5;
				twist.angular.z=buf[i+4]-50;
				twist.angular.z/=-20;
				cout<<twist.linear.x<<" "<< twist.linear.y<<" "<< twist.angular.z<<endl;

				break;
			}
		 }
		teleop_pub.publish(twist);
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
