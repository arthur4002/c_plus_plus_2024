#ifndef SUBVECTOR_H
#define SUBVECTOR_H

#include <iostream>

class SubVector {
public: //vector_profiler.cpp пытается обратиться к этим переменным
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    //конструкторы
    SubVector();
    SubVector(unsigned int initial_capacity);
    SubVector(const SubVector &other); 
    SubVector(SubVector &&other) noexcept;

    
    ~SubVector();

    //операторы присваивания
    SubVector& operator=(const SubVector &other); //копирование
    SubVector& operator=(SubVector &&other) noexcept; //перемещение

    //методы
    bool init();
    bool push_back(int d);
    int pop_back(); 
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    void clear();
};

#endif //SUBVECTOR_H
