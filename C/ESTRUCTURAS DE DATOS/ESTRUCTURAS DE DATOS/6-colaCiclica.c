/*
cola cicular
*/
#include <stdio.h>
#define TAM 5
struct  Cola{
    int arreglo[TAM];
    int *ptrM;
    int *ptrS;
};

//si el puntero de meter ya esta en la ultima posicion se regresa al primer elemento del arreglo.
int meterCola(struct Cola *ptrp, int dato){
    *ptrp -> ptrM = dato;
    if(ptrp -> ptrM == &ptrp ->arreglo[TAM]){
        ptrp -> ptrM = ptrp -> arreglo;
    }else{
        (ptrp -> ptrM)++;
    }
    return 0;
}
//guarda el dato y depues recorre el puntero al siguiente lugar
int sacarCola(struct Cola *ptrp){
    int dato;
    dato = * ptrp -> ptrS;
    (ptrp -> ptrS)++;
    return dato;
}

//si el siguiente elemento del puntero meter es igual al de salir la cola esta llena
int colaLlena(struct Cola *ptrp){
    int *sig;

    sig = ptrp->ptrM + 1;

    if(sig == &ptrp->arreglo[TAM])
        sig = ptrp->arreglo;

    if(sig == ptrp->ptrS)
        return 1;

    return 0;
}
//si  el puntero de sacar es el mismo de meter la cola esta vacia.
int colaVacia(struct Cola *ptrp){
    if(ptrp -> ptrS == ptrp ->ptrM)
        return 1;
    return 0;
}
//crea un puntero auxiliar para recorrer el arreglo hasta que llegue al puntero meter
int imprimir(struct Cola *ptrp){
    int *aux;

    aux = ptrp->ptrS;

    while(aux != ptrp->ptrM){
        printf("\n%d", *aux);
        aux++;
        if(aux == &ptrp->arreglo[TAM])
            aux = ptrp->arreglo;
    }
    return 0;
}
int menu(){
    int opc;
    printf("Menu:\n");
    printf("1.Meter\n");
    printf("2.Sacar\n");
    printf("3.Imprimir\n");
    printf("4.Salir\n");
    printf("Ingrese un dato:");
    scanf("%d",&opc);
    return opc;
}

int main(){
    struct Cola cola,*miptrP;
    int miDato;

    //inicializar punteros al inicio del arreglo
    miptrP = &cola;
    miptrP -> ptrM = miptrP -> arreglo;
    miptrP -> ptrS = miptrP -> arreglo;

      for(;;){

        switch (menu())
        {
        case 1:
            if(estaColaLlena(miptrP))
                printf("La cola esta llena");
            else{
                printf("\n\nMETER DATOS");
                scanf("%d", &miDato);
                meterCola(miptrP, miDato);
            }
            break;
        case 2:
            if(estaColaVacia(miptrP))
                printf("\n\nLa cola esta vacia ");
            else{
                printf("\n\nSACAR DATOS");
                printf("\n\nEl dato sacado es: %d",sacarCola(miptrP));
            }
            break;
        case 3:
            imprimirCola(miptrP);
            break;
        case 4:
            exit(0);
            break;

        default:
            printf("\n\nElija una opción valida.");
        }
    }
    return 0;  
}