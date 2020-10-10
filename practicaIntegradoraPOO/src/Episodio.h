// Josue Salvador Cano Martinez | A00829022
// Programación orientada a objetos (c++)
// Proyecto integrador: Streaming 
// 05 Junio 2020

// Incluir librería
#include <iostream>
using namespace std;

#ifndef Episodio_h
#define Episodio_h

// Incluir la clase padre
#include "Video.h"

// Definir la clase a crear
class Episodio : public Video {
    // Atributos públicos
    public:    
        Episodio();    
        Episodio(int id, string nombre, string genero, int duracion, int calificacion, string director,
                string tituloSerie, int numeroEpisodio, int numeroTemporada); 
        // Métodos set  
        void setTituloSerie(string tituloSerie) {this->tituloSerie = tituloSerie;}
        void setNumeroEpisodio(int numeroEpisodio) {this->numeroEpisodio = numeroEpisodio;}
        void setNumeroTemporada(int numeroTemporada) {this->numeroTemporada = numeroTemporada;}
        // Métodos get
        int getNumeroEpisodio() {return numeroEpisodio;}
        int getNumeroTemporada() {return numeroTemporada;}
        string getTituloSerie() {return tituloSerie;}
        // Método imprimir 
        void imprimir(); 
    // Atributos privados
    private:    
        int numeroEpisodio;
        int numeroTemporada;
        string tituloSerie;
};

// Constructor sin parámetros
Episodio::Episodio():Video(){  
    tituloSerie = "-";
    numeroEpisodio = 0;
    numeroTemporada = 0;
}

// Constructor con parámetros
Episodio::Episodio(int id, string nombre, string genero, int duracion, int calificacion, string director,
                string tituloSerie, int numeroEpisodio, int numeroTemporada):Video(id, nombre, genero, duracion, calificacion, director) {    
   this->numeroEpisodio = numeroEpisodio;
   this->numeroTemporada = numeroTemporada;
   this->tituloSerie = tituloSerie;
}

// Método imprimir (despliega episodios)
void Episodio::imprimir() {
    cout << "Id: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Calificacion: " << calificacion << endl;
    cout << "El director del video es: " << director << endl; 
    cout << "Titulo de la serie: " << tituloSerie << endl;
    cout << "Numero de episodio: " << numeroEpisodio << endl;
    cout << "Numero de temporada: " << numeroTemporada << endl;
}

#endif 