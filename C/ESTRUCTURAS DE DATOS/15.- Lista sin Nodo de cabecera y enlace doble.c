//Lista sin Nodo de cabecera y enlace doble
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
int clave;
struct Nodo *pS, *pA;
};

int Vacia(struct Nodo **pR2){
    if(*pR2==NULL)
        return 1;
    else
        return 0;
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

int Meter (struct Nodo **pR2, int clave){
    struct Nodo *pN=CrearNodo(clave), *pT=*pR2;

    if(Vacia(pR2)){
        *pR2=pN;
        printf("El dato se ha agregado a la Lista exitosamente. . .\n");
        return 1;
    }

    if((*pR2)->clave > clave){
        pN->pS=*pR2;
        (*pR2)->pA=pN;
        *pR2=pN;
        printf("El dato se ha agregado a la Lista exitosamente. . .\n");
        return 1;
    }

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

int Sacar (struct Nodo **pR2, int clave){
    struct Nodo *pAv=*pR2;

    if(Vacia(pR2)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }

    while((pAv!=NULL)&&(pAv->clave != clave))
        pAv=pAv->pS;

    if(pAv==NULL){
        printf("La clave no esta dentro de la Lista. . .\n");
        return 0;
    }

    if(pAv->pA!=NULL)
        pAv->pA->pS=pAv->pS;
    else
        *pR2=pAv->pS;

    if(pAv->pS!=NULL)
        pAv->pS->pA=pAv->pA;

    printf("El dato %d fue exitosamente elimando. . .\n",pAv->clave);
    free(pAv);
    return 1;
};

int Mostrar (struct Nodo **pR2){
    struct Nodo *pT=*pR2;

    if(Vacia(pR2)){
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

int Reiniciar (struct Nodo **pR2){
    struct Nodo *pB;

    if(Vacia(pR2)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }

    while(*pR2!=NULL){
        pB=*pR2;
        *pR2=pB->pS;
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
    struct Nodo *pR1, **pR2;
    int clave;

    pR2=&pR1;
    pR1=NULL;

    for(;;){
        switch(menu()){
    case 1:
        printf("Ingrese la clave que quiere meter en la Lista: ");
        scanf("%d",&clave);
        Meter(pR2,clave);
        break;
    case 2:
        if(Vacia(pR2)){
            printf("La Lista esta vacia: NULL. . .\n");
            break;
        }
        printf("Ingrese la clave que quiere sacar en la Lista: ");
        scanf("%d",&clave);
        Sacar(pR2,clave);
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
        printf("Elije una opcion que este dentro del menu\n");
        break;
        }
    }
}
