//pasar cadena a lista con cabecera
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo{
    char caracter;
    struct Nodo *ptrSig,*ptrAnt;
};

struct Nodo *crearNodo(char *caracter){
    struct Nodo *nodoNuevo;
    nodoNuevo = (struct Nodo *) malloc(sizeof(struct Nodo));
    strcpy(&nodoNuevo -> caracter,caracter);
    nodoNuevo -> ptrSig = NULL;
    nodoNuevo -> ptrAnt = NULL;
    return nodoNuevo;
}

int meterDato(struct Nodo *ptrRef,char *caracter){
    struct Nodo *ptrNuevo;
    ptrNuevo = crearNodo(caracter);
    if(ptrRef ->ptrSig == NULL){
        ptrRef -> ptrSig = ptrNuevo;
        ptrNuevo -> ptrAnt = ptrRef;
    }else{
        ptrNuevo -> ptrSig = ptrRef -> ptrSig;
        ptrNuevo -> ptrAnt = ptrRef;
        ptrRef -> ptrSig -> ptrAnt = ptrNuevo;
        ptrRef -> ptrSig = ptrNuevo;
    }
    return 0;
}

int imprimir(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    int i;
    i=0;
    ptrRec = ptrRef ->ptrSig;
    while(ptrRec != NULL){
        i++;
        printf("Caracter %d : %c\n",i, ptrRec -> caracter);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}
int main(){
    char cadena[30],*ptrC;
    struct Nodo *ptrRef;
    ptrRef = crearNodo("");
    gets(cadena);
    ptrC = cadena;

    while(*ptrC != '\0'){
        meterDato(ptrRef,ptrC);
        ++ptrC;
    }
    imprimir(ptrRef);

    return 0;
}