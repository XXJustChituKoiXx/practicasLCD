#include <stdio.h>
#include <stdlib.h>
    struct Nodo{
        int dato;
        struct Nodo *ptrIzq;
        struct Nodo *ptrDer;
    };
    struct Nodo *createNodo(int dato){
        struct Nodo *newNodo;
        newNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
        newNodo -> dato = dato;
        newNodo -> ptrDer = NULL;
        newNodo -> ptrIzq = NULL;
        return newNodo;
    }
    void insertarNodo(struct Nodo **ptrRaiz,int dato){
        if(*ptrRaiz == NULL){
            *ptrRaiz = createNodo(dato);
        }else if(((*ptrRaiz)->dato)>dato){
            insertarNodo(&((*ptrRaiz)->ptrIzq),dato);
        }else{
            insertarNodo(&((*ptrRaiz)->ptrDer),dato);
        }
    }
    void imprPreorder(struct Nodo **ptrRef){
        struct Nodo *ptrRec;
        ptrRec = *ptrRef;
        if(ptrRec != NULL){
            printf("\n Dato: %d ",ptrRec->dato);
            imprPreorder(&(ptrRec->ptrIzq));
            imprPreorder(&(ptrRec->ptrDer));
        }

    }
    void imprPostorder(struct Nodo **ptrRef){
        struct Nodo *ptrRec;
        ptrRec = *ptrRef;
        if(ptrRec != NULL){
            imprPostorder(&(ptrRec->ptrIzq));
            imprPostorder(&(ptrRec->ptrDer));
            printf("\n Dato: %d ",ptrRec->dato);
        }
    }
    void imprimirInorder(struct Nodo **ptrRef){
        struct Nodo *ptrRec;
        ptrRec = *ptrRef;
        if(ptrRec != NULL){
            imprimirInorder(&(ptrRec->ptrIzq));
            printf("\n Dato: %d ",ptrRec->dato);
            imprimirInorder(&(ptrRec->ptrDer));
        }
    }
    int imprimirArbol(struct Nodo *ptrRaiz,int contador){
        int i,j;
        i = contador;
        if(ptrRaiz != NULL){
            imprimirArbol(ptrRaiz -> ptrDer,i++);
            printf("\n");
            for(j=1;j < i; j++) printf(" - ");
            printf(" %d ",ptrRaiz -> dato);
            imprimirArbol(ptrRaiz -> ptrIzq,i++);
        }
        return 0;
    }
    int sumarNodo(struct Nodo **ptrRef){
        if(*ptrRef == NULL) return 0;
        return (*ptrRef) -> dato + sumarNodo(&((*ptrRef) -> ptrDer)) + sumarNodo(&((*ptrRef) -> ptrIzq)); 
    }
    int contarNodos(struct Nodo **ptrRef){
        if(*ptrRef == NULL) return 0;
        return (1 + contarNodos(&((*ptrRef) -> ptrDer)) + contarNodos(&((*ptrRef) -> ptrIzq)));
    }
    int contarNodosHoja(struct Nodo **ptrRef){
        if(*ptrRef == NULL) return 0;
        if((*ptrRef) -> ptrDer == NULL && (*ptrRef) -> ptrIzq == NULL) return 1;
        return (contarNodosHoja(&((*ptrRef) -> ptrDer)) + contarNodosHoja(&((*ptrRef) -> ptrIzq)));
    }
