//Arreglo de 540 elementos (aleatorios entre 100 y 9999)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fun1(int *pointer , int tam);

int main(){

	int *pointer;
	int num=540;
	pointer = (int*)malloc(sizeof(int)*num);
	fun1(pointer , num);
	
	return 0;
}

void fun1(int *pointer , int tam){
	int n=0;
	int sum = 0 , sum2 = 0;
	int prom = 0;
	int cant = 0;
	
	srand(time(NULL));
	
	pointer[n];
	for(n ; n<tam ; n++){
		pointer[n] = rand()%(9999-100)+100+1;
	
		printf("%i , ", pointer[n]);
	
		if(pointer[n] %2 != 0){
			sum = sum + pointer[n];
		}
		
		if(pointer[n] %2 == 0){
			sum2 = sum2 + pointer[n];
			cant++;
		}
		
	}
	prom = sum2 / cant;
	
	printf("\n\n");
	printf("La suma de imapares fue: %i", sum);
	printf("\n El promedio de pares fue: %i", prom);
	printf("\n");
	
	
	
	printf("valor de la variable: %i", pointer[539]);
}
