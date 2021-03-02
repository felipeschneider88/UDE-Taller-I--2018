#include "../../include/duplas/DuplaEnteroEntero.h"
#include <assert.h>


void ParsearDuplaEnteroEntero(ListaPalabras argumentos, DuplaEnteroEntero &dupla)
{
    Palabra* pal = DarPrimerPalabra(argumentos);
    dupla.izq = ParsearEntero(DarStringPalabra(pal));
    dupla.der = ParsearEntero(DarStringPalabra(DarSiguientePalabra(pal)));
}


int DarIzqDuplaEnteroEntero(DuplaEnteroEntero dupla)
{
    return dupla.izq;
}



int DarDerDuplaEnteroEntero(DuplaEnteroEntero dupla)
{
    return dupla.der;
}


void CargarDuplaEnteroEntero(DuplaEnteroEntero &dupla, FILE* archivo)
{
    fread(&dupla.izq, sizeof(int), 1, archivo);
    fread(&dupla.der, sizeof(int), 1, archivo);
}


void GuardarDuplaEnteroEntero(DuplaEnteroEntero dupla, FILE* archivo)
{
    fwrite(&dupla.izq, sizeof(int), 1, archivo);
    fwrite(&dupla.der, sizeof(int), 1, archivo);
}
