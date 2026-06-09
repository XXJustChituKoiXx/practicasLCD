//con nodo de cabecera
#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;
    struct Nodo *ptrSig,*ptrAnt;
};
struct Nodo *crearNodo(int *dato){
    struct Nodo*ptrNew;
    ptrNew = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNew -> ptrSig = NULL;
    ptrNew -> ptrAnt = NULL;
    ptrNew -> dato = *dato; 
    return ptrNew;
}

int meterNodo(struct Nodo *ptrRef, int *dato){
    struct Nodo *ptrNew;

    ptrNew = crearNodo(dato);
    if(ptrRef -> ptrSig == NULL && ptrRef -> ptrAnt == NULL){
        ptrRef -> ptrSig = ptrNew;
        ptrNew -> ptrAnt = ptrRef;
    }else{
        ptrNew -> ptrSig = ptrRef -> ptrSig;
        ptrRef -> ptrSig -> ptrAnt = ptrNew;
        ptrRef -> ptrSig = ptrNew;
        ptrNew -> ptrAnt = ptrRef;
    }
    return 0;
}
int sacarNodo(struct Nodo **ptrRef,int *dato){
    struct Nodo *ptrBasura;
    ptrBasura = *ptrRef;
    if(ptrBasura == NULL) return 1;
    (*ptrRef) -> ptrAnt = ptrBasura -> ptrAnt;
    (*ptrRef) = ptrBasura -> ptrSig;
    *dato =  ptrBasura -> dato;
    free(ptrBasura);
    return 0;
}

int imprimirTodo(struct Nodo **ptrRef){
    struct Nodo *ptrRec;
    ptrRec = (*ptrRef) -> ptrSig;
    printf("\nImprimir Normal");
    while(ptrRec != NULL){
        printf("\nDato: %d",ptrRec ->dato);
        ptrRec = ptrRec -> ptrSig;
    }
    return 0;
}
int imprimirTodoRev(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    ptrRec = ptrRef->ptrSig;
    while(ptrRec -> ptrSig != NULL){
        ptrRec = ptrRec -> ptrSig;
    }
    printf("\nImprimir Rev");
    while(ptrRec -> ptrAnt != NULL){
        printf("\nDato: %d",ptrRec ->dato);
        ptrRec = ptrRec -> ptrAnt;
    }
    return 0;
}

int menu(){
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Sacar");
    printf("\n3.Imprimir todo.");
    printf("\n4.Imprimir rev.");
    printf("\n5.Salir");
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
            imprimirTodoRev(ptrRef2);
            break;
        case 5:
            exit(1);
            break;    
        default:
            printf("\nIngrese opcion correcta");
            break;
        }
    }

    return 0;
}