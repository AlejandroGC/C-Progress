#include "Node.h"

template <class T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        void addFirst(T data);
        void addLast(T data);
        bool add(T data, int pos);
        void deleteFirst();
        void deleteLast();
        int deleteAll();
        void del(int pos);
        int getSize();
        bool isEmpty();
        void print();
    private:
        Node<T> *head;
        int size;
};

template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}

// Complejidad: O(1)
template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}

// Complejidad: O(n)
template <class T>
void LinkedList<T>::addLast(T data){
    if (size == 0){
        addFirst(data);
    } else {
        Node<T> *curr = head;
        while(curr->getNext() != nullptr){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
    }    
}

// Complejidad: O(n)
template <class T>
bool LinkedList<T>::add(T data, int pos) {
    if (pos > size) {
        return false;
    }
    if (pos == 0) {
        addFirst(data);
    } else if (pos == size){
        addLast(data);
    } else {
        Node<T> *curr = head;
        for (int i = 1; i<pos; i++){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    
}

// Complejidad: O(1)
template <class T>
void LinkedList<T>::deleteFirst() {
    if (head != nullptr){
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

// Complejidad: O(n)
template <class T>
void LinkedList<T>::deleteLast() {
    if (size <= 1){
        deleteFirst();
    } else {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr) {
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(nullptr);
        size--;
    }
}

// Complejidad: O(n)
template <class T>
int LinkedList<T>::deleteAll() {
    Node<T> *curr = head; 
    while (head != nullptr) {
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int sizeAux = size;
    size = 0;
    return sizeAux;
}

// Complejidad: O(n)
template <class T>
void LinkedList<T>::del(int pos) {
    if (pos == 0) {
        deleteFirst();
    } else if (pos == size-1) {
        deleteLast();
    } else {
        Node<T> *curr = head;
        for (int i = 0; i < pos-1; i++) {
            curr = curr->getNext();
        }
        Node<T> *aux = curr->getNext();
        curr->setNext(aux->getNext());
        delete aux;
        size--;
    }
}

// Complejidad: O(1)
template <class T>
int LinkedList<T>::getSize(){
    return size;
}

// Complejidad: O(1)
template <class T>
bool LinkedList<T>::isEmpty(){
    return head == nullptr;
}

// Complejidad: O(n)
template <class T>
void LinkedList<T>::print(){
    cout << "La LinkedList contiene: " << endl;
    Node<T> *curr = head;
    while(curr != nullptr) {
        cout << curr->getData() << endl;
        curr = curr->getNext();
    }
}