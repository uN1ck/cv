//
// Created by N1ck on 22.02.2018.
//

#ifndef CV_MATRIX_HPP
#define CV_MATRIX_HPP

#include <vector>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class Matrix {
private:
    vector<vector<float>> matrix;

public:

    Matrix(int width, int height, float fill);

    explicit Matrix(Mat &in_matrix);

    explicit Matrix(Matrix *matrix);

    explicit Matrix(vector<vector<float>> matrix);

    ~Matrix();

    long width();

    long height();

    void T();

    vector<vector<float>> *getMatrix();

    Mat toMat();

    ///
    /// region STATIC GENERATORS
    ///

    static Matrix *Sobel();

    static Matrix *Pruitt();

    /// endregion
};


#endif //CV_MATRIX_HPP
