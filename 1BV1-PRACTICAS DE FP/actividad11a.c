//Generar un arreglo de tamaño n dado por el usuario. LLenar de números aleatorios el arreglo entre 500 y 5000
//José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n = 0, i = 0;
    srand(time(NULL));

    printf("Ingrese el tamanio que quiere dar al arreglo: ");
    scanf("%i", &i); printf("\n\n");

    int array[i];
    n = i;

    printf("Impresion de datos en onrden de generacion:\n");
    for(i = 0; i < n ; i++){
        array[i] = rand() % (5000-500) + 500 + 1;
        printf("%d ,", array[i]);
    }
    printf("\n\n");

    printf("Impresion de datos en onrden inverso \n");
    for(i = n -1 ; i>=0 ; i--)
        printf("%d ,", array[i]);
    printf("\n\n");

    printf("Impresion de datos de 5 en 5 \n");
    for(i = 0 ; i < n ; i+=5)
        printf("%d ,", array[i]);
    printf("\n\n");

    printf("Impresion de datos multiplos de 7 y 9 simultaneamente \n");
    for(i = 0 ; i < n ; i++){
        if(array[i]%7 == 0 && array[i]%9 == 0){
            printf("%d ,", array[i]);
        }
    }
    printf("\n\n");

    printf("Impresion de datos multiplos de 6 o 11\n");
    for(i = 0 ; i < n ; i++){
        if(array[i]%6 == 0 || array[i]%11 == 0){
            printf("%d ,", array[i]);
        }
    }
    printf("\n\n");

    printf("Imprimir los 10 datos centrales del sistema\n");
        if( n % 2 == 0){
            for(i = (n/2) - 5 ; i < (n/2) + 5 ; i++){
            printf("%d ,", array[i]);
            }
        }
    
    printf("\n\n");

    return 0;
}