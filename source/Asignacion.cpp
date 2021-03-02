#include "../include/Asignacion.h"



void ParsearAsignacion(ListaPalabras palabras, ABBVariables abb,
                       CodigoError &cError, Asignacion &asignacion)
{
    cError = SIN_ERROR;

    Palabra* varIzq = DarPrimerPalabra(palabras);
    if (ExisteVariableABBVariables(DarStringPalabra(varIzq), abb)) {
        Palabra* palabraDer = DarSiguientePalabra(DarSiguientePalabra(varIzq));
        FormaParametro formaDer;
        ParsearFormaParametro(DarStringPalabra(palabraDer), cError, formaDer);
        if (cError == SIN_ERROR) {
            CrearStringVacio(asignacion.variableAsg);
            CopiarString(asignacion.variableAsg, DarStringPalabra(varIzq));
            asignacion.formaParametroDer = formaDer;
            switch (formaDer) {
                case ENTERO: {
                    asignacion.enteroDer = ParsearEntero(DarStringPalabra(palabraDer));
                } break;
                case VARIABLE: {
                    if (ExisteVariableABBVariables(DarStringPalabra(palabraDer), abb)) {
                        CrearStringVacio(asignacion.variableDer);
                        CopiarString(asignacion.variableDer, DarStringPalabra(palabraDer));
                    } else {
                        cError = NO_EXISTE_VARIABLE_DER_ASIGNACION;
                    }
                } break;
                case FUNCION: {
                    LlamadaFuncion llamadaFunc;
                    ParsearLlamadaFuncion(palabraDer, abb, cError, llamadaFunc);
                    if (cError == SIN_ERROR) {
                        asignacion.llamadaDer = llamadaFunc;
                    }
                }
            }
        }
    } else {
        cError = NO_EXISTE_VARIABLE_IZQ_ASIGNACION;
    }
}


FormaParametro DarFormaParametroAsignacion(Asignacion asignacion)
{
    return asignacion.formaParametroDer;
}

ConstString DarNombreVariableAsignacion(Asignacion asignacion)
{
    return asignacion.variableAsg;
}


int DarEnteroDerAsignacion(Asignacion asignacion)
{
    return asignacion.enteroDer;
}


ConstString DarVariableDerAsignacion(Asignacion asignacion)
{
    return asignacion.variableDer;
}


LlamadaFuncion DarLlamadaFuncionDerAsignacion(Asignacion asignacion)
{
    return asignacion.llamadaDer;
}


void GuardarAsignacion(Asignacion asignacion, FILE* archivo)
{
    GuardarString(asignacion.variableAsg, archivo);
    fwrite(&asignacion.formaParametroDer, sizeof(FormaParametro), 1, archivo);
    switch(asignacion.formaParametroDer)
    {
        case ENTERO: fwrite(&asignacion.enteroDer, sizeof(int), 1, archivo); break;
        case VARIABLE: GuardarString(asignacion.variableDer, archivo); break;
        case FUNCION: GuardarLlamadaFuncion(asignacion.llamadaDer, archivo); break;
    }
}


void CargarAsignacion(Asignacion &asignacion, FILE* archivo)
{
    CrearStringVacio(asignacion.variableAsg);
    CargarString(asignacion.variableAsg, archivo);
    fread(&asignacion.formaParametroDer, sizeof(FormaParametro), 1, archivo);
    switch(asignacion.formaParametroDer)
    {
        case ENTERO: fread(&asignacion.enteroDer, sizeof(int), 1, archivo); break;
        case VARIABLE:
            CrearStringVacio(asignacion.variableDer);
            CargarString(asignacion.variableDer, archivo);
            break;
        case FUNCION: CargarLlamadaFuncion(asignacion.llamadaDer, archivo); break;
    }
}


void LiberarAsignacion(Asignacion &asignacion)
{
    LiberarString(asignacion.variableAsg);
    switch(asignacion.formaParametroDer)
    {
        case ENTERO: /* No utiliza memoria dinamica */ break;
        case VARIABLE: LiberarString(asignacion.variableDer); break;
        case FUNCION: LiberarLlamadaFuncion(asignacion.llamadaDer); break;
    }
}
