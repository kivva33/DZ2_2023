#include "list"
#include <fstream>

struct Img {
        int* srcImg;
        int width;
        int height;

        int x_c;//координаты центра, с которыми сравниваем
        int y_c;
        int& get_element(int i, int j);//функция, возвращающая элемент
        Img();
        Img(int w, int h);
        Img( const int* src, int w, int h);
        ~Img();
};

class ImageProcess {
private :
    Img* srcImg;
    Img* processedImg;
    Img* mask;
public :
    ImageProcess();
    /* выделяется память для картинки размера w*h */
    ImageProcess(int w, int h);
    /* выделяется память для картинки размера w*h и копируется картинка*/
    ImageProcess(const Img* img);//откуда взять w*h
    /* выделяется память для картинки копируется картинка из файла, первая строчка в файле содержит ширину и высоту картинки*/
    ImageProcess(const char* fileName);//откуда взять w*h
    ~ImageProcess();

    /*задание маски*/
    int updateMask(const Img& mask);

    /*перезаписать исходную картинку картинкой, которая была получена в результате дилатации и/или эрозии*/
    int updateSrcImg();

    /*дилатация картинки, результат записать в processedImg*/
    /*
        input		:	srcImg = 1, обрабатывается srcImg  - результат записывается в processedImg
                        srcImg = 0, обрабатывается processedImg - результат записывается в processedImg
    */
    int dilatation(int srcImg = 1);

    /*эрозия картинки, результат записать в processedImg*/
    int erosion(int srcImg = 1);

    /*
        загрузить/сохранить из файла с имененм fileName картинку
        input		:	fileName - имя файла
                        format - формат файла 	0 - последовательность 0 и 1, без перехода на новую строку
                                                1 - последовательность 0 и 1, с переходом на новую строку
    */
    int loadImgFromFile(const char* fileName, int format = 1);// читаем из файла
    int saveImgToFile(const char* fileName, int format = 1);//записываем в файл


    /*на зачёт без зачёта*/
    std::list<std::list<std::pair<int /*x*/,int /*y*/>>> getListContours();
};
