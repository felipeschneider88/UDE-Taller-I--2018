#ifndef ASIGNACION_H
#define ASIGNACION_H


#include "FormaParametro.h" // Provee ListaPalabras, CodigoError, ConstString
#include "LlamadaFuncion.h" // Provee ABBVariables


typedef struct{
    String variableAsg; // Variable siendo asignada
    FormaParametro formaParametroDer;

    union{
        int enteroDer; // formaParametroDer = ENTERO
        String variableDer; // formaParametroDer = VARIABLE
        LlamadaFuncion llamadaDer; // formaParametroDer = FUNCION
    };
} Asignacion;


/*
    Precondiciones:
        * <<palabras>> contiene o bien 3 o 5 palabras (posibles palabras en asignaciones bien formadas).
        * La primer palabra de <<palabras>> es un nombre de variable válido, y la segunda es "=".
        * <<asignacion>> NO fue creada.
    Detalle: Crea <<asignacion>> a partir de una lista con una cantidad suficiente de palabras.
             Valida que las variables manejadas en la asignación existan en <<variables>>, y devuelve por
             referencia la asignación creada y el código de error correspondiente.
*/
void ParsearAsignacion(ListaPalabras palabras, ABBVariables variables,
                       CodigoError &codigoError, Asignacion &asignacion);


/*
    Precondición: <<asignacion>> fue creada.
    Detalle: Devuelve la forma del parámetro derecho de la asignacion
*/
FormaParametro DarFormaParametroAsignacion(Asignacion asignacion);

/*
    Precondición: <<asignacion>> fue creada.
    Detalle: Devuelve en modo de solo lectura el nombre de la variable siendo asignada.
*/
ConstString DarNombreVariableAsignacion(Asignacion asignacion);


/*
    Precondiciones:
        * <<asignacion>> fue creada.
        * <<asignacion.formaParametroDer>> es <<ENTERO>>.
    Detalle: Devuelve el lado derecho de <<asignacion>> cuando éste es de tipo <<ENTERO>>.
*/
int DarEnteroDerAsignacion(Asignacion asignacion);


/*
    Precondiciones:
        * <<asignacion>> fue creada.
        * <<asignacion.formaParametroDer>> es <<VARIABLE>>.
    Detalle: Devuelve el lado derecho de <<asignacion>> cuando éste es de tipo <<VARIABLE>>. Se devuelve el
             nombre de la variable en modo de solo lectura.
*/
ConstString DarVariableDerAsignacion(Asignacion asignacion);


/*
    Precondiciones:
        * <<asignacion>> fue creada.
        * <<asignacion.formaParametroDer>> es <<FUNCION>>.
    Detalle: Devuelve el lado derecho de <<asignacion>> cuando éste es de tipo <<FUNCION>>.
*/
LlamadaFuncion DarLlamadaFuncionDerAsignacion(Asignacion asignacion);


/*
    Precondiciones:
        * <<archivo>> fue abierto en modo escritura "wb".
        * <<asignacion>> fue creada.
    Detalle: Guarda en el archivo una asignación.
*/
void GuardarAsignacion(Asignacion asignacion, FILE* archivo);


/*
    Precondiciones:
        * <<archivo>> fue abierto en modo lectura "rb".
        * <<asignacion>> fue creada.
    Detalle: Carga desde el archivo una asignación.
*/
void CargarAsignacion(Asignacion &asignacion, FILE* archivo);


/*
    Precondiciones: <<asignacion>> fue cargada.
    Detalle: Libera toda memoria dinámica asociada a una asignación.
*/
void LiberarAsignacion(Asignacion &asignacion);

#endif
