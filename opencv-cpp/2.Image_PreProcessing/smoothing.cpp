#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int DELAY_CAPTION = 1500;
int DELAY_BLUR = 300;
int MAX_KERNEL_LENGTH = 31;

Mat src; Mat dst;
char window_name[] = "Smoothing";

int display_caption( const char* caption );
int display_dst( int delay );

int main( int argc, char ** argv )
{
    namedWindow( window_name, WINDOW_AUTOSIZE );

    const char* filename = argc >=2 ? argv[1] : ".\\images\\GNoise_robot.png";

    src = imread( samples::findFile( filename ), IMREAD_COLOR );
    if (src.empty())
    {
        printf(" Error opening image\n");
        printf(" Usage:\n %s [image_name] otherwise default is .\\images\\GNoise_robot.png \n", argv[0]);
        return EXIT_FAILURE;
    }

    if( display_caption( "Original Image" ) != 0 )
    {
        return 0;
    }

    dst = src.clone();
    if( display_dst( DELAY_CAPTION ) != 0 )
    {
        return 0;
    }

    if( display_caption( "Homogeneous Blur" ) != 0 )
    {
        return 0;
    }

    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        blur( src, dst, Size( i, i ), Point(-1,-1) );
        if( display_dst( DELAY_BLUR ) != 0 )
        {
            return 0;
        }
    }

    if( display_caption( "Gaussian Blur" ) != 0 )
    {
        return 0;
    }

    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        GaussianBlur( src, dst, Size( i, i ), 0, 0 );
        if( display_dst( DELAY_BLUR ) != 0 )
        {
            return 0;
        }
    }

    if( display_caption( "Median Blur" ) != 0 )
    {
        return 0;
    }

    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        medianBlur ( src, dst, i );
        if( display_dst( DELAY_BLUR ) != 0 )
        {
            return 0;
        }
    }

    if( display_caption( "Bilateral Blur" ) != 0 )
    {
        return 0;
    }

    int maxDiameter = 9;
    int sigmasIncrFactor = 3;
    int diameter = 1;   // How many pixels the filter takes into account
    int sigma = 1;      // sigmaColor a pixel in the window is taken into account if its color differs by at most by sigma
                        // sigmaSpace is the std of the gaussian filter

    for ( int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2 )
    {
        diameter = i <= maxDiameter ? i : maxDiameter;
        sigma = diameter <= maxDiameter ? i*2 : i*3;

        bilateralFilter ( src, dst, diameter, sigma, sigma);
        if( display_dst( DELAY_BLUR ) != 0 )
        {
            return 0;
        }
    }

    display_caption( "Done!" );

    return 0;
}

int display_caption( const char* caption )
{
    dst = Mat::zeros( src.size(), src.type() );
    putText( dst, caption,
             Point( src.cols/4, src.rows/2),
             FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255) );

    return display_dst(DELAY_CAPTION);
}

int display_dst( int delay )
{
    imshow( window_name, dst );
    int c = waitKey ( delay );
    if( c >= 0 ) { return -1; }
    return 0;
}