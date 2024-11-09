#include <iostream>
#include <iomanip>

int main() {
    int k = 2097152; // Значение k из предыдущего пункта
    float sum_forward = 0.0f;
    float sum_backward = 0.0f;

    // Находим k (как в предыдущем пункте)
    while (true) {
        float old_sum = sum_forward;
        sum_forward += 1.0f / (k + 1);
        if (sum_forward == old_sum) {
            break;
        }
        k++;
    }

    // Суммирование вперед
    sum_forward = 0.0f;
    for (int i = 1; i <= k + 100; i++) {
        sum_forward += 1.0f / i;
    }

    // Суммирование назад
    for (int i = k + 100; i >= 1; i--) {
        sum_backward += 1.0f / i;
    }

    std::cout << "Суммирование вперед: " << std::setprecision(10) << sum_forward << std::endl;
    std::cout << "Суммирование назад: " << std::setprecision(10) << sum_backward << std::endl;
    std::cout << "Разница: " << std::setprecision(10) << std::abs(sum_forward - sum_backward) << std::endl;

    return 0;
}

