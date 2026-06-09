#include <stdio.h>
#include <stdlib.h>

int mult(int m,int n){
    if(n == 0) return 0; 
    if(m == 0) return 0;
    return m + mult(m,n-1);
}

int main(){
    printf("%d",mult(9,20));
    return 1;
}