#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"

#include <iostream>

using namespace cv;
using namespace std;

#define MAX_KSIZE 4         //1, 3, 5 or 7

const String window_capture_name = "Real-time Video";
const String window_edges_name = "Sobel Edges";

int ddepth = CV_16S; // 16bit signed to avoid overflow

int index_kSize = 0;
const int arr_kSize[MAX_KSIZE] = {1, 3, 5, 7};

static void on_kSize_change_trackbar(int, void *)
{
    index_kSize = (index_kSize >= 0 && index_kSize < MAX_KSIZE)? index_kSize : 0;
    setTrackbarPos("kSize", window_edges_name, index_kSize);
}

int main(int argc, char** argv){

    VideoCapture cap(CAP_ANY);

    namedWindow(window_capture_name);
    namedWindow(window_edges_name);

    createTrackbar("kSize", window_edges_name, &index_kSize, MAX_KSIZE-1, on_kSize_change_trackbar);

    Mat frame, frame_gray, frame_edges;

    while(true){
        cap >> frame;
        if(frame.empty()){
            return 1;
        }

        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        Mat grad_x, grad_y;
        Mat abs_grad_x, abs_grad_y;

        Sobel(frame_gray, grad_x, ddepth, 1, 0, arr_kSize[index_kSize]); // grad among x - 1st conv
        Sobel(frame_gray, grad_y, ddepth, 0, 1, arr_kSize[index_kSize]); // grad among y - 2nd conv
        
        // converting back to CV_8U
        convertScaleAbs(grad_x, abs_grad_x);
        convertScaleAbs(grad_y, abs_grad_y);
    
        addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, frame_edges);


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