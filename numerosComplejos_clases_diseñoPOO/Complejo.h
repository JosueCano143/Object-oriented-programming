// A00829022

#ifndef Complejo_h
#define Complejo_h
#include <iostream>

using namespace std; 

class Complejo {
    private:
        double real;
        double imaginario;
    public:
        Complejo();
        Complejo(double real, double imaginario);
        double getReal();
        double getImaginario();
        Complejo suma(Complejo suma);
        void setReal(double r);
        void setImaginario(double i);
        void imprimir();

};

Complejo::Complejo() {
    real = 0;
    imaginario = 0;
}

Complejo::Complejo(double real, double imaginario) {
    this->real = real;
    this->imaginario = imaginario; 
}

double Complejo::getReal() {
    return real;
}
double Complejo::getImaginario() {
    return imaginario; 
}
void Complejo::setReal(double r) {
    real = r;
}
void Complejo::setImaginario(double i) {
    imaginario = i;
}

Complejo Complejo::suma(Complejo n2) {
    Complejo resultado;
    resultado.real = real + n2.real;
    resultado.imaginario = imaginario + n2.imaginario;
    
    return resultado;
}

void Complejo::imprimir() {
cout << real << " + " << imaginario << "i"<< endl;
}

#endif