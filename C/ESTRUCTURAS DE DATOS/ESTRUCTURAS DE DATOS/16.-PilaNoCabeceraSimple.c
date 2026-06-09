#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int clave;
    struct Nodo *ptrSiguiente;
};

int vacia(struct Nodo **ptrInicio) {
    return (*ptrInicio == NULL);
}

struct Nodo* crearNodo(int clave) {
    struct Nodo *ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (ptrNuevo == NULL) {
        printf("No se ha reservado el espacio en memoria\n");
        return NULL;
    }
    ptrNuevo->clave = clave;
    ptrNuevo->ptrSiguiente = NULL;
    return ptrNuevo;
}

int meterDato(struct Nodo **ptrInicio, int clave) {
    struct Nodo *ptrNuevo = crearNodo(clave);
    struct Nodo **ptrRecorrido = ptrInicio;

    // Busca la posición correcta para mantener el orden ascendente
    while ((*ptrRecorrido != NULL) && ((*ptrRecorrido)->clave < clave)) {
        ptrRecorrido = &((*ptrRecorrido)->ptrSiguiente);
    }
    
    ptrNuevo->ptrSiguiente = *ptrRecorrido;
    *ptrRecorrido = ptrNuevo;
    return 1;
}

int sacarDato(struct Nodo **ptrInicio, int clave) {
    struct Nodo *ptrBasura;
    struct Nodo **ptrRecorrido = ptrInicio;

    if (vacia(ptrInicio)) {
        printf("La Lista esta vacia!\n");
        return 0;
    }

    // Busca el nodo que contiene la clave
    while ((*ptrRecorrido != NULL) && ((*ptrRecorrido)->clave != clave)) {
        ptrRecorrido = &((*ptrRecorrido)->ptrSiguiente);
    }

    if (*ptrRecorrido == NULL) {
        printf("La clave no esta dentro de la Lista.\n");
        return 0;
    }

    ptrBasura = *ptrRecorrido;
    *ptrRecorrido = ptrBasura->ptrSiguiente;

    printf("El dato %d fue exitosamente eliminado.\n", ptrBasura->clave);
    free(ptrBasura);
    return 1;
}

int imprimir(struct Nodo **ptrInicio) {
    struct Nodo *ptrRecorrido = *ptrInicio;
    if (vacia(ptrInicio)) {
        printf("La Lista esta vacia!\n");
        return 0;
    }
    printf("LISTA ACTUAL: ");
    while (ptrRecorrido != NULL) {
        printf("[%d]->", ptrRecorrido->clave);
        ptrRecorrido = ptrRecorrido->ptrSiguiente;
    }
    printf("NULL\n");
    return 1;
}

int reiniciar(struct Nodo **ptrInicio) {
    struct Nodo *ptrBasura;
    while (*ptrInicio != NULL) {
        ptrBasura = *ptrInicio;
        *ptrInicio = ptrBasura->ptrSiguiente;
        free(ptrBasura);
    }
    printf("La LISTA se ha reiniciado correctamente.\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU LISTA ORDENADA---\n");
    printf("1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Nodo *ptrInicio = NULL;
    int clave;

    for (;;) {
        switch (menu()) {
            case 1:
                printf("Ingrese la clave a meter: ");
                scanf("%d", &clave);
                meterDato(&ptrInicio, clave);
                break;
            case 2:
                printf("Ingrese la clave a sacar: ");
                scanf("%d", &clave);
                sacarDato(&ptrInicio, clave);
                break;
            case 3:
                imprimir(&ptrInicio);
                break;
            case 4:
                reiniciar(&ptrInicio);
                break;
            case 5:
                printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
                exit(0);
            default:
                printf("Elija una opcion valida.\n");
                break;
        }
    }
    return 0;
}