//traverse the image
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;

int main() {
	cv::Mat src = cv::imread("test.jpg");
	cv::imshow("test", src);

	//Method 1: just traverse the rows and columns using for cycle
	cv::Mat firstImg = src.clone();
	for (int i = 0; i < firstImg.rows; i++) {
		for (int j = 0; j < firstImg.cols; j++) {
			cv::Vec3b pixel;
			pixel[0] = 255 - firstImg.at<cv::Vec3b>(i, j)[0];
			pixel[1] = 255 - firstImg.at<cv::Vec3b>(i, j)[1];
			pixel[2] = 255 - firstImg.at<cv::Vec3b>(i, j)[2];
			firstImg.at<cv::Vec3b>(i, j) = pixel;
		}
	}
	cv::imshow("method1", firstImg);

	//Method 2: using the iterator
	cv::Mat secondImg = firstImg.clone();
	//cv::MatIterator_<cv::Vec3b> secondIt, secondEnd;
	cv::Mat_<cv::Vec3b>::iterator secondIt, secondEnd;
	for (secondIt = secondImg.begin<cv::Vec3b>(), secondEnd = secondImg.end<cv::Vec3b>();
		secondIt != secondEnd; secondIt++) {
		(*secondIt)[0] = 255 - (*secondIt)[0];
		(*secondIt)[1] = 255 - (*secondIt)[1];
		(*secondIt)[2] = 255 - (*secondIt)[2];
	}
	cv::imshow("method2", secondImg);

	//Method 3: using pointers
	cv::Mat thirdImg = secondImg.clone();
	for (int i = 0; i < thirdImg.rows; i++) {
		cv::Vec3b *p = thirdImg.ptr<cv::Vec3b>(i);
		for (int j = 0; j < thirdImg.cols; j++) {
			p[j][0] = 255 - p[j][0];
			p[j][1] = 255 - p[j][1];
			p[j][2] = 255 - p[j][2];
		}
	}
	cv::imshow("method3", thirdImg);

	cv::waitKey();
}
