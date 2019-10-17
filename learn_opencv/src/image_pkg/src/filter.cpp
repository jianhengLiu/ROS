//
// Created by chrisliu on 2019/10/6.
//

#include <iostream>
#include <highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ros/ros.h"
#include<geometry_msgs/Twist.h>
#include "sensor_msgs/Image.h"
#include <math.h>
#include <complex.h>

#define LINEAR_X 0
using namespace std;
using namespace cv;

//////////////////////滤波//////////////////
// 空域高斯滤波器函数
void Gaussian(Mat input, Mat &output, double sigma,int size = 3) {
    int rows = input.rows;
    int cols = input.cols;

    output=Mat::zeros(rows,cols,CV_8UC1);

    int deriation=(size-1)/2;
    //构建高斯滤波器魔板
    double filter_gaussin[size][size];
    //将数组归0
    memset(filter_gaussin, 0, sizeof(filter_gaussin));
    double sum = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            //生成高斯分布点
            filter_gaussin[i][j] = exp(-((i - deriation) * (i - deriation) + (j - deriation) * (j - deriation)) / (2 * sigma * sigma));
            //为归一化预备
            sum += filter_gaussin[i][j];
        }
    //归一化
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            filter_gaussin[i][j] /= sum;
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j)
//            cout << filter_gaussin[i][j] << " ";
//        cout << endl;
//    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            //边缘检测
            if ((i - deriation) > 0 && (i + deriation) < rows && (j - deriation) > 0 && (j + deriation) < cols) {
                for (int x = 0; x < size; x++)
                    for (int y = 0; y < size; y++)
                        output.at<uchar>(i, j) += input.at<uchar>(i - deriation + y, j - deriation + x) * filter_gaussin[x][y];
            }
        }
    imshow("gaussin",output);
}

//生成倒序的二进制
// num为输入的二进制数，len为num的二进制长度，即傅里叶变换的数据数的二进制长度
int reverse_binary(int num, int len) {
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res << 1;          // 向右移动一位，给下一个数据提供位置
        res = res | (num & 1);  // 取出num最右边的第1位二进制数字
        num = num >> 1;     // 获取下一个二进制数字
    }
    return res;
}

int if_log2N(int len)//判断是否是2的整数次方
{
    float temp = log2(len);
    if (temp != (int) temp)
        return 0;
    else
        return temp;
}

void fastFuriorTransform(complex<double> *input, int len, int inv = 1) {
    if (len == 1)
        return;
    complex<double> *Xe = new complex<double>[len / 2];
    complex<double> *Xo = new complex<double>[len / 2];
    for (int i = 0; i < len; i += 2) {
        Xe[i / 2] = input[i];
        Xo[i / 2] = input[i + 1];
    }
    fastFuriorTransform(Xe, len / 2);
    fastFuriorTransform(Xo, len / 2);
    complex<double> wn(cos(2 * M_PI / len), inv * sin(2 * M_PI / len));
    complex<double> w(1, 0);
    for (int i = 0; i < (len / 2); i++) {
        input[i] = Xo[i] + Xe[i] * w;
        input[i + len / 2] = Xo[i] - Xe[i] * w;
        w *= wn;
    }
}

// 理想低通滤波器函数
void ideal_lbrf_kernel(Mat &src, float sigma) {
    circle(src, Point2i(src.cols / 2, src.rows / 2), sigma, Scalar(255), -1);
//    imshow("circle",src);
}

//将非2的整数次方边长的图片缩放为2的整数次方
void resizeImage(Mat &image, int factor = 2) {
    if (factor < 1) {
        cout << "factor must bigger than 1 !" << endl;
        return;
    }

    float c = image.cols, r = image.rows;
    int cn = 0, rn = 0, cnew = 2, rnew = 2;
    while (c / 2 > 1) {
        c = c / 2;
        cn++;
    }
    while (r / 2 > 1) {
        r = r / 2;
        rn++;
    }
    while (cn > factor) {
        cnew = cnew * 2;
        cn--;
    }
    while (rn > factor) {
        rnew = rnew * 2;
        rn--;
    }
    resize(image, image, Size(cnew, rnew));
}


