//ponerle menu
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato{
    char nombre[30];
    int edad;
};

struct Nodo{
    struct Dato dato;
    struct Nodo *ptrSig, *ptrAnt;
};

struct Nodo *crearNodo(struct Dato dato){
    struct Nodo *nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodoNuevo->ptrSig = NULL;
    nodoNuevo->ptrAnt = NULL;
    nodoNuevo->dato.edad = dato.edad;
    strcpy(nodoNuevo->dato.nombre, dato.nombre);
    return nodoNuevo;
}

int meterNodo(struct Nodo **ptrRef1, struct Nodo **ptrRef2, struct Dato dato){
    struct Nodo *nuevo = crearNodo(dato);

    if(*ptrRef1 == NULL){
        *ptrRef1 = *ptrRef2 = nuevo;
    }else{
        nuevo->ptrSig = *ptrRef1;
        (*ptrRef1)->ptrAnt = nuevo;
        *ptrRef1 = nuevo;
    }
    return 0;
}

int imprimirInicio(struct Nodo *ptrRef1){
    while(ptrRef1 != NULL){
        printf("Nombre: %s Edad: %d\n", ptrRef1->dato.nombre, ptrRef1->dato.edad);
        ptrRef1 = ptrRef1->ptrSig;
    }
    return 0;
}

int imprimirFinal(struct Nodo *ptrRef2){
    while(ptrRef2 != NULL){
        printf("Nombre: %s Edad: %d\n", ptrRef2->dato.nombre, ptrRef2->dato.edad);
        ptrRef2 = ptrRef2->ptrAnt;
    }
    return 0;
}

int main(){
    struct Nodo *ptrRef1 = NULL, *ptrRef2 = NULL;
    struct Dato dato;

    for(int i = 0; i <= 35; i += 5){
        sprintf(dato.nombre, "Persona%d", i);
        dato.edad = i;

        meterNodo(&ptrRef1, &ptrRef2, dato);
    }

    imprimirInicio(ptrRef1);
    printf("\n");
    imprimirFinal(ptrRef2);

    return 0;
}