#include "../Include/ListaInstrucciones.h"


void ParsearListaInstrucciones(FILE* archivoFuente, ABBVariables abb,
                               CodigoError &cError, int &numLineaError, ListaInstrucciones &listaInstr)
{
    cError = SIN_ERROR;
    listaInstr = NULL;
    String strLinea;
    CrearStringVacio(strLinea);
    LeerSiguienteLineaString(archivoFuente, strLinea);
    ListaPalabras listaPal;
    SepararPalabras(strLinea, listaPal);
    switch(ContarPalabras(listaPal))
    {
        case 0:
            {
                cError = FALTA_RESERVADA_LINEA_INSTRUCCIONES;
                numLineaError = 3;
            }break;
        case 1:
            {
                Palabra *pal = DarPrimerPalabra(listaPal);
                if (EsIgualString(pal->str,"INSTRUCCIONES"))
                {
                    /* Limpiar la lista de palabras */
                    LiberarListaPalabras(listaPal);

                    /* Leer la siguiente linea */
                    LeerSiguienteLineaString(archivoFuente, strLinea);

                    /* Mientras haya una línea y no se encuentren errores */
                    numLineaError = 4;
                    while (strLinea != NULL && cError == SIN_ERROR)
                    {
                        /* Separar la nueva linea */
                        SepararPalabras(strLinea, listaPal);

                        /* Parseo una instrucción */
                        Instruccion nueva;
                        ParsearInstruccion(listaPal, abb, cError, nueva);
                        if (cError == SIN_ERROR)
                        {
                            InsertarComienzoListaInstrucciones(listaInstr, nueva);
                            LeerSiguienteLineaString(archivoFuente, strLinea);

                            // Avanzo el numero de linea
                            numLineaError++;
                        }

                        /* Limpiar la lista de palabras */
                        LiberarListaPalabras(listaPal);
                    }
                }
                else
                {
                    cError = NO_ES_RESERVADA_INSTRUCCIONES;
                    numLineaError = 3;
                }
                break;
            }
        default:
            {
                cError = DEMASIADAS_PALABRAS_EN_LINEA_INSTRUCCIONES;
                numLineaError = 3;
            }
    }

    /* Limpiar */
    LiberarString(strLinea);
}


void InsertarComienzoListaInstrucciones(ListaInstrucciones &lista, Instruccion inst)
{
    ListaInstrucciones nueva = new NodoListaInstrucciones;
    nueva->instruccion = inst;
    if(lista == NULL){
        nueva->sig = NULL;
    } else {
        nueva->sig = lista;
    }
    lista = nueva;
}


void EjecutrarListaInstrucciones(ABBVariables abb, CodigoError &cError, int &numLineaError,
                                 ListaInstrucciones listaInstr)
{
    cError = SIN_ERROR;
    numLineaError = 4;
    while (listaInstr != NULL && cError == SIN_ERROR)
    {
        EjecutarInstruccion(listaInstr->instruccion, abb, cError);

        if(cError == SIN_ERROR){
            listaInstr = listaInstr->sig;
            numLineaError++;
        }
    }
}


void GuardarListaInstrucciones(ListaInstrucciones instrucciones, FILE * archivo)
{
    if(instrucciones != NULL)
    {
        GuardarInstruccion(instrucciones->instruccion, archivo);
        GuardarListaInstrucciones(instrucciones->sig, archivo);
    }
}


void CargarListaInstrucciones(ListaInstrucciones &instrucciones, FILE* archivo)
{
    instrucciones = NULL;
    Instruccion instrLeida;
    CargarInstruccion(instrLeida, archivo);
    while(!feof(archivo))
    {
        InsertarComienzoListaInstrucciones(instrucciones, instrLeida);
        CargarInstruccion(instrLeida, archivo);
    }
}


void LiberarListaInstrucciones(ListaInstrucciones &listaInst)
{
    if(listaInst != NULL)
    {
        LiberarListaInstrucciones(listaInst->sig);
        LiberarInstruccion(listaInst->instruccion);
    }
}
