// Empleado.h
// DeptoEmpleaos

#ifndef Empleado_h
#define Empleado_h

#include <iostream>
#include <fstream>
using namespace std;

class Empleado {
    public:
        Empleado(int i, string n, int nuD);
        Empleado();
        void setNumEmp(int i);
        void setNombre(string n);
        void setNumDepto(int d);
        int getNumEmp();
        string getNombre();
        int getNumDepto();
    private:
        int numEmp;
        string nombre; 
        int numDepto;
};

Empleado::Empleado(int i, string n, int nuD){
    numEmp = i;
    nombre = n;
    numDepto = nuD;
}

Empleado::Empleado(){
    numEmp = 0;
    nombre = "";
    numDepto = 0; 
}

void Empleado::setNumEmp(int i){
    numEmp = i;
}
void Empleado::setNombre(string n){
    nombre = n;
}
void Empleado::setNumDepto(int d){
    numDepto = d;
}
int Empleado::getNumEmp(){
    return numEmp;
}
string Empleado::getNombre(){
    return nombre;
}
int Empleado::getNumDepto(){
    return numDepto;
}

#endif /* Empleado_h */