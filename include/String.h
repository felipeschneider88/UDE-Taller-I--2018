#ifndef STRING_H
#define STRING_H

#include "Boolean.h"

const int STRMAX = 200;
typedef char* String;

/*
    Detalle: En varios módulos será necesario escribir cadenas constantes al programa, en forma de literales
    de string de c++. Estas literales con forma "abcd1234" son guardadas en un arreglo constante de char de
    forma interna por el compilador (comportamiento estandarizado), y por esto el programa estaría mal formado
    si asignaramos una literal a una cadena de tipo String. Entonces, es necesario un tipo de cadena constante
    que será utilizado en todos los parámetros de las operaciones que no sean pasados por referencia, es
    decir, que se pasen con el fin de solo lectura.
*/
typedef const char* ConstString;


/*
    Precondición: El String NO fue creado ni cargado previamente.
    Detalle: Crea un String con el fin de cadena como único caracter.
*/
void CrearStringVacio(String &str);

/*
    Precondición: EsStringNumerica(<<str>>) devuelve TRUE.
    Detalle: A partir de un ConstString parsea y devuelve por copia un entero.
*/
int ParsearEntero(ConstString str);


/*  Precondición: El String fue creado.
    Detalle: Devuelve el largo del String.
*/
int LargoString(ConstString str);


/*
    Precondición: <<destino>> fue creado.
    Detalle: Copia el <<origen>> en <<destino>>. Se pierde el valor previo de <<destino>>.
*/
void CopiarString(String &destino, ConstString origen);

/*
    Precondiciones:
        * <<filePath>> es un path a archivo sin la extensión.
        * <<dire>> fue creada.
        * <<base>> fue creada.
    Detalle: Separa el directorio y la base de un path a dos String.
*/
void SepararDireBaseString(ConstString filePath, String &dire, String &base);

/*
    Precondiciones:
        * <<archivo>> esta abierto en modo "r" para lectura de texto.
    Detalle: Lee la siguiente linea y la carga en el string recibido por referencia.
*/
void LeerSiguienteLineaString(FILE* archivo, String &str);


/*
    Precondiciones:
        * <<archivo>> esta abierto en modo lectura de texto.
        * <<archivo>> tiene al menos <<n>> lineas.
    Detalle: Lee la línea número <<n>> del archivo.
*/
void LeerLineaNString(FILE* archivo, int n, String &str);


/*
    Precondición: <<str>> fue creado.
    Detalle: Carga <<str>> por referencia desde el teclado.
*/
void LeerString(String &str);


/*
    Precondiciones: <<s1>> fue creado.
    Detalle: Concatena el contenido de <<s2>> por referencia al final de <<s1>>.
*/
void ConcatenarString (String &s1, ConstString s2);


/*
    Precondición: Intercambia los contenidos de <<s1>> y <<s2>> por referencia.
    Detalle: <<s1>> y <<s2>> fueron creados.
*/
void IntercambiarString (String &s1, String &s2);


/*
    Detalle: Muestra un String por pantalla.
*/
void MostrarString (ConstString str);


/* Funcion que determina si s1 es alfabéticamente menor que s2 */
Boolean EsMenorString (ConstString s1, ConstString s2);


/*
    Precondición: Ambas String fueron cargadas.
    Detalle: Determina si <<s1>> y <<s2>> son iguales.
*/
Boolean EsIgualString(ConstString str1, ConstString str2);


/*
    Detalle: Devuelve TRUE si todos los caracteres del string se encuentran en {'0', '1', '2', '3', '4', '5',
    '6', '7', '8', '9'} y FALSE en caso contrario.
*/
Boolean EsNumericaString(ConstString str);


/*
    Detalle: Devuelve TRUE si todos los caracteres del string son letras minúsculas o mayúsculas.
*/
Boolean EsAlfabeticaString(ConstString str);

/*
    Precondiciones:
        * El String fue creado o cargado.
        * El archivo está abierto en modo "wb".
    Detalle: Guarda el String al final del archivo.
*/
void GuardarString(ConstString str, FILE* archivo);


/*
    Detalle: Libera la memoria de <<str>> dejándola inusable.
*/
void LiberarString(String &str);


/*
    Procedimiento modificación de datos de entrada.
    Carga un String desde el archivo.
    Precondiciones:
        * El String NO fue creado ni cargado previamente.
        * El archivo está abierto en modo "rb".
        * El archivo contiene un String.
*/
void CargarString(String &str, FILE* archivo);

/*
    Precondición: <<destino>> fue creado.
    Detalle: Carga <<destino>> desde origen, quitando el fullpath y dejando solo el nombre del archivo.
--------------
void DarNombreArchivoSinBarras(String &destino, ConstString origen);
*/
#endif
