#include <iostream>

struct subforwardlist {
    int data;
    subforwardlist* next;
};

// Список функций к реализации, вместо "@" нужно всатвить столько звездочек, сколько необходимо вам для реализации
bool init(subforwardlist** sfl); 	//инициализация пустого недосписка
bool push_back(subforwardlist** sfl, int d); 	//добавление элемента в конец недосписка
int pop_back(subforwardlist** sfl); 	//удаление элемента с конца недосписка, если пустой - возвращать 0
bool push_forward(subforwardlist** sfl, int d); 	//добавление элемента в начало недосписка
int pop_forward(subforwardlist** sfl); 	//удаление элемента из начала недосписка, если пустой - возвращать 0
bool push_where(subforwardlist** sfl, unsigned int where, int d); //добавление элемента с порядковым номером where
int erase_where(subforwardlist** sfl, unsigned int where);	//удаление элемента с порядковым номером where, если пустой - возвращать 0

unsigned int size(subforwardlist** sfl);	//определить размер недосписка

void clear(subforwardlist** sfl);	//очистить содержимое недосписка

bool init(subforwardlist** sfl) {
    *sfl = nullptr;
    return true;
}

bool push_back(subforwardlist** sfl, int d) {
    subforwardlist* new_node = new subforwardlist{d, nullptr};
    if (*sfl == nullptr) {
        *sfl = new_node;
    }
    else {
        subforwardlist* current = *sfl;
        while(current->next!=nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

int pop_back(subforwardlist** sfl) {
    if (*sfl == nullptr) {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    int data;
    if((*sfl)->next == nullptr) {
        data = (*sfl)->data;
        delete *sfl;
        *sfl = nullptr;
    }
    else {
        subforwardlist* current = *sfl;
        while(current->next->next != nullptr) {
            current = current->next;
        }
    data = current->next->data;
    delete current->next;
    current->next = nullptr;
    }
    return data;
}

bool push_forward(subforwardlist** sfl, int d) {
    subforwardlist* new_node = new subforwardlist{d, *sfl}
    *sfl = new_node;
    return true;
}

int pop_forward(subforwardlist** sfl) {
    if (*sfl == nullptr) {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    int data = (*sfl)->data;
    subforwardlist* temp = *sfl;
    *sfl = (*sfl)->next;
    delete temp;
    return data;
}

bool push_where(subforwardlist** sfl, unsigned int where, int d) {
    if (where == 0) {
        return push_forward(sfl, d);
    }

    subforwardlist* current = *sfl;
    for (unsigned int i = 0; (i < where - 1) && current != nullptr; ++i) {
        current = current->next;
    }
    
    if (current == nullptr) {
            std::cout << "Error: Out of range\n";
            return false;
    }

    subforwardlist* new_node = new subforwardlist{d, current->next};
    current->next = new_node;
    return true;
}

int erase_where(subforwardlist** sfl, unsigned int where) {
    if(*sfl == nullptr) {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    if (where == 0) {
        return pop_forward(sfl);
    }
    subforwardlist* current = *sfl;
    for (unsigned int i = 0; (i < where - 1) && current != nullptr; ++i) {
        current = current->next;
    }
    
    if (current == nullptr) {
            std::cout << "Error: Out of range\n";
            return 0;
    }

    int data = current->next->data;
    subforwardlist* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return data;
}

unsigned int size(subforwardlist** sfl) {
    subforwardlist* current = *sfl;
    unsigned int count = 0;
    while (current!=nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

void clear(subforwardlist** sfl) {
    while (*sfl != nullptr){
        subforwardlist* temp = *sfl;
        *sfl = (*sfl)->next;
        delete temp;
    }
    return;
}