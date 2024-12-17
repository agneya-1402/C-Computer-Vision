#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // Load img
    Mat image = imread("sunflower.jpeg"); 
    if (image.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    // Convert grayscale
    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Gaussian blur 
    Mat blurredImage;
    GaussianBlur(grayImage, blurredImage, Size(5, 5), 1.5);

    // Canny edge detection
    Mat edges;
    double lowerThreshold = 10;  
    double upperThreshold = 150;
    Canny(blurredImage, edges, lowerThreshold, upperThreshold);

    // Display
    imshow("Original Image", image);
    imshow("Gray Image", grayImage);
    imshow("Blurred Image", blurredImage);
    imshow("Edges Detected", edges);

    waitKey(0);

    return 0;
}
