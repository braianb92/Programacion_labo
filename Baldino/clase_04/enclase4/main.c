#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int num;

    utn_getInt(&num,100,1,"Ingrese un numero de 1 a 100: ","Error",4);
    if(num>1 && num<100)
    {
    printf("El numero ingresado es: %d",num);
    }

    return 0;
}
