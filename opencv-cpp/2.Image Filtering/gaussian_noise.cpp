#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

#define GAUSSIAN_MEAN   0.0 // Represents the pixels intensity alteration. [0.0 = sum of all the added noise is equal to 0. Average intensity unchanged]
#define GAUSSIAN_STD    50.0 // Represents the dispersion around the mean. [(5-15) Realistic camera sensor noise. (20-40) Low quality sensor or low illumination conditions.]

void addGaussianNoise(Mat& image, double noise_mean, double noise_std, bool toShow=true) {
    // Let's create a mask containing the Gaussian Noise to be added to the image
    Mat noise = Mat(image.size(), image.type());
    randn(noise, noise_mean, noise_std);

    if (toShow){
        imshow("Noise only", noise);
        waitKey(0);
        destroyAllWindows();
    }

    // Let's add the noise to our image
    add(image, noise, image);
}

int main(int argc, char** argv) {
    
    string inputPath = argc >=2 ? argv[1] : "robot.png";

    Mat image = imread( samples::findFile( inputPath ), IMREAD_COLOR );
    if (image.empty())
    {
        printf(" Error opening image\n");
        printf(" Usage:\n %s [image_name] otherwise default is robot.jpg \n", argv[0]);
        return EXIT_FAILURE;
    }

    double noise_mean = argc >=3 ? atof(argv[2]) : GAUSSIAN_MEAN;
    double noise_std = argc >=4 ? atof(argv[3]) : GAUSSIAN_STD;

    Mat noisy = image.clone();
    addGaussianNoise(noisy, noise_mean, noise_std);

    string outputPath = "GNoise_" + inputPath;
    imwrite(outputPath, noisy);
    cout << "Writing image to path: " << outputPath << endl;

    imshow("Original", image);
    imshow("Gaussian Noise", noisy);
    waitKey(0);

    return 0;
}
