#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int getFloat (float* pNum, char* msg, char* msgE)
{
    float number;
    int ret=-1;

    do
    {
        printf("%s",msg);
        if(scanf("%f",&number)==1)
        {
            *(pNum)=number;
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

int getInt (int* pNum, char* msg, char* msgE)
{
    int number;
    int ret=-1;

    do
    {
        printf("%s",msg);
        if(scanf("%d",&number)==1)
        {
            *(pNum)=number;
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

int getChar(char* pChar, int len, char* msg)
{
    char txt[len];

    printf("%s",msg);
    gets(txt);
    pChar=txt;
    return 0;
}

int getArray(int* pArray,int len,char* msg, char* msgE)
{
    int i;
    int buffer;
    int ret;

    for(i=0;i<len;i++)
    {
        ret=getInt(&buffer,msg, msgE);

        if(ret)
        {
            break;
        }
        *(pArray+i)=buffer;
    }
    return 0;
}

int showArray(int* pArray,int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\n",pArray[i]);
    }
    return 0;
}

int promedio(int* pNum, int len, float *promResult)
{
    int i;
    int ret=-1;
    int sum=0;

    if(pNum!=NULL && len>0 && promResult!=NULL)
    {
        for(i=0;i<len;i++)
        {
            sum+=pNum[i];
        }
        *promResult=sum/len;
        ret=0;
    }

    return ret;
}

int maxArray(int* pArray,int len, int* maximo)
{
    int i;
    int buffer;
    int ret=-1;

    buffer=pArray[0];
    if(pArray!=NULL && len>0 && maximo!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(pArray[i]>buffer)
            {
                buffer=pArray[i];
            }
        }
        *maximo=buffer;
        ret=0;
    }
    return ret;
}

int minArray(int* pArray,int len, int* minimo)
{
    int i;
    int buffer;
    int ret=-1;

    buffer=pArray[0];
    if(pArray!=NULL && len>0 && minimo!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(pArray[i]<buffer)
            {
                buffer=pArray[i];
            }
        }
        *minimo=buffer;
        ret=0;
    }
    return ret;
}

int orderArrayGrowing(int* pArray, int len)
{
    int buffer;
    int i;
    int flagSwap=0;
    while(flagSwap==0)
    {
        flagSwap=1;
        for(i=1;i<len;i++)
        {
            if(pArray[i]<pArray[i-1])
            {
                buffer=pArray[i];
                pArray[i]=pArray[i-1];
                pArray[i-1]=buffer;
                flagSwap=0;
            }
        }
    }
    return 0;
}

int orderArrayDecreasing(int* pArray, int len)
{
    int buffer;
    int i;
    int flagSwap=0;
    while(flagSwap==0)
    {
        flagSwap=1;
        for(i=1;i<len;i++)
        {
            if(pArray[i]>pArray[i-1])
            {
                buffer=pArray[i];
                pArray[i]=pArray[i-1];
                pArray[i-1]=buffer;
                flagSwap=0;
            }
        }
    }
    return 0;
}

int findNum (int* pArray, int len, char* msgAsk,char* msgFound, char* msgNotFound)
{
    int i;
    int num;
    int flag=0;

    printf("%s\n",msgAsk);
    scanf("%d",&num);

    for(i=0;i<len;i++)
    {
        if(num==pArray[i])
        {
            printf("%s%d\n",msgFound,i+1);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("%s\n",msgNotFound);
    }
    return 0;
}

int valueModifier (int* pNum, int len)
{
    int i;
    int aux;
    int num;
    int ret=-1;

    do
    {
        printf("Ingrese posicion del valor: ");
        if(scanf("%d",&aux)==1);
        {
            i=aux;
        }
        fflush(stdin);
        printf("Ingrese nuevo valor: ");
        if(scanf("%d",&num)==1);
        {
            pNum[i-1]=num;
            ret=0;
        }
        fflush(stdin);
    }while(ret==-1);
    return ret;
}
