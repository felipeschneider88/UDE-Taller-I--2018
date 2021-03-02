#ifndef PROGRAMA_H
#define PROGRAMA_H

#include "ListaInstrucciones.h" // Provee FILE, Boolean, String, ConstString, CodigoError, ABBVariables
#include "ABBVariables.h"


typedef struct{
    String nombre;
    ABBVariables variables;
    ListaInstrucciones instrucciones;
} Programa;


/*
    Precondiciones:
        * <<archivoCSIM>> es el archivo abierto en modo lectura del código fuente del programa.
        * <<prog>> NO fue cargado.
        * <<err>> NO fue cargado.
    Detalle: Parsea el programa llamado <<nombre>> desde el código fuente en <<archivoCSIM>>. Devuelve el
             código de error (y el número de línea del error) por referencia.
*/
void ParsearPrograma(FILE * archivoCSIM, ConstString nombre,
                     CodigoError &cError, int &numLineaError, Programa &prog);


/*
    Precondición: <<prog>> fue creado.
    Detalle: Devuelve el nombre del programa.
*/
ConstString DarNombrePrograma(Programa prog);


/*
    Precondición: <<prog>> fue creado.
    Detalle: Devuelve el ABBVariables del programa.
*/
ABBVariables DarABBVariablesPrograma(Programa prog);


/*
    Precondición: <<prog>> fue creado.
    Detalle: Devuelve la ListaInstrucciones del programa.
*/
ListaInstrucciones DarListaInstruccionesPrograma(Programa prog);


/*
    Precondiciones:
        * <<err>> NO fue cargado.
        * <<prog>> fue cargado.
    Detalle: Ejecuta todas las instrucciones del programa. Si se detecta un error finaliza la ejecución y
             devuelve TRUE por referencia por <<hayError>>, y carga en <<err>> el error correspondiente.
*/
void EjecutarPrograma(CodigoError &cError, int &numLineaError, Programa &prog);


/*
    Precondiciones:
        * <<nombre>> es un nombre de programa valido.
        * <<dire>> es un path a directorio sin barra al final.
    Detalle:
        Abre en modo lectura el archivo de código fuente del programa llamado <<nombre>> en <<dire>>.
*/
FILE* AbrirCodigoFuentePrograma(ConstString dire, ConstString nombre);


/*
    Precondiciones:
        * <<nombre>> es un nombre de programa valido.
        * <<dire>> es un path a directorio sin barra al final.
        * <<fopenMode>> es una cadena de modo de apertura de las pasadas al comando fopen.
    Detalle:
        Abre los archivos de variables e instrucciones de un programa en modo "fopenMode" y los devuelve por
        referencia.
*/
void AbrirArchivosPrograma(ConstString dire, ConstString nombre, ConstString fopenMode,
                           FILE* &archivoVars, FILE* &archivoInst);


/*
    Precondiciones:
        * <<prog>> fue creado.
    Detalle: Abre los archivos de variables e instrucciones y ejecuta los procedimientos de guardar el árbol
            de variables y la lista de instrucciones en dichos archivos. Devuelve por referencia el código de
            error correspondiente.
*/
void GuardarPrograma(ConstString dire, CodigoError &cError, Programa prog);


/*
    Precondiciones:
        * <<nombre>> es un nombre de programa válido.
        * <<prog>> NO fue creado.
    Detalle: Carga un programa desde los archivos de variables "nomProg.vars" e instrucciones "nomProg.inst".
             Devuelve por referencia cualquier error resultante.
*/
void CargarPrograma(ConstString dire, ConstString nombre, CodigoError &cError, Programa &prog);


/*
    Precondición: <<prog>> fue cargado.
    Detalle: Libera la memoria dinámica asociada a <<prog>>.
*/
void LiberarPrograma(Programa &prog);

#endif
