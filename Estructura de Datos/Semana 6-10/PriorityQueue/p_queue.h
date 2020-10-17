// Alejandro Daniel González Carrillo
// A01570396
// Act 3.2 - Árbol Heap: Implementando una fila priorizada

class Pqueue{
    public:
        Pqueue();
        void push(int dato);
        void pop();
        int top();
        bool empty();
        int size();
        void print();

    private:
        vector<int> datos;
};

// Descripcion: Constructor
// Complejidad: O(1)
Pqueue::Pqueue(){
    datos.push_back(-1010101010);
}

// Descripcion: Agregue un dato a la fila priorizada.
// Complejidad: O(log(n))
void Pqueue::push(int dato){
    datos.push_back(dato);
    int idx = size();
    while(idx != 1 && datos[idx] > datos[idx/2]){
        int temp = datos[idx];
        datos[idx] = datos[idx/2];
        datos[idx/2] = temp;
        idx = idx/2;
    }
}

// Descripcion: Saca de la fila priorizada el dato que tiene mayor prioridad.
// Complejidad: O(log(n))
void Pqueue::pop(){
    int n = size();
    datos[1] = datos[n];
    datos.pop_back();
    bool sigo = true;
    int idx = 1;
    while(idx*2 <= n && sigo){
        int idxMayor = idx*2;
        if(idxMayor+1 <= n){
            if(datos[idxMayor] < datos[idxMayor+1]){
                idxMayor++;
            }
        }
        if(datos[idxMayor] > datos[idx]){
            swap(datos[idx], datos[idxMayor]);
            idx = idxMayor;
        } else {
            sigo = false;
        }
    }
}

// Descripcion: Regresa el valor del dato que esta con mayor prioridad en la fila priorizada.
// Complejidad: O(1)
int Pqueue::top(){
    return datos[1];
}

// Descripcion: Regresa un valor boleando diciendo si la fila priorizada esta vacía o tiene datos.
// Complejidad: O(1)
bool Pqueue::empty(){
    return size() == 0;
}

// Descripcion: Regresa la cantidad de datos que tiene la fila priorizada.
// Complejidad: O(1)
int Pqueue::size(){
    return datos.size()-1;
}

// Descripcion: Imprime los valores dentro de la lista priorizada.
// Complejidad: log(n)
void Pqueue::print(){
    while(!empty()){
        cout << top() << " ";
        pop();
    }
}