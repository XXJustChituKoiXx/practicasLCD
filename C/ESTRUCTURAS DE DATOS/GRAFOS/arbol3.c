#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int dato;
    struct nodo *pI;
    struct nodo *pD;
};

struct nodo *createNodo(int dato){

    struct nodo *ptrNuevo;

    ptrNuevo = (struct nodo *)malloc(sizeof(struct nodo));

    if(ptrNuevo == NULL){
        printf("\nError al reservar memoria");
        return NULL;
    }

    ptrNuevo->dato = dato;
    ptrNuevo->pI = NULL;
    ptrNuevo->pD = NULL;

    return ptrNuevo;
}

void insertarNodo(struct nodo **ptrRef, int dato){

    if(*ptrRef == NULL)
        *ptrRef = createNodo(dato);

    else if(dato < (*ptrRef)->dato)
        insertarNodo(&((*ptrRef)->pI), dato);

    else if(dato > (*ptrRef)->dato)
        insertarNodo(&((*ptrRef)->pD), dato);

    else
        printf("\nEl dato ya existe en el arbol");
}

void imprPreorder(struct nodo *ptrRaiz){

    if(ptrRaiz != NULL){

        printf("%d ", ptrRaiz->dato);

        imprPreorder(ptrRaiz->pI);
        imprPreorder(ptrRaiz->pD);
    }
}

void imprimirArbol(struct nodo *ptrRaiz, int contador){

    int j;

    if(ptrRaiz != NULL){

        imprimirArbol(ptrRaiz->pD, contador + 1);

        printf("\n");

        for(j = 1; j < contador; j++)
            printf(" - ");

        printf("%d", ptrRaiz->dato);

        imprimirArbol(ptrRaiz->pI, contador + 1);
    }
}

int compararArboles(struct nodo *ptrRef1, struct nodo *ptrRef2){

    if(ptrRef1 == NULL && ptrRef2 == NULL)
        return 1;

    if(ptrRef1 == NULL || ptrRef2 == NULL)
        return 0;

    if(ptrRef1->dato != ptrRef2->dato)
        return 0;

    return compararArboles(ptrRef1->pI, ptrRef2->pI) &&
           compararArboles(ptrRef1->pD, ptrRef2->pD);
}

void eliminarNodos(struct nodo **ptrRef){

    if(*ptrRef != NULL){

        eliminarNodos(&((*ptrRef)->pI));
        eliminarNodos(&((*ptrRef)->pD));

        free(*ptrRef);
        *ptrRef = NULL;
    }
}

void podarArboles(struct nodo **ptrRef, int dato){

    if(*ptrRef == NULL)
        return;

    if((*ptrRef)->dato == dato){

        eliminarNodos(ptrRef);

        printf("\nSubarbol eliminado");
        return;
    }

    podarArboles(&((*ptrRef)->pI), dato);
    podarArboles(&((*ptrRef)->pD), dato);
}

struct nodo *buscarNodo(struct nodo *ptrRaiz, int dato){

    if(ptrRaiz == NULL)
        return NULL;

    if(ptrRaiz->dato == dato)
        return ptrRaiz;

    if(dato < ptrRaiz->dato)
        return buscarNodo(ptrRaiz->pI, dato);

    return buscarNodo(ptrRaiz->pD, dato);
}

void insertarFinal(struct nodo **ptrRef, struct nodo *ptrNodo){

    if(*ptrRef == NULL){

        *ptrRef = ptrNodo;
        return;
    }

    if(ptrNodo->dato < (*ptrRef)->dato)
        insertarFinal(&((*ptrRef)->pI), ptrNodo);
    else
        insertarFinal(&((*ptrRef)->pD), ptrNodo);
}

void unirArbol(struct nodo *ptrRef1,
               struct nodo *ptrRef2,
               int dato){

    struct nodo *ptrAux;

    ptrAux = buscarNodo(ptrRef1, dato);

    if(ptrAux == NULL){

        printf("\nNodo no encontrado");
        return;
    }

    if(ptrAux->pI != NULL &&
       ptrAux->pD != NULL){

        printf("\nEl nodo ya tiene dos hijos");
        return;
    }

    if(ptrRef2->dato < ptrAux->dato){

        if(ptrAux->pI == NULL)
            ptrAux->pI = ptrRef2;
        else
            insertarFinal(&(ptrAux->pI), ptrRef2);
    }
    else{

        if(ptrAux->pD == NULL)
            ptrAux->pD = ptrRef2;
        else
            insertarFinal(&(ptrAux->pD), ptrRef2);
    }

    printf("\nArbol unido correctamente");
}

int menu(){

    int opc;

    printf("\n\n------ MENU ------");
    printf("\n1. Meter en Arbol 1");
    printf("\n2. Meter en Arbol 2");
    printf("\n3. Mostrar arboles");
    printf("\n4. Comparar arboles");
    printf("\n5. Podar Arbol 1");
    printf("\n6. Unir Arbol 2 a un nodo del Arbol 1");
    printf("\n7. Salir");
    printf("\nOpcion: ");

    scanf("%d",&opc);

    return opc;
}

int main(){

    struct nodo *ptrRef1;
    struct nodo *ptrRef2;
    struct nodo **ptrRef3;
    struct nodo **ptrRef4;

    int dato;
    int nodoDestino;

    ptrRef1 = NULL;
    ptrRef2 = NULL;

    ptrRef3 = &ptrRef1;
    ptrRef4 = &ptrRef2;

    for(;;){

        switch(menu()){

        case 1:

            printf("\nDato: ");
            scanf("%d",&dato);

            insertarNodo(ptrRef3,dato);

            break;

        case 2:

            printf("\nDato: ");
            scanf("%d",&dato);

            insertarNodo(ptrRef4,dato);

            break;

        case 3:

            printf("\n\nARBOL 1\n");

            if(ptrRef1 == NULL)
                printf("\nVacio");
            else
                imprimirArbol(ptrRef1,1);

            printf("\n\nARBOL 2\n");

            if(ptrRef2 == NULL)
                printf("\nVacio");
            else
                imprimirArbol(ptrRef2,1);

            printf("\n");

            break;

        case 4:

            if(compararArboles(ptrRef1,ptrRef2))
                printf("\nArboles iguales");
            else
                printf("\nArboles distintos");

            break;

        case 5:

            printf("\nNodo a podar: ");
            scanf("%d",&dato);

            podarArboles(ptrRef3,dato);

            break;

        case 6:

            if(ptrRef2 == NULL){

                printf("\nEl Arbol 2 esta vacio");
                break;
            }

            printf("\nNodo destino en Arbol 1: ");
            scanf("%d",&nodoDestino);

            unirArbol(ptrRef1,ptrRef2,nodoDestino);

            ptrRef2 = NULL;

            break;

        case 7:

            eliminarNodos(ptrRef3);
            eliminarNodos(ptrRef4);

            exit(0);

        default:

            printf("\nOpcion invalida");
        }
    }

    return 0;
}