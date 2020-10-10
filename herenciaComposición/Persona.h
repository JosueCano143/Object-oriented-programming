#include <iostream>

#ifndef Persona_h
#define Persona_h
#include "FechaNacimiento.h"

using namespace std;

class Persona{
    public:
        Persona();
        Persona(string name, string team, FechaNacimiento dateBorn);
        void setNombre(string name) {this->name = name;}
        void setEquipo(string team) {this->team = team;}
        void setFechaNacimiento(FechaNacimiento dateBorn){this->dateBorn = dateBorn;}
        string getNombre() {return name;};
        string getEquipo() {return team;};
        FechaNacimiento getFechaNacimiento() {return dateBorn;};
        void imprimePersona();

    protected:
        string name;
        string team; 
        FechaNacimiento dateBorn;

};

Persona::Persona(){
    FechaNacimiento dateBorn1;
    name = "N/A";
    team = "N/A";
    dateBorn = dateBorn1;
}

Persona::Persona(string name, string team, FechaNacimiento dateBorn) {
    this->name = name;
    this->team = team;
    this->dateBorn = dateBorn;
}

void Persona::imprimePersona(){
    cout << "Nombre: " << name << "\t";   
    cout << "Equipo: " << team << "\t"; 
    cout << "Fecha de nacimiento: "; 
    dateBorn.imprimeFechaNac();

}

#endif