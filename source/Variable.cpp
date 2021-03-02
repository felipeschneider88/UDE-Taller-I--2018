#include "../include/Variable.h"


void CrearVariable(ConstString nombre, Variable &var)
{

    CrearStringVacio(var.nombre);
    CopiarString(var.nombre, nombre);
    var.valor = 0;
}


ConstString DarNombreVariable(Variable variable)
{
    return variable.nombre;

}


int DarValorVariable(Variable variable)
{
    return variable.valor;
}


void CambiarValorVariable(int nuevoValor, Variable* variable)
{
    variable->valor = nuevoValor;
}


void LiberarVariable(Variable &variable)
{
    LiberarString(variable.nombre);
}

void GuardarVariable(FILE* archivo, Variable var)
{
    GuardarString(var.nombre, archivo);
}


void CargarVariable(FILE* archivo, Variable &var)
{
    CrearStringVacio(var.nombre);
    CargarString(var.nombre, archivo);
}
