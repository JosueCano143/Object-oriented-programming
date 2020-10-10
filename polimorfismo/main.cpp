#include <iostream>
#include <fstream>

using namespace std;

#include "JugadorNFL.h"
#include "EntrenadorNFL.h"


int main() {
    Persona *lista[5];
    int cantPersonas = 0;
    string name, team, position, kind; 
    int day, month, year, number; 
    char tipo;
    ifstream archivo;
    archivo.open("data.txt");

    while(archivo >> tipo){
        if (tipo == 'j'){
            archivo >> name >> team >> day >> month >> year >> number >> position;
            FechaNacimiento date1(day, month, year); 
            lista[cantPersonas++] = new JugadorNFL(name, team, date1, number, position);
        }
        else{
            archivo >> name >> team >> day >> month >> year >> kind;
            FechaNacimiento date1(day, month, year); 
            lista[cantPersonas++] = new EntrenadorNFL(name, team, date1, kind);
        }

    }
    archivo.close();

    for (int iK=0; iK<5; iK++) {
        lista[iK]->imprime();
    }

    return 0;
}
