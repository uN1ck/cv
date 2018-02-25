//
// Created by N1ck on 25.02.2018.
//

#ifndef CV_FILTER_HPP
#define CV_FILTER_HPP

#include "../Matrix.hpp"

/**
 * Интерфейс классдля фильтрации изображений
 */
class Filter {
public:
    /**
     * Метод фильтрации изображения
     *
     * Создает НОВЫЙ экземпляр фильтрованный матрицы
     * @param matrix необработанная матрциа
     * @return указатель на новый экземпляр матрицы
     */
    virtual Matrix *filter(Matrix *matrix)  =0;
};

#endif //CV_FILTER_HPP
