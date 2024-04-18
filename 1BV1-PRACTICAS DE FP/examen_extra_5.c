//José Emiliano Carrillo BArreiro
//Serie
#include <stdio.h>

void imprimir(int* , int* );

int main(){
    int m= 0 , n = 0;
    
    printf("ingrese un numero menor a 50:");
    scanf("%i" , &m);
    printf("ingrese otro numero menor a 50:");
    scanf("%i" , &n);

    imprimir(&m ,&n);
    return 0;
}

void imprimir(int*m , int*n ){
    if(*m > *n){
        for(*m , *n ; *m > *n ; (*n)+=5 , (*m)-=2){
            printf("%i\t", *m);
            printf("%i\t", *n);
        }
    }
    if(*m < *n){
        for(*m , *n ; *m < *n ; (*m)+=5 , (*n)-=2){
            printf("%i\t", *m);
            printf("%i\t", *n);
        }
    }
    if(*m == *n)
        printf("Los valores son iguales, ergo, no se puede realizar la serie");
}