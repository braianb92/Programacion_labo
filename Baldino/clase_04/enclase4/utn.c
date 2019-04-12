#include <stdio.h>


int utn_getInt (int* pNum, int max, int min,char* msg,char* msgE, int tries)
{
    int numero;
    int ret=-1;

    while(tries>0)
    {
        printf("%s",msg);
        if(scanf("%d",&numero));
        {
            if(numero<max && numero>min)
            {
                *pNum=numero;
                ret=0;
                break;
            }
            tries--;
            printf("%s",msgE);
        }

    return ret;
    }

float utn_getFloat (float* pNum, int max, int min,char* msg,char* msgE)
{
    float number;
    int ret;

    printf("%s",msg);
    scanf("%f",&number);

    if(number<max && number>min)
    {
        *pNum=number;
        ret=0;
    }
    else
    {
        printf("%s",msgE);
        *pNum=number;
        ret=-1;
    }

    return ret;
}

