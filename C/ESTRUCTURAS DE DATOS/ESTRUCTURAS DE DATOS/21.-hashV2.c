// Lista sin cabecera y ass-endente (numerico)
#include <stdio.h>
#include <stdlib.h>
struct Nodo
{
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *createNodo(int dato)
{
    struct Nodo *newNodo;
    newNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    newNodo->key = dato;
    newNodo->ptrAnt = NULL;
    newNodo->ptrSig = NULL;
    return newNodo;
}

int meterNodo(struct Nodo **ptrRef, int dato)
{
    struct Nodo *nodoNuevo, *ptrAvanzada, *ptrAtras;

    // Crear el nuevo nodo
    nodoNuevo = createNodo(dato);
    if (nodoNuevo == NULL) return 1;

    // Caso 1: Lista vacía
    if (*ptrRef == NULL){
        *ptrRef = nodoNuevo;
        return 0;
    }

    // Caso 2: Insertar al principio (dato es menor que el primer nodo)
    if (dato < (*ptrRef)->key){
        nodoNuevo->ptrSig = *ptrRef;
        (*ptrRef)->ptrAnt = nodoNuevo;
        *ptrRef = nodoNuevo;
        return 0;
    }

    // Caso 3: Buscar posición de inserción en el resto de la lista
    ptrAtras = *ptrRef;
    ptrAvanzada = (*ptrRef)->ptrSig;

    while (ptrAvanzada != NULL && ptrAvanzada->key < dato){
        ptrAtras = ptrAvanzada;
        ptrAvanzada = ptrAvanzada->ptrSig;
    }

    // Verificar duplicado
    if (ptrAtras->key == dato || (ptrAvanzada != NULL && ptrAvanzada->key == dato))
    {
        free(nodoNuevo);
        return 1;
    }

    // Insertar el nodo (en medio o al final)
    nodoNuevo->ptrAnt = ptrAtras;
    nodoNuevo->ptrSig = ptrAvanzada;
    ptrAtras->ptrSig = nodoNuevo;

    if (ptrAvanzada != NULL)
    {
        ptrAvanzada->ptrAnt = nodoNuevo;
    }

    return 0;
}
int sacarDato(struct Nodo **ptrRef, int *dato)
{
    struct Nodo *ptrBasura;
    
    // Verificar si la lista está vacía
    if (ptrRef == NULL || *ptrRef == NULL)
        return 1;
    
    ptrBasura = *ptrRef;
    
    // Buscar el nodo con el dato
    while (ptrBasura != NULL && ptrBasura->key != *dato){
        ptrBasura = ptrBasura->ptrSig;
    }
    
    // Si no se encuentra el dato
    if (ptrBasura == NULL)
        return 1;
    
    // Guardar el valor antes de eliminar
    *dato = ptrBasura->key;
    
    // Caso 1: Eliminar el único nodo
    if (ptrBasura->ptrAnt == NULL && ptrBasura->ptrSig == NULL){
        *ptrRef = NULL;
    }
    // Caso 2: Eliminar el primer nodo
    else if (ptrBasura->ptrAnt == NULL){
        *ptrRef = ptrBasura->ptrSig;
        ptrBasura->ptrSig->ptrAnt = NULL;
    }
    // Caso 3: Eliminar el último nodo
    else if (ptrBasura->ptrSig == NULL){
        ptrBasura->ptrAnt->ptrSig = NULL;
    }
    // Caso 4: Eliminar un nodo del medio
    else{
        ptrBasura->ptrAnt->ptrSig = ptrBasura->ptrSig;
        ptrBasura->ptrSig->ptrAnt = ptrBasura->ptrAnt;
    }
    
    free(ptrBasura);
    return 0;
}

int imprimir(struct Nodo **ptrRef){
    struct Nodo *ptrRec;
    
    // Verificar si la lista está vacía
    if (ptrRef == NULL || *ptrRef == NULL)
    {
        printf("Lista vacia\n");
        return 1;
    }
    
    ptrRec = *ptrRef;  // Empezar desde el primer nodo, no desde ptrSig
    
    printf("Lista completa:\n");
    while (ptrRec != NULL){
        printf("%d ", ptrRec->key);
        ptrRec = ptrRec->ptrSig;
    }
    printf("\n");
    
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
    struct Nodo *ptrRef1, **ptrRef2;
    ptrRef1 = NULL;
    ptrRef2 = &ptrRef1;

        int dato;
    for (;;)
    {
        switch (menu())
        {
        case 1:
            printf("Ingrese dato:");
            scanf("%d", &dato);
            meterNodo(ptrRef2, dato);
            break;
        case 2:
            scanf("%d", &dato);
            if (sacarDato(ptrRef2, &dato) != 0){
                printf("Dato no encontrado");
            }else{
                printf("Dato sacado: %d", dato);
            }
            break;
        case 3:
            imprimir(ptrRef2);
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("Opcion incorrecta");
            exit(1);
            break;
        }
    }
    return 0;
}
