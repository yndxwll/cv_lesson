#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {
	cv::Mat src = cv::imread("test.jpg");
	cv::imshow("src", src);
	cv::waitKey();
}