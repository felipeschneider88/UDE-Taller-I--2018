#include "../../include/duplas/DuplaVariableEntero.h"



void ParsearDuplaVariableEntero(ListaPalabras argumentos, CodigoError &codigoError,
                                  DuplaVariableEntero &dupla, ABBVariables abbVar)
{
    codigoError = SIN_ERROR;
    Palabra* pal = DarPrimerPalabra(argumentos);
    if (ExisteVariableABBVariables(DarStringPalabra(pal),abbVar)) {
        CrearStringVacio(dupla.parametroA);
        CopiarString(dupla.parametroA,DarStringPalabra(pal));
        dupla.parametroB = ParsearEntero(DarStringPalabra(DarSiguientePalabra(pal)));
    } else {
        codigoError =  NO_EXISTE_VARIABLE_DUPLA_VARIABLE_ENTERO;
    }
}


int DarEnteroDuplaVariableEntero ( DuplaVariableEntero dupla)
{
    return dupla.parametroB;
}


ConstString DarVariableDuplaVariableEntero ( DuplaVariableEntero dupla)
{
    return dupla.parametroA;
}


void CargarDuplaVariableEntero (DuplaVariableEntero &dupla, FILE* archivo)
{
    CrearStringVacio(dupla.parametroA);
    CargarString(dupla.parametroA,archivo);
    fread(&dupla.parametroB, sizeof(int), 1, archivo);
}


void GuardarDuplaVariableEntero (DuplaVariableEntero dupla, FILE* archivo)
{
    GuardarString(dupla.parametroA,archivo);
    fwrite(&dupla.parametroB, sizeof(int), 1, archivo);
}


void LiberarDuplaVariableEntero(DuplaVariableEntero &dupla)
{
    LiberarString(dupla.parametroA);
}