int sumarNodosHoja(struct Nodo **ptrRef) {
    if(*ptrRef == NULL) return 0;
    if((*ptrRef)->ptrDer == NULL && (*ptrRef)->ptrIzq == NULL) return (*ptrRef)->dato; 
    return (sumarNodosHoja(&((*ptrRef)->ptrDer)) + sumarNodosHoja(&((*ptrRef)->ptrIzq)));
} 

    int sumarNodosInternos(struct Nodo **ptrRef) {
        if(*ptrRef == NULL) return 0;
        if((*ptrRef)->ptrDer != NULL || (*ptrRef)->ptrIzq != NULL) 
            return (*ptrRef)->dato + sumarNodosInternos(&((*ptrRef)->ptrDer)) + sumarNodosInternos(&((*ptrRef)->ptrIzq));
    
        return sumarNodosInternos(&((*ptrRef)->ptrDer)) + sumarNodosInternos(&((*ptrRef)->ptrIzq));
    }
    int contarNodosInternos(struct Nodo **ptrRef) {
        if(*ptrRef == NULL) return 0;
        return (((*ptrRef)->ptrDer != NULL || (*ptrRef)->ptrIzq != NULL) ? 1 : 0)+contarNodosInternos(&((*ptrRef)->ptrDer)) 
           + contarNodosInternos(&((*ptrRef)->ptrIzq));
    }
    int contarNodosPares(struct Nodo **ptrRef){
        if(*ptrRef == NULL) return 0;
        if((*ptrRef)->dato % 2 != 0) return 0;
        return (1 + contarNodosPares(&((*ptrRef) -> ptrDer)) + contarNodosPares(&((*ptrRef) -> ptrIzq)));
    }
    int sumarNodosPares(struct Nodo **ptrRef){
        if(*ptrRef == NULL) return 0;
        if((*ptrRef)->dato % 2 != 0) return 0;
        return ((*ptrRef)->dato + sumarNodosPares(&((*ptrRef) -> ptrDer)) + sumarNodosPares(&((*ptrRef) -> ptrIzq)));
    }
    void imprimirDescend(struct Nodo **ptrRef){
        struct Nodo *ptrRec;
        ptrRec = *ptrRef;
        if(ptrRec != NULL){
            imprimirDescend(&(ptrRec->ptrDer));
            printf("\n Dato: %d ",ptrRec->dato);
            imprimirDescend(&(ptrRec->ptrIzq));
        }
    }
    int encontrarElemGrande(struct Nodo **ptrRef){
        if(*ptrRef == NULL) return 0;
        if((*ptrRef)->ptrDer == NULL) return (*ptrRef)->dato;
        return encontrarElemGrande(&((*ptrRef)->ptrDer)); 
    }
int encontrarElemMenor(struct Nodo **ptrRef){
    if(*ptrRef == NULL) return 0;
    if((*ptrRef)->ptrIzq == NULL) return (*ptrRef)->dato;
    return encontrarElemMenor(&((*ptrRef)->ptrIzq)); 
}
    void nodosLigadosMay(struct Nodo **ptrRef, int dato) {
        if(*ptrRef != NULL) {
            nodosLigadosMay(&((*ptrRef)->ptrDer), dato);
            if((*ptrRef)->dato > dato) printf("%d ", (*ptrRef)->dato);
            nodosLigadosMay(&((*ptrRef)->ptrIzq), dato); 
        }
    }
    void nodosLigadosMen(struct Nodo **ptrRef, int dato) {
        if(*ptrRef != NULL) {
        nodosLigadosMen(&((*ptrRef)->ptrDer), dato);
        if((*ptrRef)->dato < dato) printf("%d ", (*ptrRef)->dato);
        nodosLigadosMen(&((*ptrRef)->ptrIzq), dato); 
        }
    }   
int sumaNodosLigadosMay(struct Nodo **ptrRef, int dato) {
    if(*ptrRef == NULL) return 0;
    return ((*ptrRef)->dato > dato ? (*ptrRef)->dato : 0) + sumaNodosLigadosMay(&((*ptrRef)->ptrDer), dato) + sumaNodosLigadosMay(&((*ptrRef)->ptrIzq), dato);
}

int sumaNodosLigadosMen(struct Nodo **ptrRef, int dato) {
    if(*ptrRef == NULL) return 0;
    return ((*ptrRef)->dato < dato ? (*ptrRef)->dato : 0) + sumaNodosLigadosMen(&((*ptrRef)->ptrDer), dato) + sumaNodosLigadosMen(&((*ptrRef)->ptrIzq), dato);
}

int contarNodosLigadosMay(struct Nodo **ptrRef, int dato) {
    if(*ptrRef == NULL) return 0;
    return ((*ptrRef)->dato > dato ? 1 : 0) + contarNodosLigadosMay(&((*ptrRef)->ptrDer), dato) 
        + contarNodosLigadosMay(&((*ptrRef)->ptrIzq), dato);
}