// 快速傅里叶变换
void freqfilt(Mat image, Mat &output) {
    imshow("f_src", image);
    int rows_log2N = if_log2N(image.rows);
    int cols_log2N = if_log2N(image.cols);
    if (rows_log2N && cols_log2N) {
    } else {
        resizeImage(image, 2);
    }
    imshow("image_resize", image);

    int rows = image.rows;
    int cols = image.cols;
    int pixels = rows * cols;

    complex<double> mat_array[rows][cols];
    complex<double> *arrayC = new complex<double>[cols];

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            arrayC[x] = complex<double>(pow(-1, x+y ) * image.at<uchar>(y, x), 0);
        }
        fastFuriorTransform(arrayC, cols);
        for (int x = 0; x < cols; x++) {
            mat_array[y][x] = arrayC[x];
        }
    }

    complex<double> *arrayR = new complex<double>[rows];
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            arrayR[y] = mat_array[y][x];
        }
        fastFuriorTransform(arrayR, rows);
        for (int y = 0; y < rows; y++)
            mat_array[y][x] = arrayR[y];
    }

    Mat f_mat(rows, cols, CV_8UC1);
    for (int x = 0; x < cols; x++)
        for (int y = 0; y < rows; y++) {
//            cout << 5 * log2(1 + mat_array[x][y].real() * mat_array[x][y].real() +mat_array[x][y].imag() * mat_array[x][y].imag()) << endl;
            f_mat.at<uchar>(y, x) = 5 * log2(1 +
                                             mat_array[y][x].real() * mat_array[y][x].real() +
                                             mat_array[y][x].imag() * mat_array[y][x].imag());
        }
    imshow("f_output", f_mat);

    Mat mat_real(rows, cols, CV_64F);
    Mat mat_imag(rows, cols, CV_64F);

    Mat lowpass(rows, cols, CV_8UC1);
    ideal_lbrf_kernel(lowpass, 50);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            mat_array[y][x] *= complex<double>(lowpass.at<uchar>(y, x) / 255, 0);
            mat_real.at<double>(y, x) = mat_array[y][x].real();
            mat_imag.at<double>(y, x) = mat_array[y][x].imag();
        }
    }

    for (int x = 0; x < cols; x++)
        for (int y = 0; y < rows; y++) {
            f_mat.at<uchar>(y, x) = 5 * log2(1 +
                                             mat_array[y][x].real() * mat_array[y][x].real() +
                                             mat_array[y][x].imag() * mat_array[y][x].imag());
        }

    imshow("f_lowpass", f_mat);


    Mat channels[] = {mat_real, mat_imag};
    Mat mat_complex;
    merge(channels, 2, mat_complex);

    Mat iFFT[] = {Mat::zeros(mat_real.size(), CV_64F),
                  Mat::zeros(mat_imag.size(), CV_64F)};//创建两个通道，类型为float，大小为填充后的尺寸
    idft(mat_complex, mat_complex);//傅立叶逆变换
    split(mat_complex, iFFT);//结果貌似也是复数
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            iFFT[0].at<double>(y, x) *= pow(-1,x+y);
        }
    }
    normalize(iFFT[0], iFFT[0], 1, 0, CV_MINMAX);//归一化处理，float类型的显示范围为0-1,大于1为白色，小于0为黑色
    imshow("ifft", iFFT[0]);//显示逆变换
//    waitKey();

//
//    for (int x = 0; x < cols; x++)
//        for (int y = 0; y < rows; y++) {
//            f_mat.at<uchar>(y, x) = 5 * log2(1 +
//                                             mat_array[y][x].real() * mat_array[y][x].real() +
//                                             mat_array[y][x].imag() * mat_array[y][x].imag());
//        }
//
//    imshow("f_lowpass", f_mat);
//
//    //反变换
//    for (int y = 0; y < rows; y++) {
//        for (int x = 0; x < cols; x++) {
//            arrayC[x] = mat_array[y][x];
//        }
//        fastFuriorTransform(arrayC, cols, -1);
//        for (int x = 0; x < cols; x++) {
//            mat_array[y][x] = arrayC[x];
//        }
//    }
//
//    for (int x = 0; x < cols; x++) {
//        for (int y = 0; y < rows; y++) {
//            arrayR[y] = mat_array[y][x];
//        }
//
//        fastFuriorTransform(arrayR, rows, -1);
//        for (int y = 0; y < rows; y++) {
//            mat_array[y][x] = arrayR[y];
//        }
//    }
//    Mat if_mat(rows, cols, CV_8UC1);
//    for (int x = 0; x < cols; x++)
//        for (int y = 0; y < rows; y++) {
////            cout << pow(-1, x + y) * f_array.at<complex<double>>(x, y).real() / M<< endl;
//            if_mat.at<uchar>(y, x) = pow(-1, x + y) * mat_array[y][x].real() / pixels;
//
//        }
//
//    imshow("output_ifft", if_mat);

    delete[] arrayC, arrayR, mat_array;
}


