#include "../../include/duplas/DuplaVariableVariable.h"


void ParsearDuplaVariableVariable(ListaPalabras argumentos, CodigoError &codigoError,
                                  DuplaVariableVariable &duplaVariableVariable, ABBVariables abbVar)
{
    codigoError = SIN_ERROR;
    Palabra* pal = DarPrimerPalabra(argumentos);
    if (ExisteVariableABBVariables(DarStringPalabra(pal), abbVar))
    {
        CrearStringVacio(duplaVariableVariable.parametroA);
        CopiarString(duplaVariableVariable.parametroA, DarStringPalabra(pal));
        pal = DarSiguientePalabra(argumentos);
        if (ExisteVariableABBVariables(DarStringPalabra(pal), abbVar))
        {
            CrearStringVacio(duplaVariableVariable.parametroB);
            CopiarString(duplaVariableVariable.parametroB, DarStringPalabra(pal));
        }
        else
            codigoError = NO_EXISTE_VAR_DER_DUPLA_VARIABLE_VARIABLE;
    }
    else
        codigoError = NO_EXISTE_VAR_IZQ_DUPLA_VARIABLE_VARIABLE;
}


ConstString DarDerDuplaVariableVariable ( DuplaVariableVariable dupla)
{
    return dupla.parametroB;
}


ConstString DarIzqDuplaVariableVariable (DuplaVariableVariable dupla)
{
    return dupla.parametroA;
}


void CargarDuplaVariableVariable (DuplaVariableVariable &dupla, FILE* archivo)
{
    CrearStringVacio(dupla.parametroA);
    CargarString(dupla.parametroA, archivo);
    CrearStringVacio(dupla.parametroB);
    CargarString(dupla.parametroB, archivo);
}


void GuardarDuplaVariableVariable (DuplaVariableVariable dupla, FILE* archivo)
{
    GuardarString(dupla.parametroA, archivo);
    GuardarString(dupla.parametroB, archivo);
}


void LiberarDuplaVariableVariable(DuplaVariableVariable &dupla)
{
    LiberarString(dupla.parametroA);
    LiberarString(dupla.parametroB);
}
