#include "Node.h"
class BST{
	public:
		BST();
		~BST();
		void add(int data);
		bool search(int data);
		void remove(int data);
		void printPre();
		void printIn();
		void printPost();
		void printNivel();
		void printAncestors(int d);
		int size();
		void visit(int num);
		int height();
		void ancestors(int data, stack<int> &stk);
		int whatlevelamI(int data);
	private:
		NodeT *root;
		void preOrden(NodeT *r);
		void inOrden(NodeT *r);
		void postOrden(NodeT *r);
		void nivelOrden(NodeT *r);
		void destruye(NodeT *r);
		int howManyChildren(NodeT *r);
		int succ(NodeT *r);
		int pred(NodeT *r);
		int count(NodeT *r);
		int helper(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye(root);
}

void BST::destruye(NodeT *r){
	if (r != nullptr){
		destruye(r->getLeft());
		destruye(r->getRight());
		delete r;
	}
}

int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}


void BST::add(int data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr){
		if (curr->getData() == data){
			return;
		}
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (father == nullptr){
		root = new NodeT(data);
	}
	else{
/*
		if (father->getData() > data){
			father->setLeft(new NodeT(data));
		}
		else{
			father->setRight(new NodeT(data));
		}
*/
		father->getData() > data ? father->setLeft(new NodeT(data)) : 
								father->setRight(new NodeT(data));
	}

}

int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

void BST::remove(int data){
	NodeT *curr = root;
	NodeT *father = nullptr;
	while (curr != nullptr && curr->getData() != data){
		father = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == nullptr){
		return;
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos){
		case 0: if (father == nullptr){
					root = nullptr;
				}
				else{
					if (father->getData() > data){
						father->setLeft(nullptr);
					}
					else {
						father->setRight(nullptr);
					}
				}
				delete curr;
				break;
		case 1: if (father == nullptr){
					if (curr->getLeft() != nullptr){
						root = curr->getLeft();
					}
					else{
						root = curr->getRight();
					}
				}
				else{
					if (father->getData() > data){
						// quiero borrar al hijo izq del padre
						if (curr->getLeft() != nullptr){
							// único hijo esta a la izq.
							father->setLeft(curr->getLeft());
						}
						else{
							// único hijo esta a la der.
							father->setLeft(curr->getRight());
						}
					}
					else{
						// quiero borrar al hijo der del padre
						if (curr->getLeft() != nullptr){
							// único hijo esta a la izq.
							father->setRight(curr->getLeft());
						}
						else{
							// único hijo esta a la der.
							father->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2: int sucesor = succ(curr);
				remove(sucesor);
				curr->setData(sucesor);
				break;
	}
}


bool BST::search(int data){
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){
			return true;
		}
/*
		if (curr->getData() > data){
			curr = curr->getLeft();
		}
		else{
			curr = curr->getRight();
		}
*/
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;
}

// Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

// Complejidad: O(n)
void BST::printPre(){
	preOrden(root);
	cout << endl;
}

//Complejidad: O(n)
int BST::count(NodeT *r){
	if (r == nullptr){
		return 0;
	}
	return 1 + count(r->getLeft()) + count(r->getRight());
}

// Complejidad: O(n)
int BST::size(){
	return count(root);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////// TAREA ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int BST::helper(NodeT *r){
	if(r == nullptr){
		return 0;
	} else {
		int lHeight = helper(r->getLeft());
		int rHeight = helper(r->getRight());

		if(lHeight > rHeight){
			return lHeight + 1;
		} else {
			return rHeight + 1;
		}
	}
}

int BST::height(){
	return helper(root);
}

void BST::ancestors(int data, stack<int> &stk){
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){
			return;
		}
		if (curr->getData() > data){
			stk.push(curr->getData());
			curr = curr->getLeft();
		}
		else{
			stk.push(curr->getData());
			curr = curr->getRight();
		}

	}
}

void BST::printAncestors(int d){
	stack<int> stk;
	ancestors(d, stk);
	while (!stk.empty()) {
		int n = stk.top();
		cout << n << " ";
		stk.pop();
	}
	
}

int BST::whatlevelamI(int data){
	NodeT *curr = root;
	int c = 0;
	while (curr != nullptr){
		if (curr->getData() == data){
			c++;
			return c;
		}
		if (curr->getData() > data){
			c++;
			curr = curr->getLeft();
		}
		else{
			c++;
			curr = curr->getRight();
		}

	}
	return -1;
}

void BST::visit(int num){
	int opcion;
	cin >> opcion;
	switch (opcion) {
	case 1:
		printPre();
		break;
	case 2:
		printIn();
		break;
	case 3:
		printPost();
		break;
	case 4:
		
		break;
	
	default:
		break;
	}
}

// Complejidad: O(n)
void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

// Complejidad: O(n)
void BST::printIn(){
	inOrden(root);
	cout << endl;
}

// Complejidad: O(n)
void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

// Complejidad: O(n)
void BST::printPost(){
	postOrden(root);
	cout << endl;
}

// Complejidad: O(n)
void BST::nivelOrden(NodeT *r){
	queue<NodeT*> Q;
	if(root == NULL) return;
    Q.push(root);
    while(!Q.empty()) {
        NodeT *current = Q.front();
        cout<< current->getData() << " ";
        if(current->getLeft() != NULL) Q.push(current->getLeft());
        if(current->getRight() != NULL) Q.push(current->getRight());
        Q.pop();
    }
}


// Complejidad: O(n)
void BST::printNivel(){
	nivelOrden(root);
}