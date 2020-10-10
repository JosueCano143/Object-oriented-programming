
#ifndef Envio_h
#define Envio_h

#include "Persona.h"

class Envio {
protected:
    Persona remitente;
    Persona destinatario;
    double costoEstandar;
public:
    Envio();
    Envio(Persona rem, Persona dest, double costoEs);
    void setRemitente(Persona rem) {remitente = rem;}
    void setDestinatario(Persona dest) {destinatario = dest;}
    Persona getRemitente() {return remitente;}
    Persona getDestinatario() {return destinatario;}
    virtual double calculaCostoEnvio() = 0;

};

Envio::Envio() {
    Persona rem;
    Persona dest;
    remitente = rem;
    destinatario = dest;
    costoEstandar = 0;
}

Envio::Envio(Persona rem, Persona dest, double costoEs) {
    remitente = rem;
    destinatario = dest;
    costoEstandar = costoEs;

}

#endif