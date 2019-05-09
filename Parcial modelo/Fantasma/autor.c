#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "autor.h"

static int generarId(void);

int autor_menu(Autor* pAutor,int len, char* menuText,
             int exitMenuNumber,int tries)
{
    int option=0;
    int flag=0;
    char* noAddMsg="\n----AUN NO HAY AUTORES EN LA NOMINA----\n";
    char* addMsg="\n----Alta satisfactoria!----\n";
    char* addMsgE="\n----NO se realizo el Alta----\n";
    char* alterMsg="\n----Se modifico exitosamente!----\n";
    char* alterMsgE="\n----NO se realizo la Modificacion----\n";
    char* removeMsg="\n----Se dio de baja exitosamente!----\n";
    char* removeMsgE="\n----NO se realizo la Baja----\n";
    char* generalMsgE="DATO NO VALIDO\n";

    autor_initAutors(pAutor,len);
    while(option!=exitMenuNumber)
    {
        printf(menuText);

        getIntInRange(&option,"\n   INGRESE OPCION: ",generalMsgE,1,exitMenuNumber,tries);
        switch(option)
        {
            case 1:
                    if(!autor_addAutors(pAutor,len,generalMsgE,tries))
                    {
                        flag=1;
                        printf(addMsg);
                    }
                    else
                    {
                        printf(addMsgE);
                    }
                break;
            case 2:
                if(flag)
                {
                    autor_printAutors(pAutor,len);
                    if(!autor_alter(pAutor,len,generalMsgE,5,tries))
                    {
                        printf(alterMsg);
                    }
                    else
                    {
                        printf(alterMsgE);
                    }
                }
                else
                {
                    printf(noAddMsg);
                }
                break;
            case 3:
                if(flag)
                {
                    if(!autor_removeAutor(pAutor,len,generalMsgE,tries))
                    {
                        printf(removeMsg);
                    }
                    else
                    {
                        printf(removeMsgE);
                    }
                }
                else
                {
                    printf(noAddMsg);
                }
                break;
            case 4:
                if(flag)
                {
                    autor_sortAutors(pAutor,len,1);///order UP
                    autor_printAutors(pAutor,len);
                }
                else
                {
                    printf(noAddMsg);
                }
                break;
        }
    }

    return 0;
}

int autor_addAutors(Autor* pAutor,int len,char* msgE,int tries)
{
    int indexFree;
    char bufferName[50];
    char bufferSurname[50];
    int retorno=-1;
    if((pAutor!=NULL)&&(len>0))
    {
        indexFree=autor_findFree(pAutor,len);
        if((indexFree!=-1)&&(getStringLetras(bufferName,"\nIngrese Nombre: ",msgE,tries)==0)&&
            (getStringLetras(bufferSurname,"\nIngrese Apellido: ",msgE,tries)==0))
        {
            strncpy(pAutor[indexFree].name,bufferName,sizeof(bufferName));
            strncpy(pAutor[indexFree].surname,bufferSurname,sizeof(bufferSurname));
            pAutor[indexFree].idAutor=generarId();
            pAutor[indexFree].isEmpty=0;
            retorno=0;
        }
    }
    return retorno;
}

