#include <stdio.h>
#include <string.h>

void reverse(char *cadena, int inicio, int fin) {
    if (inicio >= fin) {
        return;
    }
    
    char temp = cadena[inicio];
    cadena[inicio] = cadena[fin];
    cadena[fin] = temp;

    reverse(cadena, inicio + 1, fin - 1);
}

int main() {
    char cadena[] = "Hola Mundo";
    int longitud = strlen(cadena);
    
    printf("Original: %s\n", cadena);
    
    reverse(cadena, 0, longitud - 1);
    
    printf("Reves: %s\n", cadena);
    
    return 0;
}