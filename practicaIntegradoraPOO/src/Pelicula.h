// Josue Salvador Cano Martinez | A00829022
// Programación orientada a objetos (c++)
// Proyecto integrador: Streaming 
// 05 Junio 2020

// Incluir librería
#include <iostream>
using namespace std;

#ifndef Pelicula_h
#define Pelicula_h

// Incluir la clase padre
#include "Video.h"

// Definir la clase
class Pelicula : public Video {
    // Atributos públicos
    public:    
        Pelicula();    
        Pelicula(int id, string nombre, string genero, int duracion, int calificacion, string director);  
        void imprimir(); 
    // Atributos privados 
    private:    

};

// Constructor sin parámetros
Pelicula::Pelicula(){

}

// Constructor con parámetros 
Pelicula::Pelicula(int id, string nombre, string genero, int duracion, int calificacion, string director):Video(id, nombre, genero, duracion, calificacion, director){
    
}

// Método imprime para películas
void Pelicula::imprimir() {
    cout << "Id: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "El director del video es: " << director << endl;
}

#endif 