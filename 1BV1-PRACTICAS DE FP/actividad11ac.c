//Generar un arreglo de tamaño n dado por el usuario. LLenar de números aleatorios el arreglo entre 500 y 5000
//José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n = 0, x = 0;
    srand(time(NULL));

    printf("Ingrese el tamanio que quiere dar al arreglo: ");
    scanf("%i", &n);

    x =n;
    int array[x];
    printf("\n\n");

    printf("Impresion de datos en onrden de generacion:\n");
    for(x = 0 ; x < n ; x++){
        array[x] = rand() % (5000-500) + 500 + 1;
        printf("%d ,", array[x]);
    }
    printf("\n\n");



    return 0;
}