#include <iostream>
#include <bitset>
#include <cstring>
#include <cstdint>

union FloatBits {
    float f;
    uint32_t i;
};

void printFloatBits(float num) {
    FloatBits fb;
    fb.f = num;
    
    std::bitset<32> bits(fb.i);
    std::cout << "Число: " << num << std::endl;
    std::cout << "Двоичное представление: " << bits << std::endl;
    std::cout << "Знак: " << bits[31] << std::endl;
    std::cout << "Экспонента: " << bits.to_string().substr(1, 8) << std::endl;
    std::cout << "Мантисса: " << bits.to_string().substr(9, 23) << std::endl;
}

int main() {
    float numbers[] = {1.0f, -1.0f, 3.14f, 0.1f};
    
    for (float num : numbers) {
        printFloatBits(num);
        std::cout << std::endl;
    }

    return 0;
}
