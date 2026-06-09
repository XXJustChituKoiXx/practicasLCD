//Lista con Nodo de cabecera y enlace doble
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
int clave;
struct Nodo *pS, *pA;
};

struct Nodo * CrearNodo (int clave){
    struct Nodo *pN=malloc (sizeof(struct Nodo));
    if(pN==NULL){
        printf("El espacio en memoria no se ha reservado\n");
        return NULL;
    }
    pN->clave=clave;
    pN->pS=NULL;
    pN->pA=NULL;
    return pN;
};

int Vacia (struct Nodo *pR){
    if(pR->pS==NULL)
        return 1;
    else
        return 0;
};

int Meter (struct Nodo *pR, int clave){
    struct Nodo *pN=CrearNodo(clave), *pT=pR;
    while((pT->pS!=NULL)&&(pT->pS->clave < clave))
        pT=pT->pS;
    pN->pS=pT->pS;
    pN->pA=pT;
    if(pT->pS!=NULL)
        pT->pS->pA=pN;
    pT->pS=pN;
    printf("El dato se ha agregado a la Lista exitosamente. . .\n");
    return 1;
};

int Sacar (struct Nodo *pR, int clave){
    struct Nodo *pRet=pR, *pAv=pR->pS;
    if(Vacia(pR)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    while((pAv!=NULL)&&(pAv->clave != clave)){
        pRet=pRet->pS;
        pAv=pAv->pS;
    }
    if(pAv==NULL){
        printf("La clave no esta dentro de la Lista. . .\n");
        return 0;
    }
    printf("El dato %d fue exitosamente elimando. . .\n",pAv->clave);
    pRet->pS=pAv->pS;
    if(pAv->pS!=NULL)
        pRet->pS->pA=pRet;
    free(pAv);
    return 1;
};

int Mostrar (struct Nodo *pR){
    struct Nodo *pT=pR->pS;
    if(Vacia(pR)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    printf("LISTA ACTUAL: ");
    while(pT!=NULL){
        printf("[*|%d|*]<->",pT->clave);
        pT=pT->pS;
    }
    printf("NULL. . .\n");
    return 1;
};

int Reiniciar (struct Nodo *pR){
    struct Nodo *pB;
    if(Vacia(pR)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    while(pR->pS!=NULL){
        pB=pR->pS;
        pR->pS=pB->pS;
        free(pB);
    }
    printf("La Lista se ha reiniciado correctamente. . .\n");
    return 1;
}

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
}

int main (){
    struct Nodo *pR=CrearNodo(-1000);
    int clave;

    for(;;){
        switch(menu()){
    case 1:
        printf("Ingrese la clave que quiere meter en la Lista: ");
        scanf("%d",&clave);
        Meter(pR,clave);
        break;
    case 2:
        if(Vacia(pR)){
            printf("La Lista esta vacia: NULL. . .\n");
            break;
        }
        printf("Ingrese la clave que quiere sacar en la Lista: ");
        scanf("%d",&clave);
        Sacar(pR,clave);
        break;
    case 3:
        Mostrar(pR);
        break;
    case 4:
        Reiniciar(pR);
        break;
    case 5:
        printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
        exit(0);
    default:
        printf("Elije una opcion que este dentro del menu\n");
        break;
        }
    }
}
