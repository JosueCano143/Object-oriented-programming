#include <iostream>
#ifndef EntrenadorNFL_h
#define EntrenadorNFL_h

#include "Persona.h"

using namespace std;

class EntrenadorNFL : public Persona{
    private:
        string tipo;
    public:
        EntrenadorNFL();
        EntrenadorNFL(string name, string team, FechaNacimiento dateBorn, string kind);
        void setTipo(int kind) {tipo = kind;}
        string getTipo() {return tipo;}
        void imprime();
};

EntrenadorNFL::EntrenadorNFL():Persona(){
    tipo = "-";
}

EntrenadorNFL::EntrenadorNFL(string name, string team, FechaNacimiento dateBorn, string kind) : Persona(name, team, dateBorn) {
    tipo = kind; 
}

void EntrenadorNFL::imprime(){ 
    cout << "Nombre: " << name << "\t";   
    cout << "Equipo: " << team << "\t";  
    cout << "Fecha de nacimiento: "; 
    dateBorn.imprimeFechaNac();
    cout << "Tipo: " << tipo << endl;   
}

#endif