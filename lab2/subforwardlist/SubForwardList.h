#ifndef SUBFORWARDLIST_H
#define SUBFORWARDLIST_H

class SubForwardList {
public:
    //конструкторы
    SubForwardList();
    SubForwardList(const SubForwardList& other);
    SubForwardList(SubForwardList&& other) noexcept;

    //деструктор
    ~SubForwardList();

    //операторы присваивания
    SubForwardList& operator=(const SubForwardList& other);
    SubForwardList& operator=(SubForwardList&& other) noexcept;

    //методы
    bool push_back(int d);
    int pop_back();
    bool push_forward(int d);
    int pop_forward();
    bool push_where(unsigned int where, int d);
    int erase_where(unsigned int where);
    unsigned int size() const;
    void clear();

private:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) : data(d), next(n) {}
    };

    Node* head;
};

#endif //SUBFORWARDLIST_H
