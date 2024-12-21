#include "SubVector.h"
#include <iostream>

int main() {
    try {
        SubVector vec(5);

        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::cout << "Popped element: " << vec.pop_back() << std::endl; //ожидается 5
        std::cout << "Popped element: " << vec.pop_back() << std::endl; //ожидается 4

        vec.shrink_to_fit();

        SubVector vec2;

        vec2.push_back(6);
        vec2.push_back(7);

        std::cout << "Popped element from vec2: " << vec2.pop_back() << std::endl; //ожидается 7
        std::cout << "Popped element from vec2: " << vec2.pop_back() << std::endl; //ожидается 6

        //попытка удалить из пустого вектора
        std::cout << "Popped element from vec2: " << vec2.pop_back() << std::endl; //должно бросить исключение
    } catch (const VectorException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

