 #include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;
  Vec3b val;
  int pxl;

  image= imread("perfil.png",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "couldn't load image" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE);

  for(int i=100;i<500;i++){
    for(int j=100;j<500;j++){
        pxl = image.at<uchar>(i,j);
        image.at<uchar>(i,j)= 255 - pxl;
    }
  }
  
  imwrite("negative.jpg", image);
  imshow("window", image); 

  waitKey();

  return 0;
}