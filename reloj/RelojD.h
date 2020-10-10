#include <iostream>
#include <string>
using namespace std;

class RelojD
{
  public: 
    // Método constructor
    RelojD();
    RelojD(int, int);

    //Metodos modificadores
    void setHora(int);
    void setMin(int);

    //Metodos de acceso
    int getHora();
    int getMin();

    //Otros Metodos
    void incrementaMinutos();
    string muestra();
  
  //Atributos privados
  private:
    int iMinutos, iHoras;   
};

RelojD :: RelojD()
{
  iMinutos = 0;
  iHoras = 0;
}

RelojD :: RelojD(int iHoras, int iMinutos)
{
  if( (iMinutos >= 0 && iMinutos < 60) && (iHoras >= 0 && iHoras < 24) )
  {
    this-> iMinutos = iMinutos;
    this-> iHoras = iHoras;
  }
  else
  {
    this-> iMinutos = 0;
    this-> iHoras = 0;
  }
}

//Método que recibe y asigna un valor entero al atributo iHoras
//además valida su rango entre 0...23
void RelojD :: setHora(int iHoras)
{
  if(iHoras >= 0 && iHoras < 24)
  {
    this-> iHoras = iHoras;
  }
}

//Método que recibe y asigna un valor entero al atributo iMinutos
//además valida su rango entre 0...59
void RelojD :: setMin(int iMinutos)
{
  if(iMinutos >= 0 && iMinutos < 60)
  {
    this-> iMinutos = iMinutos;
  }
}

//Método que retorna el valor del atributo iHoras
int RelojD :: getHora()
{
  return iHoras;
}

//Método que retorna el valor del atributo iMinutos
int RelojD :: getMin()
{
  return iMinutos;
}

//Método que despliega la hora en formato usual
string RelojD :: muestra()
{
  if( iMinutos > 9 && iHoras > 9)
  {
    return to_string(iHoras) + ":" + to_string(iMinutos)+"\n";
  }
  else if(iMinutos < 10 && iHoras < 10)
  {
    return "0" + to_string(iHoras) + ":" + "0" + to_string(iMinutos)+"\n";
  }
  else if(iMinutos < 10 && iHoras > 9)
  {
    return to_string(iHoras) + ":" + "0" + to_string(iMinutos)+"\n";
  }
  else if(iMinutos > 9 && iHoras < 10)
  {
    return "0" + to_string(iHoras) + ":" + to_string(iMinutos)+"\n";
  }
}

//Función que incrementa atributo iMinutos en 1
//Genera la actualización de horas a horas+1 al ser 60 el valor de minutos
//Genera la actualización de horas a 0 al ser 23 el valor anterior de horas
void RelojD :: incrementaMinutos()
{
  int updated = iMinutos + 1;
  if(updated == 60)
  {
    iMinutos = 0;
    iHoras = iHoras + 1;

    if(iHoras ==24)
    {
      iHoras = 0;
    }
  }
  else
  {
    iMinutos = iMinutos + 1; 
  }
}

