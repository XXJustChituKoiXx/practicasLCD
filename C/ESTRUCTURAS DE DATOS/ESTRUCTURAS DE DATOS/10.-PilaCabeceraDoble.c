// Pila con Nodo de cabecera y enlace doble con dato
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
        printf("El espacio en memoria no se ha reservado correctamente\n");
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
    printf("El dato se ha guardado correctamente. . .\n");
    return 1;
}

int Sacar(struct Nodo *pR) {
    struct Nodo *pB = pR->ptrSiguiente;
    if (Vacia(pR)) {
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    printf("El dato %d fue exitosamente eliminado de la Pila. . .\n", pB->dato);
    pR->ptrSiguiente = pB->ptrSiguiente;
    if (pR->ptrSiguiente != NULL)
        pR->ptrSiguiente->ptrAnterior = pR;
    free(pB);
    return 1;
}

int Mostrar(struct Nodo *pR) {
    struct Nodo *pT = pR;
    if (Vacia(pR)) {
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    printf("La Pila ACTUAL es: ");
    while (pT->ptrSiguiente != NULL) {
        pT = pT->ptrSiguiente;
        printf("[%d]<->", pT->dato);
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
    printf("La Pila se reinicio correctamente. . . \n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU PILA DOBLE---\n");
    printf("1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\n");
    printf("Selecciona una opcion: ");
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
                printf("Elija una opcion valida\n");
                break;
        }
    }
    return 0;
}