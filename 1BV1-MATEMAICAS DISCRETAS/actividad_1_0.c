//Algoritmo de Euclides

#include <stdio.h>
#include <stdlib.h>

void alg_euc(int , int , int*);

int main(){

    int a = 0 , b= 0 , mcd= 0;
    int count = 0;

    while(count < 2){
        if (count == 0){
            printf("Ingrese un valor para la variable 'a': ");
            scanf("%i" , &a);
            count++;
        }
        if (count == 1){
            printf("Ingrese un valor para la variable 'b': ");
            scanf("%i" , &b);
            count++;
        }
        if(abs(a) < abs(b)){
            printf("Vuelva a intentar ingresando un valor para 'a' mas alto que el valor para 'b'.\n");
            count = 0;
        }
    }

    alg_euc(a , b , &mcd);

    printf("El maximo comun divisor de (%i , %i) es: %i." , a , b , abs(mcd) );

    return 0;
}

void alg_euc(int ra , int rb , int *mcd){
    div_t r;

    while(rb != 0){
        r = div(ra , rb);
        ra = ( r.quot * rb ) + r.rem;
        ra = rb;
        rb = r.rem;
    }
    *mcd = ra;
}