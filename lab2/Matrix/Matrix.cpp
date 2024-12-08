#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix() : m_rows(0), m_cols(0) { //empty
    
}

Matrix::Matrix(size_t rows, size_t cols) : m_rows(rows), m_cols(cols) {
    data.init();
    data.resize(static_cast<unsigned int>(rows * cols));
    for (size_t i = 0; i < rows * cols; ++i) {
        data.mas[i] = 0;
    }
}

Matrix::Matrix(const Matrix &other, size_t skip_row, size_t skip_col) {
    //создаём матрицу (n-1)*(n-1) если other квадратная
    if (other.m_rows != other.m_cols)
        throw std::runtime_error("Minor defined only for square matrix");

    size_t n = other.m_rows;
    if (skip_row >= n || skip_col >= n)
        throw std::out_of_range("Invalid row/col for submatrix");

    m_rows = n - 1;
    m_cols = n - 1;

    data.init();
    data.resize(static_cast<unsigned int>(m_rows * m_cols));

    //заполняем подматрицу
    size_t dest_i = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i == skip_row) continue;
        size_t dest_j = 0;
        for (size_t j = 0; j < n; ++j) {
            if (j == skip_col) continue;
            data.mas[dest_i * (m_cols) + dest_j] = other(i,j);
            dest_j++;
        }
        dest_i++;
    }
}

int& Matrix::operator()(size_t i, size_t j) {
    if (i >= m_rows || j >= m_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data.mas[i * m_cols + j];
}

const int& Matrix::operator()(size_t i, size_t j) const {
    if (i >= m_rows || j >= m_cols) {
        throw std::out_of_range("Index out of range");
    }
    return data.mas[i * m_cols + j];
}
