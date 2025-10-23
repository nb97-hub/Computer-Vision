#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

int main(int, char**){
    std::cout << "Hello, from basic!\n";

    std::string imagePath = "image.jpg";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}