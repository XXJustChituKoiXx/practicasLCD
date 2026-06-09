//lista enlazada sin cabecera, se mete al inicio y se saca del inicio
#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int dato;
    struct Nodo *ptrSig;
};
struct Nodo* crearNodo(int dato){
    struct Nodo *ptrNuevo;
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo -> dato = dato;
    ptrNuevo -> ptrSig = NULL;
    return ptrNuevo;
}
struct Nodo* meterNodo(struct Nodo *ptrRef, int dato){
    struct Nodo *ptrNuevo;

    ptrNuevo = crearNodo(dato);
    ptrNuevo->ptrSig = ptrRef;

    return ptrNuevo;
}
int imprimirTodo(struct Nodo *ptrRef){
    struct Nodo *ptrRecorrer;
    ptrRecorrer = ptrRef;
    while(ptrRecorrer != NULL){
        printf("Dato: %d\n",ptrRecorrer ->dato);
        ptrRecorrer = ptrRecorrer -> ptrSig;
    }
    return 0;
}
int sacarDato(struct Nodo **ptrRef, int *dato){
    struct Nodo *ptrBasura;

    if(*ptrRef == NULL){
        printf("Lista vacia\n");
        return 0;
    }

    ptrBasura = *ptrRef;
    *dato = ptrBasura->dato;
    *ptrRef = ptrBasura->ptrSig;

    free(ptrBasura);
    return 1;
}

int menu(){
    int opc;
    printf("MENU\n 1.Meter\n 2.Sacar\n 3.Imprimir todo. \n 4.SALIR\n SELECCIONA UNA OPCION:");
    scanf("%d",&opc);
    return opc;
}
int main(){
    struct Nodo *ptrRef;
    int dato;
    ptrRef=NULL;
    for(;;){
        switch (menu()){
        case 1:
            printf("Ingrese entero:");
            scanf("%d",&dato);
            ptrRef = meterNodo(ptrRef, dato);
            break;
        case 2:
            if(sacarDato(&ptrRef, &dato)){
                printf("Dato sacado: %d\n", dato);
            }
            break;
        case 3:
            imprimirTodo(ptrRef);    
            break;
        case 4:
            exit(1);
            break;
        
        default:
        printf("Seleccione opcion valida.");
            break;
        }
    }
    return 0;
}