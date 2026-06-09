//enecontrar la longitud de una cadena con recursividad
#include <stdio.h>
#include <string.h>
char *longitud(char *ptrC2){
    if(*ptrC2 == '\0') return ptrC2;
    ptrC2++;
    return longitud(ptrC2);
}
int main(){
    char cadena[30],*ptrC,*ptrC2;
    scanf("%s",&cadena);
    ptrC = cadena;
    ptrC2 = longitud(ptrC);
    printf("%d",(int)(ptrC2 - ptrC));
    return 0;
}