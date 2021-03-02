#ifndef INSTRUCCION_H
#define INSTRUCCION_H


#include "TipoInstruccion.h" // Provee String, ListaPalabras, CodigoError
#include "Asignacion.h" // Provee ABBVariables


typedef struct{
    TipoInstruccion tipoInstr;

    union{
        String var; // tipoInstruccion == LEER o MOSTRAR
        Asignacion asignacion;  // tipoInstruccion == ASIGNAR
    };
} Instruccion;


/*
    Precondición: <<abb>> y <<listaPal>> están creadas.
    Detalle: Crea una instrucción a partir de una lista de palabras, y devuelve la instrucción con el código
             de error correspondiente por referencia.
*/
void ParsearInstruccion(ListaPalabras listaPal, ABBVariables abb,
                        CodigoError &cError, Instruccion &instr);


/*
    Precondición: <<instr>> fue creada.
    Detalle: Devuelve el tipo de instrucción de la Instrucción.
*/
TipoInstruccion DarTipoInstruccion(Instruccion instr);


/*
    Precondiciones:
        * <<instr>> fue creada.
        * <<abb>> fue creado.
    Detalle: Ejecuta la instrucción leyendo, mostrando o modificando el valor de la variable correspondiente.
             Devuelve el código de error resultante por referencia.
*/
void EjecutarInstruccion(Instruccion instr, ABBVariables &abb, CodigoError &cError);


/*
    Precondiciones:
        * <<instr>> fue creada.
        * <<archivo>> fue abierto en modo "wb".
    Detalles: Guarda la instrucción en el disco.
*/
void GuardarInstruccion(Instruccion instr, FILE * archivo);


/*
    Precondiciones:
        * <<instr>> fue creada.
        * <<archivo>> fue abierto en modo "wb".
    Detalles: Carga una instrucción desde el disco.
*/
void CargarInstruccion(Instruccion &instr, FILE * archivo);


/*
    Precondición: <<instr>> fue creada.
    Detalle: Libera la memoria asociada a la Instruccion.
*/
void LiberarInstruccion(Instruccion &instr);


#endif
