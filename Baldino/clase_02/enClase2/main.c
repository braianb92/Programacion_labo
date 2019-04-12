#include <stdio.h>
#include <stdlib.h>

//pedir numeros indefinidos, salir con -1 y mostrar maximo y minimo ingresado.
int bucle();

int main()
{
    int bucle();
    return 0;
}

int bucle()
{
    int auxInt;
    int maximo;
    int minimo;
    do
    {
        printf("Ingrese un numero: ");
        scanf("%d",&auxInt);
        maximo=auxInt;
        minimo=auxInt;

        if(auxInt>maximo)
        {
            maximo=auxInt;
        }
        if(auxInt<minimo)
        {
            minimo=auxInt;
        }
    }while(auxInt!=-1);
    printf("El numero maximo ingresado fue: %d",(int)maximo);
    printf("El numero minimo ingresado fue: %d",(int)minimo);
    return 0;
}
