//
// Created by N1ck on 25.02.2018.
//

#include "MatrixFilter.hpp"
#include "../BorderHandlers/FillBorderHandler.hpp"

Matrix *MatrixFilter::filter(Matrix *matrix) {
    Matrix *bordered = this->_borderHandler->handle(matrix, this->_filter->width(), this->_filter->height());
    long origin_x = (bordered->width() - matrix->width()) / 2;
    long origin_y = (bordered->height() - matrix->height()) / 2;


    for (long x = origin_x; x < matrix->width(); x++) {
        for (long y = origin_y; y < matrix->height(); y++) {
            long offset = (this->_filter->width() - 1) / 2;
            float sum = 0;
            for (int filter_x = 0; filter_x < this->_filter->width(); filter_x++) {
                for (int filter_y = 0; filter_y < this->_filter->height(); filter_y++) {
                    sum += bordered->getMatrix()->at(x - offset).at(y - offset) *
                           this->_filter->getMatrix()->at(filter_x - offset).at(filter_y - offset);
                }
            }

        }
    }

    Matrix *filtered = new Matrix(matrix);
    for (long x = origin_x; x < matrix->width(); x++) {
        for (long y = origin_y; y < matrix->height(); y++) {
            filtered->getMatrix()->at(x - origin_x)[y - origin_y] = bordered->getMatrix()->at(x).at(y);
        }
    }
    delete bordered;
    return filtered;
}

MatrixFilter::MatrixFilter() {
    FillBorderHandler *handler = new FillBorderHandler(0);
    vector<vector<float>> matrix = {{2}};
    Matrix *filter = new Matrix(matrix);

    this->setFilter(filter);
    this->setBorderHandler(handler);
}

void MatrixFilter::setFilter(Matrix *filter) {
//    if (this->_filter != NULL)
//        delete this->_filter;
    this->_filter = filter;
}

void MatrixFilter::setBorderHandler(BorderHandler *handler) {
//    if (this->_borderHandler != NULL)
//        delete this->_borderHandler;
    this->_borderHandler = handler;
}

MatrixFilter::MatrixFilter(Matrix *filter, BorderHandler *handler) {
    this->setFilter(filter);
    this->setBorderHandler(handler);
}


