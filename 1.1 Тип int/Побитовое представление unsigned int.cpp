#include <iostream>
#include <bitset>

void printBits(unsigned int n) {
    std::cout << "Число: " << n << std::endl;
    std::cout << "Побитовое представление: " << std::bitset<sizeof(unsigned int) * 8>(n) << std::endl;
}

int main() {
    unsigned int num1 = 42;
    unsigned int num2 = 4294967295; // max value for 32-bit unsigned int

    std::cout << "Пример 1:" << std::endl;
    printBits(num1);

    std::cout << "\nПример 2 (максимальное значение):" << std::endl;
    printBits(num2);

    return 0;
}
