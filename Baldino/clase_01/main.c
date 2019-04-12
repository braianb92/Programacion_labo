#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_REP 3  // lo voy a usar para promedio y contador.

int pedirAcumularMostrarPromedio()
{
    int acumulador=0;
    int buffer; //variable auxiliar
    int i;
    for(i=0;i<CANTIDAD_REP;i++)
    {
        printf("In Numero %d: ",i+1);
        scanf("%d",&buffer);
        //FALTA VALIDAR
        acumulador=acumulador+buffer;
    }
    printf("El promedio es: %f",acumulador / CANTIDAD_REP);
    return 0;

}
int pedirSumarMostrar() //la funcion no termina en ";".
{
    int variable1;
    int variable2;
    int resultado;

    printf("In Numero 1: ");
    scanf("%d",&variable1);
    printf("In Numero 2: ");
    scanf("%d",&variable2);
    resultado = variable1 + variable2;
    printf("El resultado es: %d",resultado);
    return 0;
}

int main()
{
    if(!pedirSumarMostrar()) //o == 0
    {
        printf("\nATR");
    }
    return 0;
}
