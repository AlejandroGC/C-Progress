// A01570396 Alejandro Daniel González Carrillo
// Act 2.1 - Implementación de un ADT de estructura de datos lineales
// Act 2.2 - Verificación de las funcionalidades de una estructura de datos lineal

#include "Node.h"

using namespace std;

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
        T get(int pos);
        T set(T data, int pos);
        bool change(int pos, int pos2);
        void create(T data, int pos);
        int read(T data);
        bool update(T data, T nData);
        bool del(T data);
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
        size++;
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
    return true;
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

// // Complejidad: O(n)
// template <class T>
// void LinkedList<T>::del(int pos) {
//     if (pos == 0) {
//         deleteFirst();
//     } else if (pos == size-1) {
//         deleteLast();
//     } else {
//         Node<T> *curr = head;
//         for (int i = 0; i < pos-1; i++) {
//             curr = curr->getNext();
//         }
//         Node<T> *aux = curr->getNext();
//         curr->setNext(aux->getNext());
//         delete aux;
//         size--;
//     }
// }

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

// Complejidad: O(n)
template <class T>
T LinkedList<T>::get(int pos){
    Node<T> *curr = head;
    for(int i=0; i < pos-1; i++){
        curr = curr->getNext();
    }
    return curr->getData();
}

// Complejidad: O(n)
template <class T>
T LinkedList<T>::set(T data, int pos) {
    Node<T> *curr = head;
    for(int i=0; i < pos-1; i++){
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

// Complejidad: O(n)
template <class T>
bool LinkedList<T>::change(int pos, int pos2){
    if (pos < 0 || pos >= size || pos2 < 0 || pos2 >= size){
        return false;
    }
    
    Node<T> *curr = head;
    int posMen = (pos < pos2 ? pos : pos2);
    int posMay = (pos > pos2 ? pos : pos2);

    for(int i = 0; i < posMen-1; i++){
        curr = curr->getNext();
    }

    Node<T> *curr2 = curr;
    for(int i = 0; i < (posMay-posMen); i++){
        curr2 = curr2->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(curr2->getData());
    curr2->setData(dataAux);
    return true;
}

//////////////////////////////////////////////////////// TAREA //////////////////////////////////////////////////////////////////////

// Insertar un elemento en la estructura de datos (create) de acuerdo a la política de acceso de la estructura
// Complejidad: O(n)
template <class T>
void LinkedList<T>::create(T data, int pos){
    // Si se introduce una posicion menor a 0 se agregara como primer elemento de la lista.
    if (pos <= 0) {
        addFirst(data);
    } else if (pos >= size) {
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

// Leer (buscar, obtener, etc.) un elemento dentro de la estructura de datos (read) de acuerdo a la política de acceso de la estructura
// Complejidad: O(n)
template <class T>
int LinkedList<T>::read(T data){
    if(head != nullptr){
        Node<T> *curr = head;
        // Itera sobre toda la lista encadenada hasta encontrar el elemento que conincide con el del usuario.
        for(int i=0; i < size; i++){
            if(curr->getData() == data){
                return i;
            }
            curr = curr->getNext();
        }
        return -1;
    }
    return -1;
}

// Actualizar un elemento dentro de la estructura de datos (update) de acuerdo a la estructura de datos específica
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::update(T data, T nData){
    bool check = false;
    if(head != nullptr){
        Node<T> *curr = head;
        // Itera sobre la lista y al encontrar cada elemento que coincide con el del usuario lo intercambia con el valor ingresado.
        for(int i=0; i < size; i++){
            // Con que ocurra un intercambio hace check == true.
            if(curr->getData() == data){
                curr->setData(nData);
                check = true;
            }
            curr = curr->getNext();
        }
    }
    return check;
}

// Borrar (eliminar) un elemento dentro de la estructura de datos (del) de acuerdo a la estructura de datos específica.
// Complejidad: O(n)
template <class T>
bool LinkedList<T>::del(T data){
    bool flag = false; // Bandera que determina si se borraron los elementos.
    // Condicion en caso de que la lista este vacia o el primer dato sea el que se esta buscando borrar.
    while(head != nullptr && head->getData() == data){
        deleteFirst();
        flag = true;
    }
    // No puede ser una lista vacia.
    if(head != nullptr){
        Node<T> *curr = head;
        Node<T> *aux;
        while(curr != nullptr){
            aux = curr->getNext();
            if(aux != nullptr && aux->getData() == data){
                curr->setNext(aux->getNext());
                delete aux;
                size--;
                flag = true;
            } else {
                curr = aux;
            }
        }
    }
    return flag;
}