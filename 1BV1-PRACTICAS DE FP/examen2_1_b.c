//Encuentra repetidos.
//José Emiliano Carrillo Barreiro.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar(int* , int* , int* , int*);
void imprimir(int* , int* , int* , int*);

int main(){

    srand(time(NULL));
    int n , x;

    printf("Ingrese la cantidad de elementos aleatorios que quiere generar: ");
    scanf("%i" , &n);

    printf("Ingrese el numero que desee encontrar entre 500 a 900: ");
    scanf("%i" , &x);

    int* array = (int*) calloc(n , sizeof(int*));
    int count = 0;

    generar(array , &n , &x , &count);
    imprimir(array , &n , &x , &count);

    return 0;
}

void generar (int* array , int* n , int* x , int* count){
    
    for(int i = 0 ; i < *n ; i++){
        array[i] = rand() % (900-500) +500 +1;

        if(*x == array[i]){
            (*count) ++;
        }
    }
}

void imprimir (int* array , int* n ,int* x , int* c){

    for(int i = 0 ; i < *n ; i++){
        printf("%i\t" , array[i]);
    }
    printf("\nEl numero de veces que se repitio el valor de '%i' fue de: %i" , *x , *c);
}