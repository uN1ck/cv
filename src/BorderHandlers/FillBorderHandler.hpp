//
// Created by N1ck on 25.02.2018.
//

#ifndef CV_FILLBORDERHANDLER_HPP
#define CV_FILLBORDERHANDLER_HPP


#include "BorderHandler.hpp"

class FillBorderHandler : public BorderHandler {
private:
    float _fill;
public:
    explicit FillBorderHandler(float fill);

    Matrix *handle(Matrix *matrix, int width, int height) override;

};


#endif //CV_FILLBORDERHANDLER_HPP
