//Jose Emiliano Carrillo Barrreio
//Arreglos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar(int** , int* );
void imprimir(int** , int* );

int main(){
    srand(time(NULL));
    int n = 0;

    printf("Ingrese el tamanio que desee que tenga el arreglo: ");
    scanf("%i" , &n);

    int** array = (int**) calloc (3 , sizeof(int*));
    for(int i = 0 ; i < 3 ; i++ ){
        array[i] = (int*) calloc (n , sizeof(int));
    }

    generar(array , &n);
    imprimir(array , &n);

    return 0;
}

void generar(int** series, int* n){
    for(int i = 0 ; i < *n ; i++){
        series[0][i] = rand() % (10-1) +1 +1;  
    }
    for(int i = 0 ; i < *n ; i++){
        series[1][(*n)-i-1] = series[0][i];  
    }
    for(int i = 0 ; i < *n ; i++){
        if( (series[0][i] % 4 == 0 ) || (series[0][i] % 7 == 0 ) ){
            series[2][i] = series[0][i];
        }  
    }
}

void imprimir(int** s, int* n){
    printf("La serie original queda:\n");
    for(int i = 0 ; i < *n ; i++){
        printf("%i\t", s[0][i]);
    }
    printf("\n");

    printf("La serie invertida queda:\n");
    for(int i = 0 ; i < *n ; i++){
        printf("%i\t", s[1][i]);
    }
    printf("\n");

    printf("La serie invertida queda:\n");
    for(int i = 0 ; i < *n ; i++){
        if(s[2][i] != 0)
            printf("%i\t", s[2][i]);
    }
    printf("\n");
}