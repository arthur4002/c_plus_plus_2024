#include "Matrix.h"
#include <iostream>
#include <chrono>

// Объявляем функцию определения детерминанта
int Determinant(const Matrix &M);

// Функция для генерации матрицы с заданным детерминантом.
// Самый простой способ: сгенерировать диагональную матрицу.
// Детерминант диагональной матрицы = произведение диагональных элементов.
// Если хотим детерминант D, то можно поставить на диагонали: D, и единицы.
void GenerateMatrixWithDeterminant(Matrix &M, int D) {
    // Предполагается, что M квадратная
    size_t n = M.rows();
    // Обнуляем
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            M(i,j) = 0;

    // Ставим 1 на всей диагонали, кроме первого элемента диагонали
    for (size_t i = 1; i < n; i++) {
        M(i,i) = 1;
    }
    // Первый диагональный элемент = D
    if (n > 0)
        M(0,0) = D;
}

// Тестовая функция
void TestMatrix(size_t n, int expected_det) {
    Matrix M(n, n);
    GenerateMatrixWithDeterminant(M, expected_det);

    auto start = std::chrono::high_resolution_clock::now();
    int det = Determinant(M);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Matrix size: " << n << "x" << n 
              << ", Expected determinant: " << expected_det 
              << ", Computed determinant: " << det 
              << ", Time: " << elapsed << " ms" << std::endl;
}

int main() {
    // Тест 1: 5x5, детерминант = 10
    TestMatrix(5, 10);

    // Тест 2: 50x50, детерминант = 5
    TestMatrix(50, 5);

    // Тест 3: 100x100, детерминант = 1
    // (Можно поменять на 200x200, но вычисление будет долгим)
    TestMatrix(100, 1);

    return 0;
}
