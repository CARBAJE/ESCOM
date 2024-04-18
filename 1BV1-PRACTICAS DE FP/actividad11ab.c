//Generar un arreglo de tamaño n dado por el usuario. LLenar de números aleatorios el arreglo entre 500 y 5000
//José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n = 0, i = 0;
    srand(time(NULL));

    printf("Ingrese el tamanio que quiere dar al arreglo: ");
    scanf("%i", &n); printf("\n\n");

    int array[n];

    printf("Impresion de datos en onrden de generacion:\n");
    for(n ; n>=0 ; n--){
        array[n] = rand() % (5000 - 500) +501;
        printf("%d ,", array[n]);
    }

    int array1[i];

    printf("Impresion de datos en onrden de generacion:\n");
    for(i = 0; i<=n ; i++){
        array1[i] = rand() % (5000 - 500) +501;
        printf("%d ,", array1[i]);
    }
    
    return 0;
    }