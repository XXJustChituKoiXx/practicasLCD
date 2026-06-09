// Lista con Nodo de cabecera y enlace doble con dato
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int clave;
    struct Nodo *ptrSiguiente;
    struct Nodo *ptrAnterior;
};

struct Nodo *CrearNodo(int clave) {
    struct Nodo *pN = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (pN == NULL) {
        printf("El espacio en memoria no se ha reservado\n");
        return NULL;
    }
    pN->clave = clave;
    pN->ptrSiguiente = NULL;
    pN->ptrAnterior = NULL;
    return pN;
}

int Vacia(struct Nodo *pR) {
    return (pR->ptrSiguiente == NULL);
}

int Meter(struct Nodo *pR, int clave) {
    struct Nodo *pN = CrearNodo(clave);
    struct Nodo *pT = pR;
    while ((pT->ptrSiguiente != NULL) && (pT->ptrSiguiente->clave < clave))
        pT = pT->ptrSiguiente;
    pN->ptrSiguiente = pT->ptrSiguiente;
    pN->ptrAnterior = pT;
    if (pT->ptrSiguiente != NULL)
        pT->ptrSiguiente->ptrAnterior = pN;
    pT->ptrSiguiente = pN;
    printf("El dato se ha agregado a la Lista exitosamente. . .\n");
    return 1;
}

int Sacar(struct Nodo *pR, int clave) {
    struct Nodo *pRet = pR, *pAv = pR->ptrSiguiente;
    if (Vacia(pR)) {
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    while ((pAv != NULL) && (pAv->clave != clave)) {
        pRet = pRet->ptrSiguiente;
        pAv = pAv->ptrSiguiente;
    }
    if (pAv == NULL) {
        printf("La clave no esta dentro de la Lista. . .\n");
        return 0;
    }
    printf("El dato %d fue exitosamente eliminado. . .\n", pAv->clave);
    pRet->ptrSiguiente = pAv->ptrSiguiente;
    if (pAv->ptrSiguiente != NULL)
        pAv->ptrSiguiente->ptrAnterior = pRet;
    free(pAv);
    return 1;
}

int Mostrar(struct Nodo *pR) {
    struct Nodo *pT = pR->ptrSiguiente;
    if (Vacia(pR)) {
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    printf("LISTA ACTUAL: ");
    while (pT != NULL) {
        printf("[%d]<->", pT->clave);
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
    printf("La Lista se ha reiniciado correctamente. . .\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU LISTA DOBLE---\n");
    printf("1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Nodo *pR = CrearNodo(-1000);
    int clave;
    for (;;) {
        switch (menu()) {
            case 1:
                printf("Ingrese la clave: ");
                scanf("%d", &clave);
                Meter(pR, clave);
                break;
            case 2:
                if (Vacia(pR)) {
                    printf("La Lista esta vacia\n");
                    break;
                }
                printf("Ingrese la clave a sacar: ");
                scanf("%d", &clave);
                Sacar(pR, clave);
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
                printf("Elija una opcion valida\n");
                break;
        }
    }
    return 0;
}