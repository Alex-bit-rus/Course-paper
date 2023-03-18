#pragma once

template<typename T>
class List
{
    struct node{
        T data;
        node* next;
    };
    node head;
    size_t sizeList;

public:
    List(int year);
    void addElem(T);
    void removeElem(unsigned short);
    void editElem(unsigned short, T);
    void insertElem(unsigned short, T);
    ~List();
};

template<typename T>
inline void List<T>::addElem(T newData)
{
    List* current = new List;
    current->head.next = (*this).head;
    (*this).head = current->head;
}
