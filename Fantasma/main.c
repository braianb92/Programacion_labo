#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_strings.h"
#include "libro.h"
#include "autor.h"
#include "socio.h"

#define LEN_AUTOR 3
#define LEN_LIBRO 3
#define REINTENTOS 3

int main()
{
    Autor autores[LEN_AUTOR];
    Libro libros[LEN_LIBRO];

    int option=0;
    int flagAltaAutor=0;
    int flagAltaLibro=0;

    while(option!=5)
    {
        printf("\n1)AUTORES\n2)LIBRO\n3)SOCIO\n4)PRESTAMOS\n5)Salir\n");
        getIntInRange(&option,"\n   Ingrese Opcion: ","\nDATO NO VALIDO\n",
                    1,5,REINTENTOS);
        switch(option)
        {
            case 1:
                if(!autor_menu(autores,LEN_AUTOR,"\n1)Alta\n2)Modificacion\n3)Baja\n"
                    "4)Informar\n5)Regresar (menu principal)\n",5,REINTENTOS))
                {
                    flagAltaAutor=1;
                }
                else
                {
                    printf("\n--No se realizo el alta!--\n");
                }
                break;

            case 2:
                if(flagAltaAutor)
                {
                    if(!libro_menu(libros,autores,LEN_LIBRO,LEN_AUTOR,
                        "\n1)Alta\n2)Modificacion\n"
                        "3)Baja\n4)Listar\n5)Regresar (menu principal)",5,REINTENTOS))
                    {
                        flagAltaLibro=1;
                    }
                    else
                    {
                        printf("\n--No se realizo el alta de libro!--\n");
                    }
                }
                else
                {
                    printf("\n--No hay AUTORES en la nomina!\n--");
                }
                break;
            case 3:
            if
        }
    }

    return 0;
}
