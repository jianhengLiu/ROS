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
void Gaussian(Mat input, Mat &output, double sigma) {
    int rows = input.rows;
    int cols = input.cols;

    int size = 3;
    //构建高斯滤波器魔板
    double filter_gaussin[size][size];
    //将数组归0
    memset(filter_gaussin, 0, sizeof(filter_gaussin));
    double sum = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            //生成高斯分布点
            filter_gaussin[i][j] = exp(-((i - 1) * (i - 1) + (j - 1) * (j - 1)) / (2 * sigma * sigma));
            //为归一化预备
            sum += filter_gaussin[i][j];
        }
    //归一化
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            filter_gaussin[i][j] /= sum;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j)
            cout << filter_gaussin[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            //边缘检测
            if ((i - 1) > 0 && (i + 1) < rows && (j - 1) > 0 && (j + 1) < cols) {
                for (int x = 0; x < size; x++)
                    for (int y = 0; y < size; y++)
                        output.at<uchar>(i, j) += input.at<uchar>(i - 1 + x, j - 1 + y) * filter_gaussin[x][y];
            }

        }
}

//void dit2rec(complex<double> *InData, complex<double> *OutData, int length, int sign) {
//    complex<double> *EvenData = new complex<double>(length / 2);
//    complex<double> *OddData = new complex<double>(length / 2);
//    complex<double> *EvenResult = new complex<double>(length / 2);
//    complex<double> *OddResult = new complex<double>(length / 2);
//    int i, j;
//    if (length == 1) {
//        OutData[0] = InData[0] / N;
//        return;
//    }
//    for (i = 0; i < length / 2; i++) {
//        EvenData[i] = InData[2 * i];
//        OddData[i] = InData[2 * i + 1];
//    }
//
//    dit2rec(EvenData, EvenResult, length / 2, sign);
//
//    dit2rec(OddData, EvenResult, length / 2, sign);
//    for (
//            i = 0;
//            i < length / 2; i++) {
//        OutData[i] =
//                *EvenData + *OddData * complex<double>(cos(2 * M_PI * i / length), sin(sign * 2 * M_PI * i / length));
//        OutData[i + length / 2] =
//                *EvenData - *OddData * complex<double>(cos(2 * M_PI * i / length), sin(sign * 2 * M_PI * i / length));
//    }
//    delete[] EvenData, OddData, EvenResult, OddResult;
//    return;
//}


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


//void fft(complex<double> input[], complex<double> omega[], int reverse_array[], int N) {
//
//
//    complex<double> temp[N];
//    for (int i = 2; i <= N; i *= 2) {
//        int m = i / 2;
//        for (int j = 0; j < N; j++) {
//            for (int k = 0; k < m; k++) {
//                temp[j + k] = input[j + k] + omega[N / i * k] * input[reverse_array[j + k + m]];
//                temp[j + k + m] = input[j + k] - omega[N / i * k] * input[reverse_array[j + k + m]];
//            }
//        }
//        for (int j = 0; j < N; j++)
//            input[j] = temp[j];
//    }
//}

void fft(complex<double> *input, int len, int inv = 1) {
    if (len == 1)
        return;
    complex<double> *Xe = new complex<double>[len / 2];
    complex<double> *Xo = new complex<double>[len / 2];
    for (int i = 0; i < len; i += 2) {
        Xe[i / 2] = input[i];
        Xo[i / 2] = input[i + 1];
    }
    fft(Xe, len / 2);
    fft(Xo, len / 2);
    complex<double> wn(cos(inv * 2 * M_PI / len), sin(inv * 2 * M_PI / len));
    complex<double> w(1, 0);
    for (int i = 0; i < (len / 2); i++) {
        input[i] = Xe[i] + Xo[i] * w;
        input[i + len / 2] = Xe[i] - Xo[i] * w;
        w *= wn;
    }
}

void resizeImage(Mat &image) { //将非2的整数次方边长的图片缩放为2的整数次方
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
    while (cn > 2) {
        cnew = cnew * 2;
        cn--;
    }
    while (rn > 2) {
        rnew = rnew * 2;
        rn--;
    }
    resize(image, image, Size(cnew, rnew));
}


