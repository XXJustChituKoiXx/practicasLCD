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
    if((*ptrRef)->ptrDer != NULL || (*ptrRef)->ptrIzq != NULL) return (*ptrRef)->dato + sumarNodosInternos(&((*ptrRef)->ptrDer)) + sumarNodosInternos(&((*ptrRef)->ptrIzq));    
    return sumarNodosInternos(&((*ptrRef)->ptrDer)) + sumarNodosInternos(&((*ptrRef)->ptrIzq));
}
int contarNodosInternos(struct Nodo **ptrRef) {
    if(*ptrRef == NULL) return 0;
    return (((*ptrRef)->ptrDer != NULL || (*ptrRef)->ptrIzq != NULL) ? 1 : 0)+contarNodosInternos(&((*ptrRef)->ptrDer)) 
        + contarNodosInternos(&((*ptrRef)->ptrIzq));
}
int contarNodosPares(struct Nodo **ptrRef){
    if(*ptrRef == NULL) return 0;
    if((*ptrRef)->dato % 2 == 0)  return (1 + contarNodosPares(&((*ptrRef) -> ptrDer)) + contarNodosPares(&((*ptrRef) -> ptrIzq)));
    return contarNodosPares(&((*ptrRef)->ptrIzq)) + contarNodosPares(&((*ptrRef)->ptrDer));
}
int sumarNodosPares(struct Nodo **ptrRef){
    if(*ptrRef == NULL) return 0;
    if((*ptrRef)->dato % 2 == 0) return ((*ptrRef)->dato + sumarNodosPares(&((*ptrRef) -> ptrDer)) + sumarNodosPares(&((*ptrRef) -> ptrIzq)));
    return (sumarNodosPares(&((*ptrRef) -> ptrDer)) + sumarNodosPares(&((*ptrRef) -> ptrIzq)));
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
int eliminarNodosConUnHijo(struct Nodo **ptrRef) {
    if(*ptrRef == NULL) return 1;
    if((*ptrRef)->ptrDer == NULL && (*ptrRef)->ptrIzq != NULL){
        struct Nodo *ptrAva = (*ptrRef)->ptrIzq;
        struct Nodo *ptrAtr = *ptrRef;
        while(ptrAva->ptrIzq != NULL) {
            ptrAtr = ptrAva;
            ptrAva = ptrAva->ptrIzq;
        }
        (*ptrRef) -> dato = ptrAva->dato;
        if(ptrAtr == *ptrRef) {
            ptrAtr -> ptrDer = ptrAva->ptrDer;
        }else{
            ptrAtr -> ptrIzq = ptrAva->ptrDer;
        }    
        free(ptrAva);
    }
    if((*ptrRef)->ptrDer != NULL && (*ptrRef)->ptrIzq == NULL){
        struct Nodo *ptrAva = (*ptrRef)->ptrDer;
        struct Nodo *ptrAtr = *ptrRef;
        while(ptrAva->ptrDer != NULL) {
            ptrAtr = ptrAva;
            ptrAva = ptrAva->ptrDer;
        }
        (*ptrRef) -> dato = ptrAva->dato;
        if(ptrAtr == *ptrRef) {
            ptrAtr -> ptrDer = ptrAva->ptrDer;
        }else{
            ptrAtr -> ptrIzq = ptrAva->ptrDer;
        }    
        free(ptrAva);
    }
    eliminarNodosConUnHijo(&(*ptrRef) -> ptrDer);
    eliminarNodosConUnHijo(&(*ptrRef) -> ptrIzq);
    return 0; 
}
void eliminarNodosHoja(struct Nodo **ptrRef){
    if(*ptrRef == NULL){
        printf("Arbol vacio\n");
        return;
    }
    if((*ptrRef)->ptrDer == NULL && (*ptrRef)->ptrIzq == NULL){
        struct Nodo *ptrBasura;
        ptrBasura = *ptrRef; 
        *ptrRef = NULL;
        free(ptrBasura);
        return;
    }
    eliminarNodosHoja(&(*ptrRef) -> ptrDer);
    eliminarNodosHoja(&(*ptrRef) -> ptrIzq);
    return;
}
void eliminarNodo2Hijos(struct Nodo **ptrRef){
    if(*ptrRef == NULL)  return;
    eliminarNodo2Hijos(&(*ptrRef) -> ptrDer);
    eliminarNodo2Hijos(&(*ptrRef) -> ptrIzq);    
    if((*ptrRef)->ptrDer != NULL && (*ptrRef)->ptrIzq != NULL){
        struct Nodo *ptrAva = (*ptrRef)->ptrDer;
        struct Nodo *ptrAtr = *ptrRef;
        while(ptrAva->ptrIzq != NULL){
            ptrAtr = ptrAva;
            ptrAva = ptrAva->ptrIzq;
        }
        (*ptrRef) -> dato = ptrAva->dato;
        if(ptrAtr == *ptrRef){
            ptrAtr -> ptrDer = ptrAva->ptrDer;
        }else{
            ptrAtr -> ptrIzq = ptrAva->ptrDer;
        }
        free(ptrAva);
    }
}

int buscarNodo(struct Nodo **ptrRef, int dato) {
    if (*ptrRef == NULL) return 0;
    if ((*ptrRef)->dato == dato) return 1;
    if (dato < (*ptrRef)->dato)
        return buscarNodo(&((*ptrRef)->ptrIzq), dato);
    else
        return buscarNodo(&((*ptrRef)->ptrDer), dato);
}

int contarNodosUnHijo(struct Nodo **ptrRef) {
    if (*ptrRef == NULL) return 0;
    int tieneUnHijo = ((*ptrRef)->ptrIzq != NULL) ^ ((*ptrRef)->ptrDer != NULL);
    return tieneUnHijo + contarNodosUnHijo(&((*ptrRef)->ptrIzq)) + contarNodosUnHijo(&((*ptrRef)->ptrDer));
}



int menu(){
    int opc;
    printf("\n=== MENU PRINCIPAL ===");
    printf("\n1. Insertar nodo (Meter)");
    printf("\n2. Imprimir arbol completo");
    printf("\n3. Recorrido Inorder");
    printf("\n4. Recorrido Preorder");
    printf("\n5. Recorrido Postorder");
    printf("\n6. Imprimir descendente");
    printf("\n7. Contar nodos");
    printf("\n8. Contar nodos hoja");
    printf("\n9. Contar nodos internos");
    printf("\n10. Contar nodos pares");
    printf("\n11. Contar nodos con un hijo");
    printf("\n12. Contar nodos ligados al mayor");
    printf("\n13. Sumar nodos (todo el arbol)");
    printf("\n14. Sumar nodos hoja");
    printf("\n15. Sumar nodos internos");
    printf("\n16. Sumar nodos pares");
    printf("\n17. Sumar nodos ligados al mayor");
    printf("\n18. Buscar elemento (pertenencia)");
    printf("\n19. Obtener elemento mayor");
    printf("\n20. Obtener elemento menor");
    printf("\n21. Imprimir nodos mayores a un numero");
    printf("\n22. Sumar nodos mayores a un numero");
    printf("\n23. Eliminar nodo especifico");
    printf("\n24. Eliminar nodo menor");
    printf("\n25. Eliminar nodo mayor");
    printf("\n26. Eliminar nodos hoja");
    printf("\n27. Eliminar nodos con un hijo");
    printf("\n28. Eliminar nodos con dos hijos");
    printf("\n29. Salir");
    printf("\nIngrese opcion: ");
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
        case 1:  // Insertar nodo
            printf("\nIngrese un entero: ");
            scanf("%d",&dato);
            insertarNodo(ptrRef2,dato);
            break;
            
        case 2:  // Imprimir arbol completo
            imprimirArbol(ptrRef1,1);
            break;
            
        case 3:  // Inorder
            imprimirInorder(ptrRef2);
            break;
            
        case 4:  // Preorder
            imprPreorder(ptrRef2);
            break;
            
        case 5:  // Postorder
            imprPostorder(ptrRef2);
            break;
            
        case 6:  // Imprimir descendente
            imprimirDescend(ptrRef2);
            break;
            
        case 7:  // Contar nodos
            printf("\nNODOS TOTALES: %d", contarNodos(ptrRef2));
            break;
            
        case 8:  // Contar nodos hoja
            printf("\nNODOS HOJA: %d", contarNodosHoja(ptrRef2));
            break;
            
        case 9:  // Contar nodos internos
            printf("\nNODOS INTERNOS: %d", contarNodosInternos(ptrRef2));
            break;
            
        case 10:  // Contar nodos pares
            printf("\nNODOS PARES: %d", contarNodosPares(ptrRef2));
            break;
            
        case 11:  // Contar nodos con un hijo
            printf("\nNODOS CON UN SOLO HIJO: %d", contarNodosUnHijo(ptrRef2));
            break;
            
        case 12:  // Contar nodos ligados al mayor
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nNODOS MAYORES A %d: %d", dato, contarNodosLigadosMay(ptrRef2, dato));
            break;
            
        case 13:  // Sumar nodos (todo el arbol)
            printf("\nSUMA TOTAL DE NODOS: %d", sumarNodo(ptrRef2));
            break;
            
        case 14:  // Sumar nodos hoja
            printf("\nSUMA NODOS HOJA: %d", sumarNodosHoja(ptrRef2));
            break;
            
        case 15:  // Sumar nodos internos
            printf("\nSUMA NODOS INTERNOS: %d", sumarNodosInternos(ptrRef2));
            break;
            
        case 16:  // Sumar nodos pares
            printf("\nSUMA NODOS PARES: %d", sumarNodosPares(ptrRef2));
            break;
            
        case 17:  // Sumar nodos ligados al mayor
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nSUMA NODOS MAYORES A %d: %d", dato, sumaNodosLigadosMay(ptrRef2, dato));
            break;
            
        case 18:  // Buscar elemento (pertenencia)
            printf("\nIngrese valor a buscar: ");
            scanf("%d", &dato);
            if(buscarNodo(ptrRef2, dato))
                printf("\nEl elemento %d SI pertenece al arbol\n", dato);
            else
                printf("\nEl elemento %d NO pertenece al arbol\n", dato);
            break;
            
        case 19:  // Obtener elemento mayor
            printf("\nELEMENTO MAYOR: %d", encontrarElemGrande(ptrRef2));
            break;
            
        case 20:  // Obtener elemento menor
            printf("\nELEMENTO MENOR: %d", encontrarElemMenor(ptrRef2));
            break;
            
        case 21:  // Imprimir nodos mayores a un numero
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nNodos mayores a %d: ", dato);
            nodosLigadosMay(ptrRef2, dato);
            printf("\n");
            break;
            
        case 22:  // Sumar nodos mayores a un numero
            printf("\nIngrese valor de referencia: ");
            scanf("%d", &dato);
            printf("\nSUMA NODOS MAYORES A %d: %d", dato, sumaNodosLigadosMay(ptrRef2, dato));
            printf("\n");
            break;
            
        case 23:  // Eliminar nodo especifico
            printf("\nIngrese valor a eliminar: ");
            scanf("%d", &dato);
            if(eliminarNodo(ptrRef2, dato) == 1)
                printf("\nDato no existe");
            else
                printf("\nDato eliminado: %d", dato);
            break;
            
        case 24:  // Eliminar nodo menor
            eliminarNodoMenor(ptrRef2);
            break;
            
        case 25:  // Eliminar nodo mayor
            eliminarNodoMayor(ptrRef2);
            break;
            
        case 26:  // Eliminar nodos hoja
            eliminarNodosHoja(ptrRef2);
            printf("\nNodos hoja eliminados");
            break;
            
        case 27:  // Eliminar nodos con un hijo
            eliminarNodosConUnHijo(ptrRef2);
            printf("\nNodos con un hijo eliminados");
            break;
            
        case 28:  // Eliminar nodos con dos hijos
            eliminarNodo2Hijos(ptrRef2);
            printf("\nNodos con dos hijos eliminados");
            break;
            
        case 29:  // Salir
            printf("\nSaliendo del programa...\n");
            exit(0);
            break;
            
        default:
            printf("\nOpcion no valida. Intente nuevamente");
            break;
        }
    }
    return 0;
}