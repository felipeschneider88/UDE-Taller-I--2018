#include "../include/Instruccion.h"


void ParsearInstruccion(ListaPalabras listaPal, ABBVariables abb,
                        CodigoError &cError, Instruccion &instr)
{
    cError = SIN_ERROR;
    TipoInstruccion tipoins;

    if (ContarPalabras(listaPal) >= 2)
    {
        ParsearTipoInstruccion(listaPal, cError, tipoins);
        if (cError == SIN_ERROR)
        {
            switch (tipoins)
            {
            case MOSTRAR:
            case LEER:
                {
                    ConstString strDer = DarStringPalabra(DarSiguientePalabra(DarPrimerPalabra(listaPal)));
                    if(EsAlfabeticaString(strDer)) {
                        if(ExisteVariableABBVariables(strDer, abb)){
                            instr.tipoInstr = tipoins;
                            CrearStringVacio(instr.var);
                            CopiarString(instr.var, strDer);
                        } else {
                            cError = NO_EXISTE_VARIABLE_INSTRUCCION;
                        }
                    } else {
                        cError = NOMBRE_VARIABLE_INVALIDO;
                    }
                }break;
            case ASIGNAR:
                {
                    Asignacion asignacion;
                    ParsearAsignacion(listaPal, abb, cError, asignacion);
                    if (cError == SIN_ERROR)
                    {
                        instr.tipoInstr = tipoins;
                        instr.asignacion = asignacion;
                    }
                }break;
            }
        }
    }
    else
    {
        cError = FALTAN_PALABRAS_EN_INSTRUCCION;
    }
}


TipoInstruccion DarTipoInstruccion(Instruccion instr)
{
    return instr.tipoInstr;
}


void GuardarInstruccion(Instruccion instr, FILE * archivo)
{
    GuardarTipoInstruccion(instr.tipoInstr, archivo);
    switch(instr.tipoInstr)
    {
        case LEER:
        case MOSTRAR:
            GuardarString(instr.var, archivo);
            break;
        case ASIGNAR:
            GuardarAsignacion(instr.asignacion, archivo);
            break;
    }
}


void CargarInstruccion(Instruccion &instr, FILE * archivo)
{
    CargarTipoInstruccion(instr.tipoInstr, archivo);
    switch(instr.tipoInstr)
    {
        case LEER:
        case MOSTRAR:
            CrearStringVacio(instr.var);
            CargarString(instr.var, archivo);
            break;
        case ASIGNAR:
            CargarAsignacion(instr.asignacion, archivo);
            break;
    }
}


void EjecutarInstruccion(Instruccion instr, ABBVariables &abb, CodigoError &cError)
{
    cError = SIN_ERROR;
    switch(instr.tipoInstr)
    {
    case LEER:
    {
        String inputAux;
        CrearStringVacio(inputAux);
        printf("Ingrese valor para ");
        Variable* var = DarVariableABBVariables(instr.var, abb);
        MostrarString(var->nombre);
        printf(": ");
        LeerString(inputAux);
        while(!EsNumericaString(inputAux)){
            printf("Error. Ingrese un entero: ");
            LeerString(inputAux);
        }
        int intAux = ParsearEntero(inputAux);
        CambiarValorVariable(intAux, var);
        LiberarString(inputAux);
        break;
    }
    case MOSTRAR:
        {
            Variable* var = DarVariableABBVariables(instr.var, abb);
            MostrarString(var->nombre);
            printf(" vale: %i\n", var->valor);
        }break;
    case ASIGNAR:
        {
            Variable* varAsg = DarVariableABBVariables(
                                DarNombreVariableAsignacion(instr.asignacion), abb);
            switch(DarFormaParametroAsignacion(instr.asignacion))
            {
            case ENTERO:
                CambiarValorVariable(DarEnteroDerAsignacion(instr.asignacion), varAsg);
                break;
            case VARIABLE:
                {
                    Variable* varDer = DarVariableABBVariables(
                                            DarVariableDerAsignacion(instr.asignacion), abb);
                    CambiarValorVariable(DarValorVariable(*varDer), varAsg);
                }break;
            case FUNCION:
                {
                    int resu;
                    CalcularResultadoFuncion(
                        DarLlamadaFuncionDerAsignacion(instr.asignacion), abb, resu, cError);
                    if(cError == SIN_ERROR)
                    {
                        CambiarValorVariable(resu, varAsg);
                    }
                }
            }
        }
    }
}


void LiberarInstruccion(Instruccion &instr)
{
    if(instr.tipoInstr == LEER || instr.tipoInstr == MOSTRAR) {
        LiberarString(instr.var);
    } else {
        LiberarAsignacion(instr.asignacion);
    }
}



