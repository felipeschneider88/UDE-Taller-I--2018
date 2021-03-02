#include "../../include/duplas/DuplaEnteroVariable.h"


void ParsearDuplaEnteroVariable(ListaPalabras argumentos, ABBVariables variables,
                                CodigoError &codigoError, DuplaEnteroVariable &dupla)
{
    codigoError = SIN_ERROR;
    Palabra* pal = DarPrimerPalabra(argumentos);

    if (ExisteVariableABBVariables(DarStringPalabra(DarSiguientePalabra(pal)), variables))
    {
        dupla.ent = ParsearEntero(DarStringPalabra(pal));
        CrearStringVacio(dupla.var);
        CopiarString(dupla.var, DarStringPalabra(DarSiguientePalabra(pal)));
    }
    else
        codigoError =  NO_EXISTE_VARIABLE_DUPLA_VARIABLE_ENTERO;
}


int DarEnteroDuplaEnteroVariable (DuplaEnteroVariable dupla)
{
    return dupla.ent;
}


ConstString DarVariableDuplaEnteroVariable(DuplaEnteroVariable dupla)
{
    return dupla.var;
}


void CargarDuplaEnteroVariable(DuplaEnteroVariable &dupla, FILE* archivo)
{
    fread(&dupla.ent, sizeof(int), 1, archivo);
    CrearStringVacio(dupla.var);
    CargarString(dupla.var,archivo);
}


void GuardarDuplaEnteroVariable(DuplaEnteroVariable dupla, FILE* archivo)
{
    fwrite(&dupla.ent, sizeof(int), 1, archivo);
    GuardarString(dupla.var, archivo);
}


void LiberarDuplaEnteroVariable(DuplaEnteroVariable &dupla)
{
    LiberarString(dupla.var);
}
