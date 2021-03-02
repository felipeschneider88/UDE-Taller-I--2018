#ifndef DUPLA_ENTERO_VARIABLE_H
#define DUPLA_ENTERO_VARIABLE_H


#include "../ABBVariables.h" // Provee ListaPalabras


typedef struct{
    int ent;
    String var;
} DuplaEnteroVariable;

/*
    Precondición: <<argumentos>> tiene dos palabras, la primera es un numero entero y la segunda es nombre de
                  variable válido.
    Detalle: A partir de los argumentos crea y devuelve por referencia una DuplaEnteroVariable, y también el
             código de error correspondiente a la operación. Verifica que la variable perteneza al árbol de
             variables.
*/
void ParsearDuplaEnteroVariable(ListaPalabras argumentos, ABBVariables variables,
                                CodigoError &codigoError, DuplaEnteroVariable &dupla);

/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve el entero de la dupla.
*/
int DarEnteroDuplaEnteroVariable ( DuplaEnteroVariable dupla);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Devuelve la variable de la dupla.
*/
ConstString DarVariableDuplaEnteroVariable(DuplaEnteroVariable dupla);


/*
    Precondiciones:
        * <<dupla>> no fue creada.
        * <<archivo>> fue abierto en modo "wb".
    Detalle: Carga una DuplaEnteroVariable desde el disco.
*/
void CargarDuplaEnteroVariable (DuplaEnteroVariable &dupla, FILE* archivo);


/*
    Precondiciones:
        * <<dupla>> no fue creada.
        * <<archivo>> fue abierto en modo "rb".
    Detalle: Guarda una DuplaEnteroVariable en el disco.
*/
void GuardarDuplaEnteroVariable (DuplaEnteroVariable dupla, FILE* archivo);


/*
    Precondición: <<dupla>> fue creada.
    Detalle: Libera la memoria dinámica asociada a la dupla.
*/
void LiberarDuplaEnteroVariable(DuplaEnteroVariable &dupla);


#endif
