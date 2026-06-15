#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato {
    char nombre[30];
    int edad;
};

struct Nodo {
    struct Dato dato;
    int clave;
    struct Nodo *ptrSig, *ptrAnt;
};

struct Nodo* crearNodo(struct Dato* dato, int clave) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo != NULL) {
        nuevo->dato = *dato;
        nuevo->clave = clave;
        nuevo->ptrSig = NULL;
        nuevo->ptrAnt = NULL;
    }
    return nuevo;
}

int meterDato(struct Nodo **ptrRef, struct Dato *dato, int clave) {
    struct Nodo *nuevo = crearNodo(dato, clave);
    struct Nodo *actual = *ptrRef;
    
    // Inserción en lista vacía o al inicio
    if (*ptrRef == NULL || clave < (*ptrRef)->clave) {
        nuevo->ptrSig = *ptrRef;
        if (*ptrRef != NULL) (*ptrRef)->ptrAnt = nuevo;
        *ptrRef = nuevo;
        return 1;
    }

    // Buscar posición
    while (actual->ptrSig != NULL && actual->ptrSig->clave < clave) {
        actual = actual->ptrSig;
    }

    // Insertar después de 'actual'
    nuevo->ptrSig = actual->ptrSig;
    nuevo->ptrAnt = actual;
    if (actual->ptrSig != NULL) actual->ptrSig->ptrAnt = nuevo;
    actual->ptrSig = nuevo;
    
    return 1;
}

int sacarDato(struct Nodo **ptrRef, int clave) {
    struct Nodo *actual = *ptrRef;

    while (actual != NULL && actual->clave != clave) {
        actual = actual->ptrSig;
    }

    if (actual == NULL) return 0; // No encontrado

    if (actual->ptrAnt != NULL) actual->ptrAnt->ptrSig = actual->ptrSig;
    else *ptrRef = actual->ptrSig;

    if (actual->ptrSig != NULL) actual->ptrSig->ptrAnt = actual->ptrAnt;

    free(actual);
    return 1;
}

void imprimir(struct Nodo *ptrRef) {
    struct Nodo *actual = ptrRef;
    printf("\n--- CONTENIDO LISTA ---");
    while (actual != NULL) {
        printf("\nClave: %d | Nombre: %s | Edad: %d", actual->clave, actual->dato.nombre, actual->dato.edad);
        actual = actual->ptrSig;
    }
    printf("\n");
}

int menu() {
    int opc;
    printf("\nMENU HASH");
    printf("\n1. Meter Dato");
    printf("\n2. Sacar Dato");
    printf("\n3. Imprimir todo");
    printf("\n4. Salir");
    printf("\nIngresa una opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct Nodo *inicio = NULL;
    struct Dato d;
    int clave;

    for (;;) {
        switch (menu()) {
            case 1:
                printf("Clave: "); scanf("%d", &clave);
                printf("Nombre: "); scanf("%s", d.nombre);
                printf("Edad: "); scanf("%d", &d.edad);
                meterDato(&inicio, &d, clave);
                break;
            case 2:
                printf("Clave a eliminar: "); scanf("%d", &clave);
                if (sacarDato(&inicio, clave)) printf("Eliminado correctamente.\n");
                else printf("No encontrado.\n");
                break;
            case 3:
                imprimir(inicio);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}