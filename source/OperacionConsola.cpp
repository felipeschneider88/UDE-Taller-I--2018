#include "../include/OperacionConsola.h"


void ParsearOperacionConsola(ListaPalabras listaPal, CodigoError &cError, OperacionConsola &opCon)
{
    ParsearTipoOperacion(listaPal, cError, opCon.tipoOp);
    if(cError == SIN_ERROR){
        if (ContarPalabras(listaPal) == 2)
        {
            ConstString strDer = DarStringPalabra(DarSiguientePalabra(DarPrimerPalabra(listaPal)));
            CrearStringVacio(opCon.dire);
            CrearStringVacio(opCon.nomProg);
            SepararDireBaseString(strDer, opCon.dire, opCon.nomProg);
            if(!EsAlfabeticaString(opCon.nomProg))
            {
                cError = NOMBRE_PROGRAMA_INVALIDO;
                LiberarString(opCon.dire);
                LiberarString(opCon.nomProg);
            }
        }
    }
}


void EjecutarOperacionConsola(OperacionConsola opCon)
{
    switch(opCon.tipoOp){
    case COMPILAR:
        {
            FILE * archivoCSIM = AbrirCodigoFuentePrograma(opCon.dire, opCon.nomProg);
            if (archivoCSIM != NULL)
            {
                // Parsear
                Programa prog;
                CodigoError cError;
                int numLineaError;
                ParsearPrograma(archivoCSIM, opCon.nomProg, cError, numLineaError, prog);

                if(cError == SIN_ERROR){
                    // Guardar
                    GuardarPrograma(opCon.dire, cError, prog);

                    if(cError == SIN_ERROR){
                        // Limpiar
                        LiberarPrograma(prog);
                        MostrarString(opCon.nomProg);
                        printf(" compilado exitosamente\n");
                    } else {
                        // Mostrar el error de guardado
                        printf("Error de guardado: ");
                        MostrarCodigoError(cError);
                        printf("\n");
                    }
                } else {
                    // Mostrar el error de compilacion
                    printf("Error de compilacion: ");
                    MostrarCodigoError(cError);
                    printf("\n");

                    // Imprimir numero de linea
                    printf("En linea %i: \"", numLineaError);

                    // Ir al principio del archivo y luego leer y mostrar la linea con error
                    fseek(archivoCSIM, 0, SEEK_SET);
                    String lineaConError;
                    CrearStringVacio(lineaConError);
                    LeerLineaNString(archivoCSIM, numLineaError, lineaConError);
                    MostrarString(lineaConError);
                    printf("\"\n");

                    // Limpiar
                    LiberarString(lineaConError);
                }
                fclose(archivoCSIM);
            }
            else
            {
                printf("Error abriendo codigo fuente\n");
            }
        } break;
    case EJECUTAR:
        {
            // Cargar
            Programa prog;
            CodigoError cError;
            CargarPrograma(opCon.dire, opCon.nomProg, cError, prog);

            if(cError == SIN_ERROR){
                // Ejecutar.
                CodigoError cError;
                int numLineaError;
                EjecutarPrograma(cError, numLineaError, prog);
                if (cError != SIN_ERROR){
                    // Mostrar el error de ejecucion
                    printf("Error de ejecucion: ");

                    // Imprimir numero de linea
                    printf("En linea %i: \"", numLineaError);

                    // Abrir el código de fuente del programa
                    FILE* codigoFuente = AbrirCodigoFuentePrograma(opCon.dire, opCon.nomProg);
                    if (codigoFuente != NULL) {
                        // Cargar y mostrar la linea con error
                        String lineaConError;
                        CrearStringVacio(lineaConError);
                        LeerLineaNString(codigoFuente, numLineaError, lineaConError);
                        MostrarString(lineaConError);
                        printf("\"\n");

                        // Limpiar
                        LiberarString(lineaConError);
                        fclose(codigoFuente);
                    } else {
                        MostrarString("ERROR ABRIENDO CODIGO FUENTE\"\n");
                    }
                    printf("\n");
                }

                // Limpiar
                LiberarPrograma(prog);
            }
            else
            {
                // Mostrar el error de Carga
                printf("Error cargando el programa: ");
                MostrarCodigoError(cError);
                printf("\n");
            }
        }break;
    case AYUDA:
        printf("Operaciones disponibles:\n");
        printf("  compilar [NOMBRE_PROGRAMA]\n");
        printf("  ejectuar [NOMBRE_PROGRAMA]\n");
        printf("  editar [NOMBRE_PROGRAMA]\n");
        printf("  ayuda compilar\n");
        printf("  ayuda ejecutar\n");
        printf("  ayuda editar\n");
        printf("  info\n");
        printf("  salir\n");
        break;
    case AYUDA_COMPILAR:
        printf("compilar [NOMBRE_PROGRAMA]: Compila el programa \"[NOMBRE_PROGRAMA].csim\"\n");
        printf("  Al terminar correctamente, el programa queda listo para ser ejecutado\n");
        break;
    case AYUDA_EJECUTAR:
        printf("ejecutar [NOMBRE_PROGRAMA]: Ejecuta un programa previamente compilado\n");
        break;
    case AYUDA_EDITAR:
        printf("editar [NOMBRE_PROGRAMA]: Abre el codigo fuente del programa en notepad.exe\n");
        break;
    case INFORMACION:
        printf("Version del compilador: CalcuSimple Entrega Final\n");
        printf("Materia: Taller 1 2018\n");
        printf("Origen: Universidad de la Empresa\n");
        printf("Equipo: Washington Chocho\n");
        printf("        Felipe Schneider\n");
        printf("        Nicolas Berrogorry\n");
        break;
    case EDITAR:
        String comandoNotepad;
        CrearStringVacio(comandoNotepad);
        ConcatenarString(comandoNotepad, "notepad.exe ");
        if(!EsIgualString(opCon.dire, ""))
        {
            ConcatenarString(comandoNotepad, opCon.dire);
            ConcatenarString(comandoNotepad, "/");
        }
        ConcatenarString(comandoNotepad, opCon.nomProg);
        ConcatenarString(comandoNotepad, ".csim");
        system(comandoNotepad);
        LiberarString(comandoNotepad);
        break;
    case SALIR:
        printf(" Hasta la proxima.\n");
        break;
    }
}

void LiberarOperacionConsola(OperacionConsola &opCon)
{
    if(opCon.tipoOp != SALIR)
    {
        LiberarString(opCon.dire); // Solo COMPILAR y EJECUTAR crean dire.
        LiberarString(opCon.nomProg);  // Solo COMPILAR y EJECUTAR crean nomProg.
    }
}
