#include <iostream>
#include <climits>
#include <bitset>

void printBits(int n) {
    std::cout << "Число: " << n << std::endl;
    std::cout << "Побитовое представление: " << std::bitset<sizeof(int) * 8>(n) << std::endl;
}

int main() {
    std::cout << "INT_MAX:" << std::endl;
    printBits(INT_MAX);

    std::cout << "\nINT_MAX + 1:" << std::endl;
    printBits(INT_MAX + 1);

    return 0;
}
