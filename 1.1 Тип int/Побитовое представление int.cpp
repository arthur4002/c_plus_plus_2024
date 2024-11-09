#include <iostream>
#include <bitset>

void printBits(int n) {
    std::cout << "Число: " << n << std::endl;
    std::cout << "Побитовое представление: " << std::bitset<sizeof(int) * 8>(n) << std::endl;
}

int main() {
    int positive = 42;
    int negative = -42;

    std::cout << "Положительное число:" << std::endl;
    printBits(positive);

    std::cout << "\nОтрицательное число:" << std::endl;
    printBits(negative);

    return 0;
}
