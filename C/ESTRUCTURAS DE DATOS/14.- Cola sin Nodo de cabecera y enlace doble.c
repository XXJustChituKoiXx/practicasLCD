//Cola sin Nodo de cabecera y enlace doble
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
int dato;
struct Nodo *pS, *pA;
};

int Vacia(struct Nodo **pI2){
    if(*pI2==NULL)
        return 1;
    else
        return 0;
};

struct Nodo * CrearNodo (int dato){
    struct Nodo *pN=malloc (sizeof(struct Nodo));
    if(pN==NULL){
        printf("No se reservo el espacio en memoria\n");
        return NULL;
    }
    pN->dato=dato;
    pN->pS=NULL;
    pN->pA=NULL;
    return pN;
};

int Meter (struct Nodo **pI2, struct Nodo **pF2, int dato){
    struct Nodo *pN=CrearNodo(dato);
    if(Vacia(pI2)){
        *pI2=pN;
        *pF2=pN;
    }
    else{
        (*pF2)->pS=pN;
        pN->pA=*pF2;
        *pF2=pN;
    }
    printf("El dato se ha agregado a la Cola exitosamente. . .\n");
    return 1;
};

int Sacar (struct Nodo **pI2, struct Nodo **pF2){
    struct Nodo *pB=*pI2;
    if(Vacia(pI2)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    *pI2=pB->pS;
    if(*pI2!=NULL)
        (*pI2)->pA=NULL;
    else
        *pF2=NULL;
    printf("El dato %d ha salido de la Cola exitosamente. . .\n",pB->dato);
    free(pB);
    return 1;
};

int Mostrar (struct Nodo **pI2){
    struct Nodo *pT=*pI2;
    if(Vacia(pI2)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    while (pT!=NULL){
        printf("[*|%d|*]<->",pT->dato);
        pT=pT->pS;
    }
    printf("NULL. . .\n");
    return 1;
}

int Reiniciar (struct Nodo **pI2, struct Nodo **pF2){
    struct Nodo *pB;
    while (*pI2!=NULL){
        pB=*pI2;
        *pI2=pB->pS;
        free(pB);
    }
    *pF2=NULL;
    printf("La Cola se ha reiniciado correctamente. . .\n");
    return 1;
};

int menu(){
    int op;
    printf("\n---MENU---\n");
    printf("1 para Meter\n");
    printf("2 para Sacar\n");
    printf("3 para Mostrar\n");
    printf("4 para Reiniciar\n");
    printf("5 para Salir\n");
    printf("Seleccione una opcion dentro del menu: ");
    scanf("%d",&op);
    return op;
}

int main(){
    struct Nodo *pI1, *pF1, **pI2, **pF2;
    int dato;
    pI2=&pI1;
    pF2=&pF1;
    pI1=NULL;
    pF1=NULL;

    for(;;){
        switch(menu()){
    case 1:
        printf("Ingrese el dato que quiere meter en la Cola: ");
        scanf("%d",&dato);
        Meter(pI2,pF2,dato);
        break;
    case 2:
        Sacar(pI2,pF2);
        break;
    case 3:
        Mostrar(pI2);
        break;
    case 4:
        Reiniciar(pI2,pF2);
        break;
    case 5:
        printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
        exit(0);
    default:
        printf("Elija una opcion dentro del menu: ");
        break;
        }
    }
}

