struct datos {
    long key;
    string mes;
    string dia;
    string hora;
    string ip;
    string problema;
};

class Node {
    public:
      Node(datos data);
      Node(datos data, Node *prev, Node *next);
      datos getData();
      Node* getNext();
      Node* getPrev();
      void setData(datos data);
      void setNext(Node *next);
      void setPrev(Node *prev);
    private:
      datos data;
      Node *prev;
      Node *next;
};

Node::Node(datos data){
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
}

Node::Node(datos data, Node *prev, Node *next){
    this->data = data;
    this->prev = prev;
    this->next = next;
}

datos Node::getData(){
    return data;
}

Node* Node::getNext(){
    return next;
}

Node* Node::getPrev(){
    return prev;
}

void Node::setData(datos data){
    this->data = data;
}

void Node::setNext(Node *next){
    this->next = next;
}

void Node::setPrev(Node *prev){
    this->prev = prev;
}