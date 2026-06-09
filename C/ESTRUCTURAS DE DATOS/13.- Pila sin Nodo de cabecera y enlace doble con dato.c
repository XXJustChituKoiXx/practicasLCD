//Pila sin Nodo de cabecera y enlace doble con dato
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
int dato;
struct Nodo *pS, *pA;
};

int Vacia(struct Nodo **pR2){
    if(*pR2==NULL)
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

int Meter (struct Nodo **pR2, int dato){
    struct Nodo *pN=CrearNodo(dato);
    pN->pS=*pR2;
    pN->pA=NULL;
    if(*pR2!=NULL)
        (*pR2)->pA=pN;
    *pR2=pN;

    printf("El dato se ha agregado a la Pila exitosamente. . .\n");
    return 1;
};

int Sacar (struct Nodo **pR2){
    struct Nodo *pB=*pR2;
    if(Vacia(pR2)){
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    *pR2=pB->pS;
    if(*pR2!=NULL)
        (*pR2)->pA=NULL;
    printf("El dato %d ha salido de la Pila exitosamente. . .\n",pB->dato);
    free(pB);
    return 1;
};

int Mostrar (struct Nodo **pR2){
    struct Nodo *pT=*pR2;
    if(Vacia(pR2)){
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    printf("PILA ACTUAL: ");
    while (pT!=NULL){
        printf("[*|%d|*]<->",pT->dato);
        pT=pT->pS;
    }
    printf("NULL. . .\n");
    return 1;
}

int Reiniciar (struct Nodo **pR2){
    struct Nodo *pB;
    while (*pR2!=NULL){
        pB=*pR2;
        *pR2=pB->pS;
        free(pB);
    }
    printf("La Pila se ha reiniciado correctamente. . .\n");
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
    struct Nodo *pR1, **pR2;
    int dato;
    pR2=&pR1;
    pR1=NULL;

    for(;;){
        switch(menu()){
    case 1:
        printf("Ingrese el dato que quiere meter en la Pila: ");
        scanf("%d",&dato);
        Meter(pR2,dato);
        break;
    case 2:
        Sacar(pR2);
        break;
    case 3:
        Mostrar(pR2);
        break;
    case 4:
        Reiniciar(pR2);
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
