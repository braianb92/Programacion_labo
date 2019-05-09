#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

typedef struct
{
    char name[50];
    char surname[50];
    int idAutor;
    int isEmpty; //1 free - 0 full
}Autor;

int autor_menu(Autor* pAutor,int len, char* menuText,
             int exitMenuNumber,int tries);

int autor_addAutors(Autor* pAutor,int len,char* msgE,int tries);
int autor_alter(Autor* pAutor, int len,char* generalMsgE,int exitAlterMenuNumber,int tries);
int autor_removeAutor(Autor* pAutor, int len,char* msgE,int tries);
int autor_sortAutors(Autor* pAutor, int len,int order);

int autor_printAutors(Autor* pAutor,int len);
int autor_informarTotalSalariosPromedio(Autor* pAutor,int len);
int autor_salaryOverPromedio(Autor* pAutor,int len,float promedioResult,int* valor);

int autor_initAutors(Autor* pAutor,int len);
int autor_findFree(Autor* pAutor, int len);
int autor_findAutorById(Autor* pAutor, int len, int idE);
int autor_getID (Autor* pAutor,int len,char* msgE,int tries);

#endif // AUTOR_H_INCLUDED

