#include<ros/ros.h> //ros标准库头文件
#include<iostream> //C++标准输入输出库
#include<cv_bridge/cv_bridge.h>
#include<sensor_msgs/image_encodings.h>
#include<image_transport/image_transport.h>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
 
static const std::string OPENCV_WINDOW = "Hough window"; //定义输出窗口名称
//定义一个转换的类
class RGB_GRAY
{
private:
    ros::NodeHandle nh_; //定义ROS句柄
    image_transport::ImageTransport it_; //定义一个image_transport实例
    image_transport::Subscriber image_sub_; //定义ROS图象接收器
    image_transport::Publisher image_pub_; //定义ROS图象发布器
public:
    RGB_GRAY()
      :it_(nh_) //构造函数
    {
        image_sub_ = it_.subscribe("/usb_cam/image_raw", 1, &RGB_GRAY::convert_callback, this); //定义图象接受器，订阅话题是“camera/rgb/image_raw”
        image_pub_ = it_.advertise("/image_converter/output_video", 1); //定义图象发布器
        //初始化输入输出窗口
        cv::namedWindow(OPENCV_WINDOW);
    }
    ~RGB_GRAY() //析构函数
    {
         cv::destroyWindow(OPENCV_WINDOW);
    }
    /*这是一个ROS和OpenCV的格式转换回调函数，将图象格式从sensor_msgs/Image  --->  cv::Mat */
    void convert_callback(const sensor_msgs::ImageConstPtr& msg)
    {
        cv_bridge::CvImagePtr cv_ptr; // 声明一个CvImage指针的实例
        try
        {
            cv_ptr =  cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8); //将ROS消息中的图象信息提取，生成新cv类型的图象，复制给CvImage指针
        }
        catch(cv_bridge::Exception& e)  //异常处理
        {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }
        image_process(cv_ptr->image); //得到了cv::Mat类型的图象，在CvImage指针的image中，将结果传送给处理函数
    }
    /*这是图象处理的主要函数，一般会把图像处理的主要程序写在这个函数中。这里的例子只是一个彩色图象到灰度图象的转化*/
    void image_process(cv::Mat img)//这里是灰度处理
    {
        Mat dst;
        Mat cdst;
        Canny(img, dst, 50, 200, 3);
        cvtColor(dst, cdst, CV_GRAY2BGR);//灰度化
        vector<Vec2f> lines;
        HoughLines(dst, lines, 1, CV_PI/180, 100, 0, 0 );
        for( size_t i = 0; i < lines.size(); i++ )//将求得的线条画出来
        {
            float rho = lines[i][0], theta = lines[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a*rho, y0 = b*rho;
            pt1.x = cvRound(x0 + 1000*(-b));
            pt1.y = cvRound(y0 + 1000*(a));
            pt2.x = cvRound(x0 - 1000*(-b));
            pt2.y = cvRound(y0 - 1000*(a));
            line( cdst, pt1, pt2, Scalar(0,0,255), 2, CV_AA);
           cout<<"x="<<(pt1.x+pt2.x)/2<<endl;        
           cout<<"y="<<(pt1.y+pt2.y)/2<<endl;
        }
            imshow(OPENCV_WINDOW, cdst);
            image_pub_.publish(cv_bridge::CvImage(std_msgs::Header(), "bgr8", cdst).toImageMsg());
            waitKey(5);
    }
};
//主函数
int main(int argc, char** argv)
{
    ros::init(argc, argv, "RGB");
    RGB_GRAY obj;
    ros::spin();
}
