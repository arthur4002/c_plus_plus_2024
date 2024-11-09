#include <iostream>
#include <algorithm> 

struct subvector {
    int *mas
    unsigned int top;
    unsigned int capacity;
}

bool init(subvector *qv); // инициализация пустого недовектора (top и capacity по нулям, а mas это NULL)
bool push_back(subvector *qv, int d); // добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости
int pop_back(subvector *qv); // удаление элемента с конца недовектора, значение удаленного элемента вернуть (если недовектор пустой, вернуть ноль)
bool resize(subvector *qv, unsigned int new_capacity); // увеличить емкость недовектора (можно использовать и для уменьшения - тогда, в рамках данной реализации, если top меньше новой capacity, то копируем только то, что влезает, и уменьшаем top до capacity)
void shrink_to_fit(subvector *qv); // очистить неиспользуемую память, переехав на новое место с уменьшением capacity до top
void clear(subvector *qv); // очистить содержимое недовектора, занимаемое место при этом не меняется
void destructor(subvector *qv);	// очистить всю используемую память, инициализировать недовектор как пустой

bool init(subvector *qv) {
    qv->mas = nullptr;
    qv->capacity = 0;
    qv->top = 0;
    return true;
}
 
bool push_back(subvector *qv, int a) {
    if (qv->top == qv->capacity) {
        unsigned int new_capacity;
        if (qv->capacity == 0)
            new_capacity = 1;
        else
            new_capacity = qv->capacity * 2;
        if (!resize(qv, new_capacity))
            return false;
    }

    qv->mas[qv->top] = a;
    qv->top++;
    return true;
}

int pop_back(subvector *qv) {
    if(qv->top == 0) {
        std::cout << "Error: empty vector\n";
        return 0;
    }
    qv->top--;
    return qv->mas[qv->top];
}

bool resize(subvector* qv, unsigned int new_capacity) {
    int* new_mas = new int[new_capacity];

    for (unsigned int i = 0; i < qv->top; ++i) {
        new_mas[i] = qv->mas[i];
    }

    delete[] qv->mas;

    qv->mas = new_mas;
    qv->capacity = new_capacity;

    return true;
}

void shrink_to_fit(subvector *qv) {
    resize(qv, qv->top);
}

void clear(subvector *qv) {
    qv->top = 0;
}

void destructor(subvector *qv) {
    delete[] qv->mas;
    init(qv);
}