//////////////////////形态学//////////////////
// 膨胀函数
void Dilate(Mat input, Mat &output, int size) {
    output = input.clone();
    int rows = input.rows;
    int cols = input.cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            //边缘检测
            if ((i - size) > 0 && (i + size) < rows && (j - size) > 0 && (j + size) < cols) {
                if (input.at<uchar>(i, j) > 10) {
                    for (int x = 0; x < size; x++)
                        for (int y = 0; y < size; y++)
                            if (input.at<uchar>(i + x, j + y) < 100) {
                                output.at<uchar>(i, j) = 0;
                                break;
                            }
                }
            }

        }
}


// 腐蚀函数
void Erode(Mat input, Mat &output, int size) {
    output = input.clone();
    int rows = input.rows;
    int cols = input.cols;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            //边缘检测
            if ((i - size) > 0 && (i + size) < rows && (j - size) > 0 && (j + size) < cols) {
                if (input.at<uchar>(i, j) < 250) {
                    for (int x = 0; x < size; x++) {
                        if (input.at<uchar>(i + x, j) < 100 && input.at<uchar>(i, j + x) < 100 &&
                            input.at<uchar>(i - x, j) < 100 && input.at<uchar>(i, j - x) < 100) {
                            output.at<uchar>(i, j) = 0;
                        } else {
                            output.at<uchar>(i, j) = 255;
                            break;
                        }
                    }

                }
            }

        }
}

int main(int argc, char **argv) {

    ROS_WARN("*****START");
    ros::init(argc, argv, "trafficLaneTrack");//初始化 ROS 节点
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/smoother_cmd_vel", 5);//定义速度发布器

    VideoCapture capture;
    capture.open(0);//打开 zed 相机
    if (!capture.isOpened()) {
        printf("摄像头没有正常打开,重新插拔工控机上当摄像头\n");
        return 0;
    }
//    waitKey(1000);
//    Mat frame;//当前帧图片
//    int nFrames = 0;//图片帧数
    while (ros::ok()) {
        Mat frIn;
        capture.read(frIn);
        if (frIn.empty()) {
            break;
        }
//        frIn = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/jiaozhun.jpg");//当前帧图片
        frIn = frIn(cv::Rect(0, 0, frIn.cols / 2, frIn.rows));//截取 zed 的左目图片
        cvtColor(frIn, frIn, CV_RGB2GRAY);

        int frameWidth = frIn.cols;//图片宽
        int frameHeight = frIn.rows;//图片高

 //空域滤波函数
        imshow("src",frIn);
        Mat output_gaussin(frameHeight, frameWidth, CV_8UC1);
        Gaussian(frIn, output_gaussin, 2.5);
        imshow("gaussin", output_gaussin);


// 频域滤波函数
//        Mat output_freqfilt(frameHeight, frameWidth, CV_8UC1);
//        freqfilt(frIn, output_freqfilt);



        frIn = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/H.jpg",
                         IMREAD_GRAYSCALE);//当前帧图片
        imshow("morphology_src", frIn);
// 膨胀函数
        Mat output_dilate;
        Dilate(frIn, output_dilate, 10);
        imshow("dilate", output_dilate);
// 腐蚀函数
        Mat output_erode;
        Erode(frIn, output_erode, 5);
        imshow("erode", output_erode);

        ros::spinOnce();
        waitKey(5);
//        ROS_INFO("1");
    }
    return 0;
}