// 快速傅里叶变换
int fastFuriorTransform(Mat image, Mat &output) {
    imshow("src", image);
    resizeImage(image);
    imshow("image_resize", image);
    int rows = image.rows;
    int cols = image.cols;

//    int rows_log2N = if_log2N(rows);
//    int cols_log2N = if_log2N(cols);
//
//    if (rows_log2N && cols_log2N) {
//        cout << 1 << endl;
//        cout << rows << endl;
//        cout << cols << endl;
//    } else {
//        cout << 0 << endl;
//        cout << rows << endl;
//        cout << cols << endl;
//        return 0;
//    }


//    complex<double> omegaC[cols];
//    for (int i = 0; i < cols; i++) {
//        omegaC[i] = complex<double>(cos(2 * M_PI * i / cols), sin(2 * M_PI * i / cols));
//    }
//    complex<double> omegaR[rows];
//    for (int i = 0; i < rows; i++) {
//        omegaR[i] = complex<double>(cos(2 * M_PI * i / rows), sin(2 * M_PI * i / rows));
//    }


    complex<double> reverse_arrayR[cols];
    complex<double> mat_array[cols][rows];
    complex<double> *arrayC = new complex<double>[cols];

    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
//            reverse_arrayR[x] = complex<double>(image.at<uchar>(reverse_binary(x, cols_log2N), y), 0);
            arrayC[x] = complex<double>(pow(-1, x + y) * image.at<uchar>(x, y), 0);
        }
        fft(arrayC, cols);
//        complex<double> temp[cols];
//        for (int i = 2; i <= cols; i *= 2) {
//            int m = i / 2;
//            for (int j = 0; j < cols; j++) {
//                for (int k = 0; k < m; k++) {
//                    temp[j + k] = reverse_arrayR[j + k] + omegaC[cols / i * k] * reverse_arrayR[j + k + m];
//                    temp[j + k + m] = reverse_arrayR[j + k] - omegaC[cols / i * k] * reverse_arrayR[j + k + m];
//                }
//            }
//            for (int j = 0; j < cols; j++) {
//                reverse_arrayR[j] = temp[j];
//            }
//        }
        for (int x = 0; x < cols; x++) {
            mat_array[x][y] = arrayC[x];
        }
    }


//    complex<double> reverse_arrayC[rows];
    complex<double> *arrayR = new complex<double>[rows];
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
//            reverse_arrayC[y] = mat_array[x][reverse_binary(y, rows_log2N)];
            arrayR[y] = mat_array[x][y];
        }
        fft(arrayR, rows);
//        complex<double> temp[rows];
//        for (int i = 2; i <= rows; i *= 2) {
//            int m = i / 2;
//            for (int j = 0; j < rows; j++) {
//                for (int k = 0; k < m; k++) {
//                    temp[j + k] = reverse_arrayC[j + k] + omegaR[rows / i * k] * reverse_arrayC[j + k + m];
//                    temp[j + k + m] = reverse_arrayC[j + k] - omegaR[rows / i * k] * reverse_arrayC[j + k + m];
//                }
//            }
//            for (int j = 0; j < rows; j++)
//                reverse_arrayC[j] = temp[j];
//        }
        for (int y = 0; y < rows; y++)
            mat_array[x][y] = arrayR[y];
    }

    Mat f_mat(rows, cols, CV_8UC1);
    for (int x = 0; x < cols; x++)
        for (int y = 0; y < rows; y++) {
            cout << 5 * log2(1 + mat_array[x][y].real() * mat_array[x][y].real() +
                             mat_array[x][y].imag() * mat_array[x][y].imag()) << endl;
            f_mat.at<uchar>(x, y) = 5 * log2(1 +
                                             mat_array[x][y].real() * mat_array[x][y].real() +
                                             mat_array[x][y].imag() * mat_array[x][y].imag());
        }

    imshow("output", f_mat);

        //反变换
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++){
//            reverse_arrayR[x] = complex<double>(image.at<uchar>(reverse_binary(x, cols_log2N), y), 0);
            arrayR[y] = mat_array[x][y];
        }
        fft(arrayR, rows,-1);
        for (int y = 0; y < rows; y++) {
            mat_array[x][y] = arrayC[y];
        }
    }

    for (int y = 0; y < rows; y++){
         for (int x = 0; x < cols; x++) {
//            reverse_arrayC[y] = mat_array[x][reverse_binary(y, rows_log2N)];
            arrayC[x] = mat_array[x][y];
        }
        fft(arrayC, cols,-1);
        for (int x = 0; x < cols; x++)
            mat_array[x][y] = arrayR[x];
    }
    Mat if_mat(rows, cols, CV_8UC1);
    for (int x = 0; x < cols; x++)
        for (int y = 0; y < rows; y++) {
            cout << mat_array[x][y].real() << endl;
            if_mat.at<uchar>(x, y) = mat_array[x][y].real();
        }

    imshow("output_inverse", if_mat);

