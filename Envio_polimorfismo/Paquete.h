#ifndef Paquete_h
#define Paquete_h

#include "Envio.h"

class Paquete : public Envio {
    public:    
        Paquete();    
        Paquete(Persona rem, Persona dest, double costoEs, double peso, double costoKg);   
        void setPeso(double peso) {this->peso = peso;}
        void setCostoKg(double costoKg) {this->costoKg = costoKg;}
        double getPeso() {return this->peso;}
        double getCostoKg() {return this->costoKg;}
        double calculaCostoEnvio(); 
        
    private:    
        double peso;
        double costoKg;
    };

Paquete::Paquete():Envio(){    
    peso = 0;
    costoKg = 0;
}

Paquete::Paquete(Persona rem, Persona dest, double costoEs, double peso, double costoKg):Envio(rem,dest,costoEs) {    
    this->peso = peso;
    if(peso < 0){
       this->peso = 0;
    }
    this->costoKg = costoKg;
    if (costoKg < 0){
        this->costoKg = 0;
    }
}


double Paquete::calculaCostoEnvio() {
    return costoEstandar + peso * costoKg;
}

#endif 