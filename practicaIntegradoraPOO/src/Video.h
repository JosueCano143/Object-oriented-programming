// Josue Salvador Cano Martinez | A00829022
// Programación orientada a objetos (c++)
// Proyecto integrador: Streaming 
// 05 Junio 2020

// Incluir librerías
#include <iostream>
using namespace std;

#ifndef Video_h
#define Video_h

// Definir la clase
class Video {
    // Atributos públicos
    public:
        Video();
        Video(int id, string nombre, string genero, int duracion, int calificacion, string director);
        // Métodos set
        void setId(int id) {this->id = id;}
        void setNombre(string nombre) {this->nombre = nombre;}
        void setGenero(string genero) {this->genero = genero;}
        void setDuracion(int duracion) {this->duracion = duracion;}
        void setCalificacion(int calificacion) {this->calificacion = calificacion;}
        void setDirector(string director) {this->director = director;}
        // Métodos get
        int getId() {return id;}
        string getNombre() {return nombre;}
        string getGenero() {return genero;}
        int getDuracion() {return duracion;}
        int getCalificacion() {return calificacion;}
        string getDirector() {return director;}
        // Método pure virtual  
        virtual void imprimir() = 0;
    // Atributos protected
    protected:
        int id;
        string nombre;
        int duracion;
        string genero; 
        int calificacion; 
        string director;

};

// Constructor sin parámetros
Video::Video() {
    id = 0;
    nombre = "-";
    genero = "-";
    duracion = 0;
    calificacion = 0;
    director = "-";

}

// Constructor con parámetros
Video::Video(int id, string nombre, string genero, int duracion, int calificacion, string director) {
    this->id = id;
    this->nombre = nombre;
    this->genero = genero;
    this->duracion = duracion;
    this->calificacion = calificacion; 
    this->director = director;
}

#endif