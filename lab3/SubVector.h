// SubVector.h
#ifndef SUBVECTOR_H
#define SUBVECTOR_H

#include "SubVectorException.h"
#include <iostream>

class SubVector {
public:
    int *mas;
    unsigned int top;
    unsigned int capacity;

public:
    SubVector();
    SubVector(unsigned int initial_capacity);
    SubVector(const SubVector &other); 
    SubVector(SubVector &&other) noexcept;

    ~SubVector();

    SubVector& operator=(const SubVector &other); //копирование
    SubVector& operator=(SubVector &&other) noexcept; //перемещение

    bool init();
    bool push_back(int d);
    int pop_back(); 
    bool resize(unsigned int new_capacity);
    void shrink_to_fit();
    void clear();
};

#endif //SUBVECTOR_H
