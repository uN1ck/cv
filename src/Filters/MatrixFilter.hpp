#ifndef CV_MATRIXFILTER_HPP
#define CV_MATRIXFILTER_HPP

#include "Filter.hpp"
#include "../BorderHandlers/BorderHandler.hpp"

class MatrixFilter : public Filter {
private:
    Matrix *_filter;
    BorderHandler *_borderHandler;

public:
    MatrixFilter();

    MatrixFilter(Matrix *filter, BorderHandler *handler);

    void setFilter(Matrix *filter);

    void setBorderHandler(BorderHandler *handler);

    Matrix *filter(Matrix *matrix) override;

};


#endif //CV_MATRIXFILTER_HPP
