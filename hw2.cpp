#include "hw2.h"

Img::Img() : Img(0, 0){}
Img::Img(int w, int h){
    width = w;
    height = h;
    srcImg = new  int[width * height];
}
Img::Img( const int* src, int w, int h) : Img(w, h) {
    for(int i = 0; i < h * w; i++)
        srcImg[i] = src[i];
}
Img::~Img() {
    delete[] srcImg;
}
int& Img::get_element(int i, int j) {
    return srcImg[i * width + j];
}
/*
ImageProcess();
 выделяется память для картинки размера w*h
ImageProcess(int w, int h);
 выделяется память для картинки размера w*h и копируется картинка
ImageProcess(const Img* img);//откуда взять w*h
 выделяется память для картинки копируется картинка из файла, первая строчка в файле содержит ширину и высоту картинки
ImageProcess(const char* fileName);//откуда взять w*h
~ImageProcess();*/
ImageProcess::ImageProcess() : ImageProcess::ImageProcess(0, 0){}
ImageProcess::ImageProcess(int w, int h){
    srcImg = new Img;
    srcImg->height = h;
    srcImg->width = w;

    processedImg = new Img;
    processedImg->width = w;
    processedImg->height = h;
}
ImageProcess::ImageProcess(const Img* img) : ImageProcess::ImageProcess(img->width, img->height){
    for(int i = 0; i < img->width * img->height; i++)
        srcImg->srcImg[i] = img->srcImg[i];
}
ImageProcess::ImageProcess(const char* fileName){
    FILE* f = fopen(fileName, "r");
    int width, height;
    fscanf(f, "%d%d", width, height);
    ImageProcess(width, height);
    for(int i = 0; i < width * height; i++)
        fscanf(f, "%d", srcImg->srcImg[i]);
}

ImageProcess::~ImageProcess(){
    delete srcImg;
    delete processedImg;
    delete mask;
}
//ImageProcess::
int ImageProcess::updateMask(const Img& mask){
    this->mask->width = mask.width;
    this->mask->height = mask.height;
    this->mask->x_c = mask.x_c;
    this->mask->y_c = mask.y_c;
    for(int i = 0; i < mask.width * mask.height; i++)
        this->mask->srcImg[i] = mask.srcImg[i];
}
int ImageProcess::updateSrcImg(){
    if(processedImg->width == srcImg->width && processedImg->height == srcImg->height) {
        Img *avarage;
        avarage = srcImg;
        srcImg = processedImg;
        processedImg = avarage;
        return 0;
    }
    return -1;
}

int ImageProcess::dilatation(int srcImg){

}

int ImageProcess::erosion(int srcImg){

}
int loadImgFromFile(const char* fileName, int format = 1);// читаем из файла
int saveImgToFile(const char* fileName, int format = 1);//записываем в файл