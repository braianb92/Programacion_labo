#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

int utn_getNumberRanged(int *pNumber, int max, int min, char* msg, char* msgError, int tries);
int utn_getInt (int *pNum, char* msg, char* msgE);
char utn_getChar (char* pChar,int MAX, char* msg);
float utn_getFloat (float *pNum, char* msg, char* msgE);
int utn_getArrayInt (int* pNumArray,int limit,int max,int min,int tries, char* msg, char* msgE);
int utn_Swap(int* arrayA, int arrayB);
int showArray(int array[],int limit);
void orderArray(int array[],int limit);

#endif // ARRAY_H_INCLUDED
