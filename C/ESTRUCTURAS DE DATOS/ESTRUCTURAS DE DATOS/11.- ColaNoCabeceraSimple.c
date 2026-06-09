#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrSiguiente;
};

int vacia(struct Nodo **ptrInicio) {
    return (*ptrInicio == NULL);
}

struct Nodo* crearNodo(int dato) {
    struct Nodo *ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (ptrNuevo == NULL) {
        printf("No se ha reservado el espacio en memoria\n");
        return NULL;
    }
    ptrNuevo->dato = dato;
    ptrNuevo->ptrSiguiente = NULL;
    return ptrNuevo;
}

int meterDato(struct Nodo **ptrInicio, int dato) {
    struct Nodo *ptrNuevo = crearNodo(dato);
    if (ptrNuevo == NULL) return 0;

    if (*ptrInicio == NULL) {
        *ptrInicio = ptrNuevo;
    } else {
        struct Nodo *ptrRecorrido = *ptrInicio;
        while (ptrRecorrido->ptrSiguiente != NULL) {
            ptrRecorrido = ptrRecorrido->ptrSiguiente;
        }
        ptrRecorrido->ptrSiguiente = ptrNuevo;
    }
    printf("El dato se ha agregado a la cola exitosamente\n");
    return 1;
}

int sacarDato(struct Nodo **ptrInicio) {
    if (vacia(ptrInicio)) {
        printf("La Cola esta vacia. . .\n");
        return 0;
    }

    struct Nodo *ptrBasura = *ptrInicio;
    printf("El dato %d fue exitosamente eliminado. . .\n", ptrBasura->dato);
    
    *ptrInicio = ptrBasura->ptrSiguiente;
    free(ptrBasura);
    return 1;
}

int imprimir(struct Nodo **ptrInicio) {
    struct Nodo *ptrRecorrido = *ptrInicio;
    if (vacia(ptrInicio)) {
        printf("La Cola esta vacia. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    while (ptrRecorrido != NULL) {
        printf("[%d]->", ptrRecorrido->dato);
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
    printf("La COLA se ha reiniciado correctamente. . .\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU (Cola sin cabecera)---\n");
    printf("1. Meter\n2. Sacar\n3. Mostrar\n4. Reiniciar\n5. Salir\n");
    printf("Seleccione una opcion del menu: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Nodo *ptrInicio = NULL;
    int dato;

    for (;;) {
        switch(menu()) {
            case 1:
                printf("Ingrese el dato que quiere en la Cola: ");
                scanf("%d", &dato);
                meterDato(&ptrInicio, dato);
                break;
            case 2:
                sacarDato(&ptrInicio);
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
                printf("Elija una opcion valida\n");
                break;
        }
    }
    return 0;
}