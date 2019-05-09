#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "autor.h"
#include "utn_strings.h"

#define LEN 3
#define REINTENTOS 3

int main()
{
    Autor autores[LEN];

    int option=0;
    int flag=0;

    while(option!=5)
    {
        printf("\n1)AUTORES\n2)LIBRO\n3)SOCIO\n4)PRESTAMOS\n5)Salir\n");
        getIntInRange(&option,"\n   Ingrese Opcion: ","\nDATO NO VALIDO\n",
                    1,5,REINTENTOS);
        switch(option)
        {
            case 1:
                if(!autor_menu(autores,LEN,"\n1)Alta\n2)Modificacion\n3)Baja\n"
                "4)Informar\n5)Salir\n",5,REINTENTOS));
                {
                    flag=1;
                }
                break;
        }
    }

    return 0;
}
