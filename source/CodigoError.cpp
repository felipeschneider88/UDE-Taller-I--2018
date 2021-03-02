#include "../include/CodigoError.h"


void MostrarCodigoError(CodigoError codigoError)
{
    switch (codigoError)
    {
    case SIN_ERROR:
        printf("Sin error."); break;
    case NO_EXISTE_ARCHIVO:
        printf("No encontro el codigo de fuente del programa.");
        break;
    case FALTAN_PALABRAS_EN_LINEA_PROGRAMA:
        printf("Linea de PROGRAMA incompleta.");
        break;
    case NOMBRE_PROGRAMA_INVALIDO:
        printf("Nombre de programa invalido.");
        break;
    case NO_ES_IGUAL_NOMBRE_ARCHIVO_NOMBRE_PROGRAMA:
        printf("Nombre de programa diferente al nombre del archivo.");
        break;
    case NO_ES_RESERVADA_PROGRAMA:
        printf("No es palabra reservada PROGRAMA.");
        break;
    case DEMASIADAS_PALABRAS_EN_LINEA_PROGRAMA:
        printf("Sobran palabras en la linea de PROGRAMA.");
        break;
    case VARIABLE_YA_EXISTE_ABB_VARIABLES:
        printf("La variable ya fue definida.");
        break;
    case NOMBRE_VARIABLE_INVALIDO:
        printf("Nombre de variable invalido.");
        break;
    case NO_ES_RESERVADA_VARIABLES:
        printf("No es palabra reservada VARIABLES.");
        break;
    case NO_HAY_PALABRAS_LINEA_VARIABLES:
        printf("La linea de variables esta vacia.");
        break;
    case FALTA_RESERVADA_LINEA_INSTRUCCIONES:
        printf("Falta la palabra reservada INSTRUCCIONES.");
        break;
    case NO_ES_RESERVADA_INSTRUCCIONES:
        printf("No es palabra reservada INSTRUCCIONES.");
        break;
    case DEMASIADAS_PALABRAS_EN_LINEA_INSTRUCCIONES:
        printf("Sobran palabras en la linea INSTRUCCIONES.");
        break;
    case FALTAN_PALABRAS_EN_INSTRUCCION:
        printf("Instruccion incompleta.");
        break;
    case NO_EXISTE_VARIABLE_INSTRUCCION:
        printf("No existe la variable de la instruccion.");
        break;
    case NO_ES_LEER_NI_MOSTRAR_TIPO_INSTRUCCION:
        printf("Se esperaba instruccion LEER o MOSTRAR.");
        break;
    case SE_ESPERABA_SIGNO_IGUAL_TIPO_INSTRUCCION:
        printf("Se esperaba signo = en la instruccion.");
        break;
    case CANTIDAD_PALABRAS_INCORRECTA_TIPO_INSTRUCCION:
        printf("La cantidad de palabras no es correcta en la instruccion.");
        break;
    case NO_EXISTE_VARIABLE_DER_ASIGNACION:
        printf("No existe la variable derecha de la asignacion.");
        break;
    case NO_EXISTE_VARIABLE_IZQ_ASIGNACION:
        printf("No existe la variable izquierda de la asignacion.");
        break;
    case NO_ES_FORMA_PARAMETRO_VALIDA:
        printf("No es valida la forma de parametro recibida.");
        break;
    case DIVISION_ENTRE_CERO_DUPLA_ENTERO_ENTERO:
        printf("La instruccion con dupla ENTERO ENTERO hace una division entre 0.");
        break;
    case DIVISION_ENTRE_CERO_DUPLA_VARIABLE_ENTERO:
        printf("Division entre cero.");
        break;
    case ARG1_NO_ES_NUM_NI_VAR_TIPO_DUPLA:
        printf("El argumento izquierdo no es ni un entero ni una variable.");
        break;
    case ARG2_NO_ES_NUM_NI_VAR_TIPO_DUPLA:
        printf("El argumento derecho no es ni un entero ni una variable.");
        break;
    case NO_EXISTE_VARIABLE_DUPLA_ENTERO_VARIABLE:
        printf("La variable usada en la funcion no fue declarada.");
        break;
    case NO_EXISTE_VARIABLE_DUPLA_VARIABLE_ENTERO:
        printf("La variable usada en la funcion no fue declarada.");
        break;
    case NO_EXISTE_VAR_DER_DUPLA_VARIABLE_VARIABLE:
        printf("La variable derecha usada en la funcion no fue declarada.");
        break;
    case NO_EXISTE_VAR_IZQ_DUPLA_VARIABLE_VARIABLE:
        printf("La variable izquierda usada en la funcion no fue declarada.");
        break;
    case DIVISION_ENTRE_CERO:
        printf("Division entre cero inesperada.");
        break;
    case FALTA_NOMBRE_PROGRAMA_TIPO_OPERACION:
        printf("Falta el nombre del programa.");
        break;
    case OPERACION_DESCONOCIDA_TIPO_OPERACION:
        printf("Operacion desconocida.");
        break;
    case CANTIDAD_PALABRAS_INCORRECTA_TIPO_OPERACION:
        printf("Sobran palabras en la operacion.");
        break;
    case NO_EXISTEN_ARCHIVOS_COMPILADOS:
        printf("El programa no fue compilado.");
        break;
    }
}
