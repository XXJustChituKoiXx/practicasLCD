//Cola con arreglo y persona
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct Persona{
int clave;
char nombre[50];
int edad;
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

int Vacia(int cont){
    if(cont==0)
        return 1;
    else
        return 0;
};

int Llena(int cont){
    if(cont==MAX)
        return 1;
    else
        return 0;
};

int Meter(struct Persona Cola[], int *pI, int *pF, int *cont, struct Persona persona){
    if(Llena(*cont)){
        printf("La Cola esta llena. . .\n");
        return 0;
    }
    if(Vacia(*cont)){
        *pI=0;
        *pF=0;
    }
    else
        *pF=(*pF+1)%MAX;
    Cola[*pF]=persona;
    *cont=*cont+1;
    printf("La persona se ha agregado a la Cola exitosamente. . .\n");
    return 1;
};

int Sacar(struct Persona Cola[], int *pI, int *pF, int *cont){
    if(Vacia(*cont)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("La persona ");
    MostrarPersona(Cola[*pI]);
    printf(" ha salido de la Cola exitosamente. . .\n");
    if(*cont==1){
        *pI=-1;
        *pF=-1;
    }
    else
        *pI=(*pI+1)%MAX;
    *cont=*cont-1;
    return 1;
};

int Mostrar(struct Persona Cola[], int pI, int cont){
    int i, pos;
    if(Vacia(cont)){
        printf("La Cola esta vacia: NULL. . .\n");
        return 0;
    }
    printf("COLA ACTUAL: ");
    for(i=0;i<cont;i++){
        pos=(pI+i)%MAX;
        MostrarPersona(Cola[pos]);
        printf("->");
    }
    printf("NULL. . .\n");
    return 1;
};

int Reiniciar(int *pI, int *pF, int *cont){
    *pI=-1;
    *pF=-1;
    *cont=0;
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
    struct Persona Cola[MAX], persona;
    int pI=-1, pF=-1, cont=0;

    for(;;){
        switch(menu()){
    case 1:
        persona=LeerPersona();
        Meter(Cola,&pI,&pF,&cont,persona);
        break;
    case 2:
        Sacar(Cola,&pI,&pF,&cont);
        break;
    case 3:
        Mostrar(Cola,pI,cont);
        break;
    case 4:
        Reiniciar(&pI,&pF,&cont);
        break;
    case 5:
        printf("*-*-*SALIENDO DEL SISTEMA*-*-*");
        exit(0);
    default:
        printf("Elija una opcion dentro del menu: ");
        break;
        }
    }
}
