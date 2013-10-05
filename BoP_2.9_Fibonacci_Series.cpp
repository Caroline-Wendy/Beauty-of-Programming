/*From Beauty of Programming, By C.L.Wang*/
/*OpenCV中cv::Mat的"="包含若干bug, 尽量使用copyto函数*/
/*使用fibonacci数列的二阶递推数列，进行矩阵相乘*/
/*时间复杂度O(log2n)*/

#include "stdafx.h"

#include <iostream>
#include <opencv.hpp>

using namespace std;
using namespace cv;

bool mat_pow(cv::Mat& my_result, const cv::Mat A, const int f_num){

	/*0, 1 为预设值*/
	if(f_num <= 2){
		return false;
	}

	int t_num = f_num-2;
	cv::Mat tmp = A;

	for( ; t_num; t_num>>=1){
		if(t_num & 1)
			my_result *= tmp;
		tmp *= tmp;
	}

	return true;

}

int main(void){

	int f_num(-1);
	int result(-1);

	std::cout << "Fibonacci Series: " << std::endl;
	std::cout << "Please input your number for the fibonacci series: ";

	while(std::cin >> f_num){

		/*二阶递推数列 A = [1 1; 1 0]*/
		cv::Mat A = cv::Mat::zeros(2, 2, CV_64FC1);
		A.at<double>(0,0) = 1.0; A.at<double>(0,1) = 1.0;
		A.at<double>(1,0) = 1.0; A.at<double>(1,1) = 0.0;

		cv::Mat result_mat = cv::Mat::eye(2, 2, CV_64FC1);

		if(f_num <= 0){
			std::cout << "Sorry, the number is larger than 0! " << std::endl;
			return -1;
		}

		if(1 == f_num || 2 == f_num){
			std::cout << "result: " << 1 << std::endl;
			std::cout << "Please input your number for the fibonacci series: ";
			continue;
		}

		if(!mat_pow(result_mat, A, f_num)){
			std::cout << "Sorry, fail to pow the matrix. " << std::endl;
		}

		result = static_cast<int>(result_mat.at<double>(0,0) + result_mat.at<double>(1,0));

		std::cout << "result: " << result << std::endl;

		std::cout << "Please input your number for the fibonacci series: ";

	}

	return 0;

}
