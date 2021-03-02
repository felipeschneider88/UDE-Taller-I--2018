#include "../include/FuncionPredefinida.h"

Boolean EsFuncionPredefinida(ConstString str)
{
    Boolean pertenece = FALSE;

    if ( EsIgualString(str, "SUM") ||
         EsIgualString(str, "RES") ||
         EsIgualString(str, "MUL") ||
         EsIgualString(str, "DIV") ){
        pertenece = TRUE;
    }

    return pertenece;
}


void ParsearFuncionPredefinida(ConstString str, FuncionPredefinida &funcion)
{
    funcion = SUM;

    switch (str[0]) {
        case 'R': funcion = RES; break;
        case 'M': funcion = MUL; break;
        case 'D': funcion = DIV; break;
    }
}


void CargarFuncionPredefinida(FuncionPredefinida &func, FILE * archivo)
{
    fread(&func,sizeof(FuncionPredefinida),1,archivo);
}


void GuardarFuncionPredefinida(FuncionPredefinida func, FILE * archivo)
{
    fwrite(&func, sizeof(FuncionPredefinida), 1, archivo);
}
