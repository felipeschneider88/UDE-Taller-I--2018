#include "../include/Programa.h"

FILE* AbrirCodigoFuentePrograma(ConstString dire, ConstString nombre)
{
    String nomArchivoFuente;
    CrearStringVacio(nomArchivoFuente);
    if(!EsIgualString(dire, ""))
    {
        CopiarString(nomArchivoFuente, dire);
        ConcatenarString(nomArchivoFuente, "/");
    }
    ConcatenarString(nomArchivoFuente, nombre);
    ConcatenarString(nomArchivoFuente, ".csim");
    FILE* archivoFuente = fopen(nomArchivoFuente, "r");
    LiberarString(nomArchivoFuente);
    return archivoFuente;
}

void AbrirArchivosPrograma(ConstString dire, ConstString nombre, ConstString fopenMode,
                           FILE* &archivoVars, FILE* &archivoInst)
{
    String nomArchivoVars, nomArchivoInst;
    CrearStringVacio(nomArchivoVars);
    CrearStringVacio(nomArchivoInst);
    if(!EsIgualString(dire, ""))
    {
        CopiarString(nomArchivoVars, dire);
        ConcatenarString(nomArchivoVars, "/");
    }
    ConcatenarString(nomArchivoVars, nombre);
    CopiarString(nomArchivoInst, nomArchivoVars);
    ConcatenarString(nomArchivoVars, ".vars");
    ConcatenarString(nomArchivoInst, ".inst");
    archivoVars = fopen(nomArchivoVars, fopenMode);
    archivoInst = fopen(nomArchivoInst, fopenMode);
    LiberarString(nomArchivoVars);
    LiberarString(nomArchivoInst);
}


ABBVariables DarABBVariablesPrograma (Programa prog)
{
    return prog.variables;
}


ListaInstrucciones DarListaInstruccionesPrograma(Programa prog)
{
    return prog.instrucciones;
}


void DarNombrePrograma(Programa prog, String &str)
{
    CrearStringVacio(str);
    CopiarString(str,prog.nombre);
}


void LiberarPrograma(Programa &programa)
{
    LiberarString(programa.nombre);
    LiberarABBVariables(programa.variables);
    LiberarListaInstrucciones(programa.instrucciones);
}


void EjecutarPrograma(CodigoError &cError, int &numLineaError, Programa &prog)
{
    EjecutrarListaInstrucciones(prog.variables, cError, numLineaError, prog.instrucciones);
}


void GuardarPrograma(ConstString dire, CodigoError &cError, Programa prog)
{
    cError = SIN_ERROR;
    FILE * archivoVars;
    FILE * archivoInst;

    //Abro los archivos en modo escritura, por eso FALSE como 3er parametro
    AbrirArchivosPrograma(dire, prog.nombre, "wb", archivoVars, archivoInst);

    //Guardo cada estructura en su correspondiente archivo
    GuardarListaInstrucciones(prog.instrucciones, archivoInst);
    GuardarABBVariables(prog.variables, archivoVars);

    //Una vez guardados los datos cierro los archivos.
    fclose(archivoVars);
    fclose(archivoInst);
}


void CargarPrograma(ConstString dire, ConstString nombre, CodigoError &cError, Programa &prog)
{
    cError = SIN_ERROR;
    CrearStringVacio(prog.nombre);
    CopiarString(prog.nombre, nombre);
    FILE* archivoVars;
    FILE* archivoInst;
    AbrirArchivosPrograma(dire, prog.nombre, "rb", archivoVars, archivoInst);
    if (archivoVars != NULL)
    {
        CrearABBVariables(prog.variables);
        CargarABBVariables(prog.variables, archivoVars);
        if (archivoInst != NULL){
            CargarListaInstrucciones(prog.instrucciones, archivoInst);
            fclose(archivoInst);
        }
        else
        {
            cError = NO_EXISTEN_ARCHIVOS_COMPILADOS;
        }
        fclose(archivoVars);
    }
    else
    {
        cError = NO_EXISTEN_ARCHIVOS_COMPILADOS;
    }
}


void ParsearPrograma(FILE * archivoCSIM, ConstString nombre,
                     CodigoError &cError, int &numLineaError, Programa &prog)
{
    cError = SIN_ERROR;
    String linea;
    CrearStringVacio(linea);
    ListaPalabras listaPal;
    LeerSiguienteLineaString(archivoCSIM, linea);
    SepararPalabras(linea, listaPal);
    switch(ContarPalabras(listaPal))
    {
        case 0:
        case 1:
            {
                cError = FALTAN_PALABRAS_EN_LINEA_PROGRAMA;
                numLineaError = 1;
            }break;
        case 2:
        {
            Palabra * pal = DarPrimerPalabra(listaPal);
            if (!EsIgualString("PROGRAMA", pal->str)) {
                cError = NO_ES_RESERVADA_PROGRAMA;
                numLineaError = 1;
            }
            else
            {
                pal = DarSiguientePalabra(pal);
                if (!EsAlfabeticaString(pal->str)) {
                    cError = NOMBRE_PROGRAMA_INVALIDO;
                    numLineaError = 1;
                }
                else
                {
                    if (EsIgualString(nombre, pal->str))
                    {
                        CrearStringVacio(prog.nombre);
                        CopiarString(prog.nombre, nombre);
                        LiberarListaPalabras(listaPal);
                    }
                    else
                    {
                        cError = NO_ES_IGUAL_NOMBRE_ARCHIVO_NOMBRE_PROGRAMA;
                        numLineaError = 1;
                    }
                }
            }
        }
    }
    LiberarString(linea);

    //Parsear el ABB de variables
    if (cError == SIN_ERROR)
    {
        CrearStringVacio(linea);
        ListaPalabras listaPal;
        LeerSiguienteLineaString(archivoCSIM, linea);
        SepararPalabras(linea, listaPal);
        LiberarString(linea);
        ParsearABBVariables(listaPal, cError, numLineaError, prog.variables);
        LiberarListaPalabras(listaPal);
    }

    //Parsear Lista de instrucciones
    if (cError == SIN_ERROR)
    {
        ParsearListaInstrucciones(archivoCSIM, prog.variables, cError, numLineaError, prog.instrucciones);
    }
}
