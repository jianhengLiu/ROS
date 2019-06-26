#include "apriltags2_ros/AprilTagDetectionArray.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/PoseStamped.h"
#include "ros/ros.h"
#include "std_msgs/String.h"

using namespace std;

class control_fly {
public:
    control_fly()
    {
        pub_pose = nh.advertise<geometry_msgs::PoseStamped>("/firefly/command/pose", 5);
        sub_tag = nh.subscribe("/tag_detections", 10, &control_fly::callback_tag, this);
        sub_fly = nh.subscribe("/firefly/ground_truth/pose", 10, &control_fly::callback_fly, this);
    }

    void callback_tag(const apriltags2_ros::AprilTagDetectionArray::ConstPtr& msg)
    {
        if (msg->detections.size() != 0) {
            bool_tag = true;
            pose_tag = msg->detections[0].pose.pose.pose;
        } else {
            bool_tag = false;
            pose_tag.position.x = 0;
            pose_tag.position.y = 0;
            pose_tag.position.z = 0.3;
        }
        //cout << msg->detections[0].pose.pose.pose << endl;
    }

    void callback_fly(const geometry_msgs::Pose::ConstPtr& msg)
    {
        pose_fly.position = msg->position;
        pose_fly.orientation = msg->orientation;
        //cout << "pose_fly" << pose_fly << endl;

        control_fly::command_fly();
    }

    void command_fly()
    {
        geometry_msgs::PoseStamped msg;

        if (bool_tag == true) {
            msg.pose.position.x = pose_fly.position.x + pose_tag.position.z - 0.333113; //0.1//0.133113
            msg.pose.position.y = pose_fly.position.y - pose_tag.position.x + 0.07;
            msg.pose.position.z = pose_fly.position.z - pose_tag.position.y + 0.3; //0.03
            // msg.pose.orientation.x = /*pose_fly.orientation.x +*/ pose_fly.orientation.x;
            // msg.pose.orientation.y = /*pose_fly.orientation.y +*/ pose_fly.orientation.y;
            // msg.pose.orientation.z = /*pose_fly.orientation.z +*/ pose_fly.orientation.z;
            // msg.pose.orientation.w = /*pose_fly.orientation.w +*/ pose_fly.orientation.w;
        } else {
            msg.pose.position.x = pose_fly.position.x - 0.233113;
            msg.pose.position.y = pose_fly.position.y;
            msg.pose.position.z = pose_fly.position.z + 0.3;
            //msg.pose.orientation.w = 180;
           // msg.pose.orientation.x = 0;
            //msg.pose.orientation.y = 0;
           // msg.pose.orientation.z = 2;
            //if (pose_fly.orientation.y >= 0.8)
           //     count = 0;
           // if (pose_fly.orientation.y <= 0.69)
           //     count = 1;
          //  if (count == 1)
          //      msg.pose.orientation.y = pose_fly.orientation.y + 0.01;
          //  if (count == 0)
          //      msg.pose.orientation.y = pose_fly.orientation.y - 0.01;
        }

        pub_pose.publish(msg);
        cout << "command_fly" << endl
             << msg << endl;
    }

    void Quaternions()
    {
        geometry_msgs::PoseStamped msg;

        msg.pose.orientation.x = pose_fly.orientation.x * 0.0174f;
        msg.pose.orientation.y = pose_fly.orientation.y * 0.0174f;
        msg.pose.orientation.z = pose_fly.orientation.z * 0.0174f;
    }

private:
    ros::NodeHandle nh;
    ros::Publisher pub_pose;
    ros::Subscriber sub_tag;
    ros::Subscriber sub_fly;
    geometry_msgs::Pose pose_tag;
    geometry_msgs::Pose pose_fly;
    bool bool_tag;
    int count;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "apriltags_fly");

    control_fly firefly;
    //while (ros::ok()) {
    //fly.command_fly();
    // }

    ros::spin();
    return 0;
}