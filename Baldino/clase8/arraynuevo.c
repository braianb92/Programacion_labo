#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"


int getString(  char *pResultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)

{
    char bufferStr[4000];
    printf("%s",msg);
    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1] = '\0';

    strncpy(pResultado,bufferStr,20);


    return 0;

}

int isValidIntNumber (char* cadena)
{
    return 1;

}

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos)
{
    int retorno = -1;
    char bufferStr[4000];
    int bufferInt;

    if( resultado != NULL &&
        reintentos >= 0) //FALTAN
    {
        if(!getString(bufferStr,msg,msgError,1,6,1) &&
            isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *resultado = bufferInt;
            }
        }
    }
    return retorno;
}

int buscarLibre (char pArray[][56],int* pIndex,int len ) //HARDCODEO PORQUE ES ASI NO QUEDA OTRA
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pArray[i][0]=='\0')
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}

int buscarNombre(char* name, char parray[][56], int len, int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(strcmp(name,parray[i])==0)
        {
            *pIndex=i;
            ret=0;
            break;
        }
    }
    return ret;
}
