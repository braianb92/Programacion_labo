#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
#define TAM_ARRAY 5

int main()
{
    int array[TAM_ARRAY];
    utn_getArrayInt(array,TAM_ARRAY,100,0,3,"Ingrese numero: ","Error ");
    showArray(array,TAM_ARRAY);
    orderArray(array,TAM_ARRAY);
    showArray(array,TAM_ARRAY);

    return 0;
}
