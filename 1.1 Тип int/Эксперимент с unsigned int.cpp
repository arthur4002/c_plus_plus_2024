#include <iostream>
#include <bitset>

void printBits(unsigned int n) {
    std::cout << "Число: " << n << std::endl;
    std::cout << "Побитовое представление: " << std::bitset<sizeof(unsigned int) * 8>(n) << std::endl;
}

int main() {
    unsigned int zero = 0;

    std::cout << "Начальное значение (0):" << std::endl;
    printBits(zero);

    std::cout << "\nПосле вычитания 1:" << std::endl;
    printBits(zero - 1);

    return 0;
}
