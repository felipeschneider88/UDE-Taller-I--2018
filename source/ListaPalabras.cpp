#include "../include/ListaPalabras.h"


void SepararPalabras(ConstString linea, ListaPalabras &listaPal)
{
    // Inicializo la listaPal y una palabra auxiliar para recordar el final
    listaPal = NULL;
    Palabra* ultima = NULL;

    // Inicializo el buffer de palabra y los cursores
    char buffer[STRMAX];
    unsigned curLinea = 0, curBuffer = 0;

    // Inicializo un flag para guardar el estado: Tengo que copiar al buffer o estoy salteando espacios?
    Boolean copiar = FALSE;

    // Inicializo un puntero para las nuevas palabras
    Palabra* nueva = NULL;

    // Itero hasta que se informe lo contrario
    Boolean continuar = TRUE;
    while(continuar)
    {
        if(copiar == FALSE)
        {
            // Si no he llegado al final
            if(linea[curLinea] != '\0'){
                // Si encuentro un espacio me lo salteo
                if(linea[curLinea] == ' '){
                    curLinea++;
                } else {
                    copiar = TRUE;
                }
            } else {
                continuar = FALSE;
            }
        } else {
            // Si encuentro un nuevo espacio o llegué el final
            if(linea[curLinea] == ' ' || linea[curLinea] == '\0'){
                // Inserto una nueva palabra al final de la listaPal
                nueva = new Palabra;
                nueva->sig = NULL;
                if (listaPal == NULL){
                    listaPal = nueva;
                    ultima = nueva;
                } else {
                    ultima->sig = nueva;
                    ultima = nueva;
                }

                // Finalizo el string en el buffer, lo copio a la palabra y reseteo el cursor
                buffer[curBuffer] = '\0';
                CrearStringVacio(nueva->str);
                CopiarString(nueva->str, buffer);
                curBuffer = 0;

                // Dejo de copiar
                copiar = FALSE;
            } else {
                // Guardo el caracter en el buffer y avanzo los cursores
                buffer[curBuffer] = linea[curLinea];
                curBuffer++;
                curLinea++;
            }
        }
    }
}


int ContarPalabras(ListaPalabras listaPal)
{
    int cuenta = 0;
    while(listaPal != NULL){
        cuenta++;
        listaPal = listaPal->sig;
    }
    return cuenta;
}


Palabra* DarPrimerPalabra(ListaPalabras listaPal)
{
    return listaPal;
}


Palabra* DarSiguientePalabra(Palabra* palabra)
{
    return palabra->sig;
}


ConstString DarStringPalabra(Palabra* palabra)
{
    return palabra->str;
}


void LiberarListaPalabras(ListaPalabras &palabras)
{
    if(palabras != NULL){
        LiberarListaPalabras(palabras->sig);
        LiberarString(palabras->str);
        delete palabras;
        palabras = NULL;
    }
}
