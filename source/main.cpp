#include <iostream>

//#include "../include/Menu.h"
#include "../include/Programa.h"
#include "../include/OperacionCOnsola.h"


int main()
{
    /* Declaro variables reutilizadas en el loop principal */
    String inputStr;
    ListaPalabras listaPal;
    CodigoError cError;
    OperacionConsola operCo;

    /* Loop principal */
    do{
        /* Espero por entrada del usuario */
        printf("Ingrese comando: ");
        LeerString(inputStr);

        /* Parseo la operación */
        SepararPalabras(inputStr, listaPal);
        ParsearOperacionConsola(listaPal, cError, operCo);
        if (cError == SIN_ERROR){
            /* Ejecuto la operación parseada */
            EjecutarOperacionConsola(operCo);

            /* Limpieza */
            LiberarOperacionConsola(operCo);
        } else {
            /* Despliego el error de parseo de la operación */
            printf("Error de operacion: ");
            MostrarCodigoError(cError);
            printf("\n");

            /* Reseteo el código de error para la próxima entrada del usuario */
            cError = SIN_ERROR;
        }

        /* Limpieza */
        LiberarListaPalabras(listaPal);
        LiberarString(inputStr);
    } while (operCo.tipoOp != SALIR);
}
