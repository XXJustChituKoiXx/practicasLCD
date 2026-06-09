/*
Lista enlazada con nodo cabeza (HEAD).

En esta estructura existe un nodo especial llamado HEAD.
Este nodo siempre es el primero y nunca se elimina.

Los nodos reales se insertan después del HEAD.

Cada nodo contiene:
- un dato
- un puntero al siguiente nodo
*/

#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int dato;              // valor guardado en el nodo
    struct Nodo *ptrSig;   // dirección del siguiente nodo
};

int main(){

    /*
    ptrRef -> apunta al nodo HEAD (inicio fijo de la lista)

    ptrNuevo -> se usa para crear nuevos nodos con malloc

    ptrBasura -> guarda temporalmente el nodo que se eliminará

    ptrRec -> se usa para recorrer la lista nodo por nodo
    */
    struct Nodo *ptrRef,*ptrNuevo, *ptrBasura,*ptrRec;    

    // ---------- CREAR NODO HEAD ----------
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo)); 
    ptrNuevo->dato = -1000;    // valor solo para identificar el nodo HEAD
    ptrNuevo->ptrSig = NULL;   // todavía no hay nodos después

    // ptrRef será la referencia permanente al HEAD
    ptrRef = ptrNuevo;  


    // ---------- PRIMER NODO  ----------
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo->dato = 5;
    ptrNuevo->ptrSig = NULL;   // será el último nodo por ahora

    // el HEAD apunta al primer nodo real
    ptrRef->ptrSig = ptrNuevo; 
    

    // ---------- SEGUNDO NODO ----------
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo->dato = 10;

    // insertar el nodo después del HEAD
    ptrNuevo->ptrSig = ptrRef->ptrSig;
    ptrRef->ptrSig = ptrNuevo;


    // ---------- TERCER NODO ----------
    ptrNuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    ptrNuevo->dato = 15;

    ptrNuevo->ptrSig = ptrRef->ptrSig;
    ptrRef->ptrSig = ptrNuevo;


    // ---------- RECORRER LISTA ----------
    // debería imprimir: 15, 10, 5

    // usar un puntero auxiliar para no mover el HEAD
    ptrRec = ptrRef;

    while (ptrRec != NULL){
        printf("Dato: %d  Direccion: %p\n", ptrRec->dato, ptrRec);
        ptrRec = ptrRec->ptrSig;
    } 


    // ---------- ELIMINAR NODO CON DATO 15 ----------

    // guardar el nodo que se eliminará
    ptrBasura = ptrRef->ptrSig;

    // enlazar el HEAD con el siguiente nodo
    ptrRef->ptrSig = ptrBasura->ptrSig;

    // liberar memoria del nodo eliminado
    free(ptrBasura);


    // ---------- RECORRER DE NUEVO ----------
    // debería imprimir: 10, 5

    ptrRec = ptrRef;

    while (ptrRec != NULL){
        printf("Dato: %d  Direccion: %p\n", ptrRec->dato, ptrRec);
        ptrRec = ptrRec->ptrSig;
    } 

    return 0;
}