#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"

#include <iostream>

using namespace cv;
using namespace std;

#define MAX_KSIZE 4         //1, 3, 5 or 7

const String window_capture_name = "Real-time Video";
const String window_edges_name = "Laplacian Edges";

int ddepth = CV_16S; // 16bit signed to avoid overflow

int index_kSize = 0;
const int arr_kSize[MAX_KSIZE] = {1, 3, 5, 7};

int gaussian_enabled = 1;

static void on_kSize_change_trackbar(int, void *)
{
    index_kSize = (index_kSize >= 0 && index_kSize < MAX_KSIZE)? index_kSize : 0;
    setTrackbarPos("kSize", window_edges_name, index_kSize);
}

static void on_gaussian_button_press(int, void*){
}

int main(int argc, char** argv){

    VideoCapture cap(CAP_ANY);

    namedWindow(window_capture_name);
    namedWindow(window_edges_name);

    createTrackbar("kSize", window_edges_name, &index_kSize, MAX_KSIZE-1, on_kSize_change_trackbar);
    createTrackbar("Gaussian ON/OFF", window_edges_name, &gaussian_enabled, 1, on_gaussian_button_press); // createButton has some problems due to missing QT support

    Mat frame, frame_gray, frame_edges;
    while(true){
        cap >> frame;
        if(frame.empty()){
            return 1;
        }

        if(gaussian_enabled) GaussianBlur(frame, frame, Size(3,3), 0);

        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        Mat frame_deeper;
        Laplacian(frame_gray, frame_deeper, ddepth, arr_kSize[index_kSize]);
        convertScaleAbs(frame_deeper, frame_edges); // converting back to CV_8U


        imshow(window_capture_name, frame);
        imshow(window_edges_name, frame_edges);

        char key = (char) waitKey(30);
        if (key == 'q' || key == 27)
        {
            break;
        }
    }
    return 0;
}