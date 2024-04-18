//Funciones de "pasos de parametros por valor". Se hacen copias de los valores.
#include <stdio.h>

void fun1( int num);
int main(){
	
	int num = 50;
	printf("\n1. Valor de num: %d", num);
	printf("\n1. Direccion de num: %p", &num);
	
	fun1(num);
	
	printf("\n2. Valor de num: %d", num);
	printf("\n2. Direccion de num: %p", &num);
	
	printf("\n");
	
	return 0;
	}

void fun1( int n ){
	n = 100;
	printf("\nValor de num (fun1): %d", n);
	printf("\nDireccion de num (fun1): %d", &n);
}
