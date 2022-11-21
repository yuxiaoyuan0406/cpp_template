#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>
#include <cstdio>

int main (int argc, char **argv)
{
    auto image = cv::imread(argv[1], cv::IMREAD_COLOR );

    if (argc != 2 || !image.data) {
        fprintf(stdout, "No image data\n");
        return -1;
    }

    cv::Mat image_gray;
    cv::cvtColor(image, image_gray, cv::COLOR_RGB2GRAY);
    // 如果想在图形界面查看图像对比可以取消这几行行的注释
    cv::namedWindow("image", cv::WINDOW_AUTOSIZE);
    cv::namedWindow("image gray", cv::WINDOW_AUTOSIZE);

    cv::imshow("image", image);
    cv::imshow("image gray", image_gray);

    try {
        std::vector<int> compression_params;
        compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
        compression_params.push_back(95);
        cv::imwrite("out.jpg", image_gray, compression_params);
    } catch (std::runtime_error& ex) {
        fprintf(stderr, "Exception converting image to JPG format: %s\n", ex.what());
        return 1;
    }

    fprintf(stdout, "Saved JPG file gray\n");

    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}