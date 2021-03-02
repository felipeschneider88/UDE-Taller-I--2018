#ifndef DUPLA_VARIABLE_VARIABLE_H
#define DUPLA_VARIABLE_VARIABLE_H


#include "../ABBVariables.h" // Provee ListaPalabras


typedef struct{
    String parametroA;
    String parametroB;
} DuplaVariableVariable;


/*
    Precondición: <<argumentos>> tiene dos palabras, la primera es un nombre de variable válido y la segunda
                  es un numero entero.
    Detalle: A partir de los argumentos crea y devuelve por referencia una DuplaVariableEntero, y también
             el código de error correspondiente a la operación.
*/
void ParsearDuplaVariableVariable(ListaPalabras argumentos, CodigoError &codigoError,
                                  DuplaVariableVariable &duplaVariableVariable, ABBVariables abbVar);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve la variable derecha de la dupla.
*/
ConstString DarDerDuplaVariableVariable (DuplaVariableVariable dupla);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve la variable izquierda de la dupla.
*/
ConstString DarIzqDuplaVariableVariable (DuplaVariableVariable dupla);


/*
    Precondiciones:
        * <<dupla>> no fue creada.
        * <<archivo>> fue abierto en modo "wb".
    Detalle: Carga una DuplaVariableVariable desde el disco.
*/
void CargarDuplaVariableVariable (DuplaVariableVariable &dupla, FILE* archivo);


/*
    Precondiciones:
        * <<dupla>> no fue creada.
        * <<archivo>> fue abierto en modo "rb".
    Detalle: Guarda una DuplaVariableVariable en el disco.
*/
void GuardarDuplaVariableVariable (DuplaVariableVariable dupla, FILE* archivo);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Libera la memoria dinámica asociada a la dupla.
*/
void LiberarDuplaVariableVariable(DuplaVariableVariable &dupla);


#endif
