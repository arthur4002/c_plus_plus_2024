#include <iostream>
#include <iomanip>

int main() {
    float a = 1.0f;

    
    while (a + 1.0f != a) {
        a += 1.0f; // Удваиваем или добавляем единицу
    }

    // Выводим найденное значение a
    std::cout << std::setprecision(20);
    std::cout << "Первое число a, для которого a + 1 == a: " << a << std::endl;

    return 0;
}






/*
    // Проверяем дальше
    float x = a;
    std::cout << "\nПроверка x == x + 1 для x >= a:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "x = " << x << ", x + 1 = " << (x + 1.0f) 
                  << ", равны: " << (x == (x + 1.0f)) << std::endl;
        x *= 2.0f;
    }
*/   
