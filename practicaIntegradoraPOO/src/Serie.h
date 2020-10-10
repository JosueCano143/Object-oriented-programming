// Josue Salvador Cano Martinez | A00829022
// Programación orientada a objetos (c++)
// Proyecto integrador: Streaming 
// 05 Junio 2020

// Incluir librerías
#include <iostream>
using namespace std;

#ifndef Serie_h
#define Serie_h

#include "Episodio.h"

// Definir clase a crear
class Serie {
    // Atributos públicos
    public:
        Serie();
        Serie(string titulo);
        // Métodos set
        void setTitulo(string titulo) {this->titulo = titulo;}
        void setNumTemporadas(int numTemporadas) {this->numTemporadas = numTemporadas;}
        // Métodos get
        string getTitulo() {return titulo;}
        int getNumTemporadas() {return numTemporadas;}
        void getArrEpisodios(Episodio *arr[], int &size);
        // Método para agregar episodios
        bool agregaEpisodio(Episodio *episodio);
        // Método para imprimir
        void imprimir();

    // Atributos privados
    private:
        string titulo;
        int numTemporadas;
        Episodio *arrEpisodios[50];
};

// Constructor sin parámetros
Serie::Serie() {
    titulo = "-";
    numTemporadas = 0;

}

// Constructor con parámetros
Serie::Serie(string titulo) {
    this->titulo = titulo;
    this->numTemporadas = 0;
}

// Booleano para agregar episodios
bool Serie::agregaEpisodio(Episodio *episodio){
    if (numTemporadas < 50){
        arrEpisodios[numTemporadas++] = episodio;
        return true;
    }
    else {
        return false;
    }
}

// Método get para arreglo de episodios
void Serie::getArrEpisodios(Episodio *arr[], int &size){
    for (int i=0; i<numTemporadas; i++){
        arr[i] = arrEpisodios[i];
    }
    size = numTemporadas;
}

// Método imprimir (despliega los episodios de una serie)
void Serie::imprimir(){
    cout << "Serie: " << titulo << endl;
    for (int i=0; i<numTemporadas; i++)
        cout << arrEpisodios[i]->getNombre()<<endl; 
}

#endif