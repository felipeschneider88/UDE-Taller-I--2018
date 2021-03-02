#ifndef CODIGO_ERROR_H
#define CODIGO_ERROR_H

#include "String.h"

typedef enum{
    /* Sin error se define a cero para habilitar la comparación booleana
       a FALSE en caso de que no haya un error */
    SIN_ERROR = 0,

    /* Los siguientes items son los errores extraídos del algoritmo de
       parseo del proceso de compilación.
    */
    NO_EXISTE_ARCHIVO, //Se esperaba archivo nombre.csim pero no se encotro
    NO_EXISTEN_ARCHIVOS_COMPILADOS, //Es esperaba archivo .vars o .inst y no se encontro
    FALTAN_PALABRAS_EN_LINEA_PROGRAMA,
    NOMBRE_PROGRAMA_INVALIDO,
    NO_ES_RESERVADA_PROGRAMA,
    NO_ES_IGUAL_NOMBRE_ARCHIVO_NOMBRE_PROGRAMA,
    DEMASIADAS_PALABRAS_EN_LINEA_PROGRAMA,
    VARIABLE_YA_EXISTE_ABB_VARIABLES,
    NOMBRE_VARIABLE_INVALIDO,
    NO_ES_RESERVADA_VARIABLES,
    NO_HAY_PALABRAS_LINEA_VARIABLES,
    FALTA_RESERVADA_LINEA_INSTRUCCIONES,
    NO_ES_RESERVADA_INSTRUCCIONES,
    DEMASIADAS_PALABRAS_EN_LINEA_INSTRUCCIONES,
    FALTAN_PALABRAS_EN_INSTRUCCION,
    NO_EXISTE_VARIABLE_INSTRUCCION,
    NO_ES_LEER_NI_MOSTRAR_TIPO_INSTRUCCION,
    SE_ESPERABA_SIGNO_IGUAL_TIPO_INSTRUCCION,
    CANTIDAD_PALABRAS_INCORRECTA_TIPO_INSTRUCCION,
    NO_EXISTE_VARIABLE_DER_ASIGNACION,
    NO_EXISTE_VARIABLE_IZQ_ASIGNACION,
    NO_ES_FORMA_PARAMETRO_VALIDA,
    DIVISION_ENTRE_CERO_DUPLA_ENTERO_ENTERO,
    DIVISION_ENTRE_CERO_DUPLA_VARIABLE_ENTERO,
    ARG1_NO_ES_NUM_NI_VAR_TIPO_DUPLA,
    ARG2_NO_ES_NUM_NI_VAR_TIPO_DUPLA,
    NO_EXISTE_VARIABLE_DUPLA_ENTERO_VARIABLE,
    NO_EXISTE_VARIABLE_DUPLA_VARIABLE_ENTERO,
    NO_EXISTE_VAR_DER_DUPLA_VARIABLE_VARIABLE,
    NO_EXISTE_VAR_IZQ_DUPLA_VARIABLE_VARIABLE,

    /* Los siguientes son errores de tipo operacion de la CLI */
    FALTA_NOMBRE_PROGRAMA_TIPO_OPERACION, // Falta la palabra del nombre de programa
    OPERACION_DESCONOCIDA_TIPO_OPERACION, // No se reconoción el tipo de operación
    CANTIDAD_PALABRAS_INCORRECTA_TIPO_OPERACION, // Cero palabras o más de 3 palabras en el comando de consola

    /* Los siguientes items son los errores extraídos del algoritmo de
       ejecución.
    */
    DIVISION_ENTRE_CERO
} CodigoError;


/*
    Detalle: Muestra el error por la consola.
*/
void MostrarCodigoError(CodigoError codigoError);



#endif
