//
// Created by N1ck on 22.02.2018.
//

#include "Matrix.hpp"

#include <utility>


Matrix::Matrix(Mat &in_matrix) {
    int height = in_matrix.cols;
    int width = in_matrix.rows;
    this->matrix = vector<vector<float>>(width, vector<float>(height, 0));

    for (int i = 0; i < width; i++) {
        for (int k = 0; k < height; k++) {
            this->matrix[i][k] = in_matrix.at<uchar>(i, k) / 255.0;
        }
    }
}

Matrix::Matrix(int width, int height, float fill) {
    this->matrix = vector<vector<float> >(width, vector<float>(height, fill));

    for (int i = 0; i < width; i++) {
        for (int k = 0; k < height; k++) {
            this->matrix[i][k] = 0;
        }
    }
}

Matrix::Matrix(Matrix *matrix) {
    this->matrix = matrix->matrix;
}

Matrix::Matrix(vector<vector<float>> matrix) {
    this->matrix = std::move(matrix);
}

long Matrix::width() {
    return this->matrix.size();
}

long Matrix::height() {
    if (this->width() > 0) {
        return this->matrix[0].size();
    } else {
        return 0;
    }
}


vector<vector<float>> *Matrix::getMatrix() {
    return &this->matrix;
}

void Matrix::T() {
    for (long x = 0; x < this->width(); x++) {
        for (long y = 0; y < this->height(); y++) {
            float buffer = this->matrix[x][y];
            this->matrix[x][y] = this->matrix[y][x];
            this->matrix[y][x] = buffer;
        }
    }
}

Matrix *Matrix::Sobel() {
    vector<vector<float>> matrix = {{1, 0, -1},
                                    {2, 0, -2},
                                    {1, 0, -1}};
    return new Matrix(matrix);
}

Matrix *Matrix::Pruitt() {
    vector<vector<float>> matrix = {{1, 0, -1},
                                    {1, 0, -1},
                                    {1, 0, -1}};
    return new Matrix(matrix);
}

Mat Matrix::toMat() {
    Mat matrix = Mat(this->width(), this->height(), CV_8UC1);
    for (int i = 0; i < this->width(); i++) {
        for (int k = 0; k < this->height(); k++) {
            matrix.at<uchar>(i, k) = (uchar) (this->matrix[i][k] * 255);
        }
    }
    return matrix;
}


Matrix::~Matrix() = default;
