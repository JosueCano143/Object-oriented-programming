// Josue Salvador Cano Martinez | A00829022
// Programación orientada a objetos (c++)
// Proyecto integrador: Streaming 
// 05 Junio 2020

// Incluir librerías
#include <iostream>
#include <fstream>
using namespace std;

// Incluir clases
#include "Pelicula.h"
#include "Episodio.h"
#include "Serie.h"
#include "Video.h"

// Cargar los datos de los archivos .txt
void cargaDatosVideo(Video *listaVideos[], int &cantVideos) {
    
    // Definir variables
    int id, duracion, calificacion, numeroEpisodio, numeroTemporada;
    string nombre, genero, tituloSerie, director; 
    char tipo;

    // Abrir archivo
    ifstream archivo;
    archivo.open("datosVideos.txt");
    
    // Ciclo que itera todos los registros 
    cantVideos = 0;
    while (archivo >> tipo) {
        // Determinar si se trata de una película
        if (tipo == 'p'){
            // Obtener datos de la película
            archivo >> id >> nombre >> genero >> duracion >> calificacion >> director;
            // Asignar datos de la película 
            listaVideos[cantVideos++] = new Pelicula(id, nombre, genero, duracion, calificacion, director);
        }
        else{
            // Obtener datos de una serie
            archivo >> id >> nombre >> genero >> duracion >> calificacion >> director >> tituloSerie >> numeroEpisodio >> numeroTemporada;
            // Asignar datos de la serie
            listaVideos[cantVideos++] = new Episodio(id, nombre, genero, duracion, calificacion, director, tituloSerie, numeroEpisodio, numeroTemporada);
        }

    }
    // Cerrar el archivo de lectura
    archivo.close();
}

// Cargar los dtos del fichero de series
void cargaDatosSerie(Serie *listaSeries[], int &cantSeries) {
    
    // Definir variables
    string nombre;
    int id;

    // Abrir archivo
    ifstream archivo;
    archivo.open("datosSeries.txt");
    
    // Iterar todos los registros del fichero
    cantSeries = 0;
    while (archivo >> id){
        // Obtener el nombre de la serie
        archivo >> nombre;
        // Asignar el nombre de la serie
        listaSeries[cantSeries++] = new Serie(nombre);
    }
    // Cerrar el archivo
    archivo.close();
}

// Método que muestra las películas 
void muestraPeliculas(Video *listaVideos[], int cantVideos){
    // Iterar la lista de videos 
    for(int i=0; i<cantVideos; i++){
        // Seleccionar los videos que sean películas
        if(typeid(*listaVideos[i]) == typeid(Pelicula)){
            // Imprimir los vídeos (películas) selecionados
            listaVideos[i]->imprimir();
        }
    }
}

// Método que muestra videos con cierta calificación
void muestraVideosCalificacion(Video *listaVideos[], int cantVideos, int cal){
    // Iteración de la lista de videos
    for(int i=0; i<cantVideos; i++){
        // Comparar si la calificación del vídeo coincide con la que ingresa el usuario
        if(listaVideos[i]->getCalificacion() == cal){
            // Imprimir los vídeos
            listaVideos[i]->imprimir();
        }
    }
}

// Método que muestra los videos con cierto género
void muestraVideosGenero(Video *listaVideos[], int cantVideos, string genero){
    int validacion = 0;
    // Iteración de la lista de videos
    for(int i=0; i<cantVideos; i++){
        // Comparar si el género del vídeo coincide con el ingresado por el usuario
        if(listaVideos[i]->getGenero() == genero){
            // Imprimir el vídeo
            listaVideos[i]->imprimir();
            validacion += 1;
        }        
    }
    // Validación el dato ingresado por el usuario
    if(validacion == 0){
        cout <<"Error, el genero no existente o fue escrito incorrectamente";
    }
}

// Método que imprime las series
void muestraSeries(Serie *listaSeries[], int cantSeries){
    // Iteración de la lista de series
    for(int i=0; i<cantSeries; i++){
        // Impresión del nombre de la serie
        listaSeries[i]->imprimir();
    }
}

// Método que imprime los episodios de una serie con su respectiva calificación
void episodiosDeSerie(Video *listaVideos[], int cantVideos, string serie){
    Episodio *misEpisodios;
    int validacion = 0;
    // Iteración de la lista de videos
    for(int i=0; i<cantVideos; i++){
        // Determinar si el video se trata de un episodio
        if(typeid(*listaVideos[i]) == typeid(Episodio)){
            // Agregar los episodios
            misEpisodios = (Episodio *)listaVideos[i];
            // Comparar si los títulos son iguales
            if(misEpisodios->getTituloSerie() == serie) {
                // Obtner el nombre y la calificación de episodio
                string name = misEpisodios->getNombre();
                int cal = misEpisodios->getCalificacion();
                // Imprimir el nombre y la calificación del episodio
                cout << name <<" ";
                cout << cal << endl;
                validacion += 1;
            }
        }
    }
    // Validar el dato ingresado por el usuario
    if (validacion == 0){
        cout << "El nombre de la serie es incorrecto o no existe";
    }
}

