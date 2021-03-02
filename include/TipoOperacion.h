#ifndef TIPO_OPERACION_H
#define TIPO_OPERACION_H

#include "ListaPalabras.h"
#include "CodigoError.h"

typedef enum {
    /* Comandos requeridos */
    COMPILAR,
    EJECUTAR,
    SALIR,

    /* Comandos extra */
    AYUDA,
    AYUDA_COMPILAR,
    AYUDA_EJECUTAR,
    AYUDA_EDITAR,
    INFORMACION,
    EDITAR
} TipoOperacion;


/*
    Precondición: <<listaPal>> fue creada.
    Detalle: Parsea el tipo de operación a partir de una lista de palabras. Devuelve por referencia el código
             de error correspondiente.
*/
void ParsearTipoOperacion(ListaPalabras listaPal, CodigoError &cError, TipoOperacion &tipoOp);


#endif // TIPO_OPERACION_H
