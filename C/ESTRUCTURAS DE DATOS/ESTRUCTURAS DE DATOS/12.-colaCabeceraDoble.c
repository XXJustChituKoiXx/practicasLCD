// Cola con Nodo de cabecera y enlace doble con dato
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrSiguiente;
    struct Nodo *ptrAnterior;
};

int Vacia(struct Nodo *pR) {
    return (pR->ptrSiguiente == NULL);
}

struct Nodo *CrearNodo(int dato) {
    struct Nodo *pN = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (pN == NULL) {
        printf("No se reservo el espacio de memoria\n");
        return NULL;
    }
    pN->dato = dato;
    pN->ptrSiguiente = NULL;
    pN->ptrAnterior = NULL;
    return pN;
}

int Meter(struct Nodo *pR, int dato) {
    struct Nodo *pN = CrearNodo(dato);
    pN->ptrSiguiente = pR->ptrSiguiente;
    if (pR->ptrSiguiente != NULL)
        pR->ptrSiguiente->ptrAnterior = pN;
    pR->ptrSiguiente = pN;
    pN->ptrAnterior = pR;
    printf("El dato se ha agregado a la Cola exitosamente\n");
    return 1;
}

int Sacar(struct Nodo *pR) {
    struct Nodo *pRet = pR, *pAv = pR->ptrSiguiente;
    if (Vacia(pR)) {
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    while (pAv->ptrSiguiente != NULL) {
        pAv = pAv->ptrSiguiente;
        pRet = pRet->ptrSiguiente;
    }
    printf("El elemento [%d] ha salido de la Cola exitosamente. . .\n", pAv->dato);
    pRet->ptrSiguiente = pAv->ptrSiguiente;
    if (pAv->ptrSiguiente != NULL)
        pAv->ptrSiguiente->ptrAnterior = pRet;
    free(pAv);
    return 1;
}

int Mostrar(struct Nodo *pR) {
    struct Nodo *pT = pR->ptrSiguiente;
    if (Vacia(pR)) {
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    while (pT != NULL) {
        printf("[%d]<->", pT->dato);
        pT = pT->ptrSiguiente;
    }
    printf("NULL\n");
    return 1;
}

int Reiniciar(struct Nodo *pR) {
    struct Nodo *pB;
    while (pR->ptrSiguiente != NULL) {
        pB = pR->ptrSiguiente;
        pR->ptrSiguiente = pB->ptrSiguiente;
        free(pB);
    }
    printf("La COLA se ha reiniciado correctamente. . .\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU COLA DOBLE---\n");
    printf("1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Nodo *pR = CrearNodo(-1000);
    int dato;
    for (;;) {
        switch (menu()) {
            case 1:
                printf("Ingrese el dato: ");
                scanf("%d", &dato);
                Meter(pR, dato);
                break;
            case 2:
                Sacar(pR);
                break;
            case 3:
                Mostrar(pR);
                break;
            case 4:
                Reiniciar(pR);
                break;
            case 5:
                printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
                exit(0);
            default:
                printf("Elige una opcion valida\n");
                break;
        }
    }
    return 0;
}