#include "../include/TipoInstruccion.h"


void ParsearTipoInstruccion(ListaPalabras listaPal, CodigoError &cError, TipoInstruccion &tipoInst)
{
    cError = SIN_ERROR;
    Palabra* pal = DarPrimerPalabra(listaPal);
    switch (ContarPalabras(listaPal))
    {
    case 2:
        {
            ConstString palStr = DarStringPalabra(pal);
            if(EsIgualString(palStr, "MOSTRAR")){
                tipoInst = MOSTRAR;
            } else if(EsIgualString(palStr, "LEER")){
                tipoInst = LEER;
            } else {
                cError = NO_ES_LEER_NI_MOSTRAR_TIPO_INSTRUCCION;
            }
        }break;
    case 3: case 5:
        {
            pal = DarSiguientePalabra(pal);
            if (EsIgualString(DarStringPalabra(pal), "=")) {
                tipoInst = ASIGNAR;
            } else {
                cError =  SE_ESPERABA_SIGNO_IGUAL_TIPO_INSTRUCCION;
            }
        }break;
    default :
        cError = CANTIDAD_PALABRAS_INCORRECTA_TIPO_INSTRUCCION;
        break;
    }
}


void GuardarTipoInstruccion(TipoInstruccion tInst, FILE * archivo)
{
    fwrite(&tInst, sizeof(TipoInstruccion), 1, archivo);
}


void CargarTipoInstruccion(TipoInstruccion &tInst, FILE * archivo)
{
    fread(&tInst,sizeof(TipoInstruccion),1,archivo);
}



