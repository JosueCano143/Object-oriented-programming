// A00829022

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "Fraccion.h"

int main() {
    // Lectura del archivo de texto
   ifstream file("operaciones.txt");

    // Declaración de variables 
   int iOperation, iNumerator1, iDenominator1, iNumerator2, iDenominator2, iRenglon;

   // Obtener tamaño de vector
   file >> iRenglon; 
   Fraccion vecFrac[iRenglon];

   // Leer datos del vector 
   for (int iK = 0; iK < iRenglon; iK++) {
       file >> iOperation >> iNumerator1 >> iDenominator1 >> iNumerator2 >> iDenominator2;
       Fraccion fraction1(iNumerator1, iDenominator1);
       Fraccion fraction2(iNumerator2, iDenominator2);
       //Realización de operaciones correspondientes y asignación al arreglo creado
       if (iOperation == 1) {
           vecFrac[iK] = fraction1.suma(fraction2);
       }
        else { 
           vecFrac[iK] = fraction1.multiplicacion(fraction2);
       } 
   }
   
   // Imprimir el resultado 
   for (int iK = 0; iK < iRenglon; iK++) {
       vecFrac[iK].imprimir();
   }

    return 0;
}

