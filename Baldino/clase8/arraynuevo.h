#ifndef ARRAYNUEVO_H_INCLUDED
#define ARRAYNUEVO_H_INCLUDED

int getString(  char *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int getNumber(  int *resultado,
                char *msg,
                char *msgError,
                int minimo,
                int maximo,
                int reintentos);

int isValidNumber (char* cadena);

int buscarLibre (char pArray[][56],int* pIndex,int len );
int buscarNombre(char* name, char parray[][56], int len, int* pIndex);


#endif // ARRAYNUEVO_H_INCLUDED
