#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrSiguiente;
    struct Nodo *ptrAnterior;
};

int vacia(struct Nodo *ptrCabecera) {
    return (ptrCabecera->ptrSiguiente == NULL);
}

struct Nodo* crearNodo(int valor) {
    struct Nodo *ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (ptrNuevo == NULL) {
        printf("No se reservo el espacio de memoria\n");
        return NULL;
    }
    ptrNuevo->dato = valor;
    ptrNuevo->ptrSiguiente = NULL;
    ptrNuevo->ptrAnterior = NULL;
    return ptrNuevo;
}

int meterDato(struct Nodo *ptrCabecera, int valor) {
    struct Nodo *ptrNuevo = crearNodo(valor);
    ptrNuevo->ptrSiguiente = ptrCabecera->ptrSiguiente;
    if (ptrCabecera->ptrSiguiente != NULL) {
        ptrCabecera->ptrSiguiente->ptrAnterior = ptrNuevo;
    }
    ptrCabecera->ptrSiguiente = ptrNuevo;
    ptrNuevo->ptrAnterior = ptrCabecera;
    printf("El dato se ha agregado a la Cola exitosamente\n");
    return 1;
}

int sacarDato(struct Nodo *ptrCabecera) {
    struct Nodo *ptrRetorno = ptrCabecera, *ptrAvanzar = ptrCabecera->ptrSiguiente;
    if (vacia(ptrCabecera)) {
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    while (ptrAvanzar->ptrSiguiente != NULL) {
        ptrAvanzar = ptrAvanzar->ptrSiguiente;
        ptrRetorno = ptrRetorno->ptrSiguiente;
    }
    printf("El elemento [%d|*] ha salido de la Cola exitosamente. . .\n", ptrAvanzar->dato);
    ptrRetorno->ptrSiguiente = ptrAvanzar->ptrSiguiente;
    if (ptrAvanzar->ptrSiguiente != NULL)
        ptrAvanzar->ptrSiguiente->ptrAnterior = ptrRetorno;
    free(ptrAvanzar);
    return 1;
}

int imprimir(struct Nodo *ptrCabecera) {
    struct Nodo *ptrRecorrido = ptrCabecera->ptrSiguiente;
    if (vacia(ptrCabecera)) {
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    while (ptrRecorrido != NULL) {
        printf("[%d|*]<->", ptrRecorrido->dato);
        ptrRecorrido = ptrRecorrido->ptrSiguiente;
    }
    printf("NULL. . .\n");
    return 1;
}

int reiniciar(struct Nodo *ptrCabecera) {
    struct Nodo *ptrBasura = ptrCabecera->ptrSiguiente;
    if (vacia(ptrCabecera)) {
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    while (ptrCabecera->ptrSiguiente != NULL) {
        ptrBasura = ptrCabecera->ptrSiguiente;
        ptrCabecera->ptrSiguiente = ptrBasura->ptrSiguiente;
        free(ptrBasura);
    }
    printf("La COLA se ha reiniciado correctamente. . .\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU---\n");
    printf("1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\n");
    printf("Seleccione una opcion dentro del menu: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Nodo *ptrCabecera = crearNodo(-1000);
    int dato;

    for (;;) {
        switch(menu()) {
            case 1:
                printf("Ingrese el dato que quiere en la Cola: ");
                scanf("%d", &dato);
                meterDato(ptrCabecera, dato);
                break;
            case 2:
                sacarDato(ptrCabecera);
                break;
            case 3:
                imprimir(ptrCabecera);
                break;
            case 4:
                reiniciar(ptrCabecera);
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