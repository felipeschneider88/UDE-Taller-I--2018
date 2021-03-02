#include "../include/String.h"


void CrearStringVacio(String &str)
{
    str = new char;
    *str = '\0';
}


Boolean  EsNumericaString(ConstString str)
{
    int i = 0;
    Boolean es = TRUE;
    while (str[i] != '\0' && es)
    {
        //Comprueba el caracter con el codigo ASCII
        if (str[i]<48 || str[i]>57)
            es = FALSE;
        i++;
    }
    return es;
}


Boolean  EsAlfabeticaString(ConstString str)
{
    int i = 0;
    Boolean es = TRUE;
    while (str[i] != '\0' && es)
    {
        // Comprueba el caracter con el codigo ASCII
        if ((int) str[i]<65 || (int) str[i]>122)
        {
            es = FALSE;
        }
        else
        {
            //Caracteres ASCII no validos entre los uppercase y los lowercase
            if ((int) str[i]>90 && (int) str[i]<97)
                es = FALSE;
        }
        i++;
    }
    return es;
}


int ParsearEntero(ConstString str)
{
    int cur = LargoString(str) - 1;
    int exp = 1;
    int sum = 0;
    while(cur > -1) {
        int aporte;
        switch(str[cur])
        {
            case '0': aporte = 0; break;
            case '1': aporte = 1; break;
            case '2': aporte = 2; break;
            case '3': aporte = 3; break;
            case '4': aporte = 4; break;
            case '5': aporte = 5; break;
            case '6': aporte = 6; break;
            case '7': aporte = 7; break;
            case '8': aporte = 8; break;
            case '9': aporte = 9; break;
            default: aporte = -1;
        }
        sum += aporte * exp;
        exp *= 10;
        cur--;
    }
    return sum;
}


int LargoString(ConstString str)
{
    int largo = 0;
    while (str[largo] != '\0')
    {
        largo ++;
    }
    return largo;
}


void CopiarString (String &destino, ConstString origen)
{
    delete [] destino;
    destino = new char[LargoString(origen) + 1];
    int i = 0;
    while (origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }
    destino[i]='\0';
}

void LeerString(String &str)
{
    delete [] str;
    char tempStr[STRMAX];
    int i = 0;
    char c;
    fflush(stdin);
    scanf("%c", &c);
    while (c != '\n' && i < (STRMAX -1))
    {
        tempStr[i] = c;
        i++;
        scanf("%c", &c);
    }

    tempStr[i] = '\0';
    CopiarString(str,tempStr);

}


void ConcatenarString (String &s1, ConstString s2)
{
    String old_s1 = s1;
    int largo = LargoString(s1) + LargoString(s2) + 1;
    if (largo > STRMAX)
        largo = STRMAX;
    s1 = new char[largo];
    int i = 0;
    while (old_s1[i] != '\0')
    {
        s1[i] = old_s1[i];
        i++;
    }
    delete[] old_s1;
    int j = 0;
    while (s2[j] != '\0' && i < STRMAX-1)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
}



void IntercambiarString (String &s1, String &s2)
{

    String aux;
    aux = s2;
    s2 = s1;
    s1= aux;
}


void MostrarString (ConstString str)
{
    int i=0;
    while(str[i] != '\0')
    {
        printf("%c", str[i]);
        i++;
    }
}


Boolean EsMenorString (ConstString s1, ConstString s2)
{

    int i = 0;
    Boolean encontre = FALSE;
    Boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;


}


Boolean EsIgualString(ConstString str1, ConstString str2)
{

    Boolean iguales = TRUE;
    Boolean fin = FALSE;
    while(iguales && !fin)
    {
        if(*str1 == '\0') fin = TRUE;
        if (*str2 == '\0') fin = TRUE;
        if(*str1 != *str2) iguales = FALSE;
        str1++;
        str2++;
    }
    return iguales;
}


void GuardarString(ConstString str, FILE* archivo)
{
    while(*str != '\0'){
        fwrite(str, sizeof(char), 1, archivo);
        str++;
    }
    fwrite(str, sizeof(char), 1, archivo);
}


void LiberarString(String &str){
    delete[] str;
}


void CargarString(String &str, FILE* archivo)
{
    delete[]str;
    char tempStr[STRMAX];
    int i = 0;
    char c;
    fread(&c,sizeof(char),1,archivo);
    while (c != '\0' && !feof(archivo))
    {
        tempStr[i] = c;
        i++;
        fread(&c,sizeof(char),1,archivo);
    }
    tempStr[i] = '\0';
    CopiarString(str,tempStr);
    /*
    if(!feof(archivo))
    {
        while(dummy != '\0')
            fread(&dummy, sizeof(char), 1, archivo);
        int pos_ultimo_char = ftell(archivo);
        int char_count = pos_ultimo_char - pos_primer_char;
        String s = new char[char_count];
        fseek(archivo, pos_primer_char, SEEK_SET);
        fread(s, sizeof(char), char_count, archivo);
    }
    */
}


void SepararDireBaseString(ConstString filePath, String &dire, String &base)
{
    int curFilePath = LargoString(filePath);

    /* Partiendo del final, coloco el cursor en la primer barra o al comienzo del string */
    while(filePath[curFilePath] != '/' && curFilePath > 0)
    {
        curFilePath--;
    }

    /* Copio del filePath hasta donde dejé el cursor */
    char bufferDire[STRMAX];
    int curDire = 0;
    while(curDire < curFilePath)
    {
        bufferDire[curDire] = filePath[curDire];
        curDire++;
    }
    bufferDire[curDire] = '\0';

    /* Si quedé en una barra la salteo */
    if (filePath[curFilePath] == '/') curFilePath++;

    /* Copio desde filePath desde donde dejé el cursor y hasta el final */
    char bufferBase[STRMAX];
    int curBase = 0;

    while(filePath[curFilePath] != '\0')
    {
        bufferBase[curBase] = filePath[curFilePath];
        curFilePath++;
        curBase++;
    }
    bufferBase[curBase] = '\0';

    /* Creo y copio los string */
    CopiarString(dire, bufferDire);
    CopiarString(base, bufferBase);
}


void LeerSiguienteLineaString(FILE* archivo, String &str)
{
    /* Si no hay nada en el archivo la string queda nula */
    char nextChar;
    if (fscanf(archivo, "%c", &nextChar) != 1) {
        LiberarString(str);
        str = NULL;
    }

    /* Si hay una línea que leer */
    if (str != NULL) {
        /* En caso contrario guardo el caracter leído */
        char buffer[STRMAX];
        int cur = 0;
        buffer[cur] = nextChar;
        cur++;

        /* Continúo leyendo mientras no llegue al final */
        while((fscanf(archivo, "%c", &nextChar) == 1) && (nextChar != '\n'))
        {
            /* Guardo el caracter */
            buffer[cur] = nextChar;

            /* Avanzo el cursor */
            cur++;
        }

        /* Inserto el fin de cadena */
        buffer[cur] = '\0';

        /* Copio el buffer al string */
        CopiarString(str, buffer);
    }
}


void LeerLineaNString(FILE* archivo, int n, String &str)
{
    /* Descarto lineas caracter a caracter hasta llegar a la línea n-1 */
    char nextChar;
    int numLinea = 1;
    while(numLinea < n && (fscanf(archivo, "%c", &nextChar) == 1))
    {
        if(nextChar == '\n') numLinea++;
    }

    /* Leo la línea n */
    LeerSiguienteLineaString(archivo, str);
}
