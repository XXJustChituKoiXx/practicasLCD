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
    if (ptrNuevo == NULL) return NULL;
    ptrNuevo->dato = valor;
    ptrNuevo->ptrSiguiente = NULL;
    ptrNuevo->ptrAnterior = NULL;
    return ptrNuevo;
}

int meterDato(struct Nodo *ptrCabecera, int valor) {
    struct Nodo *ptrNuevo = crearNodo(valor);
    if (ptrNuevo == NULL) return 0;

    // En cola, metemos al final para mantener el orden FIFO
    struct Nodo *ptrRecorrido = ptrCabecera;
    while (ptrRecorrido->ptrSiguiente != NULL) {
        ptrRecorrido = ptrRecorrido->ptrSiguiente;
    }

    ptrNuevo->ptrSiguiente = NULL;
    ptrNuevo->ptrAnterior = ptrRecorrido;
    ptrRecorrido->ptrSiguiente = ptrNuevo;

    printf("Dato agregado a la cola correctamente.\n");
    return 1;
}

int sacarDato(struct Nodo *ptrCabecera) {
    if (vacia(ptrCabecera)) {
        printf("La cola esta vacia!\n");
        return 0;
    }

    // En cola, sacamos del inicio (lo que apunta la cabecera)
    struct Nodo *ptrBasura = ptrCabecera->ptrSiguiente;
    printf("El elemento [%d] ha salido de la cola.\n", ptrBasura->dato);

    ptrCabecera->ptrSiguiente = ptrBasura->ptrSiguiente;
    if (ptrCabecera->ptrSiguiente != NULL) {
        ptrCabecera->ptrSiguiente->ptrAnterior = ptrCabecera;
    }

    free(ptrBasura);
    return 1;
}

int imprimir(struct Nodo *ptrCabecera) {
    if (vacia(ptrCabecera)) {
        printf("La cola esta vacia.\n");
        return 0;
    }
    struct Nodo *ptrRecorrido = ptrCabecera->ptrSiguiente;
    printf("COLA ACTUAL: ");
    while (ptrRecorrido != NULL) {
        printf("[%d|*]->", ptrRecorrido->dato);
        ptrRecorrido = ptrRecorrido->ptrSiguiente;
    }
    printf("NULL.\n");
    return 1;
}

int reiniciar(struct Nodo *ptrCabecera) {
    while (!vacia(ptrCabecera)) {
        sacarDato(ptrCabecera);
    }
    printf("La cola se ha reiniciado correctamente.\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU COLA---\n1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\nSeleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Nodo *ptrCabecera = crearNodo(-1000);
    int dato;

    for (;;) {
        switch (menu()) {
            case 1:
                printf("Ingrese dato: ");
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
                exit(0);
        }
    }
    return 0;
}