int autor_alter(Autor* pAutor, int len,char* generalMsgE,int exitAlterMenuNumber,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferName[50];
    char bufferSurname[50];
    char* alterMenuText="\n1-Modificar Nombre\n2-Modificar Apellido\n"
                        "3- Atras (Menu Principal)\n";
    int retorno=-1;

    if((pAutor!=NULL)&&(len>0))
    {
        auxID=autor_getID(pAutor,len,generalMsgE,tries);
        if(auxID>=0)
        {
            posOfID=autor_findAutorById(pAutor,len,auxID);
            if(posOfID!=-1)
            {
                while(opcion!=exitAlterMenuNumber)
                {
                    printf(alterMenuText);
                    getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",generalMsgE,1,
                                  exitAlterMenuNumber,tries);
                    switch(opcion)
                    {
                        case 1:
                        {
                            if(!getStringLetras(bufferName,"\nIngrese NUEVO Nombre: ",generalMsgE,tries))
                            {
                                strncpy(pAutor[posOfID].name,bufferName,sizeof(bufferName));
                                retorno=0;
                            }
                            break;
                        }
                        case 2:
                        {
                            if(!getStringLetras(bufferSurname,"\nIngrese NUEVO Apellido: ",generalMsgE,tries))
                            {
                                strncpy(pAutor[posOfID].surname,bufferSurname,sizeof(bufferSurname));
                                retorno=0;
                            }
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
        }
    }
    return retorno;
}

int autor_removeAutor(Autor* pAutor, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;
    if(pAutor!=NULL && len>0)
    {
        auxID=autor_getID(pAutor,len,msgE,tries);
         if(auxID>=0)
        {
            posOfID=autor_findAutorById(pAutor,len,auxID);
            if(posOfID!=-1)
            {
               pAutor[posOfID].isEmpty=1;
               retorno=0;
            }
        }
     }
    return retorno;
}

int autor_sortAutors(Autor* pEmpleado, int len,int order)///1up 0down
{
    int i;
    int j;
    int retorno=-1;
    Autor buffer;
    if(pEmpleado!=NULL && len>0)
    {
        for(i=0;i<len-1;i++)
        {

            for(j=i+1;j<len;j++)
            {

                if((order==1)&&(strcmp(pEmpleado[i].surname,pEmpleado[j].surname)>0))
                {
                    buffer=pEmpleado[i];
                    pEmpleado[i]=pEmpleado[j];
                    pEmpleado[j]=buffer;
                    retorno=0;
                }
                else if((order==0)&&(strcmp(pEmpleado[i].surname,pEmpleado[j].surname)<0))
                {
                    buffer=pEmpleado[i];
                    pEmpleado[i]=pEmpleado[j];
                    pEmpleado[j]=buffer;
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/*int autor_informarTotalSalariosPromedio(Autor* pAutor,int len)
{
    int i;
    float totalResult;
    float promedioResult;
    int autorloyeeOverPromedio;
    int contadorPromedio=0;
    float sum=0;
    int ret=-1;
    if(pAutor!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(pAutor[i].isEmpty==0)
            {
                sum+=pAutor[i].salary;
                contadorPromedio++;
            }
        }
        totalResult=sum;
        promedioResult=totalResult/contadorPromedio;
        autor_salaryOverPromedio(pAutor,len,promedioResult,&autorloyeeOverPromedio);
        ret=0;
        if(ret==0)
        {
            printf("\nEL TOTAL DE SALARIOS ES: %.2f\nEL PROMEDIO DE SALARIOS ES: %.2f\n"
                    "LOS EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO SON: %d\n",
                    totalResult,promedioResult,autorloyeeOverPromedio);
        }
    }
    return ret;
}*/

/*int autor_salaryOverPromedio(Autor* pAutor,int len,float promedioResult,int* valor)
{
    int i;
    int contadorAutor=0;
    int ret=-1;
    if(pAutor!=NULL && len>0 && valor!=NULL)
    {
        for(i=0;i<len;i++)
        {
            if(pAutor[i].isEmpty==0)
            {
                if(pAutor[i].salary>promedioResult)
                {
                    contadorAutor++;
                }
            }

        }
        *valor=contadorAutor;
        ret=0;
    }
    return ret;
}*/

int autor_initAutors(Autor* pAutor,int len)
{
    int i;
    if(pAutor!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            //pAutor[i].idAutor=-1;
            pAutor[i].isEmpty=1;
        }
    }
    return 0;
}

int autor_findFree(Autor* pAutor, int len)
{
    int i;
    int ret=-1;
    if(pAutor!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            if(pAutor[i].isEmpty==1)
            {
                ret=i;
                printf("\n----Se encontro lugar libre----\n");
                break;
            }
        }
        if(ret==-1)
        {
            printf("\n----NO hay lugar libre!!----\n");
        }
    }
    return ret;
}

int autor_findAutorById(Autor* pAutor, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if((pAutor[i].isEmpty==0)&&(pAutor[i].idAutor==idE))
        {
            ret=i;
        }
    }
    return ret;
}

int autor_getID (Autor* pEmpleado,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;
    if(pEmpleado!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}

int autor_printAutors(Autor* pAutor,int len)
{
    int i;
    int flag=1;
    for(i=0;i<len;i++)
    {
        if(pAutor[i].isEmpty==0)
        {
            printf("\nID: %d\nNombre: %s\nApellido: %s\n-------",
                   pAutor[i].idAutor,pAutor[i].name,pAutor[i].surname);
            flag=0;
        }
    }
    if(flag)
    {
        printf("\n----El listado se encuentra vacio----\n");
    }
    return 0;
}

static int generarId(void)
{
    static int idEmp=0;
    return idEmp++;
}
