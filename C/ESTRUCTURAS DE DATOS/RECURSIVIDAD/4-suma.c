//corregir 
#include <stdio.h>

int suma(int a, int b) {
    if (b == 0) return a;
    
    return suma(a + 1, b - 1);
}

int main() {
    printf("Resultado: %d\n", suma(50, 5000));
    return 0;
}