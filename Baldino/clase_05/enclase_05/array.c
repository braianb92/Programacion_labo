#include <stdio.h>
#include <string.h>

int utn_getNumberRanged(int *pNumber, int max, int min, char* msg, char* msgError, int tries)
{
    int number;
    int ret = -1;

    while(tries>0)
    {
        printf("%s",msg);
        if (scanf("%d", &number)==1)
        {
            if (number>min && number<max)
            {
                *pNumber = number;
                ret = 0;
                break;
            }
        }
    printf("%s\n", msgError);
    tries--;
    fflush(stdin);
    //fpurge(stdin);
    }
return ret;
}

int utn_getInt (int *pNum, char* msg, char* msgE)
{
    int number;
    int ret=-1;

    do
    {
        printf("%s",msg);
        if(scanf("%d",&number)==1)
        {
            (*pNum)=number;
            ret=0;
        }
        else
        {
            printf("%s",msgE);
        }
        fflush(stdin);
        //fpurge(stdin);

    }while(ret==-1);
    return ret;
}

char utn_getChar (char* pChar,int MAX, char* msg)
{
    char vec[MAX];

    printf("%s",msg);
    gets(vec);
    *(pChar)=vec;
    return 0;
}

int utn_getArrayInt (int* pNumArray,int limit,int max,int min,int tries, char* msg, char* msgE)
{
    int i;
    int buffer;
    int ret;
    for(i=0;i<limit;i++)
    {
        ret=utn_getNumberRanged(&buffer,max,min,msg,msgE,tries);

        if(ret)
        {
            break;
        }
        *(pNumArray+i)=buffer;
    }
    return 0;
}

/**
*\brief Solicita al usuario un numero flotante
*\param *pNum Puntero de numero pedido al usuario
*\param msg Mensaje que pide el ingreso del flotante
*\param msgE Mensaje que se muestra si el dato ingresado no es valido
*\return 0 si esta bien, -1 si esta mal
*/
float utn_getFloat (float *pNum, char* msg, char* msgE)
{
    float number;
    int ret=-1;

    do
    {
        printf("%s",msg);
        if(scanf("%f",&number)==1)
        {
            (*pNum)=number;
            ret=0;
        }
        else
        {
            printf("%s",msgE);
        }
        fflush(stdin);
        //fpurge(stdin);

    }while(ret==-1);
    return ret;
}

int utn_Swap(int* array, int limit)
{
    int i;
    int buffer;
    int ret=-1;

    buffer=array[i];
    array[i]=array[i+1];
    array[i+1]=buffer;
    return 0;
}

int showArray(int array[],int limit)
{
    int i;
    for(i=0;i<limit;i++)
    {
        printf("%d\n",array[i]);
    }
    return 0;
}

void orderArray(int array[],int limit)
{
    int i;
    int flagSwap=0;
    do
    {
        for(i=0;i<limit-1;i++)
        {
            if(array[i]>array[i+1])
            {
                utn_Swap(&array[i],&array[i+1]);
                flagSwap=1;
            }
        }
    }while(flagSwap==1);
}


