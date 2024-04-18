//Eliminar repetidos
//José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generador(int* , int* , int*);
void impresion(int* , int* , int* , int*);

int main(){
    int n;
    int count = 0;
    srand(time(NULL));
    
    printf("ingresa la cantidad de numeros aleatorios que quieres guenerar: ");
    scanf("%i", &n);

    int* array = (int*) calloc(n , sizeof(int));
    int* array2 = (int*) calloc(n , sizeof(int));

    generador(&n , array , array2);
    impresion(&n , array , array2 , &count);

    return 0;
}

void generador(int* n , int* array , int* array2){

    for(int i=0 ; i < *n ; i++){
        array[i] = rand() % (500-200) + 200 + 1;
        array2[i] = array[i];
    }

    for(int i=0 ; i < *n ; i++){
        for(int j=i+1 ; j < *n ; j++){
            if(array2[i] == array2[j]){
                array2[j] = 0;
            }
        }
    }
}

void impresion(int* n , int* array , int* array2 ,int* count){

    printf("La cadena original queda asi:\n");

    for(int i = 0 ; i < *n ; i++){
        printf("%d\t" , array[i]);
    }

    printf("\n");
    printf("\n");

    printf("La cadena sin numeros repetidos queda asi:\n");

    for(int i = 0 ; i < *n ; i++){
        if(array2[i] != 0){
            printf("%d\t" , array2[i]);
            (*count)++;
        }
    }

    printf("\nLa cantidad de veces que se elimino el numero fue de: %i", (*n)-(*count));
}