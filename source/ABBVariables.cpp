#include "../include/ABBVariables.h"


void ParsearABBVariables(ListaPalabras palabras, CodigoError &cError, int &numLineaError, ABBVariables &abb)
{
    cError = SIN_ERROR;
    CrearABBVariables(abb);
    if (ContarPalabras(palabras) > 0 ){
        Palabra* pal = DarPrimerPalabra(palabras);
        if (EsIgualString(DarStringPalabra(pal), "VARIABLES")){
            pal = DarSiguientePalabra(pal);
            while ((pal != NULL) && (cError == SIN_ERROR)){
                ConstString nombre = DarStringPalabra(pal);
                if (EsAlfabeticaString(nombre) == TRUE){
                    InsertarNuevaABBVariable(nombre, cError, abb);
                    pal = DarSiguientePalabra(pal);
                }
                else{
                    cError = NOMBRE_VARIABLE_INVALIDO;
                }
            }
        }
        else
        {
            cError = NO_ES_RESERVADA_VARIABLES;
        }
    }
    else
    {
        cError = NO_HAY_PALABRAS_LINEA_VARIABLES;
    }

    /* Si encontré un error fue en la línea de variables */
    if(cError != SIN_ERROR){
        numLineaError = 2;
    }
}


void CrearABBVariables (ABBVariables &abb)
{
    abb = NULL;
}


void InsertarNuevaABBVariable(ConstString nombre, CodigoError &cError, ABBVariables &abb)
{
    cError = SIN_ERROR;
    if (abb == NULL) {
        abb = new NodoABBVariables;
        CrearVariable(nombre, abb->var);
        abb -> izq = NULL;
        abb -> der = NULL;
    } else {
        if (EsIgualString(nombre, DarNombreVariable(abb->var))){
            cError = VARIABLE_YA_EXISTE_ABB_VARIABLES;
        }else if (EsMenorString(nombre, DarNombreVariable(abb->var))){
            InsertarNuevaABBVariable(nombre, cError, abb->izq);
        } else {
            InsertarNuevaABBVariable(nombre, cError, abb->der);
        }
    }
}


Variable* DarVariableABBVariables(ConstString nombre, ABBVariables abb)
{
    if(abb == NULL) {
        return NULL;
    }else{
        if(EsIgualString(nombre, DarNombreVariable(abb->var))){
            return &(abb->var);
        } else {
            if(EsMenorString(nombre, DarNombreVariable(abb->var))){
                return DarVariableABBVariables(nombre, abb->izq);
            } else {
                return DarVariableABBVariables(nombre, abb->der);
            }
        }
    }
}


Boolean ExisteVariableABBVariables(ConstString nombre, ABBVariables abb)
{
    if (DarVariableABBVariables(nombre, abb) == NULL){
        return FALSE;
    } else {
        return TRUE;
    }
}


void LiberarABBVariables(ABBVariables &variables)
{
    if (variables != NULL)
    {
        LiberarABBVariables (variables -> izq);
        LiberarABBVariables (variables -> der);
        LiberarVariable(variables->var);
        delete variables;
        variables = NULL;
    }
}


void GuardarABBVariables(ABBVariables arbol, FILE *archivo)
{
    if (arbol != NULL){
        //GuardarEnArchivoString(DarNombreVariable(arbol->var), archivo);
        GuardarVariable(archivo,arbol->var);
        GuardarABBVariables(arbol->izq, archivo);
        GuardarABBVariables(arbol->der, archivo);
    }
}


void CargarABBVariables(ABBVariables &abb, FILE* archivo)
{
    Variable var;
    CargarVariable(archivo, var);
    while (!feof(archivo))
    {
        CodigoError dummyError; // Se ignora este código de error por precondición!
        InsertarNuevaABBVariable(var.nombre,dummyError,abb);
        LiberarVariable(var);
        CargarVariable(archivo, var);
    }
}

