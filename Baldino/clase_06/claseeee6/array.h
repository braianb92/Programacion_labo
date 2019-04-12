#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

int getFloat (float* pNum, char* msg, char* msgE);
int getInt (int* pNum, char* msg, char* msgE);
int getChar(char* pChar, int len, char* msg);
int getArray(int* pArray,int len,char* msg, char* msgE);

int showArray(int* pArray,int len);
int promedio(int* pNum, int len, float* promResult);
int maxArray(int* pArray,int len, int* maximo);
int minArray(int* pArray,int len, int* minimo);

int orderArrayGrowing(int* pArray, int len);
int orderArrayDecreasing(int* pArray, int len);
int findNum (int* pArray, int len, char* msgAsk,char* msgFound, char* msgNotFound);
int valueModifier (int* pNum, int len);
#endif // ARRAY_H_INCLUDED
