//lista enlazada sin cabecera
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo *ptrSig;
};

struct Nodo *crearNodo(int dato){
    struct Nodo *ptrNuevo;
    ptrNuevo = (struct Nodo *) malloc(sizeof (struct Nodo));
    ptrNuevo -> dato = dato;
    ptrNuevo -> ptrSig = NULL;
    return ptrNuevo;
}

int meterNodo(struct Nodo **ptrRef2,int dato){
    struct Nodo *ptrNew;
    ptrNew = crearNodo(dato);
    if(*ptrRef2 == NULL){
        *ptrRef2 = ptrNew;
    }else{
        ptrNew -> ptrSig = *ptrRef2;
        *ptrRef2 = ptrNew;
    }
    return 0;
}

int sacarDato(struct Nodo **ptrRef2,int *dato){
    struct Nodo *ptrBasura;

    if(*ptrRef2 == NULL){
        printf("Lista Vacia");
        return 0;
    }

    ptrBasura = *ptrRef2;
    *ptrRef2 = ptrBasura->ptrSig;
    *dato = ptrBasura->dato;
    free(ptrBasura);

    return 1;
}
int imprimirTodo(struct Nodo **ptrRef2){
    struct Nodo *ptrRecorrer;
    ptrRecorrer = *ptrRef2;
    while(ptrRecorrer != NULL){
        printf("\nDato: %d",ptrRecorrer->dato);
        ptrRecorrer = ptrRecorrer->ptrSig;
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
    scanf("%d",&opc);
    return opc;
}
int main(){
    struct Nodo *ptrRef1,**ptrRef2;
    int dato;
    ptrRef1 = NULL;
    ptrRef2 = &ptrRef1;

    for(;;){
        switch (menu()){
        case 1:
            printf("\nIngrese un entero:");
            scanf("%d",&dato);
            meterNodo(ptrRef2,dato);
            break;
        case 2:
            if(sacarDato(ptrRef2,&dato) != 0)
                printf("Dato eliminado: %d",dato);
            break;
        case 3:
            imprimirTodo(ptrRef2);
            break;
        case 4:
            exit(1);
            break;    
        default:
            printf("\nIngrese opcion correcta");
            break;
        }
    }

    return 0;
}