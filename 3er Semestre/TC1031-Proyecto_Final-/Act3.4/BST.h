#include "Node.h"

class BST{
	public:
		BST();
		~BST();
		void add(long ip, int rep, string ipString);
    void inOrden(NodeT *r, int &c);
    void printIn();
    void destruye(NodeT *r);
	private:
		NodeT *root;
};

// Descripcion: El contructor
BST::BST(){
  root = nullptr;
}

// Descripcion: El destructor
BST::~BST(){
  destruye(root);
}

// Complejidad: O(n)
// Descripcion: Itera por todo el arbol y va borrando cada nodo.
void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

// Complejidad: O(n)
// Descripcion: Añade un nodo con sus atributos accesos, ip (valor long) y ip (sin puerto) al arbol.
void BST::add(long ip, int rep, string ipString){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
    father = curr;
		if(curr->getRep() > rep){
      curr = curr->getLeft();
    } else if(curr->getRep() < rep){
      curr = curr->getRight();
    } else {
      curr = (curr->getIp() > ip) ? curr->getRight() : curr->getLeft();
    }
	}
	if (father == nullptr){
		root = new NodeT(ip,rep, ipString);
	} else {
    if(father->getRep() > rep) {
      father->setLeft(new NodeT(ip, rep, ipString));
    } else if (father->getRep() < rep) {
      father->setRight(new NodeT(ip, rep, ipString));
    } else {
      (father->getIp() > ip) ? father->setRight(new NodeT(ip, rep, ipString)) : father->setLeft(new NodeT(ip, rep, ipString));
    }
	}
}

// Complejidad: O(n)
// Descripcion: Recorre todo el arbol de manera de inOrden y despliega del arbol los 5 ips con mas accesos y si son iguales los accesos imprime primero el de ip menor.
void BST::inOrden(NodeT *r, int &c) {
	if(r != nullptr){
    inOrden(r->getRight(), c);
    if(c++ < 5){
      cout << c << ": " << r->getIpString() << " " << r->getRep() << endl;
    }
    inOrden(r->getLeft(), c);
	}
}

// Complejidad: O(n)
// Descripcion: Imprime la funcion inOrden
void BST::printIn(){
  int c = 0;
	inOrden(root, c);
}