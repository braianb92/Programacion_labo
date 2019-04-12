/******************************************************************
* Programa: Ejemplo Clase 3
*
* Objetivo:
*   -Crear una función que permita ingresar un numero al usuario y lo retorne.
*   -Crear una función que reciba el radio de un círculo y retorne su área
*   -Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
*    el área de un círculo cuyo radio es ingresado por el usuario
*   -Documentar las funciones al estilo Doxygen
*
* Aspectos a destacar:
*   -Declaración de funciones que devuelven y reciben valores
*   -Hacer notar que el uso de funciones evita el código repetido y ayuda a que
*    el mismo sea mas legible
*   -La función debería comenzar indicando el objetivo que persigue y el
*    significado de sus parámetros.
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/


#include <stdio.h>
#include <stdlib.h>

// Prototipos de las funciones
float getNum();
float calculateCircleArea(float radio);


int main()
{
    float auxNumR;
    float area;
    auxNumR = getNum();
    area = calculateCircleArea(auxNumR);
    printf("El area del circulo es: %.2f",(float)area);
    return 0;
}

/**
*\brief Ask user for a number
*\param auxNum num entered
*\return auxNum
*
*/

float getNum()
{
    float auxNum;
    printf("Ingrese un numero: ");
    scanf("%f",&auxNum);
    return auxNum;
}

float calculateCircleArea(float radio)
{
    float result;
    result = 3.14 * radio * radio;
    return result;
}




