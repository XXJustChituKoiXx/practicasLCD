#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct Cola{
int elementos[TAM];
int *pCe, *pCs;
};

int Vacia (struct Cola *pC){
    if(pC->pCs==pC->pCe)
        return 1;
    else
        return 0;
};
int Llena (struct Cola *pC){
    if(pC->pCe==&pC->elementos[TAM])
        return 1;
    else
        return 0;
};

int Meter (struct Cola *pC, int dato){
    *(pC->pCe)=dato;
    pC->pCe=(pC->pCe)+1;
    printf("El elemento se guardo correctamente en la Cola\n");
    return 1;
};

int Sacar (struct Cola *pC){
    printf("El elemento sacado de la cola fue: %d\n",*(pC->pCs));
    pC->pCs=(pC->pCs)+1;

    return 1;
};

int Mostrar (struct Cola *pC){
    int *pCT;
    if(Vacia(pC)){
        printf("La cola esta vacia\n");
        return 0;
    }
    else{
        pCT=pC->elementos;
        printf("La cola actual es: ");
        while (pCT!=pC->pCe){
            printf("[%d] ",*pCT);
            pCT=pCT+1;
        }
    printf("\n");
    }

};

int Reiniciar (struct Cola *pC){
    pC->pCe=pC->elementos;
    pC->pCs=pC->elementos;
    printf("La cola se ha reiniciado correctamente\n");
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
    printf("Elige una opcion del menu: ");
    scanf("%d",&op);
    return op;
}

int main(){
    struct Cola c, *pC;
    int dato;

    pC=&c;
    pC->pCe=pC->elementos;
    pC->pCs=pC->elementos;

    for(;;){
        switch(menu()){
    case 1:
        if(Llena(pC)){
            printf("La cola ya esta llena");
            break;
        }
        printf("\nIngrese el elemento que quiere ingresar a la Cola: ");
        scanf("%d",&dato);
        Meter(pC,dato);
        break;
    case 2:
        if(Vacia(pC)){
            printf("La cola ya esta vacia\n");
            break;
        }
        Sacar(pC);
        break;
    case 3:
        Mostrar(pC);
        break;
    case 4:
        Reiniciar(pC);
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

