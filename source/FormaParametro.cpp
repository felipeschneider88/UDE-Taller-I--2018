#include "../include/FormaParametro.h"


void GuardarFormaParametro(FILE *archivo, FormaParametro forma)
{
    int i;
    switch(forma)
    {
    case ENTERO:
        i = 0;
        break;
    case VARIABLE:
        i = 1;
        break;
    case FUNCION:
        i = 2;
        break;
    }
    fwrite(&i,sizeof(int),1,archivo);
}

void CargarFormaParametro(FILE *archivo, FormaParametro &forma)
{
    int i;
    fread(&i,sizeof(int),1,archivo);
    switch(i)
    {
        case 0:
            forma = ENTERO;
            break;
        case 1:
            forma = VARIABLE;
            break;
        case 2:
            forma = FUNCION;
            break;
    }
}

void ParsearFormaParametro(ConstString str, CodigoError &codigo, FormaParametro &forma)
{
    codigo = SIN_ERROR;
    //FormaParametro forma = NULL;

    if (EsFuncionPredefinida(str)) {
        forma = FUNCION;
    } else if (EsNumericaString(str)) {
        forma = ENTERO;
    } else if (EsAlfabeticaString(str)) {
        forma  = VARIABLE;
    } else {
        codigo = NO_ES_FORMA_PARAMETRO_VALIDA;
    }
}
