#include "SubForwardList.h"
#include <iostream>

//по умолчанию
SubForwardList::SubForwardList() : head(nullptr) {}

//копирование
SubForwardList::SubForwardList(const SubForwardList& other) : head(nullptr) {
    if (other.head != nullptr) {
        head = new Node(other.head->data);
        Node* current = other.head->next;
        Node* last = head;
        while (current != nullptr) {
            last->next = new Node(current->data);
            last = last->next;
            current = current->next;
        }
    }
}

//перемещение
SubForwardList::SubForwardList(SubForwardList&& other) noexcept : head(other.head) {
    other.head = nullptr;
}


SubForwardList::~SubForwardList() {
    clear();
}

//присваивание копированием
SubForwardList& SubForwardList::operator=(const SubForwardList& other) {
    if (this != &other) {
        clear();
        if (other.head != nullptr) {
            head = new Node(other.head->data);
            Node* current = other.head->next;
            Node* last = head;
            while (current != nullptr) {
                last->next = new Node(current->data);
                last = last->next;
                current = current->next;
            }
        }
    }
    return *this;
}

//присваивание перемещением
SubForwardList& SubForwardList::operator=(SubForwardList&& other) noexcept {
    if (this != &other) {
        clear();
        head = other.head;
        other.head = nullptr;
    }
    return *this;
}

//методы...

bool SubForwardList::push_back(int d) {
    Node* new_node = new Node(d, nullptr);
    if (head == nullptr) {
        head = new_node;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    return true;
}

int SubForwardList::pop_back() {
    if (head == nullptr) {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    int data;
    if (head->next == nullptr) {
        data = head->data;
        delete head;
        head = nullptr;
    }
    else {
        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        data = current->next->data;
        delete current->next;
        current->next = nullptr;
    }
    return data;
}

bool SubForwardList::push_forward(int d) {
    Node* new_node = new Node(d, head);
    head = new_node;
    return true;
}

int SubForwardList::pop_forward() {
    if (head == nullptr) {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    int data = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return data;
}

bool SubForwardList::push_where(unsigned int where, int d) {
    if (where == 0) {
        return push_forward(d);
    }

    Node* current = head;
    for (unsigned int i = 0; (i < where - 1) && current != nullptr; ++i) {
        current = current->next;
    }
    
    if (current == nullptr) {
        std::cout << "Error: Out of range\n";
        return false;
    }

    Node* new_node = new Node(d, current->next);
    current->next = new_node;
    return true;
}

int SubForwardList::erase_where(unsigned int where) {
    if (head == nullptr) {
        std::cout << "Error: Empty list\n";
        return 0;
    }

    if (where == 0) {
        return pop_forward();
    }
    Node* current = head;
    for (unsigned int i = 0; (i < where - 1) && current != nullptr; ++i) {
        current = current->next;
    }
    
    if (current == nullptr) {
        std::cout << "Error: Out of range\n";
        return 0;
    }

    int data = current->next->data;
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return data;
}

unsigned int SubForwardList::size() const {
    Node* current = head;
    unsigned int count = 0;
    while (current != nullptr) {
        ++count;
        current = current->next;
    }
    return count;
}

void SubForwardList::clear() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
