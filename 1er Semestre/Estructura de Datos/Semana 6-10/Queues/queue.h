#include "Node.h"

template <class T>
class queue {
    public:
        queue();
        ~queue();
        void push(T data);
        void pop();
        T front();
        int size();
        bool empty();
    private:
        Node<T> *fin;
        int tam;
};

// complejidad: O(1)
template <class T>
queue<T>::queue(){
    fin = nullptr;
    tam = 0;
}

// complejidad: O(1)
template <class T>
queue<T>::~queue(){
    if(fin != nullptr){
        Node<T> *curr = fin->getNext();
        fin->setNext(nullptr);
        fin = curr;
        while(fin != nullptr){
            fin = fin->getNext();
            delete curr;
            curr = fin;
        }
    }
}

// complejidad: O(1)
template <class T>
void queue<T>::push(T data){
    if(fin == nullptr){
        fin = new Node<T>(data);
        fin->setNext(fin);
    } else {
        fin->setNext(new Node<T>(data,fin->getNext()));
        fin = fin->getNext();
    }
    tam++;
}

// complejidad: O(1)
template <class T>
void queue<T>::pop(){
    Node<T> *curr = fin->getNext();
    if(fin->getNext() == fin){
        fin = nullptr;
    } else {
        fin->setNext(curr->getNext());
    }
    delete curr;
    tam--;
    
}

// complejidad: O(1)
template <class T>
T queue<T>::front(){
    return fin->getNext()->getData();
}

// complejidad: O(1)
template <class T>
int queue<T>::size(){
    return tam;
}

// complejidad: O(1)
template <class T>
bool queue<T>::empty(){
    return fin == nullptr;
}