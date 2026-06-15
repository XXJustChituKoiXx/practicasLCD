// Lista doblemente enlazada, sin nodo de cabecera, ordenada alfanumericamente (puntero doble)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    char key[30];
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo* crearNodo(char *dato) {
    struct Nodo *nodoNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nodoNuevo == NULL) {
        printf("Error de memoria.\n");
        return NULL;
    }
    
    strcpy(nodoNuevo->key, dato);
    // Trucazo para limpiar el salto de linea que deja el fgets
    nodoNuevo->key[strcspn(nodoNuevo->key, "\n")] = 0; 
    
    nodoNuevo->ptrSig = NULL;
    nodoNuevo->ptrAnt = NULL;
    return nodoNuevo;
}

int meterDato(struct Nodo **ptrRef, char *dato) {
    struct Nodo *newNodo = crearNodo(dato);
    if (newNodo == NULL) return 0;

    // Caso 1: Lista completamente vacia
    if (*ptrRef == NULL) {
        *ptrRef = newNodo;
        return 1;
    }

    // Caso 2: El dato va al inicio (es menor alfabeticamente que el primero)
    if (strcmp(newNodo->key, (*ptrRef)->key) < 0) {
        newNodo->ptrSig = *ptrRef;
        (*ptrRef)->ptrAnt = newNodo;
        *ptrRef = newNodo;
        return 1;
    }

    // Caso 3: Buscar su posicion intermedia o final
    struct Nodo *ptrAvanzada = *ptrRef;
    struct Nodo *ptrAtras = NULL;

    while (ptrAvanzada != NULL && strcmp(ptrAvanzada->key, newNodo->key) < 0) {
        ptrAtras = ptrAvanzada;
        ptrAvanzada = ptrAvanzada->ptrSig;
    }

    // Verificar si el dato ya existe (Evitar duplicados)
    if (ptrAvanzada != NULL && strcmp(ptrAvanzada->key, newNodo->key) == 0) {
        free(newNodo);
        return 0; // Retorna 0 si es duplicado
    }

    // Insertar el nodo en su lugar correspondiente
    newNodo->ptrSig = ptrAvanzada;
    newNodo->ptrAnt = ptrAtras;
    ptrAtras->ptrSig = newNodo;

    // Si no es el ultimo nodo, conectamos el siguiente hacia atras
    if (ptrAvanzada != NULL) {
        ptrAvanzada->ptrAnt = newNodo;
    }

    return 1;
}

int sacarDato(struct Nodo **ptrRef, char *dato) {
    if (*ptrRef == NULL) {
        printf("\nLa lista esta vacia, we.\n");
        return 0;
    }

    // Limpiamos el salto de linea del dato ingresado a buscar
    dato[strcspn(dato, "\n")] = 0;

    struct Nodo *ptrRec = *ptrRef;

    // Buscar el nodo
    while (ptrRec != NULL && strcmp(ptrRec->key, dato) != 0) {
        ptrRec = ptrRec->ptrSig;
    }

    if (ptrRec == NULL) { 
        printf("\nEl dato [%s] no se encontro en la lista.\n", dato);
        return 0;
    }

    // Caso 1: Sacar el primer nodo
    if (ptrRec == *ptrRef) {
        *ptrRef = ptrRec->ptrSig; 
        if (*ptrRef != NULL) {
            (*ptrRef)->ptrAnt = NULL;
        }
    } 
    // Caso 2: Sacar un nodo en medio o al final
    else {
        ptrRec->ptrAnt->ptrSig = ptrRec->ptrSig;
        if (ptrRec->ptrSig != NULL) {
            ptrRec->ptrSig->ptrAnt = ptrRec->ptrAnt;
        }
    }

    printf("\nEl dato [%s] fue eliminado con exito.\n", ptrRec->key);
    free(ptrRec);
    return 1;
}

int imprimirTodo(struct Nodo **ptrRef) {
    if (*ptrRef == NULL) {
        printf("\nLa lista esta vacia: NULL.\n");
        return 0;
    }
    
    struct Nodo *ptrRec = *ptrRef;
    printf("\n--- ESTADO DE LA LISTA ---\n");
    while (ptrRec != NULL) {
        printf("[%s] <-> ", ptrRec->key);
        ptrRec = ptrRec->ptrSig;
    }
    printf("NULL\n");
    return 1;
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
    struct Nodo *ptrRef1 = NULL;
    struct Nodo **ptrRef2 = &ptrRef1; 
    char dato[30];
    
    for (;;) {
        switch (menu()) {
            case 1:
                printf("\nIngrese el texto a guardar: ");
                fgets(dato, sizeof(dato), stdin);
                
                if (meterDato(ptrRef2, dato)) {
                    printf("Se inserto correctamente en orden alfabetico.\n");
                } else {
                    printf("El dato ya existe, no se admiten duplicados.\n");
                }
                break;
                
            case 2:
                if (*ptrRef2 != NULL) {
                    printf("\nIngrese el texto que desea eliminar: ");
                    fgets(dato, sizeof(dato), stdin);
                    sacarDato(ptrRef2, dato);
                } else {
                    printf("\nNo hay datos para sacar, mete algo primero.\n");
                }
                break;
                
            case 3:
                imprimirTodo(ptrRef2);
                break;
                
            case 4:
                printf("\nSaliendo del sistema...\n");
                exit(0);
                
            default:
                printf("\nOpcion incorrecta. Intenta de nuevo.\n");
                break;
        }
    }
    return 0;
}