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

void registro_pasajero();
void lug_disponibles();
void most_asientos();
void most_pasajeros();
void buscar_pasajero();

typedef struct{
char nombre[30];
int id[16];
int edad;
int asiento;
}pasajero;

int main(){
	int f = 0 , c = 4;
	pasajero var;
	
	printf("Ingrese el numero de filas que quiere en su avion");
	scanf("%d" , &f);
	
	int **num_asientos = (int**) malloc ( sizeof(int*) * c);
	for(int i = 0 ; i < f ; i++){
		num_asientos[i] = (int*) calloc (f , sizeof(int));
	}

	int opcion = 0;

	switch(opcion){
		case 1:
			registro_pasajero();
		break;
		
		case 2:
			lug_disponibles();
		break;

		case 3:
			most_asientos();
		break;

		case 4:
			most_pasajeros ();
		break;

		case 5:
			buscar_pasajero();
		break;
	}
	return 0;
}