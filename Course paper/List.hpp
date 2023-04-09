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
    
     List() {
         head = NULL;
         sizeList = 0;
         
     };
    List(size_t) {};
    void addElem(T);
    void removeElem(size_t);
    void editElem(size_t, T);
    void insertElem(size_t, T);
    void writeToFile(FILE*);
    void readToFile(FILE*);
    void clear();
    int findElem(T);
    int findElem(int);
    int partition(int , int );
    void quickSort(int, int);
    
    T& operator[] (int);
    size_t getSize() {
        return sizeList;
    };
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
        if (head == NULL) 
            break;
        _current = head->next;
        delete head;
        head = _current;
    }
    delete _current;
    sizeList = 0;
    head = NULL;
}

template<typename T>
T& List<T>::operator[](int index)
{
        
        if (index >= 0 and index < sizeList) {
            node* current = new node();
            current = head;
            for (int i = 0; i < index; i++)
                current = current->next;
            return current->data;
        }
        else if (sizeList + index > 0) {
            node* current = new node();
            current = head;
            for (int i = 0; i < sizeList + index; i++) {
                current = current->next;
            }
            return current->data;
        }
    
}
template <typename T>
void List<T>::clear() {
    node* _current;
    _current = new node;
    for (int i = 0; i < sizeList; i++) {
        if (head == NULL)
            break;
        _current = head->next;
        delete head;
        head = _current;
    }
    delete _current;
    sizeList = 0;
    head = NULL;
}
template <typename T>
void List<T>::writeToFile(FILE* file) {
    fwrite(this, sizeof(List), 1, file);
}

template <typename T>
void List<T>::readToFile(FILE* file) {
    fseek(file, 0, SEEK_SET);
    fread(this, sizeof(List), 1, file);
}
template <typename T>
int List<T>::partition(int low, int high)
{
    T pivot = (*this)[high];
    int pIndex = low;

    for (int j = low; j < high; j++)
    {
        if ((*this)[j] < pivot)
        {
            T temp;
            temp = (*this)[pIndex];
            (*this)[pIndex] = (*this)[j];
            (*this)[j] = temp;
            pIndex++;
        }
    }
    T temp;
    temp = (*this)[pIndex];
    (*this)[pIndex] = (*this)[high];
    (*this)[high] = temp;
    return pIndex;
}
template <typename T>
void List<T>::quickSort(int low, int high)
{
    if (low < high)
    {
        int pivot = partition(low, high);

        quickSort(low, pivot - 1);
        quickSort(pivot + 1, high);
    }
    else return;
}