//Lista con cabecera y ass-endente (alfanumerico)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Nodo{
    char key[30];
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *crearNodo(int dato){
    struct Nodo *nodoNuevo;
    nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nodoNuevo -> ptrSig = NULL;
    nodoNuevo -> ptrAnt = NULL;
    strcpy(nodoNuevo -> key, dato);
    return nodoNuevo;
}

int meterDato(struct Nodo *ptrRef,char * dato){
    struct Nodo *newNodo,*ptrAvanzada,*ptrAtras;
    newNodo = crearNodo(dato);
    //hash vacia
    if(ptrRef -> ptrSig == NULL){
        ptrRef -> ptrSig = newNodo;
        newNodo -> ptrAnt = ptrRef;
        return 0;
    }
    //dato menor al primero
    if(strcmp((ptrRef -> ptrSig) -> key,dato) > 0){
        newNodo -> ptrAnt = ptrRef;
        newNodo -> ptrSig = ptrRef -> ptrSig;
        (ptrRef -> ptrSig) -> ptrAnt = newNodo;
        ptrRef -> ptrSig = newNodo;
        return 0;
    }
    //dato enmedio
    ptrAvanzada = ptrRef -> ptrSig;
    ptrAtras = ptrRef;

    while(ptrAvanzada != NULL){
        if(strcmp((ptrRef -> ptrSig) -> key,dato) == 0){
            free(newNodo);
            return 1;
        }
        ptrAvanzada = ptrAvanzada -> ptrSig;
    }
    ptrAvanzada = ptrRef -> ptrSig;
    ptrAtras = ptrRef;    
    while(ptrAvanzada != NULL && dato > (ptrAvanzada -> key)){
        ptrAtras = ptrAvanzada;
        ptrAvanzada = ptrAvanzada -> ptrSig;
    }
    if(ptrAvanzada == NULL){
        newNodo -> ptrAnt = ptrAtras;
        ptrAtras -> ptrSig = newNodo;
        return 0;
    }
    newNodo -> ptrSig = ptrAvanzada;
    newNodo -> ptrAnt = ptrAtras;
    ptrAvanzada -> ptrAnt = newNodo;
    ptrAtras -> ptrSig = newNodo;
    return 0;
}

int sacarDato(struct Nodo *ptrRef, char * dato){
    struct Nodo *ptrRec,*ptrAtras;
    if(ptrRef -> ptrSig == NULL){
        printf("\n Lista vacia.");
        return 1;
    }
    ptrRec = ptrRef -> ptrSig;
    while(ptrRec != NULL && strcmp((ptrRef -> ptrSig) -> key,dato) != 0) ptrRec = ptrRec ->ptrSig;
    if(ptrRec == NULL){ 
        printf("\nDato no encontrado");
        return 1;
    }
    (ptrRec -> ptrAnt) -> ptrSig = ptrRec -> ptrSig;
    if(ptrRec -> ptrSig != NULL) (ptrRec -> ptrSig) -> ptrAnt = ptrRec -> ptrAnt;

    free(ptrRec);
    return 0;
}

int imprimirTodo(struct Nodo *ptrRef){
    struct Nodo *ptrRec;
    ptrRec = ptrRef -> ptrSig;
    if(ptrRec == NULL) printf("\nLista Vacia.");
    while(ptrRec != NULL){
        printf("\n %s", ptrRec -> key);
        ptrRec = ptrRec -> ptrSig;
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
    scanf("%d", &opc);
    return opc;
}
int main(){
    struct Nodo *ptrRef = crearNodo(-10000);  // Crear nodo cabecera
    char dato[30];
    int resultado;
    
    for(;;){
        switch(menu()){
            case 1:  // Meter dato
                printf("Ingrese dato: ");
                fgets(dato, sizeof(dato),stdin);
                resultado = meterDato(ptrRef, dato);
                if(resultado == 0){
                    printf("\nDato %d insertado correctamente", dato);
                } else {
                    printf("\nDato %d ya existe, no se inserto", dato);
                }
                break;
                
            case 2:  // Sacar dato
                printf("Ingrese dato a eliminar: ");
                fgets(dato, sizeof(dato),stdin);
                resultado = sacarDato(ptrRef, dato);
                if(resultado == 0){
                    printf("\nDato %d eliminado correctamente", dato);
                }
                break;
                
            case 3:  // Imprimir todo
                imprimirTodo(ptrRef);
                break;
                
            case 4:  // Salir
                exit(0);
                break;
                
            default:
                printf("\nOpcion incorrecta");
                printf("\nPor favor, ingrese una opcion valida (1-4)\n");
                break;
        }
        printf("\n"); 
    }
    
    return 0;
}