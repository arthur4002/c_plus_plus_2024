#include "SubVector.h"


SubVector::SubVector() : mas(nullptr), top(0), capacity(0) {}

//конструктор с инициализацией размера
SubVector::SubVector(unsigned int initial_capacity) : mas(new int[initial_capacity]), top(0), capacity(initial_capacity) {}


SubVector::SubVector(const SubVector &other) : mas(new int[other.capacity]), top(other.top), capacity(other.capacity) {
    for (unsigned int i = 0; i < top; ++i) {
        mas[i] = other.mas[i];
    }
}


SubVector::SubVector(SubVector &&other) noexcept : mas(other.mas), top(other.top), capacity(other.capacity) {
    other.mas = nullptr;
    other.top = 0;
    other.capacity = 0;
}


SubVector::~SubVector() {
    delete[] mas;
}


SubVector& SubVector::operator=(const SubVector &other) {
    if (this == &other) {
        return *this;
    }

    delete[] mas;

    mas = new int[other.capacity];
    top = other.top;
    capacity = other.capacity;

    for (unsigned int i = 0; i < top; ++i) {
        mas[i] = other.mas[i];
    }

    return *this;
}


SubVector& SubVector::operator=(SubVector &&other) noexcept {
    if (this == &other) {
        return *this;
    }

    delete[] mas;

    mas = other.mas;
    top = other.top;
    capacity = other.capacity;

    other.mas = nullptr;
    other.top = 0;
    other.capacity = 0;

    return *this;
}


bool SubVector::init() {
    mas = nullptr;
    capacity = 0;
    top = 0;
    return true;
}


bool SubVector::push_back(int d) {
    if (top == capacity) {
        unsigned int new_capacity = capacity == 0 ? 1 : capacity * 2;
        if (!resize(new_capacity)) {
            return false;
        }
    }

    mas[top] = d;
    top++;
    return true;
}


int SubVector::pop_back() {
    if (top == 0) {
        std::cout << "Error: empty vector\n";
        return 0;
    }
    top--;
    return mas[top];
}


bool SubVector::resize(unsigned int new_capacity) {
    int* new_mas = new int[new_capacity];

    for (unsigned int i = 0; i < top; ++i) {
        new_mas[i] = mas[i];
    }

    delete[] mas;

    mas = new_mas;
    capacity = new_capacity;

    return true;
}


void SubVector::shrink_to_fit() {
    resize(top);
}


void SubVector::clear() {
    top = 0;
}
