#include <iostream>
#include <fstream>

using namespace std;

#include "Sobre.h"
#include "Paquete.h"
#include "Persona.h"


int main() {
    char tipoEnvio;
    int cantEnvios = 0;
    double costoEstandar, peso, costoKg;
    double largo, ancho, cargoAd;
    string nombreR, estadoR, ciudadR, cpR;
    string nombreD, estadoD, ciudadD, cpD;

    ifstream file("datosEnvios.txt");
    Envio *listaEnvios[10];

    while (file >> tipoEnvio) {
        if (tipoEnvio == 'p') {
            file >> nombreR >> estadoR >> ciudadR >> cpR >> nombreD >> estadoD >> ciudadD >> cpD >> costoEstandar  >> peso >> costoKg;
            Persona rem(nombreR, estadoR, ciudadR, cpR);
            Persona dest(nombreD, estadoD, ciudadD, cpD);
            listaEnvios[cantEnvios++] = new Paquete(rem, dest, costoEstandar, peso, costoKg);
        }
        else {
            file >> nombreR >> estadoR >> ciudadR >> cpR >> nombreD >> estadoD >> ciudadD >> cpD >> costoEstandar  >> largo >> ancho >> cargoAd;
            Persona rem(nombreR, estadoR, ciudadR, cpR);
            Persona dest(nombreD, estadoD, ciudadD, cpD);
            listaEnvios[cantEnvios++] = new Sobre(rem, dest, costoEstandar, largo, ancho, cargoAd);
        }
    }

    int total = 0;
    for(int iK = 0; iK < cantEnvios; iK++){
        cout << "Remitente: " << endl;
        Persona remi =  listaEnvios[iK]->getRemitente();
        remi.imprimir();

        cout << "Destinatario: " << endl;
        Persona desti =  listaEnvios[iK]->getDestinatario();
        desti.imprimir();

        cout << "Costo: ";
        cout << listaEnvios[iK]->calculaCostoEnvio() << endl;
        total += listaEnvios[iK]->calculaCostoEnvio();
    }
    cout << "Total envios: " << total;

    return 0;
}




