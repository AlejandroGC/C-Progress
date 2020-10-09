#include "Node.h"

class BST{
    public:
        BST();
        ~BST();
        void add(int data);
        bool search(int data);
        void printPre();
    private:
        NodeT *root;
        void preOrden(NodeT *r);
        void destruye(NodeT *r);
};

BST::BST(){
    root = nullptr;
}

BST::~BST(){
    destruye(root);
}

void BST::destruye(NodeT *r){
    if(r != nullptr){
        destruye(r->getLeft());
        destruye(r->getRight());
        delete r;
    }
}

void BST::add(int data){
    NodeT *curr = root;
    NodeT *father = nullptr;
    while(curr != nullptr){
        if(curr->getData() == data){
            return;
        }
        father = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    if(father == nullptr){
        root = new NodeT(data);
    } else {
        // if(father->getData() > data){
        //     father->setLeft(new NodeT(data));
        // } else {
        //     father->setRight(new NodeT(data));
        // }
        father->getData() > data ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
    }
}

bool BST::search(int data){
    NodeT *curr = root;
    while(curr != nullptr){
        if(curr->getData() == data){
            return true;
        }
        // if(curr->getData() > data){
        //     curr = curr->getLeft();
        // } else {
        //     curr = curr->getRight();
        // }

        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::preOrden(NodeT *r) {
    if(r != nullptr){
        cout << r->getData() << " ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}

void BST::printPre(){
    preOrden(root);
    cout << endl;
}