#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << std::setw(10) << std::setprecision(4) << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<double> gaussElimination(std::vector<std::vector<double>> matrix) {
    int n = matrix.size();

    //прямой ход
    for (int i = 0; i < n; i++) {
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(matrix[k][i]) > std::abs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }

        //обмен строк
        std::swap(matrix[i], matrix[maxRow]);

        if (std::abs(matrix[i][i]) < 1e-10) {
            throw std::runtime_error("Матрица вырождена или система не имеет решения");
        }

        //нормализация текущей строки
        for (int j = n; j >= i; j--) {
            matrix[i][j] /= matrix[i][i];
        }

        //вычитание текущей строки из всех нижележащих строк
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i];
            for (int j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }

        std::cout << "После шага " << i + 1 << ":" << std::endl;
        printMatrix(matrix);
    }

    //обратный ход
    std::vector<double> solution(n);
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }

    return solution;
}

int main() {
    //пример СЛАУ:
    //2x + y - z = 8
    //-3x - y + 2z = -11
    //-2x + y + 2z = -3
    std::vector<std::vector<double>> matrix = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);

    try {
        std::vector<double> solution = gaussElimination(matrix);

        std::cout << "Решение:" << std::endl;
        for (int i = 0; i < solution.size(); i++) {
            std::cout << "x" << i + 1 << " = " << solution[i] << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
} 
