#include "process.hpp"
using namespace cv;

Mat ConvertImage(Mat input){
    Mat output;
    cvtColor(input, output, CV_RGBA2GRAY);
    return output;
}