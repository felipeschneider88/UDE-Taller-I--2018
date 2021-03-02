#ifndef LISTA_PALABRAS_H
#define LISTA_PALABRAS_H


#include "String.h"


typedef struct nodoPalabra{
	nodoPalabra *sig;
	String str;
} Palabra;


typedef Palabra* ListaPalabras;


/*
    Precondición: <<palabras>> no está creada.
    Detalle: Genera una lista de palabras a partir de un string con grupos de caracteres separados por
             espacios en blanco. Los espacios en blanco son descartados y cada grupo se guarda en una Palabra.
*/
void SepararPalabras(ConstString linea, ListaPalabras &listaPal);


/*
    Precondición: <<listaPal>> fue creada.
    Detalle: Devuelve la cantidad de palabras en la lista.
*/
int ContarPalabras(ListaPalabras listaPal);


/*
    Precondición: <<listaPal>> tiene al menos una palabra.
    Detalle: Devuelve la primer palabra de la lista.
*/
Palabra* DarPrimerPalabra(ListaPalabras listaPal);


/*
    Precondición: <<palabra>> tiene al menos una Palabra siguiente en su lista.
    Detalle: Devuelve la siguiente Palabra.
*/
Palabra* DarSiguientePalabra(Palabra* palabra);

/*
    Precondición: <<palabra>> fue creada.
    Detalle: Devuelve en modo solo lectura la cadena de <<palabra>>.
*/
ConstString DarStringPalabra(Palabra* palabra);


/*
    Precondición: <<listaPal>> fue creada.
    Detalle: Elimina todas las palabras de la lista.
*/
void LiberarListaPalabras(ListaPalabras &listaPal);


#endif
