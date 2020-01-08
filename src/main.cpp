#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main()
{
    cout << "start" << endl;

    cv::Mat img = cv::imread("umbrella.png");
    if(img.empty()) return -1;

    cv::namedWindow("hogehoge", cv::WINDOW_AUTOSIZE);
    cv::imshow("hogehoge", img);
    cv::waitKey(0);

    cv::destroyAllWindows();
    cout << "Finish" << endl;
}
