//Programa que define si la ecuacion "ax + by = c" tiene solucion. Teorema de combinacion lineal
//José Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>

void alg_euc(int , int , int*);
void sol_ec(int , int , int , int , int* , int*);

int main(){

    int a = 0 , b= 0 , c , d;
    int x0= 0 , y0 = 0;
    int count = 0;

    while(count < 3){
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
        if(a > b){
            printf("Ingrese un valor para la variable 'c': ");
            scanf("%i" , &c);
            if (c < 0){
                c = abs(c);
            }
            count++;
        }
    }

    alg_euc(a , b , &d);

    if( ( (a % d == 0) && (b % d == 0) ) && c % d == 0){
        sol_ec(a , b , c , d , &x0 , &y0);
        printf("La ecuacion '%ix + %iy = %i'tiene solucion en los numeros enteros cuando:\n" , a , b , c);
        printf("X = %i\nY = %i", x0 , y0);
    }
    else
        printf("La ecuacion '%ix + %iy = %i' no tiene solucion en los numeros enteros" , a , b , c);

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

void sol_ec(int a, int b, int c, int mcd, int*x, int*y){
    int q = c / mcd;
    int s = 1 , t = 1 , r = a-b;
    while (r != mcd){
        if(abs(a*s) < abs(b*t))
            s++;
        t--;
        r = abs(a*s) - abs(b*t);
    }
    printf("el valor de s=%i , de t=%i , a=%i , d=%i , b=%i , r=%i , q=%i\n" , s , t , a , mcd , b, r , q);
    *x = (c*s) / mcd;
    *y = (c*t)/ mcd;
}