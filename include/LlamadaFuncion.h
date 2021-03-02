#ifndef LLAMADA_FUNCION_H
#define LLAMADA_FUNCION_H


#include "FuncionPredefinida.h"
#include "TipoDupla.h" // Provee ListaPalabras
#include "duplas/DuplaEnteroEntero.h" // Provee ABBVariables
#include "duplas/DuplaEnteroVariable.h"
#include "duplas/DuplaVariableEntero.h"
#include "duplas/DuplaVariableVariable.h"
#include "ABBVariables.h"


typedef struct{
    FuncionPredefinida funcion;
    TipoDupla tipoDupla; // Discriminante

    union{
        DuplaEnteroEntero enteroEntero; // tipoDupla = ENTERO_ENTERO
        DuplaEnteroVariable enteroVariable; // tipoDupla = ENTERO_VARIABLE
        DuplaVariableEntero variableEntero; // tipoDupla = VARIABLE_ENTERO
        DuplaVariableVariable variableVariable; // tipoDupla = VARIABLE_VARIABLE
    };
} LlamadaFuncion;


/*
    Precondiciones:
        * <<palabras>> contiene tres palabras.
        * <<variables>> fue creado.
    Detalle: A partir de <<palabras>> crea <<llamadaF>>, creando la dupla de parámetros correspondiente
             y devolviendo el código de error, ambos por referencia.
*/
void ParsearLlamadaFuncion(ListaPalabras palabras, ABBVariables variables,
                           CodigoError &codigoError, LlamadaFuncion &llamadaF);


/*
    Precondición: <<llamadaF>> fue creada.
    Detalle: Libera la memoria dimámica asociada con la llamada.
*/
void LiberarLlamadaFuncion(LlamadaFuncion &llamadaF);


/*
    Precondición: <<llamadaF>> fue creada.
    Detalle: Devuelve la función predefinida de la llamada.
*/
FuncionPredefinida DarFuncionPredefinidaLlamadaFuncion(LlamadaFuncion llamadaF);

/*
    Precondición: <<llamadaF>> fue creada.
    Detalle: Devuelve el tipo de dupla de la llamada.
*/
TipoDupla DarTipoDuplaLlamadaFuncion(LlamadaFuncion llamadaF);


/*
    Precondición: <<llamadaF>> fue creada.
    Detalle: Devuelve el resultado de una llamada a funcion
*/
void CalcularResultadoFuncion(LlamadaFuncion llamadaF, ABBVariables vars,  int &resu, CodigoError &cError);


/*
    Precondición: <<llamadaF>> fue creada.
    Detalle: <<archivo>> fue abierto en modo "wb".
*/
void GuardarLlamadaFuncion(LlamadaFuncion llamadaF, FILE * archivo);


/*
    Precondición: <<llamadaF>> fue creada.
    Detalle: <<archivo>> fue abierto en modo "rb".
*/
void CargarLlamadaFuncion(LlamadaFuncion &llamadaF, FILE * archivo);


#endif
