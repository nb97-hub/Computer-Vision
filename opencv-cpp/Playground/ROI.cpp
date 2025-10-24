#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    
    cv::Mat A = cv::imread("robot.png");
    
    // Dimensions
    int roi_size = 300;                                 // roi = region of interest
    cv::Point center(A.cols/2, A.rows/2);

    // Computing the x_start and y_start since the rectangle is built from the top-left corner
    int x_start = center.x - roi_size/2;                
    int y_start = center.y - roi_size/2;

    // Ensure ROI doesn't go outside the image boundaries
    x_start = std::max(0, x_start);
    y_start = std::max(0, y_start);

    cv::Mat B(A, cv::Rect(x_start, y_start, roi_size, roi_size));
    cv::imshow("Display Original", A);
    cv::waitKey(0);
    std::cout << "Press Enter to exit..." << std::endl;


    cv::imshow("Display ROI", B);
    cv::waitKey(0);
    std::cout << "Press Enter to exit..." << std::endl;

    return 0;

}