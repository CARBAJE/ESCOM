//Arreglo de 540 elementos (aleatorios entre 100 y 9999)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void impresion(int *pointer , int tam);
void sumimpar(int *pointer , int tam , int sumimpar);
void pormpar(int *pointer , int tam , int sumpar);

int main(){

	int *pointer;
	int num = 540;
    int sum = 0;

	pointer = (int*)malloc(sizeof(int)*num);

	impresion(pointer , num);
    sumimpar(pointer , num , sum);
    pormpar(pointer , num , sum);
	
	return 0;
}

void impresion(int *pointer , int tam){
    for(int n = 0 ; n<tam ; n++){
		pointer[n] = rand()%(9999-100)+100+1;
	
		printf("%i , ", pointer[n]);
	}
    printf("\n\n");
}

void sumimpar(int *pointer , int tam , int sumimpar){
    
    for(int n = 0 ; n<tam ; n++){
		if(pointer[n] %2 != 0){
			sumimpar += pointer[n];
		}
    }
    printf("La suma de imapares fue: %i", sumimpar);
    printf("\n\n");
}

void pormpar(int *pointer , int tam , int sumpar){
    int count = 0;

    for(int n = 0 ; n<tam ; n++){
		if(pointer[n] %2 == 0){
			sumpar += pointer[n];
			count++;
		}
    }

    int prom = sumpar / count;

    printf("\nEl promedio de pares fue: %i", prom);
    printf("\n\n");
}

