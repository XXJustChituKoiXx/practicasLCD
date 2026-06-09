#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct Pila{
int elementos[TAM];
int *pP0;
};

int Vacia (struct Pila *pP){
    if(pP->pP0==pP->elementos)
        return 1;
    else
        return 0;
};
int Llena (struct Pila *pP){
    if(pP->pP0==&pP->elementos[TAM])
        return 1;
    else
        return 0;
};

int Meter (struct Pila *pP, int dato){
    *(pP->pP0)=dato;
    pP->pP0=(pP->pP0)+1;
    printf("El elemento se guardo correctamente en la Pila\n");
    return 1;
};

int Sacar (struct Pila *pP){
    pP->pP0=(pP->pP0)-1;
    printf("El elemento sacado de la pila fue: %d\n",*(pP->pP0));
    return 1;
};

int Mostrar (struct Pila *pP){
    int *pPT;
    if(Vacia(pP)){
        printf("La pila esta vacia\n");
        return 0;
    }
    else{
        pPT=pP->elementos;
        printf("La pila actual es: ");
        while (pPT!=pP->pP0){
            printf("[%d] ",*pPT);
            pPT=pPT+1;
        }
    printf("\n");
    }
};

int Borrar (struct Pila *pP){
    if(Vacia(pP)){
        printf("La pila ya esta vacia\n");
        return 0;
    }
    else{
        pP->pP0=pP->elementos;
        printf("La pila se ha borrado correctamente\n");
        return 1;
    }
};

int menu(){
    int op;
    printf("\n---MENU---\n");
    printf("1 para Meter\n");
    printf("2 para Sacar\n");
    printf("3 para Mostrar\n");
    printf("4 para Borrar\n");
    printf("5 para Salir\n");
    printf("Elige una opcion del menu: ");
    scanf("%d",&op);
    return op;
}

int main(){
    struct Pila p, *pP;
    int dato;

    pP=&p;
    pP->pP0=pP->elementos;

    for(;;){
        switch(menu()){
    case 1:
        if(Llena(pP)){
            printf("La pila ya esta llena");
            break;
        }
        printf("\nIngrese el elemento que quiere ingresar a la Pila: ");
        scanf("%d",&dato);
        Meter(pP,dato);
        break;
    case 2:
        if(Vacia(pP)){
            printf("La pila ya esta vacia\n");
            break;
        }
        Sacar(pP);
        break;
    case 3:
        Mostrar(pP);
        break;
    case 4:
        Borrar(pP);
        break;
    case 5:
        printf("*-*-*Saliendo del sistema-*-*-");
        exit(0);
    default:
        printf("Elige una opcion dentro del menu\n");
        break;
        }
    }
}
