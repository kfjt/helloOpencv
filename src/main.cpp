#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

int main()
{
    cout << "start" << endl;

    cout << "net" << endl;
    cv::dnn::Net net = cv::dnn::readNet("model.onnx");
    cv::Mat img = imread("kuchikomi889.jpg", cv::IMREAD_GRAYSCALE);
    if(img.empty()) return -1;

    cout << "setInput" << endl;
    cv::Mat dst;
    resize(img, dst, cv::Size(64, 64));
    cv::Mat blob = cv::dnn::blobFromImage(dst);
    net.setInput(blob);
    cout << "forward" << endl;
    cv::Mat result;
    try
    {
        result = net.forward();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if(result.empty()) return -1;

    cout << "result" << endl;
    cout << result << endl;
    cout << result.size << endl;

    cv::namedWindow("hogehoge", cv::WINDOW_AUTOSIZE);
    cv::imshow("hogehoge", dst);
    cv::waitKey(0);

    cv::destroyAllWindows();
    cout << "Finish" << endl;
}
