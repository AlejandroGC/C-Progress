#include "Node.h"

using namespace std;

class DoublyLinkedList {
    public:
      DoublyLinkedList();
      ~DoublyLinkedList();
      void addFirst(datos data);
      void addLast(datos data);
      int deleteAll();
      void sort();
      void search(long ipInicial, long ipFinal);
    private:
      Node *head;
      Node *tail;
      int size;
};

DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Complejidad: O(1)
// Descripcion: Llama al método deleteAll, el cual borra la Double Linked List.
DoublyLinkedList::~DoublyLinkedList(){
    deleteAll();
}

// Complejidad: O(1)
// Descripcion: Agrega un dato al principio de la Double Linked List.
void DoublyLinkedList::addFirst(datos data){
    if(head == nullptr){
      head = tail = new Node(data, head, tail);
    } else {
      head->setPrev(new Node(data, nullptr, head));
      head = head->getPrev();
    }
    size++;
}

// Complejidad: O(1)
// Descripcion: Agrega un dato al final de la Double Linked List.
void DoublyLinkedList::addLast(datos data){
    if (size == 0){
        addFirst(data);
    } else {
      tail->setNext(new Node(data, tail, nullptr));
      tail = tail->getNext();
      size++;
    }    
}

// Complejidad: O(n)
// Descripcion: Borra la Double Linked List.
int DoublyLinkedList::deleteAll(){
    Node *curr = head;
    while (head != nullptr){
      head = head->getNext();
      delete curr;
      curr = head;
    }
    int sizeAux = size;
    size = 0;
    return sizeAux;
}

// Complejidad: O(n^2)
// Descripcion: Ordena los datos de la Double Linked List utilizando el método de Bubble Sort.
void DoublyLinkedList::sort() {
  bool swapped;
  Node *rPtr = nullptr;
  do {
    swapped = false;
    Node *lPtr = head;
    while(lPtr->getNext() != rPtr){
      if(lPtr->getData().key > lPtr->getNext()->getData().key){
        datos temp = lPtr->getData();
        datos temp2 = lPtr->getNext()->getData();
        lPtr->getNext()->setData(temp);
        lPtr->setData(temp2);
        swapped = true;
      }
      lPtr = lPtr->getNext();
    }
    rPtr = lPtr;
  } while(swapped);
}

// Complejidad: O(n)
// Descripcion: Busca datos dentro de la Double Linked List utilizando el método de Búsqueda Secuencial.
void DoublyLinkedList::search(long ipInicial, long ipFinal) {
  ofstream outfile;
  outfile.open("ordenado.txt", ios::out);
  
  Node *curr = head;
  while(curr != nullptr){
    if((curr->getData().key >= ipInicial) && (curr->getData().key <= ipFinal)) {
      outfile << curr->getData().mes << " " << curr->getData().dia  << " " << curr->getData().hora << " " << curr->getData().ip << curr->getData().problema << endl;
      cout << curr->getData().mes  << " " << curr->getData().dia  << " " << curr->getData().hora << " " << curr->getData().ip << curr->getData().problema << endl;
    }
    curr = curr->getNext();
  }
}