//Método que muestra las películas con cierta calificación
void muestraPeliculasCalificacion(Video *listaVideos[], int cantVideos, int cal){
    // Iterar la lista de videos
    for(int i=0; i<cantVideos; i++){
        // Determinar si el video es una película y además tiene una calificación igual a la ingresada por el usuario
        if(typeid(*listaVideos[i]) == typeid(Pelicula) && listaVideos[i]->getCalificacion() == cal){
            // Imprimir los videos
            listaVideos[i]->imprimir();
        }
    }
}

// Método que permite determinar si el usuario conoce al director de cierto video
void evaluaDirector(Video *listaVideos[], int cantVideos, string video, string director){
    int validar = 0;
    // Iteración de la lista de videos
    for(int i=0; i<cantVideos; i++){
        // Comparar si el video tiene el nombre que ingresó el usuario
        if(listaVideos[i]->getNombre() == video){
            validar += 1;
            // Obtner el nombre del director del video
            string name = listaVideos[i]->getDirector();
            // Comparar si coincide la respuesta del usuario con el dato real
            if(name == director){
                // Mensaje en caso de ser correcto
                cout << "Correcto, has acertado";
            }
            // Mensaje en caso de ser incorrecto
            else{
                cout << "Incorrecto";
            }
        }
    }
    // Validar nombre del video ingresado por el usuario
    if(validar == 0){
        cout << "Error, video escrito incorrectamente o no existente";
    }
}

// Menú de opciones para el usuario
int menu()
{
    int iOpcion;
    // Impresión de las funciones que existen
    cout << "\n1. Cargar ficheros"
         << "\n2. Mostrar lista de peliculas"
         << "\n3. Mostrar lista de series"
         << "\n4. Mostrar videos en general con cierta calificacion"
         << "\n5. Mostrar videos en general con cierto genero"
         << "\n6. Mostrar episodios de una determinada serie con sus calificaciones"
         << "\n7. Mostrar peliculas con cierta calificacion"
         << "\n8. Adivina el director del video"
         << "\n0. Salir"
         << "\nIngrese su opcion: ";
    // Tomar la respuesta del usuario
    cin >> iOpcion;
    // Retornar respuesta del usuario
    return iOpcion;
}

// Main
int main()
{
    // Apuntadores
    Video *listaVideos[50]; 
    int cantVideos;
    Serie *listaSeries[50]; 
    int cantSeries;

    // Varianles a manejar en el switch-case
    int iOpcion;
    string genero, serie, director, video;
    int cal, id;

    // Mandar al menú
    iOpcion = menu();
    // Permitir usar el programa hasta que el usuario ingrse 0
    while (iOpcion != 0)
    {
        switch (iOpcion)
        {
        // Cargar los datos del fichero
        case 1:
            cargaDatosVideo(listaVideos, cantVideos);
            cargaDatosSerie(listaSeries, cantSeries);
            break;
        // Mostrar las películas
        case 2:
            muestraPeliculas(listaVideos, cantVideos);
            break;
        // Mostrar las series
        case 3:
            muestraSeries(listaSeries, cantSeries);
            break;
        // Mostrar videos con cierta calificación
        case 4:
            cout << "Ingrese la calificacion (entero entre 1 y 5): ";
            cin >> cal; 
            while(cal<0 or cal>5){
                cout << "ERROR, dato fuera de parametros" <<endl;
                cout << "Ingrese la calificacion (entero entre 1 y 5): ";
                cin >> cal; 
            }
            muestraVideosCalificacion(listaVideos, cantVideos, cal);
            break;
        // Mostrar los videos de cierto género
        case 5:
            cout << "Ingrese el genero (sintaxis: Genero | Mi_genero): ";
            cin >> genero; 
            muestraVideosGenero(listaVideos, cantVideos, genero);
            break;
        // Mostrar episodios de una serie con su calificación
        case 6:
            cout << "Ingrese la serie (sintaxis: Stranger_things): ";
            cin >> serie;
            episodiosDeSerie(listaVideos, cantVideos, serie);
            break;
        // Mostrar películas con cierta calificación
        case 7:
            cout << "Ingrese la calificacion (entero entre 1 y 5): ";
            cin >> cal; 
            while(cal<0 or cal>5){
                cout << "ERROR, dato fuera de parametros" << endl;
                cout << "Ingrese la calificacion (entero entre 1 y 5): ";
                cin >> cal; 
            }
            muestraPeliculasCalificacion(listaVideos, cantVideos, cal);
            break;
        // Adivinar el director del video
        case 8:
            cout << "Ingrese el nombre del video:";
            cout << "Nota: primera letra de cada palabra con mayuscula, conectores" <<endl;
            cout << "se escriben con minusculas, palabras separadas por guion bajo: ";
            cin >> video;
            cout << "Ingrese solo el primer nombre del director (en minusculas): ";
            cin >> director;
            evaluaDirector(listaVideos, cantVideos, video, director);
            break;
        // En caso de que el usuario ingrse una opción inválida
        default:
            cout << "Opcion Incorrecta\n";
            break;
        }
        iOpcion = menu();
    }
    return 0;
}