#ifndef DUPLA_VARIABLE_ENTERO_H
#define DUPLA_VARIABLE_ENTERO_H


#include "../ABBVariables.h" // Provee ListaPalabras


typedef struct{
    String parametroA;
    int parametroB;
} DuplaVariableEntero;

/*
    Precondición: <<argumentos>> tiene dos palabras, la primera es un nombre de variable válido y la segunda
                  es un numero entero.
    Detalle: A partir de los argumentos crea y devuelve por referencia una DuplaVariableEntero, y también
             el código de error correspondiente a la operación.
*/
void ParsearDuplaVariableEntero(ListaPalabras argumentos, CodigoError &codigoError,
                                DuplaVariableEntero &duplaVariableEntero, ABBVariables abbVar);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve el entero de la dupla.
*/
int DarEnteroDuplaVariableEntero ( DuplaVariableEntero dupla);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve la variable de la dupla.
*/
ConstString DarVariableDuplaVariableEntero (DuplaVariableEntero dupla);


/*
    Precondiciones:
        * <<dupla>> no fue creada.
        * <<archivo>> fue abierto en modo "wb".
    Detalle: Carga una DuplaVariableEntero desde el disco.
*/
void CargarDuplaVariableEntero (DuplaVariableEntero &dupla, FILE* archivo);



/*
    Precondiciones:
        * <<dupla>> no fue creada.
        * <<archivo>> fue abierto en modo "rb".
    Detalle: Guarda una DuplaVariableEntero en el disco.
*/
void GuardarDuplaVariableEntero (DuplaVariableEntero dupla, FILE* archivo);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Libera la memoria dinámica asociada a la dupla.
*/
void LiberarDuplaVariableEntero(DuplaVariableEntero &dupla);


#endif
