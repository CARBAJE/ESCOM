//Genera un arreglo con n datos aleatorios (10 a 40).
//José Emiliano carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n = 0 , i = 0 , count20 = 0 , sum= 0 , prom = 0, max = 0;
    srand(time(NULL));

    printf("Ingresa el tamanio que quieres que tenga tu arreglo: ");
    scanf("%i", &n);
    int array[n];

    i = n;

    printf("\nLos datos almacenados en cada celda del arreglo son:\n");
    for(n=0 ; n < i ; n++){
        array[n] = rand() % (40-10) + 10 + 1;
        printf("%i, ", array[n]);

        sum = array[n] + sum;
        if(array[n] == 20){
            count20++;
        }
        if(array[n] > max){
            max = array[n];
        }
    }
    printf("\nEl dato de mayor cantidad registrado fue: %i\n", max);
    printf("La frecuencia del numero 20 fue de. %i\n", count20);
    printf("El promedio de los datos fue: %i", sum/n);


    return 0;
}