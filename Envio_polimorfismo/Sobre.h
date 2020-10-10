#ifndef Sobre_h
#define Sobre_h

#include "Envio.h"

class Sobre : public Envio {
    public:    
        Sobre();    
        Sobre(Persona rem, Persona dest, double costoEs, double largo, double ancho, double cargoAdicional);   
        void setLargo(double largo) {this->largo = largo;}
        void setAncho(double ancho) {this->ancho = ancho;}
        void setCargoAdicional(double cargoAdicional) {this->cargoAdicional = cargoAdicional;}
        double getLargo() {return this->largo;}
        double getAncho() {return this->ancho;}
        double getCargoAdicional() {return this->cargoAdicional;}
        double calculaCostoEnvio(); 
        
    private:    
        double largo;
        double ancho;
        double cargoAdicional;
    };

Sobre::Sobre():Envio(){    
    largo = 0;
    ancho = 0;
    cargoAdicional = 0;
}

Sobre::Sobre(Persona rem, Persona dest, double costoEs, double largo, double ancho, double cargoAdicional):Envio(rem,dest,costoEs) {    
    this->largo = largo;
    if(largo < 0){
        largo = 0;
    }
    this->ancho = ancho;
    if (ancho < 0){
        ancho = 0;
    }
    this->cargoAdicional = cargoAdicional;
    if (cargoAdicional < 0){
        cargoAdicional = 0;
    }
}

double Sobre::calculaCostoEnvio() {
    if(largo > 25 && ancho > 30){
        return costoEstandar + cargoAdicional;
    }
    else {
        return costoEstandar;
    }
}

#endif 