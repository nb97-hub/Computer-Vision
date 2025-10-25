
#include "iostream"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

const char* window_name = "Pyramids Demo";

int main( int argc, char** argv )
{
    cout << "\n Zoom In-Out demo \n "
            "------------------  \n"
            " * [i] -> Zoom in   \n"
            " * [o] -> Zoom out  \n"
            " * [q] -> Quit program \n" << endl;

    const char* filename = argc >=2 ? argv[1] : ".\\images\\robot.png";

    // Loads an image
    Mat src = imread( samples::findFile( filename ) );

    // Check if image is loaded fine
    if(src.empty()){
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default .\\images\\robot.png] \n");
        return EXIT_FAILURE;
    }

    for(;;)
    {
        imshow( window_name, src );
        char c = (char)waitKey(0);

        if( c == 'q' || c == 27)
        { break; }
        else if( c == 'i' )
        { pyrUp( src, src, Size( src.cols*2, src.rows*2 ) );
            printf( "** Zoom In: Image x 2 \n" );
        }
        else if( c == 'o' )
        { pyrDown( src, src, Size( src.cols/2, src.rows/2 ) );
            printf( "** Zoom Out: Image / 2 \n" );
        }
    }

    return EXIT_SUCCESS;
}