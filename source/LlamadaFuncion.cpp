#include "../include/LlamadaFuncion.h"


void ParsearLlamadaFuncion(ListaPalabras palabras, ABBVariables variables,
                      CodigoError &codigoError, LlamadaFuncion &llamadaF)
{
    codigoError = SIN_ERROR;

    Palabra* pal = DarPrimerPalabra(palabras);
    ListaPalabras argumentos = DarSiguientePalabra(pal);
    TipoDupla tipoDupla ;
    ParsearTipoDupla(argumentos,codigoError,tipoDupla);
    if (codigoError== SIN_ERROR)
    {
        FuncionPredefinida funcionPredef;
        ParsearFuncionPredefinida(DarStringPalabra(pal), funcionPredef);
        switch (tipoDupla)
        {
        case ENTERO_ENTERO :
            {
                DuplaEnteroEntero duplaEnteroEnt;
                ParsearDuplaEnteroEntero(argumentos, duplaEnteroEnt);
                if (DarDerDuplaEnteroEntero(duplaEnteroEnt)> 0)
                {
                    llamadaF.funcion = funcionPredef;
                    llamadaF.tipoDupla = tipoDupla;
                    llamadaF.enteroEntero = duplaEnteroEnt;
                }
                else
                {
                    codigoError =  DIVISION_ENTRE_CERO_DUPLA_ENTERO_ENTERO;
                }

            } break;
        case ENTERO_VARIABLE :
            {

                DuplaEnteroVariable duplaEnteroVar;
                ParsearDuplaEnteroVariable(argumentos, variables, codigoError, duplaEnteroVar);
                if (codigoError == SIN_ERROR)
                {
                    llamadaF.funcion = funcionPredef;
                    llamadaF.tipoDupla = tipoDupla;
                    llamadaF.enteroVariable = duplaEnteroVar;
                }
            } break;
        case VARIABLE_ENTERO :
            {
                DuplaVariableEntero duplaVariableEnt;
                ParsearDuplaVariableEntero(argumentos, codigoError, duplaVariableEnt, variables);

                if (codigoError == SIN_ERROR)
                {
                    if (DarEnteroDuplaVariableEntero(duplaVariableEnt)> 0){

                    llamadaF.funcion = funcionPredef;
                    llamadaF.tipoDupla = tipoDupla;
                    llamadaF.variableEntero = duplaVariableEnt;

                    }
                    else{
                        codigoError =  DIVISION_ENTRE_CERO_DUPLA_VARIABLE_ENTERO;
                    }

                }
            } break;
        case VARIABLE_VARIABLE :
            {
                DuplaVariableVariable duplaVariableVar;
                ParsearDuplaVariableVariable(argumentos, codigoError,  duplaVariableVar, variables);

                if (codigoError == SIN_ERROR) {
                    llamadaF.funcion = funcionPredef;
                    llamadaF.tipoDupla = tipoDupla;
                    llamadaF.variableVariable = duplaVariableVar;
                }
            } break;
        }
    }
}


FuncionPredefinida DarFuncionPredefinidaLlamadaFuncion(LlamadaFuncion llamadaF)
{
    return llamadaF.funcion;
}


TipoDupla DarTipoDuplaLlamadaFuncion(LlamadaFuncion llamadaF)
{
    return llamadaF.tipoDupla;
}


void CalcularResultadoFuncion(LlamadaFuncion llamadaF, ABBVariables abbvars,  int &resu, CodigoError &cError)
{
    cError = SIN_ERROR;
    int valIzq, valDer;
    switch(llamadaF.tipoDupla)
    {
        case ENTERO_ENTERO:
            valIzq = DarIzqDuplaEnteroEntero(llamadaF.enteroEntero);
            valDer = DarDerDuplaEnteroEntero(llamadaF.enteroEntero);
            break;
        case ENTERO_VARIABLE:
            {
                valIzq = DarEnteroDuplaEnteroVariable(llamadaF.enteroVariable);
                Variable* varDer = DarVariableABBVariables(
                    DarVariableDuplaEnteroVariable(llamadaF.enteroVariable), abbvars);
                valDer = DarValorVariable(*varDer);
            } break;
        case VARIABLE_ENTERO:
            {
                Variable* varIzq = DarVariableABBVariables(
                    DarVariableDuplaVariableEntero(llamadaF.variableEntero), abbvars);
                valIzq = DarValorVariable(*varIzq);
                valDer = DarEnteroDuplaVariableEntero(llamadaF.variableEntero);
            } break;
        case VARIABLE_VARIABLE:
            {
                Variable* varIzq = DarVariableABBVariables(
                    DarIzqDuplaVariableVariable(llamadaF.variableVariable), abbvars);
                valIzq = DarValorVariable(*varIzq);
                Variable* varDer = DarVariableABBVariables(
                    DarDerDuplaVariableVariable(llamadaF.variableVariable), abbvars);
                valDer = DarValorVariable(*varDer);
            } break;
    }

    switch(llamadaF.funcion)
    {
        case SUM: resu = valDer + valIzq; break;
        case RES: resu = valIzq - valDer; break;
        case MUL: resu = valDer * valIzq; break;
        case DIV:
            if(valDer == 0)
                cError = DIVISION_ENTRE_CERO;
            else
                resu = valIzq / valDer;
            break;
    }
}


void GuardarLlamadaFuncion(LlamadaFuncion llamadaF, FILE * archivo)
{
    GuardarFuncionPredefinida(llamadaF.funcion, archivo);
    GuardarTipoDupla(llamadaF.tipoDupla, archivo);
    switch (llamadaF.tipoDupla)
    {
    case ENTERO_ENTERO:
        GuardarDuplaEnteroEntero(llamadaF.enteroEntero, archivo);
        break;
    case ENTERO_VARIABLE:
        GuardarDuplaEnteroVariable(llamadaF.enteroVariable, archivo);
        break;
    case VARIABLE_ENTERO:
        GuardarDuplaVariableEntero(llamadaF.variableEntero, archivo);
        break;
    case VARIABLE_VARIABLE:
        GuardarDuplaVariableVariable(llamadaF.variableVariable, archivo);
        break;
    }
}


void CargarLlamadaFuncion(LlamadaFuncion &llamadaF, FILE * archivo)
{
    CargarFuncionPredefinida(llamadaF.funcion, archivo);
    CargarTipoDupla(llamadaF.tipoDupla, archivo);
    switch (llamadaF.tipoDupla)
    {
        case ENTERO_ENTERO:
            CargarDuplaEnteroEntero(llamadaF.enteroEntero, archivo);
            break;
        case ENTERO_VARIABLE:
            CargarDuplaEnteroVariable(llamadaF.enteroVariable, archivo);
            break;
        case VARIABLE_ENTERO:
            CargarDuplaVariableEntero(llamadaF.variableEntero, archivo);
            break;
        case VARIABLE_VARIABLE:
            CargarDuplaVariableVariable(llamadaF.variableVariable, archivo);
            break;
    }
}


void LiberarLlamadaFuncion(LlamadaFuncion &llamadaF)
{
    switch(llamadaF.tipoDupla){
        case ENTERO_ENTERO: /* No utiliza memoria dinámica */ break;
        case ENTERO_VARIABLE: LiberarDuplaEnteroVariable(llamadaF.enteroVariable); break;
        case VARIABLE_ENTERO: LiberarDuplaVariableEntero(llamadaF.variableEntero); break;
        case VARIABLE_VARIABLE: LiberarDuplaVariableVariable(llamadaF.variableVariable); break;
    }
}
