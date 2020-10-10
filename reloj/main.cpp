//Author: Josue Salvador Cano Martinez
//Date: 20/11/2019
//ID: A00829022

#include <iostream>
//Incluir la clase creada
#include "RelojD.h"
#include <string>
using namespace std;

//Crear el menú de opciones para el usuario
int menu()
{
  int iChoice;
  
  cout << "1. Crear objeto\n";
  cout << "2. Set Hora\n";
  cout << "3. Set Minutnos\n";
  cout << "4. Get Hora\n";
  cout << "5. Get Minutos\n";
  cout << "6. Incrementar Minutos\n";
  cout << "7. Desplegar\n";
  cout << "8. Salir\n";
  cout << "Escriba el número de la opción a ejecutar:";
  cin >> iChoice;
  //Ciclo centinela en caso de que la opción elegida no esté en el rango
  while(iChoice < 1 || iChoice > 8)
  {
    cout << "Error, la opción no existe";
    cout<<"Ingrese un valor válido:";
    cin>> iChoice;
  }
  return iChoice;
}

//Función principal
int main() {
  //Crear el objeto clock usando el	constructor	default
  RelojD clock;
  //Leer la opción ingresada por el usuario
  int iChoice = menu();

  //Ciclo centinela que termina el programa cuando se teclea 8
  while(iChoice != 8)
  {
    //Crear el objeto
    if(iChoice == 1)
    {
      RelojD clock;
    }
    //Ingresar la hora
    else if (iChoice == 2)
    {
      int iHour;
      cout << "Ingrese la hora: ";
      cin >> iHour;
      clock.setHora(iHour);
    }
    //Ingresar los minutos
    else if (iChoice == 3)
    {
      int iMinutes;
      cout << "Ingrese los minutos: ";
      cin >> iMinutes;
      clock.setMin(iMinutes);
    }
    //Desplegar las horas llamando al método getHora
    else if (iChoice == 4)
    {
      cout << clock.getHora() << endl;
    }
    //Desplegar los minutos llamando al método getMin
    else if (iChoice == 5)
    {
      cout << clock.getMin() << endl;
    }
    //Llamar al método incrementaMinutos para incrementar el tiempo
    else if (iChoice == 6)
    {
      clock.incrementaMinutos();
    }
    //Desplegar la hora en formato 00:00 
    else if (iChoice == 7)
    {
      cout << clock.muestra();
    }
    iChoice = menu();
  }
  return 0;
}