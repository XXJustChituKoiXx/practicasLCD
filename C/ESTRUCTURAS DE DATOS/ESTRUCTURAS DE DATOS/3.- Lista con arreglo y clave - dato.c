#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define MAX_NOMBRE 15

struct Persona {
    int clave;
    char nombre[MAX_NOMBRE];
};

struct Lista {
    struct Persona elementos[TAM];
    int inicio;
    int fin;
};

void inicializar(struct Lista *pL) {
    int i;
    for (i = 0; i < TAM; i++) {
        pL->elementos[i].clave = i + 1;
        strcpy(pL->elementos[i].nombre, "");
    }
    pL->inicio = 0;
    pL->fin = 0;
}

int vacia(struct Lista *pL) {
    return (pL->inicio == pL->fin);
}

int llena(struct Lista *pL) {
    return (pL->fin == TAM);
}

int meterDato(struct Lista *pL, char nombre[]) {
    if (llena(pL)) {
        printf("La lista ya esta llena\n");
        return 0;
    }

    strcpy(pL->elementos[pL->fin].nombre, nombre);
    printf("El elemento se guardo correctamente en la lista con clave %d\n",
           pL->elementos[pL->fin].clave);
    
    pL->fin++;
    return 1;
}

int sacarDato(struct Lista *pL) {
    if (vacia(pL)) {
        printf("La lista ya esta vacia\n");
        return 0;
    }

    printf("La persona que salio de la lista fue: %s con clave %d\n",
           pL->elementos[pL->inicio].nombre,
           pL->elementos[pL->inicio].clave);

    pL->inicio++;
    return 1;
}

int imprimir(struct Lista *pL) {
    int i;
    if (vacia(pL)) {
        printf("La lista esta vacia\n");
        return 0;
    }

    printf("Esta es la lista actual:\n");
    for (i = pL->inicio; i < pL->fin; i++) {
        printf("[%d : %s] ", pL->elementos[i].clave, pL->elementos[i].nombre);
    }
    printf("\n");
    return 1;
}

int reiniciar(struct Lista *pL) {
    if (vacia(pL)) {
        printf("La lista ya esta vacia\n");
        return 0;
    }

    pL->inicio = 0;
    pL->fin = 0;
    printf("La lista se ha reiniciado correctamente\n");
    return 1;
}

int menu() {
    int op;
    printf("\n---MENU---\n");
    printf("1 para Meter\n");
    printf("2 para Sacar\n");
    printf("3 para Mostrar\n");
    printf("4 para Reiniciar\n");
    printf("5 para Salir\n");
    printf("Elige una opcion del menu: ");
    scanf("%d", &op);
    return op;
}

int main() {
    struct Lista l;
    char nombre[MAX_NOMBRE];

    inicializar(&l);

    for (;;) {
        switch (menu()) {
            case 1:
                printf("Ingrese un nombre: ");
                scanf(" %[^\n]", nombre);
                meterDato(&l, nombre);
                break;
            case 2:
                sacarDato(&l);
                break;
            case 3:
                imprimir(&l);
                break;
            case 4:
                reiniciar(&l);
                break;
            case 5:
                printf("*-*-* Saliendo del sistema -*-*-*\n");
                exit(0);
            default:
                printf("Elige una opcion valida dentro del menu\n");
                break;
        }
    }
    return 0;
}