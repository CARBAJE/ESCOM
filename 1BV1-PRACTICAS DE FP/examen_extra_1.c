//Número Binario.
//José Emiliano Carrillo Barreiro.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cambiodebase(long* , int* , long);
void imprimir(long* , int* , long);

int main(){

    long* array= (long*) calloc(100 , sizeof(long));
    int basediez = 0;
    long binario=0;

    printf("Ingrese el numero binario que quiere cambiar a base 10: ");
    scanf("%d" , &binario);

    //printf("\n%d\n", binario);
    //printf("%d\n", sizeof(array));

    cambiodebase(array , &basediez , binario);
    imprimir(array , &basediez , binario);

    return 0;
}

void cambiodebase(long* bin , int* dec , long numero){
    long r[100];
    int d = 0;
    int c=0;

    for(int i = 0 ; d <= numero ; i++ ){
        r[i] = numero % 10;
        d = r[i];
          
        //printf("%d ", r[i]);
        numero = numero / 10;
        //printf(" | %d\n", numero);
        c++;
    }

    //printf("%d\n" , c);

    for(int i=0 ; i < c ; i++){
        bin[c-i-1] = r[i]; 
    }

    //printf("%d\n",c);
    for(int i = 0 ; i < c ; i++){
        //printf("%d", bin[c-i-1]);
        *dec = ( bin[c-i-1] * pow (2 , i) ) + (*dec);
        //printf(" [%i] \t" , *dec);
    }
}

void imprimir(long* bin, int* dec , long num){
    printf("\nEl numero binario '%d' en decimal es: %d", num , *dec);
}