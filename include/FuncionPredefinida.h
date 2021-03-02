#ifndef FUNCION_PREDEFINIDA_H
#define FUNCION_PREDEFINIDA_H


#include "String.h" // Provee Boolean


typedef enum {
    SUM = 0, // Suma
    RES = 1, // Resta
    MUL = 2, // Multiplicación
    DIV = 3 // División
} FuncionPredefinida;


/*
    Detalle: Devuelve TRUE si <<str>> pertenece a {"SUM", "RES", "MUL", "DIV"} y FALSE en caso contrario.
*/
Boolean EsFuncionPredefinida(ConstString str);


/*
    Precondición: <<str>> pertenece a {"SUM", "RES", "MUL", "DIV"}.
    Detalle: Devuevle por referencia una FuncionPredefinida dada una string de función predefinida.
*/
void ParsearFuncionPredefinida(ConstString str, FuncionPredefinida &funcion);


/*
    Precondicion: <<archivo>> fue abierto en modo lectura.
    Detalle: Guarda la función predefinida en el archivo.
*/
void GuardarFuncionPredefinida(FuncionPredefinida func, FILE * archivo);


/*
    Precondicion: <<archivo>> fue abierto en modo lectura.
    Detalle: Carga la función predefinida desde el archivo.
*/
void CargarFuncionPredefinida(FuncionPredefinida &func, FILE * archivo);


#endif
