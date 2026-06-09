//Lista con arreglo y persona
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

int Vacia(int n){
    if(n==0)
        return 1;
    else
        return 0;
};

int Llena(int n){
    if(n==MAX)
        return 1;
    else
        return 0;
};

int Meter(struct Persona Lista[], int *n, struct Persona persona){
    int i=*n-1;
    if(Llena(*n)){
        printf("La Lista esta llena. . .\n");
        return 0;
    }
    while((i>=0)&&(Lista[i].clave > persona.clave)){
        Lista[i+1]=Lista[i];
        i--;
    }
    Lista[i+1]=persona;
    *n=*n+1;
    printf("La persona se ha agregado a la Lista exitosamente. . .\n");
    return 1;
};

int Sacar(struct Persona Lista[], int *n, int clave){
    int i=0, j;
    if(Vacia(*n)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    while((i<*n)&&(Lista[i].clave != clave))
        i++;
    if(i==*n){
        printf("La clave no esta dentro de la Lista. . .\n");
        return 0;
    }
    printf("La persona ");
    MostrarPersona(Lista[i]);
    printf(" fue exitosamente eliminada. . .\n");
    for(j=i;j<*n-1;j++)
        Lista[j]=Lista[j+1];
    *n=*n-1;
    return 1;
};

int Mostrar(struct Persona Lista[], int n){
    int i;
    if(Vacia(n)){
        printf("La Lista esta vacia: NULL. . .\n");
        return 0;
    }
    printf("LISTA ACTUAL: ");
    for(i=0;i<n;i++){
        MostrarPersona(Lista[i]);
        printf("->");
    }
    printf("NULL. . .\n");
    return 1;
};

int Reiniciar(int *n){
    *n=0;
    printf("La Lista se ha reiniciado correctamente. . .\n");
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
    struct Persona Lista[MAX], persona;
    int n=0, clave;

    for(;;){
        switch(menu()){
    case 1:
        persona=LeerPersona();
        Meter(Lista,&n,persona);
        break;
    case 2:
        if(Vacia(n)){
            printf("La Lista esta vacia: NULL. . .\n");
            break;
        }
        printf("Ingrese la clave que quiere sacar en la Lista: ");
        scanf("%d",&clave);
        Sacar(Lista,&n,clave);
        break;
    case 3:
        Mostrar(Lista,n);
        break;
    case 4:
        Reiniciar(&n);
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
