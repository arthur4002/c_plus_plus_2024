#include <iostream>
#include <iomanip>

int main() {
    float sum = 0.0f;
    int k = 1;

    while (true) {
        float old_sum = sum;
        sum += 1.0f / k;
        
        // Проверяем, увеличилась ли сумма
        if (sum == old_sum) {
            std::cout << "Первый элемент, не увеличивающий сумму: " << k << std::endl;
            std::cout << "Значение суммы: " << std::setprecision(10) << sum << std::endl;
            break;
        }
        
        k++;
    }

    return 0;
} 

