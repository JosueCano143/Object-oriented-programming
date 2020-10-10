#include <iostream>
#ifndef FechaNacimiento_h
#define FechaNacimiento_h

using namespace std;

class FechaNacimiento {
    private:
        int dia;
        int mes;
        int anio;
    public:
        FechaNacimiento();
        FechaNacimiento(int day, int month, int year);
        void setDia(int day) {dia = day;}
        void setMes(int month) {mes = month;}
        void setAnio(int year) {anio = year;}
        int getDia() {return dia;}
        int getMes() {return mes;}
        int getAnio() {return anio;}
        void imprimeFechaNac();
};

FechaNacimiento::FechaNacimiento(){
    dia = 0;
    mes = 0;
    anio = 0;
}

FechaNacimiento::FechaNacimiento(int day, int month, int year) {
    dia = day;
    mes = month;
    anio = year;
}

void FechaNacimiento::imprimeFechaNac(){
    cout << "Día:" << dia << "\t";   
    cout << "Mes:" << mes << "\t";   
    cout << "Año:" << anio << "\t"; 
}

#endif