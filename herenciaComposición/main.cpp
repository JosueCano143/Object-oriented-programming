#include <iostream>
#include <fstream>

using namespace std;

#include "JugadorNFL.h"
#include "EntrenadorNFL.h"


int main() {
    JugadorNFL *listaJugador[5];
    EntrenadorNFL *listaEntrenador[2];
    FechaNacimiento date1(21, 11, 2000);
    FechaNacimiento date2(13, 03, 2001);

    listaJugador[0] = new JugadorNFL("nombre1", "equipo1", date1, 1, "universidad1", "posicion1");
    listaJugador[1] = new JugadorNFL("nombre2", "equipo2", date1, 2, "universidad2", "posicion2");
    listaJugador[2] = new JugadorNFL("nombre3", "equipo3", date1, 3, "universidad3", "posicion3");
    listaJugador[3] = new JugadorNFL("nombre4", "equipo4", date1, 4, "universidad4", "posicion4");
    listaJugador[4] = new JugadorNFL("nombre5", "equipo5", date1, 5, "universidad5", "posicion5");
    
    listaEntrenador[0] = new EntrenadorNFL("nombreEntrenador1", "team1", date2, "tipo1");
    listaEntrenador[1] = new EntrenadorNFL("nombreEntrenador2", "team1", date2, "tipo2");

    for (int iK=0; iK<5; iK++) {
        listaJugador[iK]->imprimeJugador();
    }
    for (int iK=0; iK<2; iK++) {
        listaEntrenador[iK]->imprimeEntrenador();
    }

    return 0;
}
