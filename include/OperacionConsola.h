#ifndef OPERACION_CONSOLA_H
#define OPERACION_CONSOLA_H

#include "Programa.h" // Provee ListaPalabras, CodigoError
#include "TipoOperacion.h"
#include <stdlib.h>


typedef struct {
    TipoOperacion tipoOp; // Discriminante
    String dire; // Usado solo en operaciones COMPILAR y EJECUTAR
    String nomProg; // Usado solo en operaciones COMPILAR y EJECUTAR
} OperacionConsola;


/*
    Precondiciones:
        * <<listaPal>> fue creada.
        * <<opCon>> NO fue creada.
    Detalle: Requiere a traves de la consola que el usuario escoja la siguiente operación.
*/
void ParsearOperacionConsola(ListaPalabras listaPal, CodigoError &cError, OperacionConsola &opCon);


/*
    Precondición: <<opCon>> fue creada.
    Detalle: Ejecuta la operación correspondiente.
*/
void EjecutarOperacionConsola(OperacionConsola opCon);


/*
    Precondición: <<opCon>> fue creada.
    Detalle: Libera la memoria asociada a la operación.
*/
void LiberarOperacionConsola(OperacionConsola &opCon);

#endif // OPERACION_CONSOLA_H
