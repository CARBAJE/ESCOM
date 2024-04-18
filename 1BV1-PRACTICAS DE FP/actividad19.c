//Registro de pasajeros 
/* 1 estructura de pasajero
	1.1 registro de pasajero
	1.2 lugares disponibles
	1.3 mostrar asientos
	1.4 mostrar pasajero (Nombre, id de cliente , asiento asignado , edad)
	1.5 buscar pasajero
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
char nombre[30];
int id[16];
int edad;
int num;
}pasajero;

void registro_pasajero(pasajero** , int , int );
void lug_disponibles(pasajero** , int f);
void most_asientos(pasajero** , int);
void most_pasajeros(pasajero** , int);
void buscar_pasajero(pasajero** , int);

int main(){
	int f = 0 , c = 4;
	int i = 0 , j = 0;
	pasajero var;
	
	printf("Ingrese el numero de filas que quiere en su avion");
	scanf("%d" , &f);
	fflush(stdin);
	
	pasajero** num_asientos = (pasajero**) malloc (c* sizeof(pasajero*) );

	for(int i = 0 ; i < f ; i++){
		num_asientos[i] = (pasajero*) calloc (c, sizeof(pasajero));
	
	}

	for(int i = 0 ; i < f ; i++){
		for(int j = 0 ; j < c ; j++)
			num_asientos[i][j].id[15] = 0;
			num_asientos[i][j].edad = 0;
			num_asientos[i][j].num = 0;
	}
	
	int num = c*f;
	int opcion = 0;

	for(i=0 ; i < f ; i++){
		for(j=0 ; j < c ; j++){
			printf("Digite una de las siguientes opciones:\n");
			printf("1 - Registro de Pasajero\n");
			printf("2 - Visualizacion de lugares disponibles\n");
			printf("3 - Mostrar asientos disponibles\n");
			printf("4 - Mostrar lista total de pasajeros\n");
			printf("5 - Buscar un pasajero por su id;\n");
			printf("Ingrese una de las opciones mencionadas: ");
			scanf("%i" , &opcion);
			fflush(stdin);

			switch(opcion){
				case 1:
					registro_pasajero(num_asientos , i , j);
				break;
				
				case 2:
					lug_disponibles(num_asientos , f);
				break;

				case 3:
					most_asientos(num_asientos , f);
				break;   

				case 4:
					most_pasajeros (num_asientos , f);
				break;

				case 5:
					buscar_pasajero(num_asientos , f);
				break;
			}
		}
	}
	return 0;
}

void registro_pasajero(pasajero** asientos , int i , int j){
	int option = 0 , n = 0;
	while(n < 4){
		printf("Ingrese las cuatro opciones para registar su pasajero. Opciones:\n");
		printf("1-Ingresar Nombre.\n");
		printf("2-Ingresar Edad.\n");
		printf("3-Asignacion de numero de asiento.\n");
		printf("4-Asignacion del ID del pasajero.\n");
		printf("Ingrese una de las opciones mencionadas: ");
		scanf("%i" , &option);
		fflush(stdin);
		printf("\n");

		switch(option){
			case 1:
				if(asientos[i][j].nombre[1] == NULL){
					printf("Ingrese el nombre del pasajero:\n");
					gets(asientos[i][j].nombre);
					fflush(stdin);
					n++;
					printf("\n");
				}
				else
					printf("Este pasajero ya fue nombrado\n");
					printf("\n");
			break;

			case 2:
				if(asientos[i][j].edad == 0){
					printf("Ingrese la edad del pasajero: ");
					scanf("%i", &asientos[i][j].edad);
					fflush(stdin);
					n++;
					printf("\n");
				}
				else
					printf("Este pasajero ya se le registro su edad.");
					printf("\n");
			break;

			case 3:
				if(asientos[i][j].num == 0){
					asientos[i][j].num = 1 + 4 * i + j;
					printf("El asiento asignado para el pasajero es: %i\n", asientos[i][j].num);
					n++;
					printf("\n");
				}
				else
					printf("Este pasajero ya tiene un numero de asiento asignado.\n");
					printf("\n");
			break;

			case 4:
				if(asientos[i][j].id[15] == 0){
					srand(time(NULL));
					for(int k = 0; k < 16 ; k++){
						asientos[i][j].id[k] = rand() % 10; 
					}
					printf("El ID asignado para el pasajero es: %i\n", asientos[i][j].id);
					n++;
					printf("\n");
				}
				else
					printf("Este pasajero ya tiene un ID asignado.\n");
					printf("\n");
			break;
		}
	}
}  

void lug_disponibles(pasajero** asiento , int f){
	for(int i = 0 ; i < f ; i++){
		for(int j =0 ; j < 4 ; j++){
			if(asiento[i][j].id[15] == 0)
				printf(" O ");
			else
				printf(" X ");
		}
		printf("\n");
	}
}

void most_pasajeros(pasajero** pas , int f){
	for(int i=0; i < f ; i++){
		for(int j=0 ; j < 4 ; j++){
			if(pas[i][j].id[15] != 0){
				printf("Nombre del pasajero %i : %s \n",pas[i][j].num , pas[i][j].nombre);
				printf("Edad del pasajero %i : %i \n",pas[i][j].num , pas[i][j].edad);
				printf("Numero de asiento del pasajero %i : %i \n",pas[i][j].num , pas[i][j].num);
				printf("ID del pasajero %i : %i \n",pas[i][j].num , pas[i][j].id);
			}
			else
				printf("El pasajero[%i][%i] todavia no existe\n", i , j);
		}
	}
}

void buscar_pasajero(pasajero** pas , int f){
	int n[16];
	int i = 0 , j = 0;
	while(n != pas[i][j].id){
		printf("Ingrese el ID del pasajero: ");
		scanf("%i" , &n);
		fflush(stdin);
		for(i = 0; i < f ; i++){
			for(j = 0 ; j < 4 ; j++){
				if(n == pas[i][j].id){
					printf("Nombre del pasajero %i : %s \n",pas[i][j].num , pas[i][j].nombre);
					printf("Edad del pasajero %i : %i \n",pas[i][j].num , pas[i][j].edad);
					printf("Numero de asiento del pasajero %i : %i \n",pas[i][j].num , pas[i][j].num);
					printf("ID del pasajero %i : %s \n",pas[i][j].num , pas[i][j].id);
				}
			}
		}
	}
}

void most_asientos(pasajero** asiento , int f){
	for(int i = 0 ; i < f ; i++){
		for(int j =0 ; j < 4 ; j++){
			if(asiento[i][j].id[15] == 0)
				printf(" O ");
			else
				printf(" X ");
		}
		printf("\n");
	}
}