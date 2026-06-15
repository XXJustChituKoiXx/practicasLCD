//pasar cadena a lista sin cabecera
//hacerlo con puntero doble 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
    char caracter;
    struct Nodo *ptrSig,*ptrAnt;
};

struct Nodo *createNodo(char *caracter){
    struct Nodo *nodoNuevo;
    nodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    nodoNuevo -> ptrAnt = NULL;
    nodoNuevo -> ptrSig = NULL;
    strcpy(nodoNuevo -> caracter, caracter);
}

int meterDato(struct Nodo **ptrRef2,char *caracter){
    struct Nodo *newNodo;
    newNodo = createNodo(caracter);
    if(*ptrRef2 == NULL){
        *ptrRef2 = newNodo;
    }else{
        newNodo -> ptrSig = *ptrRef2;
        (*ptrRef2) -> ptrAnt = newNodo;
        *ptrRef2 = newNodo;
    }
    return 0;
}
int imprimir(struct Nodo **ptrRef){
    struct Nodo *ptrRec;
    int i;
    i=0;
    ptrRec = (*ptrRef) ->ptrSig;
    while(ptrRec != NULL){
        i++;
        printf("Caracter %d : %c\n",i, ptrRec -> caracter);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}
int main(){
    char cadena[30],*ptrC;
    struct Nodo *ptrRef,**ptrRef2;
    ptrRef = NULL;
    ptrRef2 = &ptrRef;
    gets(cadena);
    ptrC = cadena;

    while(*ptrC != '\0'){
        meterDato(ptrRef2,ptrC);
        ++ptrC;
    }
    imprimir(ptrRef2);

    return 0;
}   