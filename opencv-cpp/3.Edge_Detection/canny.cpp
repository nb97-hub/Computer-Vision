#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/videoio.hpp"

#include <iostream>

using namespace cv;
using namespace std;

#define MAX_THRESHOLD 300

const String window_capture_name = "Real-time Video";
const String window_edges_name = "Canny Edges";

int lowThreshold = 0;
int highThreshold = MAX_THRESHOLD;

static void on_low_threshold_trackbar(int, void *)
{
    lowThreshold = min(highThreshold-1, lowThreshold);
    cout << "LT: " << lowThreshold << endl;
    setTrackbarPos("Low Threshold", window_edges_name, lowThreshold);
}

static void on_high_threshold_trackbar(int, void *)
{
    highThreshold = max(lowThreshold+1, highThreshold);
    cout << "HT: " << highThreshold << endl;
    setTrackbarPos("High Threshold", window_edges_name, highThreshold);
}

int main(int argc, char** argv){

    VideoCapture cap(CAP_ANY);

    namedWindow(window_capture_name);
    namedWindow(window_edges_name);

    createTrackbar("Low Threshold", window_edges_name, &lowThreshold, MAX_THRESHOLD, on_low_threshold_trackbar);
    createTrackbar("High Threshold", window_edges_name, &highThreshold, MAX_THRESHOLD, on_high_threshold_trackbar);
    
    Mat frame, frame_gray, frame_edges;
    while(true){
        cap >> frame;
        if(frame.empty()){
            return 1;
        }

        cvtColor(frame, frame_gray, COLOR_BGR2GRAY);

        blur(frame_gray, frame_gray, Size(3,3));

        Canny(frame_gray, frame_edges, lowThreshold, highThreshold);


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