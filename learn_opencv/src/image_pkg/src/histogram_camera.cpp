//
// Created by chrisliu on 2019/9/22.
//

#include "ros/ros.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <algorithm>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    VideoCapture capture;
    capture.open(0);//打开相机


    ROS_WARN("*****START");
    ros::init(argc, argv, "histogram");//初始化ROS节点
    ros::NodeHandle n;

    if (!capture.isOpened())
    {
       printf("摄像头没有正常打开，重新插拔工控机上当摄像头\n");
        return 0;
    }
    Mat frame;//当前帧图片


    while (ros::ok()) {
        capture.read(frame);
        if(frame.empty())
       {
            break;
       }

		//读图测试
       // frame = imread("/woniu.jpg");
        Mat greyImage;
        //将RGB转化为灰度图
        cvtColor(frame, greyImage, CV_RGB2GRAY);
        imshow("src", greyImage);

        //该数组用于记录灰度像素个数
        int grey[256];
        //将数组归0
        memset(grey, 0, sizeof(grey));
//        cout << sizeof(grey) << endl;
//        for (int i = 255; i >= 0; i--)
//            cout << grey[i] << endl;

        int r = greyImage.rows;//行
        int c = greyImage.cols;//列
        int sum_pixels = r * c;//像素总数
//        cout << r * c << endl;

        for (int w = r; w > 0; w--)
            for (int h = c; h > 0; h--) {
                //grey[灰度值]++,遍历完成后可的每个灰度在图像中的个数，存储于数组grey中
                grey[greyImage.at<uchar>(w, h)]++;
            }

        int maxGrey = *max_element(grey, grey + 255);
        int minGrey = *min_element(grey, grey + 255);

        Mat histogram(256, 256, CV_8U, Scalar(0));

        //r的概率
        float pro_r[256];
        //累计密度
        int projectedGrey[256];
//        memset(accumulateDensep,0, sizeof(accumulateDensep));

//        int pixels = 0;
//        float one = 0;

        for (int i = 0; i < 256; i++) {
            pro_r[i] = (float) grey[i] / sum_pixels;

            float temp = 0;
            for (int j = 0; j < i + 1; j++) {
                temp += pro_r[j];
            }
            //四舍五入，得到灰度值i映射为accumuDense[i]
            //即accumuDense[i]=si=T[i]
            projectedGrey[i] = (int) (255 * temp + 0.5);

//            pixels += grey[i];
//            cout<<frequency[i]<<endl;
//            one += frequency[i];

            line(histogram, Point(i, 255), Point(i, 255 - 2 * maxGrey * pro_r[i]), Scalar(255));
        }
//        cout << pixels << endl;
//        cout << one << endl;
        imshow("histogram", histogram);

        //用于均衡化的数组
        int balanced[256];
        memset(balanced, 0, sizeof(balanced));
        float pro_s[256];
        Mat accumulate_histogram(256, 256, CV_8U, Scalar(0));
        for (int i = 0; i < 256; i++) {
            //获取映射后各个灰度值的像素个数
            //灰度值为i在原图中像素个数为grey[i]
            //i映射为灰度值accumulateDense[i]
            //因此将原味i的像素个数归为accumulateDense[i]下
            //记灰度值为accumulateDense[i]的像素总数为balanced[si]
            balanced[projectedGrey[i]] += grey[i];
//            cout<<i<<":"<<accumulateDense[i]<<endl;
        }
        for (int i = 0; i < 256; i++) {
            //获取均衡化后各灰度值的概率
            pro_s[i] = (float)balanced[i] / sum_pixels;

//            cout<<i<<":"<<balance[i]<<endl;
//            cout<<i<<":"<<pro_s[i]<<endl;

            line(accumulate_histogram, Point(i, 255), Point(i, 255 - 2 * maxGrey * pro_s[i]), Scalar(255));
        }
        imshow("accumulate_histogram", accumulate_histogram);

        for (int w = 0; w < r; w++)
            for (int h = 0; h < c; h++) {
//                cout<<(int)greyImage.at<uchar>(w, h)<<endl;
//                cout<<accumulateDense[(int)greyImage.at<uchar>(w, h)]<<endl;

                //更新均衡化后的每个点的像素
                //原(w,h)处的像素=projectedGrey[原灰度值]=si=映射后的灰度值
                greyImage.at<uchar>(w, h)=projectedGrey[(int)greyImage.at<uchar>(w, h)];
            }

        imshow("balanced",greyImage);
        
        ros::spinOnce();
//		loop_rate.sleep();
        waitKey(5);

    }
    return 0;
}
