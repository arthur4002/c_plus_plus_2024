#include <iostream>
#include <iomanip>

int main() {
    float sum = 0.0f;
    int max_k = 2097152; 

    //сложение в обратном порядке
    for (int k = 10 * max_k; k > 0; --k) {
        sum += 1.0f / k;
    }

    std::cout << "Значение суммы при обратном порядке сложения: " 
              << std::setprecision(10) << sum << std::endl;

    return 0;
}