int contarNodosLigadosMen(struct Nodo **ptrRef, int dato) {
    if(*ptrRef == NULL) return 0;
    return ((*ptrRef)->dato < dato ? 1 : 0) + contarNodosLigadosMen(&((*ptrRef)->ptrDer), dato) 
        + contarNodosLigadosMen(&((*ptrRef)->ptrIzq), dato);
}
int eliminarNodo(struct Nodo **ptrRef, int dato){
    struct Nodo *nodoBasura;
    if(*ptrRef == NULL) return 1; //arbol vacio
    
    if(dato < (*ptrRef)->dato) return eliminarNodo(&(*ptrRef)->ptrIzq, dato);
    else if(dato > (*ptrRef)->dato) return eliminarNodo(&(*ptrRef)->ptrDer, dato);
    else {
        nodoBasura = *ptrRef;
        if((*ptrRef)->ptrIzq == NULL && (*ptrRef)->ptrDer == NULL) {
            //Nodo hoja
            free(*ptrRef);
            *ptrRef = NULL;
        }
        else if((*ptrRef)->ptrIzq == NULL) {
            //Solo hijo derecho
            *ptrRef = (*ptrRef)->ptrDer;
            free(nodoBasura);
        }
        else if((*ptrRef)->ptrDer == NULL) {
            //Solo hijo izquierdo
            *ptrRef = (*ptrRef)->ptrIzq;
            free(nodoBasura);
        }
        else {
            //Dos hijos
            struct Nodo *ptrAva = (*ptrRef)->ptrDer;
            struct Nodo *ptrAtr = *ptrRef;
            while(ptrAva->ptrIzq != NULL) {
                ptrAtr = ptrAva;
                ptrAva = ptrAva->ptrIzq;
            }
            (*ptrRef) -> dato = ptrAva->dato;
            if(ptrAtr == *ptrRef) {
                ptrAtr -> ptrDer = ptrAva->ptrDer;
            } else {
                ptrAtr -> ptrIzq = ptrAva->ptrDer;
            }
            
            free(ptrAva);
        }
        return 0;
    }
}
void eliminarNodoMenor(struct Nodo **ptrRef){
    if(*ptrRef == NULL) {
        printf("Arbol vacio\n");
        return;
    }
    if((*ptrRef)->ptrIzq != NULL) {
        eliminarNodoMenor(&((*ptrRef)->ptrIzq));
    } else {
        struct Nodo *nodoBasura = *ptrRef;
        printf("Dato eliminado: %d\n", (*ptrRef)->dato);
        *ptrRef = (*ptrRef)->ptrDer;
        
        free(nodoBasura);
    }
}

void eliminarNodoMayor(struct Nodo **ptrRef){
    if(*ptrRef == NULL) {
        printf("\nArbol vacio");
        return;
    }
    if((*ptrRef)->ptrDer != NULL) {
        eliminarNodoMayor(&((*ptrRef)->ptrDer));
    } else {
        struct Nodo *nodoBasura = *ptrRef;
        printf("\nDato eliminado: %d", (*ptrRef)->dato);
        *ptrRef = (*ptrRef)->ptrIzq;
        free(nodoBasura);
    }
}
void eliminarNodoConUnHijo(struct Nodo **ptrRef) {
    struct Nodo *nodoBasura;
    if(*ptrRef == NULL) {
        printf("Arbol vacio\n");
        return;
    }
    if((*ptrRef)->ptrDer != NULL && (*ptrRef)->ptrIzq != NULL)
    

}
int menu(){
    int opc;
    printf("\nMenu");
    printf("\n1.Meter");
    printf("\n2.Imprimir inorder");
    printf("\n3.Imprimir preorder");
    printf("\n4.Imprimir postorder");
    printf("\n5.Imprimir arbol");
    printf("\n6.Sumar Nodos");
    printf("\n7.Contar Nodos");
    printf("\n8.Contar Nodos Hoja");
    printf("\n9.Sumar Nodos Hoja");
    printf("\n10.Contar Nodos Internos");
    printf("\n11.Sumar Nodos Internos");
    printf("\n12.Contar Nodos pares");
    printf("\n13.Sumar Nodos pares");
    printf("\n14.Imprimir descendente");
    printf("\n15.Nodo Mayor");
    printf("\n16.Nodo Menor");
    printf("\n17.Nodos ligados(mayor)");
    printf("\n18.Suma Nodos ligados(mayor)");
    printf("\n19.Numero Nodos ligados(mayor)");
    printf("\n20.Eliminar Nodo");
    printf("\n21.Eliminar Nodo Menor.");
    printf("\n22.Eliminar Nodo Mayor.");
    printf("\n23.Eliminar Nodo con 1 hijo.");
    printf("\n24.Salir");
    printf("\nIngresa opcion:");
    scanf("%d",&opc);
    return opc;
}

