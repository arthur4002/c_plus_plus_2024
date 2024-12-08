#include "Matrix.h"
#include <stdexcept>
#include <cmath>
#include <vector>

//функция для вычисления детерминанта через LU-разложение с использованием вещественных чисел
int Determinant(const Matrix &A) {
    size_t n = A.rows();
    if (A.rows() != A.cols()) {
        throw std::runtime_error("Determinant is defined only for square matrix.");
    }
    if (n == 0) return 1;

    //создаём временную матрицу с типом double для вычислений
    std::vector<std::vector<double>> M(n, std::vector<double>(n, 0.0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            M[i][j] = static_cast<double>(A(i, j));
        }
    }

    double sign = 1.0; //запоминаем знак от перестановок строк

    //выполняем LU-разложение с частичным выбором главного элемента
    for (size_t k = 0; k < n; ++k) {
        double pivot = std::abs(M[k][k]);
        size_t pivot_row = k;
        for (size_t i = k + 1; i < n; ++i) {
            if (std::abs(M[i][k]) > pivot) {
                pivot = std::abs(M[i][k]);
                pivot_row = i;
            }
        }

        //находим строку с максимальным элементом
        if (pivot < 1e-12) { 
            return 0; //матрица вырождена
        }

        //перестановка строк
        if (pivot_row != k) {
            std::swap(M[k], M[pivot_row]);
            sign = -sign;
        }

        //гауссово исключение для строк ниже
        for (size_t i = k + 1; i < n; ++i) {
            double factor = M[i][k] / M[k][k];
            M[i][k] = 0.0; //элемент под диагональю становится нулём
            for (size_t j = k + 1; j < n; ++j) {
                M[i][j] -= factor * M[k][j];
            }
        }
    }

    //вычисляем det как произведение диагональных элементов U, умноженное на знак
    double det = sign;
    for (size_t i = 0; i < n; ++i) {
        det *= M[i][i];
    }

    //проверяем, что детерминант целый, если нет то округляем...
    return static_cast<int>(std::round(det));
}




