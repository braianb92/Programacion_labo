#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraynuevo.h"
#define LEN_LIST 100


int main()
{
    char nombres[100][56];
    int i;
    int opcion;
    char buffer[20];
    int aux;
    int posEncontrada;
    //EJEMPLO
    /*strncpy(nombres[0], "toto",20);
    strncpy(nombres[1], "lala",20);
    printf("nombre:%s\n",nombres[0]);
    printf("nombre:%s\n",nombres[1]);*/

    //INICIALIZACION
    for(i=0;i<LEN_LIST;i++)
    {
        nombres[i][0]='\0';
        //nombres[0][0]='A';
        //nombres[1][0]='B';
    }
    while(1)
    {
        getNumber( &opcion,
                    "1)INGRESAR NOMBRE: \n2)LISTAR\n3)ORDENAR\n4)BORRAR NOMBRE\n",
                    "error ",
                    1,10,2);
        printf("elegiste:%d --> ",opcion);
        switch(opcion)
        {
            case 1:
            {
                printf("Agregar nombre\n");
                if(buscarLibre(nombres,&aux,LEN_LIST)==0)
                {
                printf("se encontro lugar en %d\n",aux);
                getString(buffer,"ingrese texto: ","NO!",0,20,2);
                printf("Se ingreso: %s\n",buffer);
                //nombres[aux]=buffer;
                strncpy(nombres[aux],buffer,20);

                }
                break;
            }
            case 2:
            {
                for(i=0;i<10;i++)
                {
                    printf("%d: %s\n",i,nombres[i]);
                }
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                buscarNombre(buffer,nombres,LEN_LIST,&posEncontrada);
                printf("El nombre encontrado esta en la posicion: %d\n",posEncontrada);
            }
        }



    }
    return 0;
}
