//Lista con Nodo de cabecera y enlace doble con personas
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

struct Nodo * CrearNodo (struct Persona persona){
    struct Nodo *pN=malloc (sizeof(struct Nodo));
    if(pN==NULL){
        printf("El espacio en memoria no se ha reservado\n");
        return NULL;
    }
    pN->persona=persona;
    pN->pS=NULL;
    pN->pA=NULL;
    return pN;
};

int Vacia (struct Nodo *pR){
    if(pR->pS==NULL)
        return 1;
    else
        return 0;
};

int Meter (struct Nodo *pR, struct Persona persona){
    struct Nodo *pN=CrearNodo(persona), *pT=pR;
    while((pT->pS!=NULL)&&(pT->pS->persona.clave < persona.clave))
        pT=pT->pS;
    pN->pS=pT->pS;
    pN->pA=pT;
    if(pT->pS!=NULL)
        pT->pS->pA=pN;
    pT->pS=pN;
    printf("La persona se ha agregado a la Lista exitosamente. . .\n");
    return 1;
};

int Sacar (struct Nodo *pR, int clave){
    struct Nodo *pRet=pR, *pAv=pR->pS;
    if(Vacia(pR)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    while((pAv!=NULL)&&(pAv->persona.clave != clave)){
        pRet=pRet->pS;
        pAv=pAv->pS;
    }
    if(pAv==NULL){
        printf("La clave no esta dentro de la Lista. . .\n");
        return 0;
    }
    pRet->pS=pAv->pS;
    if(pAv->pS!=NULL)
        pRet->pS->pA=pRet;
    printf("La persona ");
    MostrarPersona(pAv->persona);
    printf(" fue exitosamente eliminada. . .\n");
    free(pAv);
    return 1;
};

int Mostrar (struct Nodo *pR){
    struct Nodo *pT=pR->pS;
    if(Vacia(pR)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    printf("LISTA ACTUAL: ");
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
    if(Vacia(pR)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    while(pR->pS!=NULL){
        pB=pR->pS;
        pR->pS=pB->pS;
        free(pB);
    }
    printf("La Lista se ha reiniciado correctamente. . .\n");
    return 1;
}

int menu (){
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

int main (){
    struct Persona persona={-1000,"CABECERA",0};
    struct Nodo *pR=CrearNodo(persona);
    int clave;

    for(;;){
        switch(menu()){
    case 1:
        persona=LeerPersona();
        Meter(pR,persona);
        break;
    case 2:
        if(Vacia(pR)){
            printf("La Lista esta vacia: NULL. . .\n");
            break;
        }
        printf("Ingrese la clave que quiere sacar en la Lista: ");
        scanf("%d",&clave);
        Sacar(pR,clave);
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
        printf("Elije una opcion que este dentro del menu\n");
        break;
        }
    }
}
