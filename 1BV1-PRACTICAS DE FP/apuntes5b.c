//Funciones de "pasos de referencia por valor". Se hacen copias de los valores.
#include <stdio.h>

//int s; //Variable global (NO UTILIZAR).
void fun1( int *num);

int main(){
	
	int num = 50;
	//s = 20;
	printf("\n1. Valor de num: %d", num);
	printf("\n1. Direccion de num: %p", &num);
	
	fun1(&num);
	
	printf("\n2. Valor de num: %d", num);
	printf("\n2. Direccion de num: %p", &num);
	
	printf("\n");
	
	return 0;
	}

void fun1( int *num ){
	*num = 100;
	//s = 40;
	printf("\nValor de num (fun1): %d", *num);
	printf("\nDireccion de num (fun1): %p", num);
}
