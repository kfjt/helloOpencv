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
    if(net.empty()) return -1;

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
    catch(cv::Exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if(result.empty()) return -1;

    cout << "result" << endl;
    cout << result << endl;
    cout << result.rows << endl;
    cout << result.cols << endl;
    cout << result.row(0).col(0) << endl;
    cout << result.row(0).col(1) << endl;

    cout << "Finish" << endl;
}
