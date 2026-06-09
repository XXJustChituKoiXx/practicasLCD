#include <stdio.h>
#include <stdlib.h>

struct Nodo{
int dato;
struct Nodo *pS;
};

int Vacia(struct Nodo *pR){
    if(pR->pS==NULL)
        return 1;
    else
        return 0;
};

struct Nodo * CrearNodo (int dato){
    struct Nodo *pN=(struct Nodo*) malloc (sizeof(struct Nodo));

    if(pN==NULL){
        printf("El espacio en memoria no se ha reservado correctamente\n");
        return NULL;
    }
    pN->dato=dato;
    pN->pS=NULL;
    return pN;
};

int Meter (struct Nodo *pR, int dato){
    struct Nodo *pN=CrearNodo(dato);

    if(pN == NULL)
        return 0;

    pN->pS=pR->pS;
    pR->pS=pN;
    return 1;

};

int Sacar (struct Nodo *pR){
    struct Nodo *pB;

    if(Vacia(pR)){
        printf("La Pila ya esta vacia!\n");
        return 0;
    }
    pB=pR->pS;
    printf("El dato que salio de la Pila fue: %d. . .\n",pB->dato);
    pR->pS=pB->pS;
    free(pB);
    return 1;
};

int Mostrar (struct Nodo *pR){
    struct Nodo *pT=pR;

    if(Vacia(pR)){
        printf("La Pila esta vacia!\n");
        return 0;
    }
    printf("La Pila ACTUAL es: ");
    while(pT->pS!=NULL){
        pT=pT->pS;
        printf("[%d]\t",pT->dato);
    }
    printf(". . . \n");
    return 1;
};

int Reiniciar (struct Nodo *pR){
    struct Nodo *pB;

    while(pR->pS!=NULL){
        pR=pR->pS;
        pB=pR;
        free(pB);
    }
    printf("La Pila se reinicio correctamente. . . \n");
    return 1;
};

int menu(){
    int op;
    printf("\n---MENU---\n");
    printf("1 para Meter\n");
    printf("2 para Sacara\n");
    printf("3 para Mostrar\n");
    printf("4 para Reiniciar\n");
    printf("5 para Salir\n");
    printf("Selecciona una opcion del menu: ");
    scanf("%d",&op);
    return op;
};

int main(){
    struct Nodo *pR=CrearNodo(-1000);
    int dato;

    for(;;){
        switch(menu()){
    case 1:
        printf("Ingrese el dato que quiere meter en la Pila: ");
        scanf("%d",&dato);
        printf("\n");
        Meter(pR,dato);
        break;
    case 2:
        if(Vacia(pR)){
            printf("La pila esta vacia\n");
            break;
        }
        Sacar(pR);
        break;
    case 3:
        Mostrar(pR);
        break;
    case 4:
        Reiniciar(pR);
        break;
    case 5:
        printf("*-*-* Saliendo del Sistema *-*-*");
        exit(0);
    default:
        printf("Elija una opcion dentro del menu\n");
        break;
        }
    }
};
