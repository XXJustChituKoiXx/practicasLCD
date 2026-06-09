#include <stdio.h>
#include <stdlib.h>

int exponente(int i,int base){
    if(base == 0) return 0;
    if(i == 0) return 1;

    return base * exponente(i-1,base);
}

int main(){
    int base,exp;
    base =2;
    exp = 10;

    printf("%d",exponente(exp,base));
    return 0;
}