#include <stdio.h>
#include <stdlib.h>

struct Nodo{
int dato;
struct Nodo *pS;
};

int Vacia (struct Nodo * pR){
    if(pR->pS==NULL)
        return 1;
    else
        return 0;
};

struct Nodo * CrearNodo (int dato){
    struct Nodo *pN=malloc(sizeof(struct Nodo));

    if(pN==NULL){
        printf("No se reservo el espacio de memoria\n");
        return NULL;
    }
    pN->dato=dato;
    pN->pS=NULL;
    return pN;
};

int Meter (struct Nodo *pR, int dato){
    struct Nodo *pN=CrearNodo(dato);
    pN->pS=pR->pS;
    pR->pS=pN;
    printf("El dato se ha agregado a la Cola exitosamente\n");
    return 1;
};

int Sacar (struct Nodo *pR){
    struct Nodo *pRet=pR, *pAv=pR->pS;
    if(Vacia(pR)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    while (pAv->pS!=NULL){
        pAv=pAv->pS;
        pRet=pRet->pS;
    }
    printf("El elemento [%d|*] ha salido de la Cola exitosamente. . .\n",pAv->dato);
    pRet->pS=pAv->pS;
    free(pAv);
    return 1;
};

int Mostrar (struct Nodo *pR){
    struct Nodo *pT=pR->pS;
    if(Vacia(pR)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    while (pT!=NULL){
        printf("[%d|*]->",pT->dato);
        pT=pT->pS;
    }
    printf("NULL. . .\n");
    return 1;
};

int Reiniciar (struct Nodo *pR){
    struct Nodo *pB=pR->pS;
    if(Vacia(pR)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    while (pR->pS!=NULL){
        pB=pR->pS;
        pR->pS=pB->pS;
        free(pB);
    }
    printf("La COLA se ha reiniciado correctamente. . .\n");
    return 1;
};

int menu (){
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
};

int main(){
    struct Nodo *pR=CrearNodo(-1000);
    int dato;

    for(;;){
        switch(menu()){
    case 1:
        printf("Ingrese el dato que quiere en la Cola: ");
        scanf("%d",&dato);
        Meter(pR,dato);
        break;
    case 2:
        Sacar(pR);
        break;
    case 3:
        Mostrar(pR);
        break;
    case 4:
        Reiniciar(pR);
        break;
    case 5:
        printf("*-*-*SALIENDO DEL SISTEMAs*-*-*");
        exit(0);
    default:
        printf("Elige una opcion opcionable\n");
        break;
        }
    }
}
