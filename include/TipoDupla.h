#ifndef TIPO_DUPLA_H
#define TIPO_DUPLA_H

#include "CodigoError.h"
#include "Variable.h"
#include "ListaPalabras.h"


typedef enum{
    ENTERO_ENTERO = 0,
    ENTERO_VARIABLE = 1,
    VARIABLE_ENTERO = 2,
    VARIABLE_VARIABLE = 3
} TipoDupla;


/*
    Precondición: <<argumentos>> tiene dos palabras.
    Detalle: Identifica que tipo de dupla se requiere para almacenar los argumentos y lo devuelve por
             referencia junto con un CodigoError.
*/
void ParsearTipoDupla(ListaPalabras argumentos, CodigoError &codigoError, TipoDupla &tipoD);


/*
    Precondiciones:
        * <<tipoD>> fue creado.
        * <<archivo>> fue abierto en modo "wb".
    Detalle: Guarda el TipoDupla en el archivo.
*/
void GuardarTipoDupla(TipoDupla tipoD, FILE *archivo);


/*
    Precondiciones:
        * <<tipoD>> fue creado.
        * <<archivo>> fue abierto en modo "wb".
    Detalle: Carga un TipoDupla desde el archivo.
*/
void CargarTipoDupla(TipoDupla &tipoD, FILE *archivo);


#endif
