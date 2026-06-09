//Pila con arreglo y persona
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

int Vacia(int tope){
    if(tope==-1)
        return 1;
    else
        return 0;
};

int Llena(int tope){
    if(tope==MAX-1)
        return 1;
    else
        return 0;
};

int Meter(struct Persona Pila[], int *tope, struct Persona persona){
    if(Llena(*tope)){
        printf("La Pila esta llena. . .\n");
        return 0;
    }
    *tope=*tope+1;
    Pila[*tope]=persona;
    printf("La persona se ha agregado a la Pila exitosamente. . .\n");
    return 1;
};

int Sacar(struct Persona Pila[], int *tope){
    if(Vacia(*tope)){
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    printf("La persona ");
    MostrarPersona(Pila[*tope]);
    printf(" ha salido de la Pila exitosamente. . .\n");
    *tope=*tope-1;
    return 1;
};

int Mostrar(struct Persona Pila[], int tope){
    int i;
    if(Vacia(tope)){
        printf("La Pila esta vacia: NULL. . .\n");
        return 0;
    }
    printf("PILA ACTUAL: ");
    for(i=tope;i>=0;i--){
        MostrarPersona(Pila[i]);
        printf("->");
    }
    printf("NULL. . .\n");
    return 1;
};

int Reiniciar(int *tope){
    *tope=-1;
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
    struct Persona Pila[MAX], persona;
    int tope=-1;

    for(;;){
        switch(menu()){
    case 1:
        persona=LeerPersona();
        Meter(Pila,&tope,persona);
        break;
    case 2:
        Sacar(Pila,&tope);
        break;
    case 3:
        Mostrar(Pila,tope);
        break;
    case 4:
        Reiniciar(&tope);
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
