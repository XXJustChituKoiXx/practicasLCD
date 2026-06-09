//cola circular con una lista enlazada doble
//terminado we
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo* crearNodo(int dato) {
    struct Nodo *ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (ptrNuevo == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return NULL;
    }
    ptrNuevo->dato = dato;
    ptrNuevo->ptrSig = NULL;
    ptrNuevo->ptrAnt = NULL;
    return ptrNuevo;
}

int meterDato(struct Nodo **ptrFrente, struct Nodo **ptrFin, int dato) {
    struct Nodo *ptrNuevo = crearNodo(dato);
    if (ptrNuevo == NULL) return 0;

    // Caso 1: La cola está vacía
    if (*ptrFrente == NULL) {
        *ptrFrente = ptrNuevo;
        *ptrFin = ptrNuevo;
        // Al ser circular, se apunta a sí mismo
        ptrNuevo->ptrSig = ptrNuevo;
        ptrNuevo->ptrAnt = ptrNuevo;
    } 
    // Caso 2: Ya hay elementos (se mete por el FIN)
    else {
        ptrNuevo->ptrAnt = *ptrFin;
        ptrNuevo->ptrSig = *ptrFrente;
        
        (*ptrFin)->ptrSig = ptrNuevo;
        (*ptrFrente)->ptrAnt = ptrNuevo;
        
        *ptrFin = ptrNuevo; // El nuevo nodo es el nuevo fin
    }
    printf("\nDato [%d] metido a la cola circular exitosamente.\n", dato);
    return 1;
}

int sacarDato(struct Nodo **ptrFrente, struct Nodo **ptrFin, int *dato) {
    // Si la cola está vacía
    if (*ptrFrente == NULL) {
        printf("\nLa cola circular ya esta vacia bro.\n");
        return 0;
    }

    struct Nodo *ptrBasura = *ptrFrente;
    *dato = ptrBasura->dato;

    // Si solo queda un elemento
    if (*ptrFrente == *ptrFin) {
        *ptrFrente = NULL;
        *ptrFin = NULL;
    } 
    // Si hay más de un elemento (se saca por el FRENTE)
    else {
        *ptrFrente = ptrBasura->ptrSig;
        (*ptrFrente)->ptrAnt = *ptrFin;
        (*ptrFin)->ptrSig = *ptrFrente;
    }

    free(ptrBasura);
    return 1;
}

int imprimirTodo(struct Nodo *ptrFrente) {
    if (ptrFrente == NULL) {
        printf("\nLa cola esta vacia, no hay nada que mostrar.\n");
        return 0;
    }

    struct Nodo *ptrRec = ptrFrente;
    
    while (ptrRec != ptrFrente) {
            printf("\n %d", ptrRec->dato);
            ptrRec = ptrRec->ptrSig;
        }
    
    printf("(Regresa al inicio: [%d])\n", ptrFrente->dato);
    return 1;
}

int menu() {
    int opc;
    printf("\n--- MENU COLA CIRCULAR ---");
    printf("\n1. Meter");
    printf("\n2. Sacar");
    printf("\n3. Imprimir todo");
    printf("\n4. Salir");
    printf("\nIngresa opcion: ");
    scanf("%d", &opc);
    return opc;
}

int main() {
    struct Nodo *frente = NULL;
    struct Nodo *fin = NULL;
    int dato;

    for(;;) {
        switch (menu()) {
            case 1:
                printf("\nIngrese un entero para la cola: ");
                scanf("%d", &dato);
                meterDato(&frente, &fin, dato);
                break;
            case 2:
                if (sacarDato(&frente, &fin, &dato)) {
                    printf("\nEl dato que salio de la cola fue: %d\n", dato);
                }
                break;
            case 3:
                imprimirTodo(frente);
                break;
            case 4:
                printf("\nSaliendo...\n");
                exit(0);
                break;
            default:
                printf("\nOpcion invalida, intenta de nuevo.\n");
                break;
        }
    }
    return 0;
}