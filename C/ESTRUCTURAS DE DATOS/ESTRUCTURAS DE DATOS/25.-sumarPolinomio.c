#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    char base;
    int exponente;
    int coeficiente;
    struct Nodo *ptrSig;
};

// Crea un nuevo nodo
struct Nodo* crearNodo(char base, int exp) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->base = base;
    nuevo->exponente = exp;
    nuevo->coeficiente = 1;
    nuevo->ptrSig = NULL;
    return nuevo;
}

void procesarTermino(struct Nodo **ptrRef2, char base, int exp) {
    struct Nodo *ptrRec = *ptrRef2;
    while (ptrRec != NULL) {
        if (ptrRec->base == base && ptrRec->exponente == exp) {
            ptrRec->coeficiente += 1;
            return;
        }
        ptrRec = ptrRec->ptrSig;
    }

    struct Nodo *nuevo = crearNodo(base, exp);
    nuevo->ptrSig = *ptrRef2;
    *ptrRef2 = nuevo;
}

void imprimir(struct Nodo *ptrRef) {
    printf("Resultado: ");
    while (ptrRef != NULL) {
        printf("%d%c^%d", ptrRef->coeficiente, ptrRef->base, ptrRef->exponente);
        if (ptrRef->ptrSig != NULL) printf(" + ");
        ptrRef = ptrRef->ptrSig;
    }
    printf("\n");
}

int main() {
    struct Nodo *lista = NULL;
    char cadena[50];
    
    printf("Ingrese la polinomio (ejemplo: x^2 + x^2): ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = 0;

    char *termino = strtok(cadena, "+");
    while (termino != NULL) {
        char base;
        int exp;
        
        if (sscanf(termino, " %c^%d", &base, &exp) == 2) {
            procesarTermino(&lista, base, exp);
        }
        
        termino = strtok(NULL, "+");
    }
    
    imprimir(lista);

    return 0;
}