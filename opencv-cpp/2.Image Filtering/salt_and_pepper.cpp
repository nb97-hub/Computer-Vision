#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;
using namespace std;

void addSaltPepperNoise(Mat& image, double amount) {
    RNG rng;
    int num_pixels = static_cast<int>(amount * image.rows * image.cols);

    for (int i = 0; i < num_pixels; i++) {
        int y = rng.uniform(0, image.rows);
        int x = rng.uniform(0, image.cols);
        if (image.channels() == 1) {
            image.at<uchar>(y, x) = (rng.uniform(0.0, 1.0) < 0.5) ? 0 : 255;
        } else {
            Vec3b& pixel = image.at<Vec3b>(y, x);
            if (rng.uniform(0.0, 1.0) < 0.5)
                pixel = Vec3b(0, 0, 0);
            else
                pixel = Vec3b(255, 255, 255);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <path_to_image> [noise_level]" << endl;
        return -1;
    }

    string path = argv[1];
    double amount = 0.02; // percentuale di pixel da alterare
    if (argc >= 3) amount = atof(argv[2]);

    Mat image = imread(path, IMREAD_COLOR);
    if (image.empty()) {
        cout << "Errore: impossibile leggere l'immagine!" << endl;
        return -1;
    }

    Mat noisy = image.clone();
    addSaltPepperNoise(noisy, amount);

    string outputPath = "SP_" + path;
    imwrite(outputPath, noisy);
    cout << "Writing image to path: " << outputPath << endl;

    imshow("Original", image);
    imshow("Salt and Pepper", noisy);
    waitKey(0);

    return 0;
}
