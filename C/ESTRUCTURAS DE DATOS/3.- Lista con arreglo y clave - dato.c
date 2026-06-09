#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define MAX_NOMBRE 15

struct Lista {
    int keys[TAM];
    char names[TAM][MAX_NOMBRE];
    int inicio;
    int fin;
};

void Inicializar(struct Lista *pL) {
    int i;

    for (i = 0; i < TAM; i++) {
        pL->keys[i] = i + 1;
        strcpy(pL->names[i], "");
    }

    pL->inicio = 0;
    pL->fin = 0;
}

int Vacia(struct Lista *pL) {
    if (pL->inicio == pL->fin)
        return 1;
    else
        return 0;
}

int Llena(struct Lista *pL) {
    if (pL->fin == TAM)
        return 1;
    else
        return 0;
}

int Meter(struct Lista *pL, char name[]) {
    if (Llena(pL)) {
        printf("La lista ya esta llena\n");
        return 0;
    }

    strcpy(pL->names[pL->fin], name);

    printf("El elemento se guardo correctamente en la lista con clave %d\n",
           pL->keys[pL->fin]);

    pL->fin++;

    return 1;
}

int Sacar(struct Lista *pL) {
    if (Vacia(pL)) {
        printf("La lista ya esta vacia\n");
        return 0;
    }

    printf("La persona que salio de la lista fue: %s con clave %d\n",
           pL->names[pL->inicio],
           pL->keys[pL->inicio]);

    pL->inicio++;

    return 1;
}

int Mostrar(struct Lista *pL) {
    int i;

    if (Vacia(pL)) {
        printf("La lista esta vacia\n");
        return 0;
    }

    printf("Esta es la lista actual:\n");

    for (i = pL->inicio; i < pL->fin; i++) {
        printf("[%d : %s] ", pL->keys[i], pL->names[i]);
    }

    printf("\n");

    return 1;
}

int Borrar(struct Lista *pL) {
    if (Vacia(pL)) {
        printf("La lista ya esta vacia\n");
        return 0;
    }

    pL->inicio = 0;
    pL->fin = 0;

    printf("La lista se ha borrado correctamente\n");

    return 1;
}

int menu() {
    int op;

    printf("\n---MENU---\n");
    printf("1 para Meter\n");
    printf("2 para Sacar\n");
    printf("3 para Mostrar\n");
    printf("4 para Borrar\n");
    printf("5 para Salir\n");
    printf("Elige una opcion del menu: ");
    scanf("%d", &op);

    return op;
}

int main() {
    struct Lista l;
    char name[MAX_NOMBRE];

    Inicializar(&l);

    for (;;) {
        switch (menu()) {
            case 1:
                if (Llena(&l)) {
                    printf("La lista ya esta llena\n");
                    break;
                }

                printf("Ingrese un nombre: ");
                scanf(" %[^\n]", name);

                Meter(&l, name);
                break;

            case 2:
                Sacar(&l);
                break;

            case 3:
                Mostrar(&l);
                break;

            case 4:
                Borrar(&l);
                break;

            case 5:
                printf("*-*-* Saliendo del sistema -*-*-*\n");
                exit(0);

            default:
                printf("Elige una opcion dentro del menu\n");
                break;
        }
    }

    return 0;
}
