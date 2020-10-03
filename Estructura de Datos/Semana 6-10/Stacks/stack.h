#include "Node.h"

template <class T>
class stack {
    public:
        stack();
        ~stack();
        T top();
        void push(T data);
        void pop();
        bool empty();
        int size();

    private:
        Node<T> *tope;
        int tam;
};

// Complejidad: O(1)
template <class T>
stack<T>::stack(){
    tope = nullptr;
    tam = 0;
}

// Complejidad: O(n)
template <class T>
stack<T>::~stack(){
    Node<T> *curr = tope;
    while(tope != nullptr){
        tope = tope->getNext();
        delete curr;
        curr = tope;
    }
}

// Complejidad: O(1)
template <class T>
T stack<T>::top(){
    return tope->getData();
}

// Complejidad: O(1)
template <class T>
void stack<T>::push(T data){
    tope = new Node<T>(data, tope);
    tam++;
}

// Complejidad: O(?)
template <class T>
void stack<T>::pop(){
    Node<T> *curr = tope;
    tope = tope->getNext();
    delete curr;
    tam--;
}

// Complejidad: O(1)
template <class T>
bool stack<T>::empty(){
    return (tope == nullptr);
}

// Complejidad: O(1)
template <class T>
int stack<T>::size(){
    return tam;
}