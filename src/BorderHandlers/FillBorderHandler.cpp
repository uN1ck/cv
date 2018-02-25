//
// Created by N1ck on 25.02.2018.
//

#include "FillBorderHandler.hpp"

Matrix *FillBorderHandler::handle(Matrix *matrix, int width, int height) {
    Matrix *cloned = new Matrix(matrix->width() + width * 2, matrix->height() + height * 2, this->_fill);

    for (long x = 0; x < matrix->width(); x++) {
        for (long y = 0; y < matrix->height(); y++) {
            cloned->getMatrix()->at(x + width)[y + height] = matrix->getMatrix()->at(x)[y];
        }
    }
    return cloned;
}

FillBorderHandler::FillBorderHandler(float fill) {
    this->_fill = fill;
}
