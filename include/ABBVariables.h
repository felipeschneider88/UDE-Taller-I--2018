#ifndef ABB_VARIABLES_H
#define ABB_VARIABLES_H

#include "CodigoError.h"
#include "ListaPalabras.h"
#include "Variable.h"


typedef struct nodoABB{ // Nombre interno para autoreferencia
    nodoABB* izq; // Hijo izquierdo
    nodoABB* der; // Hijo derecho
	Variable var; // Variable de informacion del nodo
} NodoABBVariables; // Nodo


typedef NodoABBVariables* ABBVariables; // Raiz


/*
    Precondiciones:
        <<palabras>> fue creada.
        <<err>> no fue creado.
        <<abb> NO fue creado.
    Detalle: Verifica que la primer palabra de <<palabras>> sea "VARIABLES" y las siguientes sean nombres
             válidos de variables, y crea <<abb>> a partir de éstas. Todas las variables son inicializa-
             das a cero. Devuelve TRUE por <<hayError>> si se encontraron errores, y carga <<err>> con el
             error correspondiente.
*/
void ParsearABBVariables(ListaPalabras palabras, CodigoError &cError, int &numLineaError, ABBVariables &abb);


/*
    Precondición: <<abb>> NO fue creado.
    Detalle: Crea un ABBVariables vacío.
*/
void CrearABBVariables(ABBVariables &abb);


/*
    Precondiciones:
        * <<nombre>> es alfabética.
        * <<abb>> fue creado.
    Detalle: Inserta de forma ordenada una nueva variable en el árbol. Devuelve por referencia el código de
             error correspondiente.
*/
void InsertarNuevaABBVariable(ConstString nombre, CodigoError &cError, ABBVariables &abb);


/*
    Precondiciones:
        * <<abb>> fue creado.
        * Existe una variable de nombre <<nombre>> en <<abb>>.
    Detalle: Devuelve la variable desde <<abb>> que tenga el nombre <<nombre>>.
*/
Variable* DarVariableABBVariables(ConstString nombre, ABBVariables abb);


/*
    Precondicion: <<abb>> fue creado.
    Detalle: Devuelve TRUE si la variable existe en el árbol.
*/
Boolean ExisteVariableABBVariables(ConstString nombre, ABBVariables abb);


/*
    Precondiciones:
        * <<archivo>> está abierto en modo "wb".
        * <<abb>> fue creado.
    Detalle: Guarda <<abb>> en el <<archivo>>.
*/
void GuardarABBVariables(ABBVariables abb, FILE *archivo);


/*
    Precondiciones:
        * <<archivo>> está abierto en modo "rb".
        * <<abb>> NO fue creado.
    Detalle: Carga <<abb>> desde <<archivo>>.
*/
void CargarABBVariables(ABBVariables &abb, FILE* archivo);


/*
    Precondición: <<abb>> fue creado.
    Detalle: Libera la memoria dinamica asociada a <<abb>>.
*/
void LiberarABBVariables(ABBVariables &abb);



#endif
