#include "../include/TipoOperacion.h"

void ParsearTipoOperacion(ListaPalabras listaPal, CodigoError &cError, TipoOperacion &tipoOp)
{
    cError = SIN_ERROR;
    int cantPal = ContarPalabras(listaPal);
    if(cantPal == 1) {
        ConstString palIzq = DarStringPalabra(DarPrimerPalabra(listaPal));
        if(EsIgualString(palIzq, "compilar") || EsIgualString(palIzq, "ejecutar")) {
            cError = FALTA_NOMBRE_PROGRAMA_TIPO_OPERACION;
        } else if(EsIgualString(palIzq, "ayuda")){
            tipoOp = AYUDA;
        } else if(EsIgualString(palIzq, "info")){
            tipoOp = INFORMACION;
        } else if (EsIgualString(palIzq,"salir")) {
            tipoOp = SALIR;
        } else {
            cError = OPERACION_DESCONOCIDA_TIPO_OPERACION;
        }
    } else if(cantPal == 2) {
        Palabra* primerPal = DarPrimerPalabra(listaPal);
        ConstString strIzq = DarStringPalabra(primerPal);
        if (EsIgualString(strIzq, "compilar")) {
            tipoOp = COMPILAR;
        } else if(EsIgualString(strIzq, "ejecutar")) {
            tipoOp = EJECUTAR;
        } else if(EsIgualString(strIzq, "ayuda")) {
            ConstString strDer = DarStringPalabra(DarSiguientePalabra(primerPal));
            if (EsIgualString(strDer, "compilar")) {
                tipoOp = AYUDA_COMPILAR;
            } else if (EsIgualString(strDer, "ejecutar")) {
                tipoOp = AYUDA_EJECUTAR;
            } else if (EsIgualString(strDer, "editar")) {
                tipoOp = AYUDA_EDITAR;
            } else {
                cError = OPERACION_DESCONOCIDA_TIPO_OPERACION;
            }
        }
        else
        {
            if(EsIgualString(strIzq, "editar"))
                tipoOp = EDITAR;
            else
                cError = OPERACION_DESCONOCIDA_TIPO_OPERACION;
        }
    } else {
        cError = CANTIDAD_PALABRAS_INCORRECTA_TIPO_OPERACION;
    }
}
