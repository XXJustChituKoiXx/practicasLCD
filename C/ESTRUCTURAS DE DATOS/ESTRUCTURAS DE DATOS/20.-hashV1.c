#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int key;
    struct Nodo *ptrSig;
    struct Nodo *ptrAnt;
};

struct Nodo *createNodo(int key)
{
    struct Nodo *nodoNuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nodoNuevo->key = key;
    nodoNuevo->ptrSig = NULL;
    nodoNuevo->ptrAnt = NULL;
    return nodoNuevo;
}

int meterNodo(struct Nodo *ptrRef, int key)
{
    struct Nodo *ptrRec, *ptrAtras;
    ptrRec = ptrRef->ptrSig;
    ptrAtras = ptrRef;

    while (ptrRec != NULL && key >= ptrRec->key)
    {
        if (ptrRec->key == key)
        {
            return 1;
        }
        ptrAtras = ptrRec;
        ptrRec = ptrRec->ptrSig;
    }

    struct Nodo *ptrNew;
    ptrNew = createNodo(key);

    ptrNew->ptrSig = ptrRec;
    ptrNew->ptrAnt = ptrAtras;
    ptrAtras->ptrSig = ptrNew;

    if (ptrRec != NULL)
    {
        ptrRec->ptrAnt = ptrNew;
    }

    return 0;
}

int imprimir(struct Nodo *ptrRef)
{
    struct Nodo *ptrRec;
    ptrRec = ptrRef->ptrSig;
    while (ptrRec != NULL)
    {
        printf("%d\n", ptrRec->key);
        ptrRec = ptrRec->ptrSig;
    }
    return 0;
}

int sacarDato(struct Nodo *ptrRef, int *dato)
{
    struct Nodo *ptrBasura, *ptrAtras;
    ptrBasura = ptrRef->ptrSig;
    ptrAtras = ptrBasura;
    if(ptrRef ->ptrSig == NULL){
        printf("Lista vacia");
        return 0;
    }
    while (ptrBasura->key != *dato || ptrBasura != NULL)
    {
        ptrAtras = ptrBasura;
        ptrBasura = ptrBasura->ptrSig;
    }
    if (ptrBasura == NULL)
        return 1;
    if (ptrBasura->ptrSig == NULL)
    {
        ptrAtras->ptrSig = NULL;
        *dato = ptrBasura->key;
        free(ptrBasura);
    }
    else
    {
        ptrBasura->ptrSig->ptrAnt = ptrAtras;
        ptrAtras->ptrSig = ptrBasura->ptrSig;
        *dato = ptrBasura->key;
        free(ptrBasura);
    }
    return 0;
}
int menu()
{
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Sacar");
    printf("\n3.Imprimir todo");
    printf("\n4.Salir");
    printf("\nIngresa opcion:");
    scanf("%d", &opc);
    return opc;
}

int main()
{
    struct Nodo *ptrRef = createNodo(-1);
    int dato;
    for (;;)
    {
        switch (menu())
        {
        case 1:
            printf("Ingrese dato:");
            scanf("%d", &dato);
            meterNodo(ptrRef, dato);
            break;
        case 2:
            scanf("%d", &dato);
            if (sacarDato(ptrRef, &dato) != 0){
                printf("Dato no encontrado");
            }else{
                printf("Dato sacado: %d", dato);
            }
            break;
        case 3:
            imprimir(ptrRef);
            break;
        case 4:
            exit(1);
            break;

        default:
            printf("Opcion incorrecta");
            exit(1);
            break;
        }
    }
    return 0;
}