#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <apriltags2_ros/AprilTagDetectionArray.h>

using namespace std;

class detect_and_fly {
public:
    detect_and_fly()
    {
        pub = nh.advertise<geometry_msgs::PoseStamped>("firefly/command/pose", 1);
        sub2 = nh.subscribe("/tag_detections", 1, &detect_and_fly::detect_data, this);
        sub = nh.subscribe("/firefly/ground_truth/pose", 1,
            &detect_and_fly::Callback, this);
    }
    void detect_data(const apriltags2_ros::AprilTagDetectionArray::ConstPtr& msg)
    {
        if (msg->detections.size() != 0)
            tag_pose = msg->detections[0].pose.pose.pose;
        else {
            tag_pose.position.x = 0;
            tag_pose.position.y = 0;
            tag_pose.position.z = 0.3;
        }
    }
    void Callback(const geometry_msgs::Pose::ConstPtr& msg)
    {
        geometry_msgs::PoseStamped msg2;
        msg2.pose.position.x = msg->position.x - 0.13311 + tag_pose.position.z - 0.3;
        msg2.pose.position.y = msg->position.y - tag_pose.position.x;
        msg2.pose.position.z = msg->position.z + 0.19711 - tag_pose.position.y;
        cout << "x,y,z:" << endl
             << tag_pose.position << endl;
        pub.publish(msg2);
    }

private:
    ros::NodeHandle nh;
    ros::Publisher pub;
    ros::Subscriber sub;
    ros::Subscriber sub2;
    geometry_msgs::Pose tag_pose;
};

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "fly");
    detect_and_fly a;
    ros::spin();
    return 0;
}