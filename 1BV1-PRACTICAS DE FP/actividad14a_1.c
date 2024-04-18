//Cancion de perritos

#include <stdio.h>

void fun1(char []);

int main(){
	char animal[20];
	
	printf("Ingrese su animal favorito");
	scanf("%s", animal);
	
	fun1(animal);
	
	
	return 0;
}

void fun1(char animal[]){
	char trag[10][30] = {"quedo en la nieve" , "trago un bizcocho" , "fue en un cohete" , "comio un ciempies" ,
	"golpeo el hocico" , "perdio el teatro" , "volteo al reves"  , "enfermo de tos" , "lo llevo Bruno" ,
	"a acampar al cerro" };
	
	for(int n= 0 ; n < 10 ; n++ ){
		printf("Yo tenia %i %s \n", 10-n , animal);
		printf("Yo tenia %i %s \n", 10-n , animal);
		printf("Uno se %s \n", trag[n]);
		printf("Nada mas me quedan %i %s \n", 10-n , animal);
		printf("\n");
		
	}
}



