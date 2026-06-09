//Cola sin Nodo de cabecera y enlace doble con personas
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

int Vacia(struct Nodo **pI2){
    if(*pI2==NULL)
        return 1;
    else
        return 0;
};

struct Nodo * CrearNodo (struct Persona persona){
    struct Nodo *pN=malloc (sizeof(struct Nodo));
    if(pN==NULL){
        printf("No se reservo el espacio en memoria\n");
        return NULL;
    }
    pN->persona=persona;
    pN->pS=NULL;
    pN->pA=NULL;
    return pN;
};

int Meter (struct Nodo **pI2, struct Nodo **pF2, struct Persona persona){
    struct Nodo *pN=CrearNodo(persona);
    if(Vacia(pI2)){
        *pI2=pN;
        *pF2=pN;
    }
    else{
        (*pF2)->pS=pN;
        pN->pA=*pF2;
        *pF2=pN;
    }
    printf("La persona se ha agregado a la Cola exitosamente. . .\n");
    return 1;
};

int Sacar (struct Nodo **pI2, struct Nodo **pF2){
    struct Nodo *pB=*pI2;
    if(Vacia(pI2)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    *pI2=pB->pS;
    if(*pI2!=NULL)
        (*pI2)->pA=NULL;
    else
        *pF2=NULL;
    printf("La persona ");
    MostrarPersona(pB->persona);
    printf(" ha salido de la Cola exitosamente. . .\n");
    free(pB);
    return 1;
};

int Mostrar (struct Nodo **pI2){
    struct Nodo *pT=*pI2;
    if(Vacia(pI2)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    while (pT!=NULL){
        MostrarPersona(pT->persona);
        printf("<->");
        pT=pT->pS;
    }
    printf("NULL. . .\n");
    return 1;
}

int Reiniciar (struct Nodo **pI2, struct Nodo **pF2){
    struct Nodo *pB;
    while (*pI2!=NULL){
        pB=*pI2;
        *pI2=pB->pS;
        free(pB);
    }
    *pF2=NULL;
    printf("La Cola se ha reiniciado correctamente. . .\n");
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
    struct Nodo *pI1, *pF1, **pI2, **pF2;
    struct Persona persona;
    pI2=&pI1;
    pF2=&pF1;
    pI1=NULL;
    pF1=NULL;

    for(;;){
        switch(menu()){
    case 1:
        persona=LeerPersona();
        Meter(pI2,pF2,persona);
        break;
    case 2:
        Sacar(pI2,pF2);
        break;
    case 3:
        Mostrar(pI2);
        break;
    case 4:
        Reiniciar(pI2,pF2);
        break;
    case 5:
        printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
        Reiniciar(pI2,pF2);
        exit(0);
    default:
        printf("Elija una opcion dentro del menu: ");
        break;
        }
    }
}