int main(){
    struct Nodo *ptrRef1, **ptrRef2;
    int dato;
    ptrRef1 = NULL;
    ptrRef2 = &ptrRef1;

    for(;;){
        switch (menu()){
        case 1:
            printf("\nIngrese un entero:");
            scanf("%d",&dato);
            insertarNodo(ptrRef2,dato);
            break;
        case 2:
            imprimirInorder(ptrRef2);
            break;
        case 3:
            imprPreorder(ptrRef2);
            break;
        case 4:
            imprPostorder(ptrRef2);
            break;
        case 5:
            imprimirArbol(ptrRef1,1);
            break;
        case 6:
            printf("\nTOTAL DE SUMA DE LOS NODOS: %d", sumarNodo(ptrRef2));
            break;
        case 7:
            printf("\nNODOS INGRESADOS: %d", contarNodos(ptrRef2));
            break;
        case 8:
            printf("\nNODOS HOJA: %d", contarNodosHoja(ptrRef2));
            break;
        case 9:
            printf("\nSUMA NODOS HOJA: %d", sumarNodosHoja(ptrRef2));
            break;
        case 10:
            printf("\nNODOS INTERNOS: %d", contarNodosInternos(ptrRef2)); 
            break;
        case 11:
            printf("\nSUMA NODOS INTERNOS: %d", sumarNodosInternos(ptrRef2)); 
            break;
        case 12:
            printf("\nNODOS PARES: %d", contarNodosPares(ptrRef2)); 
            break;
        case 13:
            printf("\nSUMA NODOS PARES: %d", sumarNodosPares(ptrRef2)); 
            break;
        case 14:
            imprimirDescend(ptrRef2);
            break;
        case 15:
            printf("\nNODO MAYOR: %d", encontrarElemGrande(ptrRef2)); 
            break;
        case 16:
            printf("\nNODO MENOR: %d", encontrarElemMenor(ptrRef2));
            break;
        case 17: {
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nNodos mayores a %d: ", dato);
            nodosLigadosMay(ptrRef2, dato);
            printf("\n");
            break;
        }
        case 18: {
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nSUMA NODOS MAYORES A %d: %d", dato, sumaNodosLigadosMay(ptrRef2, dato));
            printf("\n");
            break;
        }
        case 19: {
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nNUMERO NODOS MAYORES A %d: %d", dato, contarNodosLigadosMay(ptrRef2, dato));
            printf("\n");
            break;
        }
        case 20: { //eliminar nodo
            printf("\nIngrese valor a eliminar: ");
            scanf("%d", &dato);
            if(eliminarNodo(ptrRef2,dato) == 1){
                printf("\nDato no existe");
            }else{
                printf("\nDato eliminiado: %d", dato);
            }
            break;
        }
        case 21: { //eliminar nodo  menor
            eliminarNodoMenor(ptrRef2);
            break;
        }
        case 22: {//eliminar nodo mayor
            eliminarNodoMayor(ptrRef2);
            break;
        }
        case 23:
            exit(0);
            break;    
        default:
            printf("\nIngrese opcion correcta");
            break;
        }
    }
    return 0;
}