/////////////////////////////////
//    int M = image.rows * image.cols;



//    int imageR[rows];
//
//    for (int i = 0; i < rows; i++) {
//        imageR[i] = image.at<uchar>(i);
//    }
//
//
//    int K = M / 2;
//
//    //WK
//    complex<double> WK = exp(complex<double>(0, -2 * M_PI / K));
//    complex<double> W2K = exp(complex<double>(0, -2 * M_PI / (2 * K)));
//
////    memset(H, 0, sizeof(H));
//    //F(u)
//    complex<double> F;
////    memset(F, 0, sizeof(F));
//    int F_abs[M];
//    memset(F_abs, 0, sizeof(F_abs));
//
//
//    for (int u = 0; u < K; u++) {
//        //G(u)
//        complex<double> G(0, 0);
//        //H(u)
//        complex<double> H(0, 0);
//        for (int x = 0; x < K; x++) {
//            G += complex<double>(image.at<uchar>(2 * x), 0) * pow(WK, u * x);
//            H += complex<double>(image.at<uchar>(2 * x + 1), 0) * pow(WK, u * x);
//
//        }
////        cout<<u<<endl;
//        F = G + H * pow(W2K, u);
//        F_abs[u] = 4 * (1 + sqrt(F.real() * F.real() + F.imag() * F.imag()));
//        output.at<uchar>(u) = F_abs[u];
////        cout << "F" << u << ":" << F << endl;
//        F = G - H * pow(W2K, u);
//        F_abs[u + K] = 4 * (1 + sqrt(F.real() * F.real() + F.imag() * F.imag()));
//        output.at<uchar>(u + K) = F_abs[u + K];
////        cout << "F" << u + K << ":" << F << endl;
////        cout << "F" << u + K << ":" << (int)output.at<uchar>(u + K) << endl;
//
//    }
//    cout << 1 << endl;
//    imshow("furior", output);
}

// 理想低通滤波器函数
Mat ideal_lbrf_kernel(Mat scr, float sigma) {

}

// 频率域滤波函数
// src:原图像
// blur:滤波器函数
Mat freqfilt(Mat scr, Mat blur) {
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
                    for (int x = 0; x < size; x++)
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

int main(int argc, char **argv) {

    ROS_WARN("*****START");
    ros::init(argc, argv, "trafficLaneTrack");//初始化 ROS 节点
    ros::NodeHandle n;
//    ros::Rate loop_rate(10);//定义速度发布频率
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/smoother_cmd_vel", 5);//定义速度发布器

//    VideoCapture capture;
//    capture.open(0);//打开 zed 相机
//    if (!capture.isOpened()) {
//        printf("摄像头没有正常打开,重新插拔工控机上当摄像头\n");
//        return 0;
//    }
//    waitKey(1000);
//    Mat frame;//当前帧图片
//    int nFrames = 0;//图片帧数
    while (ros::ok()) {
//        capture.read(frame);
//        if (frame.empty()) {
//            break;
//        }
        Mat frIn = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/jiaozhun.jpg",
                          IMREAD_GRAYSCALE);//当前帧图片
//        Mat frIn = frame(cv::Rect(0, 0, frame.cols / 2, frame.rows));//截取 zed 的左目图片
        int frameWidth = frIn.cols;//图片宽
        int frameHeight = frIn.rows;//图片高

// 空域滤波函数
//        Mat output_gaussin(frameHeight, frameWidth, CV_8UC1);
//        Gaussian(frIn, output_gaussin, 2.5);
//        imshow("gaussin", output_gaussin);


// 频域滤波函数


        Mat output_freqfilt(frameHeight, frameWidth, CV_8UC1);
//        dft(frIn,frIn);
        fastFuriorTransform(frIn, output_freqfilt);
//        imshow("furior", frIn);

//        freqfilt();


//        Mat src = imread("/home/chrisliu/ROS/learn_opencv/src/image_pkg/image/H.jpg",
//                         IMREAD_GRAYSCALE);//当前帧图片
//        imshow("src", src);
// 膨胀函数
//        Mat output_dilate;
//        Dilate(src, output_dilate, 10);
//        imshow("dilate", output_dilate);
// 腐蚀函数
//        Mat output_erode;
//        Erode(src, output_erode, 5);
//        imshow("erode", output_erode);

        ros::spinOnce();
        waitKey(5);
    }
    return 0;
}