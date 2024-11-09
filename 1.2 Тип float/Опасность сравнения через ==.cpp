#include <iostream>
#include <iomanip>

int main() {
    float a = 0.1f;
    float b = 0.2f;
    float c = 0.3f;

    std::cout << std::setprecision(20);
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "a + b == c: " << ((a + b) == c) << std::endl;

    float d = 1.0f;
    float e = 1.0f;
    std::cout << "d == e: " << (d == e) << std::endl;

    return 0;
}
