
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    // Declare the output variables
    Mat dst, cdst, cdstP;

    const char* default_file = "chess2.jpg";
    const char* filename = argc >=2 ? argv[1] : default_file;

    // Loads an image
    Mat src = imread( samples::findFile( filename ), IMREAD_GRAYSCALE );

    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default %s] \n", default_file);
        return -1;
    }

    // Edge detection
    Canny(src, dst, 50, 200, 3);

    // Copy edges to the images that will display the results in BGR
    cvtColor(dst, cdst, COLOR_GRAY2BGR);
    cdstP = cdst.clone();
    int width = cdstP.cols;
    int height = cdstP.rows;

    // Standard Hough Line Transform
    vector<Vec2f> lines; // will hold the results of the detection
    HoughLines(dst, lines, 1, CV_PI/180, 150, 0, 0 ); // runs the actual detection
    // Draw the lines
    for( size_t i = 0; i < lines.size(); i++ )
    {
        float rho = lines[i][0], theta = lines[i][1];
        Point pt1, pt2;
        double a = cos(theta), b = sin(theta);  // (a,b) is the normal vector of the line we are looking for
        double x0 = a*rho, y0 = b*rho;      // point where the polar line intersects the line (perpendicular)

        // now we have a point of the line (x0, y0) and its normal <a,b>.
        // we need to extend the line (aka to found at least 2 points)
        // the lines grows in the direction perpendicular to the line's normal
            // in 2D given a normal vector <a,b>, it perpendicular is <-b,a>
        // thus we can draw a line that goes beyond the picture boundaries.
        // we start from the point (x0, y0) and we move along this direction from +1000px to -1000px
        pt1.x = cvRound(x0 + 1000*(-b));    
        pt1.y = cvRound(y0 + 1000*(a));
        pt2.x = cvRound(x0 - 1000*(-b));
        pt2.y = cvRound(y0 - 1000*(a));
        line( cdst, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);
    }

    // Probabilistic Line Transform
    vector<Vec4i> linesP; // will hold the results of the detection
    HoughLinesP(dst, linesP, 1, CV_PI/180, 200, 50, 10 ); // runs the actual detection
    // // Draw the segments
    // for( size_t i = 0; i < linesP.size(); i++ )
    // {
    //     Vec4i l = linesP[i];

    //     line( cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0,0,255), 3, LINE_AA);
    // }


    // Draw the lines
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        int x1 = l[0], y1 = l[1];
        int x2 = l[2], y2 = l[3];
        // Compute line directions
        double dx = x2 - x1;
        double dy = y2 - y1;
        
        // Compute extended points
        Point pt1, pt2;
        
        if(dx != 0) {
            double m = dy / dx;
            
            // Extend towards image boundaries (x=0 and x=width)
            pt1.x = 0;
            pt1.y = cvRound(y1 + m * (0 - x1));
            
            pt2.x = width;
            pt2.y = cvRound(y1 + m * (width - x1));
        }
        else {
            // Vertical line
            pt1.x = x1;
            pt1.y = 0;
            
            pt2.x = x1;
            pt2.y = height;
        }
        
        line(cdstP, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);
    }

    // Show results
    imshow("Source", src);
    imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
    imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);

    // Wait and Exit
    waitKey();
    return 0;
}