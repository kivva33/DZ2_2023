#include "hw2.h"

Img::Img() : Img(0, 0){}
Img::Img(int w, int h){
    width = w;
    height = h;
    srcImg = new  int[width * height];
}
Img::Img( const int* src, int w, int h) : Img(w, h) {
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++){
            srcImg[h * i + j] = src[h * i + j];
        }
}
Img::~Img() {
    delete[] srcImg;
}

ImageProcess::ImageProcess(){}
ImageProcess::ImageProcess(int w, int h){}
ImageProcess::ImageProcess(const Img* img){}
ImageProcess::ImageProcess(const char* fileName){}

