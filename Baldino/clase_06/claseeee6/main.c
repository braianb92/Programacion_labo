#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "array.h"
#define LEN 5

int main()
{
    int opcion;
    char seguir='s';
    int numeros[LEN];
    float prom;
    int max;
    int min;

    while(seguir=='s')
    {
        system("color 06");
        printf("--------Generador array--------\n");
        printf("-------------------------------\n");
        printf("1-Cargar Array\n");
        printf("2-Buscar valor\n");
        printf("3-Calcular promedio\n");
        printf("4-Buscar valor maximo\n");
        printf("5-Buscar valor minimo\n");
        printf("6-Ordenar creciente\n");
        printf("7-Ordenar decreciente\n");
        printf("8-Modificar valor\n");
        printf("9-Mostrar array\n");
        printf("10-Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                getArray(numeros,LEN,"Ingrese valor: ","Error\n");
                break;
            case 2:
                findNum(numeros,LEN,"Ingrese valor a buscar: ","Se encontro el valor en la posicion: ","No se encontro el valor\n");
                break;
            case 3:
                promedio(numeros,LEN,&prom);
                printf("El promedio es: %.2f\n",prom);
                break;
            case 4:
                maxArray(numeros,LEN,&max);
                printf("El valor maximo es: %d\n",max);
                break;
            case 5:
                minArray(numeros,LEN,&min);
                printf("El valor minimo es: %d\n",min);
                break;
            case 6:
                orderArrayGrowing(numeros,LEN);
                break;
            case 7:
                orderArrayDecreasing(numeros,LEN);
                break;
            case 8:
                valueModifier(numeros,LEN);
                break;
            case 9:
                showArray(numeros,LEN);
                break;
            case 10:
                seguir='n';
                break;
        }
    }
    return 0;
}
