#ifndef LISTA_INSTRUCCIONES_H
#define LISTA_INSTRUCCIONES_H


#include <stdio.h> // Provee FILE
#include "Instruccion.h" // Provee ABBVariables, CodigoError


typedef struct nodoLista{ // Nombre para autoreferencia
    nodoLista* sig;
	Instruccion instruccion;
} NodoListaInstrucciones; // Nodo de lista de instrucciones


typedef NodoListaInstrucciones* ListaInstrucciones; // Primero en lista de instrucciones


/*
    Precondiciones:
        * <<archivoFuente>> es archivo de programa de CalcuSimple del que ya se leyó hasta la línea de
            variables.
        * <<abb>> fue creado.
        * <<listaInstr>> NO fue creada.
        * <<err>> NO fue creado.
    Detalle: Parsea el resto del <<archivoFuente>> y construye la lista de instrucciones del programa.
             Si se encuentra un error, devuelve TRUE por referencia por <<hayError>> y carga <<err>>.
*/
void ParsearListaInstrucciones(FILE* archivoFuente, ABBVariables abb,
                               CodigoError &cError, int &numLineaError, ListaInstrucciones &listaInstr);


/*
    Precondiciones:
        * <<listaInstr>> esta creada
    Detalle: Inserta la instruccion al comienzo de la lista

*/
void InsertarComienzoListaInstrucciones(ListaInstrucciones &listaInstr, Instruccion inst);


/*
    Precondiciones:
        <<abb>> fue creado.
        <<err>> NO fue creado.
        <<listaInstr>> fue creada.
    Detalle: Ejecuta cada instrucción de la lista. Devuelve TRUE por <<hayError>> por referencia si encuentra
             un error, cargando <<err>>.
*/
void EjecutrarListaInstrucciones(ABBVariables abb, CodigoError &cError, int &numLineaError,
                                 ListaInstrucciones listaInstr);


/*
    Precondiciones:
        * <<lista>> esta creada y no es vacia
    Detalle: Inserta la instruccion al comienzo de la lista
    Guarda de forma recursiva y deja la lista invertida para que a la hora de leer desde
    el archivo sea más eficiente el alogritmo
*/
void GuardarListaInstrucciones(ListaInstrucciones listaInstr, FILE * archivo);


/*
    Precondiciones:
        * <<archivo>> está abierto en modo escritura binaria.
        * <<listaInstr>> fue creada.
    Detalles: Carga desde el disco una lista de instrucciones previamente compilada y la devuelve por
              referencia.
*/
void CargarListaInstrucciones(ListaInstrucciones &listaInstr, FILE* archivo);


/*
    Precondición: <<instrucciones>> fue creada.
    Detalle: Libera la memoria dinámica asociada a la lista de instrucciones y la deja vacia
*/
void LiberarListaInstrucciones(ListaInstrucciones &listaInstr);


#endif
