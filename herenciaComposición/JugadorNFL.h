#include <iostream>
#ifndef JugadorNFL_h
#define JugadorNFL_h

#include "Persona.h"

using namespace std;

class JugadorNFL : public Persona{
    private:
        int numero;
        string universidad;
        string posicion;
    public:
        JugadorNFL();
        JugadorNFL(string name, string team, FechaNacimiento dateBorn, int number, string university, string position);
        void setNumero(int number) {numero = number;}
        void setUniversidad(int university) {universidad = university;}
        void setPosicion(int position) {posicion = position;}
        int getNumero() {return numero;}
        string getUniversidad() {return universidad;}
        string getPosicion() {return posicion;}
        void imprimeJugador();
};

JugadorNFL::JugadorNFL():Persona(){
    numero = 0;
    universidad = "-";
    posicion = "-";
}

JugadorNFL::JugadorNFL(string name, string team, FechaNacimiento dateBorn, int number, string university, string position) : Persona(name, team, dateBorn) {
    numero = number;
    universidad = university;
    posicion = position;
}

void JugadorNFL::imprimeJugador(){
    cout << "Nombre: " << name << "\t";   
    cout << "Equipo: " << team << "\t";  
    cout << "Fecha de nacimiento: "; 
    dateBorn.imprimeFechaNac();
    cout << "Número: " << numero << "\t";   
    cout << "Universidad: " << universidad << "\t";    
    cout << "Posición: " << posicion << endl; 
}

#endif