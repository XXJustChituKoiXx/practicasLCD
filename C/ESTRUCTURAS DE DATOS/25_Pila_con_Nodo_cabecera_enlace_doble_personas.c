//Pila con Nodo de cabecera y enlace doble con personas
#include <stdio.h>
#include <stdlib.h>

struct Persona{
int clave;
char nombre[50];
int edad;
};

struct Nodo{
struct Persona persona;
struct Nodo *pS, *pA;
};

struct Persona LeerPersona(){
    struct Persona persona;
    printf("Ingrese la clave de la persona: ");
    scanf("%d",&persona.clave);
    printf("Ingrese el nombre de la persona: ");
    scanf("%49s",persona.nombre);
    printf("Ingrese la edad de la persona: ");
    scanf("%d",&persona.edad);
    return persona;
};

void MostrarPersona(struct Persona persona){
    printf("[*|%d|%s|%d|*]",persona.clave,persona.nombre,persona.edad);
};

int Vacia(struct Nodo *pR){
    if(pR->pS==NULL)
        return 1;
    else
        return 0;
};

struct Nodo * CrearNodo (struct Persona persona){
    struct Nodo *pN=malloc (sizeof(struct Nodo));
    if(pN==NULL){
        printf("El espacio en memoria no se ha reservado correctamente\n");
        return NULL;
    }
    pN->persona=persona;
    pN->pS=NULL;
    pN->pA=NULL;
    return pN;
};

int Meter (struct Nodo *pR, struct Persona persona){
    struct Nodo *pN=CrearNodo(persona);
    pN->pS=pR->pS;
    if(pR->pS!=NULL)
        pR->pS->pA=pN;
    pR->pS=pN;
    pN->pA=pR;
    printf("La persona se ha agregado a la Pila exitosamente. . .\n");
    return 1;
};

int Sacar (struct Nodo *pR){
    struct Nodo *pB=pR->pS;
    if(Vacia(pR)){
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    pR->pS=pB->pS;
    if(pR->pS!=NULL)
        pR->pS->pA=pR;
    printf("La persona ");
    MostrarPersona(pB->persona);
    printf(" ha salido de la Pila exitosamente. . .\n");
    free(pB);
    return 1;
};

int Mostrar (struct Nodo *pR){
    struct Nodo *pT=pR->pS;
    if(Vacia(pR)){
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    printf("PILA ACTUAL: ");
    while(pT!=NULL){
        MostrarPersona(pT->persona);
        printf("<->");
        pT=pT->pS;
    }
    printf("NULL. . .\n");
    return 1;
};

int Reiniciar (struct Nodo *pR){
    struct Nodo *pB;
    while(pR->pS!=NULL){
        pB=pR->pS;
        pR->pS=pB->pS;
        free(pB);
    }
    printf("La Pila se ha reiniciado correctamente. . .\n");
    return 1;
};

int menu(){
    int op;
    printf("\n---MENU---\n");
    printf("1 para Meter\n");
    printf("2 para Sacar\n");
    printf("3 para Mostrar\n");
    printf("4 para Reiniciar\n");
    printf("5 para Salir\n");
    printf("Seleccione una opcion dentro del menu: ");
    scanf("%d",&op);
    return op;
}

int main(){
    struct Persona persona={-1000,"CABECERA",0};
    struct Nodo *pR=CrearNodo(persona);

    for(;;){
        switch(menu()){
    case 1:
        persona=LeerPersona();
        Meter(pR,persona);
        break;
    case 2:
        Sacar(pR);
        break;
    case 3:
        Mostrar(pR);
        break;
    case 4:
        Reiniciar(pR);
        break;
    case 5:
        printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
        Reiniciar(pR);
        free(pR);
        exit(0);
    default:
        printf("Elija una opcion dentro del menu: ");
        break;
        }
    }
}
