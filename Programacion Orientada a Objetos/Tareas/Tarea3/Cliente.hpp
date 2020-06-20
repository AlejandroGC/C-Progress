//clase Cliente
#ifndef Cliente_hpp
#define Cliente_hpp
#include <string>

using namespace std;

class Cliente {
public:
    string nombre, direccion, ciudad, estado, codigoPostal;
    Cliente();
    Cliente(string,string,string,string,string);
    string str();
};

Cliente::Cliente() {
    nombre = "Ivan Ramirez";
    direccion = "Pamplona 211, Bosques de las Cumbres";
    ciudad = "Monterrey";
    estado = "N.L.";
    codigoPostal = "64619";
}

Cliente::Cliente(string nombre, string direccion, string ciudad, string estado, string codigoPostal) {
    this->nombre=nombre;
    this->direccion=direccion;
    this->ciudad=ciudad;
    this->estado=estado;
    this->codigoPostal=codigoPostal;
}

string Cliente::str() {
   return "\nNombre: " + nombre + "\nDireccion: " + direccion + "\nCiudad " + ciudad + ", " + estado + "\nCodigo Postal: " + codigoPostal + "\n";
}

#endif