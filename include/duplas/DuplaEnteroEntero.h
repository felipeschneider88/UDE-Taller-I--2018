#ifndef DUPLA_ENTERO_ENTERO_H
#define DUPLA_ENTERO_ENTERO_H


#include "../ListaPalabras.h"


typedef struct{
    int izq;
    int der;
} DuplaEnteroEntero;


/*
    Precondición: <<argumentos>> tiene dos palabras numericas.
    Detalle: A partir de una ListaPalabras con dos palabras que contienen un numero entero cada una,
             devuelve por referencia una DuplaEnteroEntero.
*/
void ParsearDuplaEnteroEntero(ListaPalabras argumentos, DuplaEnteroEntero &dupla);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve el entero izquierdo de la dupla.
*/
int DarIzqDuplaEnteroEntero(DuplaEnteroEntero dupla);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve el entero derecho de la dupla.
*/
int DarDerDuplaEnteroEntero(DuplaEnteroEntero dupla);


/*
    Precondiciones:
        * <<archivo>> fue abierto en modo escritura de bytes "wb" o "ab".
        * <<dupla>> NO fue creada.
    Detalle: Carga una DuplaEnteroEntero desde el disco.
*/
void GuardarDuplaEnteroEntero(DuplaEnteroEntero dupla, FILE* archivo);


/*
    Precondiciones:
        * <<archivo>> fue abierto en modo lectura "rb" y contiene los datos binarios de una DuplaEnteroEntero.
        * <<dupla>> NO fue creada.
    Detalle: Carga una DuplaEnteroEntero desde el disco.
*/
void CargarDuplaEnteroEntero(DuplaEnteroEntero &dupla, FILE* archivo);


#endif
