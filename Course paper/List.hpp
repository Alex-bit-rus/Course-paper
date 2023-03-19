#pragma once

template<typename T>
class List
{
    struct node{
        T data;
        node* next;
    };
    node* head;
    size_t sizeList = 0;

public:
     List() {};
    List(size_t) {};
    void addElem(T);
    void removeElem(size_t);
    void editElem(size_t, T);
    void insertElem(size_t, T);
    int findElem(T);
    ~List();
};

template<typename T>
void List<T>::addElem(T _newData)
{
    node* _newList = new node;
    _newList->data = _newData;
    if (sizeList == 0) {
        _newList->next = NULL;
    }
    else {
        _newList->next = head;
    }
    head = _newList;
    sizeList++;
}
 
template<typename T>
void List<T>::removeElem(size_t _index) {
    if (_index >= 0 && _index < sizeList && sizeList > 0) {
        node* _current = head;
        node* _old;
        if (_index == 0) {
            _old = head;
            head = _current->next;
            delete _old;
            sizeList--;
        }
        else {
            size_t _i = 0;
            while (_current) {
                if (_i == _index - 1) {
                    _old = _current->next->next;
                    delete _current->next;
                    _current->next = _old;
                    sizeList--;
                    break;
                }
                _i++;
                _current = _current->next;
            }
        }
    }
    
}

template<typename T>
void List<T>::editElem(size_t _index, T _editT) {
    if (_index > 0 && _index < sizeList && sizeList > 0) {
        node* _current = new node();
        for (size_t _i = 0; _i < _index; _i++) {
            _current = head->next;
        }
        _current->data = _editT;

    }
   

}

template<typename T>
void List<T>::insertElem(size_t _index, T _editT) {
    if (_index > 0 && _index < sizeList + 1 && sizeList > 0) {
        node* _current = new node();
        node* _newList = new node();
        _current = head;
        _newList->data = _editT;
        for (int _i = 0; _i < _index - 1; _i++) {
            _current = _current->next;
        }
        _newList->next = _current->next;
        _current->next = _newList;
        sizeList++;
    }

}
template<typename T>
int List<T>::findElem(T _elem) {
    node* current = new node;
    size_t _index = 0;
    current = head;
    while (current) {
        if (current->data == _elem) {
            return _index;
        }
        current = current->next;
        _index++;
    }
    return -1;
}



template<typename T>
List<T>::~List() {
    node* _current;
    _current = new node;
    for (int i = 0; i < sizeList; i++) {
        _current = head->next;
        delete head;
        head = _current;
    }
    sizeList = 0;
}