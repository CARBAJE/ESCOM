//invertir los numeros de una cantidad dada por el usuario
//José Emiliano Carrillo Barreiro

#include <stdio.h>

void invertir(int , int);

int main(){
    int n , inv = 0;

    printf("Ingrese el numero que quiere invertir: ");
    scanf("%d" , &n);

    invertir(n , inv);
    return 0;
}

void invertir(int n , int inv){
    if( n == 0)
        printf("%d" , inv);
    if( n != 0 ){
        int r = n % 10;
        inv = (inv * 10) + r;
        invertir( n / 10 , inv);
    }
}