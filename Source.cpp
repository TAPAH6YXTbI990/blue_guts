#include <opencv2/opencv.hpp>
#include <iostream>
#include <locale>
#include <codecvt>

using namespace cv;

int main()
{
    std::system("chcp 65001 > nul");

    std::string image_path = "C:/Users/User/.vscode/projects/open_guts.jpg"; 
   
    Mat img = imread(image_path);

    if (img.empty())
    {
        std::cerr << "Îøèáêà ïðè çàãðóçêå èçîáðàæåíèÿ!" << std::endl;
        return -1; 
    }

    int down_width = 500;
    int down_height = 500;

    resize(img, img, Size(down_width, down_height), INTER_LINEAR); 

    Mat hsvImg, mask, result;

    cvtColor(img, hsvImg, COLOR_BGR2HSV);

    inRange(hsvImg, Scalar(100, 150, 0), Scalar(140, 255, 255), mask);

    bitwise_and(img, img, result, mask);
    
    imshow("OrigImg", img); 
    imshow("Mask", mask);
    imshow("Result", result); 

    int k = waitKey(0); 

    return 0;
}
