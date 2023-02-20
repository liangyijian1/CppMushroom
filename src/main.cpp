#include "opencv2/opencv.hpp"
#include <string.h>
#include <iostream>
#include <unistd.h>

using namespace cv;
using namespace std;

void xyGradientImg(Mat src, const char* direction){
  int rows = src.rows;
  int cols = src.cols;
  Mat ret(rows, cols, CV_8U);
  Mat gray;
  cvtColor(src, gray, COLOR_BGR2GRAY);

  for(int i = 0; i < rows; i++){
    uchar* ptr = gray.ptr<uchar>(i);
    uchar* _ptr = ret.ptr<uchar>(i);
    for(int j = 0; j < cols; j++){
      if(direction == "x"){
        if(j != cols - 1){
          _ptr[j] = ptr[j + 1] - ptr[j] < 0 ? 0 : ptr[j + 1] - ptr[j];
        }
        else{
          _ptr[j] = 0;
        }
      }
    }
  }
  imwrite("../../output/5663.jpg", ret);
}

int main() {       
  cv::Mat img = cv::imread("../../source/rgb5663.jpg");
  xyGradientImg(img, "x");
}