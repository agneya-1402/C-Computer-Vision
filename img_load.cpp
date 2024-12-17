#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
 // Read image file
 Mat image = imread("sunflower.jpeg");

 // Check for failure
 if (image.empty()) 
 {
  cout << "Could not open or find the image" << endl;
  return -1;
 }

// Display Window
 String windowName = "Image"; 
 namedWindow(windowName); 
 imshow(windowName, image); 

// destroy windows
 waitKey(0); 
 destroyWindow(windowName); 

 return 0;
}