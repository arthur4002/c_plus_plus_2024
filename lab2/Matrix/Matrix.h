#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include "SubVector.h"

class Matrix {
public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    //конструктор подматрицы (используем для расчёта минора)
    Matrix(const Matrix &other, size_t skip_row, size_t skip_col);

    size_t rows() const { return m_rows; }
    size_t cols() const { return m_cols; }

    int& operator()(size_t i, size_t j);
    const int& operator()(size_t i, size_t j) const;

private:
    size_t m_rows;
    size_t m_cols;
    SubVector data;

    friend int Determinant(const Matrix &M);
};

#endif // MATRIX_H
