#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "src/Matrix.hpp"
#include "src/Filters/MatrixFilter.hpp"


using namespace std;
using namespace cv;

char window_name1[] = "Unprocessed Image";
char window_name2[] = "Processed Image";

int main(int argc, char **argv) {
    if (argc != 2) {
        cout << " Usage: display_image ImageToLoadAndDisplay" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   // Read the file

    if (!image.data)                              // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }

    Matrix *m = new Matrix(image);

    MatrixFilter *simply = new MatrixFilter();
    Matrix *filtered = simply->filter(m);

    Mat newiimage = m->toMat();
    Mat newifilteredimage = filtered->toMat();

    namedWindow("Display window", WINDOW_AUTOSIZE);     // Create a window for display.
    imshow("Display window", newifilteredimage);                // Show our image inside it.

    waitKey(0);                                         // Wait for a keystroke in the window

    return 0;
}
