//Juego ahorcado.
//Jose Emiliano Carrillo Barreiro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void asignacion(char[][20] , int*);
void juego(char[][20] , int);
int main(){
	char array[10][20];
	int o = 10;
	
	printf("Programa que simula un juego de 'ahorcados'\n");
	
	asignacion(array , &o);
	printf("%i\n", o);
	juego(array , o);
	return 0;
}

void asignacion(char array[][20] , int* option){
	srand(time(NULL));
	
	for(int i = 0 ; i < 10 ; i++){
		for(int j = 0 ; j < 20 ; j++){
			array[i][j] = rand() % (90-65) +65 + 1;
		}
	}
	*option = rand() % 10;
	
}

void juego(char array[][20] , int o){
	char array2[20], c;
	for(int l = 0 ; l< 20; l++){
		array2[l] ='_';												
	}
	int oport=0;
	
	printf("Ingrese la cantidad de oportunidades que desee tener: ");
	scanf("%i", &oport);
	fflush(stdin);

	for(int z = 0; z < 20 ; z++){
		printf("%3c" , array[o][z]);
	}

	printf("\n");

	for(oport ; oport > 0 ; oport--){
		if( strncmp(array[o] , array2 , 20) == 0 ){
			printf("Felicidades. Ganaste\n");
			oport = 0;
		}
			if( strncmp(array[o] , array2 , 20) != 0 ){
			printf("\nTus oportunidades son: %i\n", oport);
			printf("\nIngrese una letra del vocabulario: ");
			scanf("%c", &c);
			fflush(stdin);

			for(int m = 0 ; m < 20 ; m++){
				if ( array2[m] != array[o][m] ){
					array2[m] = c;
				}
				if(array2[m] != array[o][m]){
					array2[m] ='_';
				}
			}
			printf("\n");

			for(int l = 0; l<20 ; l++){
				printf("%3c", array2[l]);
			}
		}
		
		printf("\n");
	}
	printf("FIN DEL JUEGO");
}
