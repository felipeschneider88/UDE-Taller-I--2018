#ifndef TIPO_INSTRUCCION_H
#define TIPO_INSTRUCCION_H


#include "CodigoError.h"
#include "ListaPalabras.h"
#include "Variable.h"


typedef enum{
    LEER = 0,
    MOSTRAR = 1,
    ASIGNAR = 2
} TipoInstruccion;


/*
    Precondición: <<palabras>> fue creada.
    Detalle: A partir de una lista de palabras detecta el tipo de instrucción y lo devuelve por referencia
             junto con el código de error.
*/
void ParsearTipoInstruccion(ListaPalabras palabras,
                            CodigoError &codigoError, TipoInstruccion &tipoInstruccion);


/*
    Precondiciones:
        * <<tInst>> fue cargada.
        * <<archivo>> fue abierto en modo "wb".
    Detalle: Guarda el tipo de instrucción en el disco.
*/
void GuardarTipoInstruccion(TipoInstruccion tInst, FILE * archivo);


/*
    Precondición: <<archivo>> fue abierto en modo "rb".
    Detalle: Carga un tipo de instrucción desde el disco.
*/
void CargarTipoInstruccion(TipoInstruccion &tInst, FILE * archivo);


#endif
