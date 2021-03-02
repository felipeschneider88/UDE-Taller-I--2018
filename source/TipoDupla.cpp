#include "../include/TipoDupla.h"


void GuardarTipoDupla(TipoDupla dupla, FILE *archivo)
{
    fwrite(&dupla, sizeof(TipoDupla), 1, archivo);
}


void CargarTipoDupla(TipoDupla &dupla, FILE *archivo)
{
    fread(&dupla, sizeof(TipoDupla), 1, archivo);
}


void ParsearTipoDupla(ListaPalabras argumentos, CodigoError &codigoError, TipoDupla &tipoDupla)
{
    codigoError = SIN_ERROR;
    Boolean arg1esNum;
    Boolean arg2esNum;
    Palabra* arg1 = DarPrimerPalabra(argumentos);

    if (EsNumericaString(DarStringPalabra(arg1))){
        arg1esNum = TRUE;
    } else if (DarStringPalabra(arg1)) {
        arg1esNum = FALSE;
    } else {
        codigoError = ARG1_NO_ES_NUM_NI_VAR_TIPO_DUPLA;
    }

    if (codigoError == SIN_ERROR)
    {
        Palabra* arg2 = DarSiguientePalabra(arg1);
        if (EsNumericaString(DarStringPalabra(arg2))){
            arg2esNum = TRUE;
        //} else if (EsValidoNombreVariable(DarStringPalabra(arg2))) {
        } else if (DarStringPalabra(arg2)) {
            arg2esNum = FALSE;
        } else {
            codigoError = ARG2_NO_ES_NUM_NI_VAR_TIPO_DUPLA;
        }
    }

    if (codigoError == SIN_ERROR)
    {
        if (arg1esNum == TRUE && arg2esNum == TRUE) {
            tipoDupla = ENTERO_ENTERO;
        } else if (arg1esNum == TRUE && arg2esNum == FALSE) {
            tipoDupla = ENTERO_VARIABLE;
        } else if (arg1esNum == FALSE && arg2esNum == TRUE) {
            tipoDupla = VARIABLE_ENTERO;
        } else {
            tipoDupla = VARIABLE_VARIABLE;
        }
    }
}
