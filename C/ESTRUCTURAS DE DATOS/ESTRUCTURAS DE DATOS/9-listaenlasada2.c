/*
Lista enlazada simple.

Una lista enlazada está formada por nodos conectados entre sí mediante punteros.
Cada nodo tiene:
- un dato
- un puntero al siguiente nodo.

Ventajas:
- se pueden insertar o eliminar nodos sin mover otros en memoria.

En esta versión NO existe nodo cabeza fijo.
El puntero "ptrReferencia" solo guarda la dirección del primer nodo de la lista
(el nodo más reciente que se insertó al inicio).
*/

#include<stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;              // valor almacenado en el nodo
    struct nodo *ptrsig;   // dirección del siguiente nodo
};

int main(){

    /*
    ptrReferencia -> apunta al primer nodo de la lista.

    ptrNuevo -> se usa para crear nuevos nodos con malloc.

    ptrRecorrer -> se usa para recorrer la lista nodo por nodo.

    ptrBasura -> guarda temporalmente un nodo que se eliminará
    para no perder su dirección antes de liberar memoria.
    */
    struct nodo *ptrReferencia ,*ptrNuevo, *ptrRecorrer, *ptrBasura;

    // La lista inicia vacía (no apunta a ningún nodo)
    ptrReferencia = NULL;
    
    // ---------- PRIMER NODO ----------
    ptrNuevo = (struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->dato = 5;
    ptrNuevo->ptrsig = NULL;   // no hay nodo después

    // la referencia ahora apunta al primer nodo
    ptrReferencia = ptrNuevo;
    
    // ---------- SEGUNDO NODO ----------
    ptrNuevo = (struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->dato = 10;

    // el nuevo nodo apunta al nodo que antes era el primero
    ptrNuevo->ptrsig = ptrReferencia;

    // la referencia ahora apunta al nuevo nodo
    ptrReferencia = ptrNuevo;
    
    // ---------- TERCER NODO ----------
    ptrNuevo = (struct nodo*)malloc(sizeof(struct nodo));
    ptrNuevo->dato = 15;

    ptrNuevo->ptrsig = ptrReferencia;
    ptrReferencia = ptrNuevo;
    

    // ---------- RECORRER LA LISTA ----------
    ptrRecorrer = ptrReferencia;   // empezar desde el primer nodo

    while(ptrRecorrer != NULL){
        printf("%d ", ptrRecorrer->dato);
        ptrRecorrer = ptrRecorrer->ptrsig;
    }

    // ---------- ELIMINAR PRIMER NODO ----------
    ptrBasura = ptrReferencia;              // guardar nodo a eliminar
    ptrReferencia = ptrBasura->ptrsig;      // la referencia pasa al siguiente nodo

    printf("\nEl dato eliminado fue %d", ptrBasura->dato);

    free(ptrBasura);   // liberar memoria del nodo eliminado


    /*
    Diferencia con una lista con nodo cabeza:

    Aquí:
    - ptrReferencia siempre apunta al primer nodo real de la lista.
    - cada nuevo nodo se inserta al inicio.

    Con nodo cabeza:
    - existe un nodo fijo que nunca se elimina.
    - los nodos nuevos se insertan después de ese nodo.
    */

    return 0;
}