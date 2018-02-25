//
// Created by N1ck on 25.02.2018.
//

#ifndef CV_BORDERHANDLER_HPP
#define CV_BORDERHANDLER_HPP

#include "../Matrix.hpp"

/**
 * Интерфейс подготовителя краев матрицы
 */
class BorderHandler {
public:
    /**
     * Метод обработки краев матрицы
     *
     * Метод создает НОВЫЙ экземпляр матрицы с подготовленными краями
     * @param matrix необработанная матрциа
     * @param width ширина одного края
     * @param height высота одного края
     * @return указатель на новый экземпляр матриц
     */
    virtual Matrix *handle(Matrix *matrix, int width, int height) = 0;
};

#endif //CV_BORDERHANDLER_HPP
