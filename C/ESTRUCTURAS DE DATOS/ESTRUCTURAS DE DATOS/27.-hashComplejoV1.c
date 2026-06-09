// lista puntero doble (con cabecera) numerico
//terminar 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Dato{
    char nombre[30];
    int edad;
};

struct Nodo{
    struct Dato dato;
    int clave;
    struct Nodo *ptrSig,*ptrAnt; 
};

struct Nodo* crearNodo(struct Dato* dato, int clave){
    struct Nodo *newNodo;
    newNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
    newNodo -> dato.edad = dato -> edad;
    strcpy(newNodo -> dato.nombre,dato ->nombre);
    newNodo -> ptrAnt = NULL;
    newNodo -> ptrSig = NULL;
    newNodo -> clave = clave;
    return newNodo;
}

int meterNodo(struct Nodo *ptrRef, struct Dato *ptrD,int clave){
    struct Nodo *nodoNuevo,*ptrAv,*ptrAtr;
    nodoNuevo = crearNodo(ptrD,clave);
    if(ptrRef -> ptrSig == NULL){
        ptrRef -> ptrSig = nodoNuevo;
        return 0;
    }
    if(clave < ((ptrRef -> ptrSig) -> clave)){
        nodoNuevo -> ptrSig = ptrRef -> ptrSig;
        (ptrRef -> ptrSig) -> ptrAnt = nodoNuevo; 
        ptrRef -> ptrSig = nodoNuevo;
        return 0;
    }
    ptrAv = ptrRef -> ptrSig;
    while(ptrAv != NULL){
        if(ptrAv -> clave == clave) {
            free(nodoNuevo);
            return 1;
        }
        ptrAv = ptrAv ->ptrSig;
    }

    ptrAv = ptrRef -> ptrSig;
    while(ptrAv != NULL && ptrAv -> clave < clave){
        ptrAtr = ptrAv;
        ptrAv = ptrAv ->ptrSig;
    }

    if(ptrAv == NULL){
        nodoNuevo -> ptrAnt = ptrAtr;
        nodoNuevo -> ptrSig = NULL;
        ptrAtr -> ptrSig = nodoNuevo;
    }else{
        nodoNuevo -> ptrSig = ptrAv;
        nodoNuevo -> ptrAnt = ptrAtr;
        ptrAtr -> ptrSig = nodoNuevo;
        ptrAv -> ptrAnt = nodoNuevo;
    }

    return 0;
}
int sacarDato(struct Nodo *ptrRef, int clave, struct Dato *dato) {
    struct Nodo *ptrAv = ptrRef->ptrSig;
    if (ptrAv == NULL) return 1; // Lista vacía
    while (ptrAv != NULL && ptrAv->clave != clave) {
        ptrAv = ptrAv->ptrSig;
    }
    if (ptrAv == NULL) return 2; // Clave no existe
    struct Nodo *ptrAtr = ptrAv->ptrAnt;
    // Reconectar punteros
    ptrAtr->ptrSig = ptrAv->ptrSig;
    if (ptrAv->ptrSig != NULL) {
        (ptrAv->ptrSig)->ptrAnt = ptrAtr;
    }

    *dato = ptrAv->dato;
    free(ptrAv);
    
    return 0;
}
int imprimir(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    ptrRec = ptrRef ->ptrSig;
    if(ptrRec == NULL) return 1;
    while (ptrRec != NULL){
        printf("\n Nombre: %s y edad %d en la clave: %d.", ptrRec -> dato.nombre, ptrRec -> dato.edad, ptrRec -> clave);
        ptrRec = ptrRec ->ptrSig;
    }
    return 0;
}
int menu(){
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Sacar");
    printf("\n3.Imprimir todo");
    printf("\n4.Salir");
    printf("\nIngresa opcion:");
    scanf("%d", &opc);
    return opc;
}

int main(){
    struct Nodo *ptrRef;
    ptrRef = crearNodo(-1000,-200000);
    struct Dato dato;
    int clave;
    int sacar;
    for (;;)
    {
        switch (menu())
        {
        case 1:
            printf("\nIngrese clave:");
            scanf("%d", &clave);
            printf("\nIngrese nombre:");
            gets(dato.nombre);
            printf("\nIngrese edad:");
            scanf("%d",&dato.edad);
            fflush(stdin);
            meterNodo(ptrRef, &dato,clave);
            break;
        case 2:
            scanf("%d", &clave);
            sacar = sacarDato(ptrRef, clave, &dato);
            if ( sacar == 1){
                printf("Lista vacia");
            }else if(sacar == 2){
                printf("Clave no existe");
            }else if(sacar  == 0){
                printf("\n Nombre: %s y edad %d en la clave: %d.",dato.nombre, dato.edad, clave);
            }
            break;
        case 3:
            imprimir(ptrRef);
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("Opcion incorrecta");
            exit(1);
            break;
        }
    }
    return 0;
}