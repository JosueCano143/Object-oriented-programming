// A00829022

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

#define NOM_ARCHIVO "numerosComplejos.txt"

#include "Complejo.h"

int main() {

    // Calcular número de lineas
    FILE *myFile;
    int iCharacter, iLineas; 

    if ((myFile = fopen(NOM_ARCHIVO, "r")) == NULL) {
        perror (NOM_ARCHIVO);
    }

    iLineas = 1;
    while ((iCharacter = fgetc(myFile)) != EOF)
        if(iCharacter == '\n')
        iLineas++;
    
    fclose(myFile);

    // Manejo del array
    Complejo myArray[iLineas];
    ifstream entrada2("numerosComplejos.txt");

    Complejo total(0,0);

    int position = 0;
    double dNum1, dNum2;
    while(entrada2 >> dNum1 >> dNum2){
        Complejo registro(dNum1, dNum2);
        myArray[position] = registro;
        total = total.suma(registro);
        position++;
    }
    
    // Impresión de resultados
    for (int iK = 0; iK < iLineas; iK++) {
        myArray[iK].imprimir();
    }
    cout << "Suma: ";
    total.imprimir();

    return 0;
}