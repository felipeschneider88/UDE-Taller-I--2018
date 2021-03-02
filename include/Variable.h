#ifndef VARIABLE_H
#define VARIABLE_H


#include "String.h" // Provee Boolaean


typedef struct{
    String nombre;
    int valor;
} Variable;


/*
    Precondición: <<variable>> NO fue creada.
    Detalle: Crea <<variable>> con nombre <<nombre>> y valor cero, y la devuelve por referencia.
*/
void CrearVariable(ConstString nombre, Variable &variable);


/*
    Precondición: <<variable>> fue creada.
    Detalle: Devuelve el nombre <<variable>> en modo solo lectura. No realiza una copia.
*/
ConstString DarNombreVariable(Variable variable);


/*
    Precondición: <<variable>> fue creada.
    Detalle: Devuelve el valor actual de <<variable>>.
*/
int DarValorVariable(Variable variable);


/*
    Precondición: <<variable>> fue creada.
    Detalle: Cambia el valor de <<variable>>.
*/
void CambiarValorVariable(int nuevoValor, Variable *variable);


/*
    Precondicion: <<archivo>> esta abierto en modo "wb".
    Detalle: Guarda la variable en el disco.
*/
void GuardarVariable(FILE* archivo, Variable var);


/*
    Precondicion: <<archivo>> esta abierto en modo "rb".
    Detalle: Carga una variable desde el disco.
*/
void CargarVariable(FILE* archivo, Variable &var);


/*
    Precondición: <<variable>> fue creada.
    Detalle: Libera la memoria dinámica asociada a <<variable>>. Queda en un estado inutilizable.
*/
void LiberarVariable(Variable &variable);

#endif
