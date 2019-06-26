// #include "ros/ros.h"
// #include "actionlib/server/simple_action_server.h"
// #include "eai_tutorial/FibonacciAction.h"

// class FibonacciAction
// {
// protected:
//     ros::NodeHandle nh_;
//     actionlib::SimpleActionServer<eai_tutorial::FibonacciAction> as_;
//     std::string action_name_;
//     eai_tutorial::FibonacciFeedback feedback_;
//     eai_tutorial::FibonacciResult result_;
// public:
//     FibonacciAction(std::string name):
//     as_(nh_,name,boost::bind(&FibonacciAction::executeCB,this,_1),false),
//     action_name_(name){
//         as_.start();
//     }
//     ~FibonacciAction(void){}

// void executeCB(const eai_tutorial::FibonacciGoalConstPtr &goal)
// {
//     ros::Rate r(1);
//     bool success = true;

//     feedback_.sequence.clear();
//     feedback_.sequence.push_back(0);
//     feedback_.sequence.push_back(1);

//     ROS_WARN("%s: Executing， creating fibonacci sequence of order %i with seeds %i,%i",action_name_.c_str(),goal.>order,feedback_.sequence[0],feedback_[1]);

// }

// };

