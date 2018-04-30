#include "linked_list.h"

template<typename T>
class Stack : private LinkedList<T> {
public:
    Stack() : LinkedList<T>::LinkedList() {
    }

    ~Stack() {
    }

    void push(T data) {
        LinkedList<T>::addNode(data);
    }

    T pop() {
        return LinkedList<T>::remove(getSize() - 1);
    }

    bool isEmpty() {
        return LinkedList<T>::isEmpty();
    }

    T getSize() {
        return LinkedList<T>::getSize();
    }

    T top(){
        return LinkedList<T>::get(getSize()-1);
    }

};
