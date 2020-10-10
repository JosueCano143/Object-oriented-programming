#include <iostream>
#include <string>

using namespace std;

#ifndef Persona_h
#define Persona_h


class Persona {
private:
    string nombre;
    string estado;
    string ciudad;
    string cp;
public:
    Persona();
    Persona(string nombre, string estado, string ciudad, string cp);
    void imprimir();
};

Persona::Persona() {
    nombre = "-";
    estado = "-";
    ciudad = "-";
    cp = "-";
}

Persona::Persona(string nom, string edo, string cd, string c) {
    nombre = nom;
    estado = edo;
    ciudad = cd;
    cp = c;
}

void Persona::imprimir() {
    cout << "Nombre: " << nombre << endl;
    cout << "Dirección: " << estado << " " << ciudad << " "<< cp<< endl;
 }

#endif