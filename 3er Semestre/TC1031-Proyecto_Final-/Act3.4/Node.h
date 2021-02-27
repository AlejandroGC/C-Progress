class NodeT {
    public:
        NodeT(long ip, int rep, string ipString);
        NodeT(long ip, int rep, string ipString, NodeT *left, NodeT *right);
        long getIp();
        void setIp(long ip);
        int getRep();
        void setRep(int rep);
        NodeT *getLeft();
        void setLeft(NodeT *left);
        NodeT *getRight();
        void setRight(NodeT *right);
        string getIpString();
        void setIpString(string ipString);
    private:
        string ipString;
        long ip;
        int rep;
        NodeT *left;
        NodeT *right;
};

NodeT::NodeT(long ip, int rep, string ipString){
  this->ip = ip;
  this->rep = rep;
  this->ipString = ipString;
  this->left = nullptr;
  this->right = nullptr;
}

NodeT::NodeT(long ip, int rep, string ipString, NodeT *left, NodeT *right){
  this->ip = ip;
  this->rep = rep;
  this->ipString = ipString;
  this->left = left;
  this->right = right;
}

long NodeT::getIp(){
  return ip;
}

void NodeT::setIp(long ip){
  this->ip = ip;
}

int NodeT::getRep(){
  return rep;
}

void NodeT::setRep(int rep){
  this->rep = rep;
}

NodeT* NodeT::getLeft(){
  return left;
}

void NodeT::setLeft(NodeT *left){
  this->left = left;
}

NodeT* NodeT::getRight(){
  return right;
}

void NodeT::setRight(NodeT *right){
  this->right = right;
}

string NodeT::getIpString(){
  return ipString;
}

void NodeT::setIpString(string ipString){
  this->ipString = ipString;
}