#ifndef FORMA_PARAMETRO_H
#define FORMA_PARAMETRO_H


#include "CodigoError.h" // Provee ConstString
#include "FuncionPredefinida.h"
#include "Variable.h"

typedef enum{
    ENTERO = 0,
    VARIABLE = 1,
    FUNCION = 2
} FormaParametro;


/*
    Precondición: <<str>> es la primer palabra del lado derecho de una Asignacion.
    Detalle: A partir de <<str>> determina la forma del parámetro de una asignación. Devuelve la forma y el
             código de error generado por referencia.
*/
void ParsearFormaParametro(ConstString str, CodigoError &codigo, FormaParametro &forma);


/*
    Precondición: <<archivo>> ya fue abierto en modo escritura.
    Detalle: Guarda la forma del parametro en un archivo.
*/
void GuardarFormaParametro(FormaParametro forma, FILE *archivo);


/*
    Precondición: <<archivo>> ya fue abierto en modo lectura.
    Detalle: Guarda la forma del parametro en un archivo.
*/
void CargarFormaParametro(FormaParametro &forma, FILE *archivo);

#endif
