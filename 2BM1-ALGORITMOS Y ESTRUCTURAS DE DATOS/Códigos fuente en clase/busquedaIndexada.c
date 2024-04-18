#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//strcat
//strcpy
//strlen
//sprintf
//strcmp
//

void retirarCaracterSaltoDeLinea(char *linea){
  char *carSalto;
  //se busca el caracter salto de linea y se devuelve la dirección de memoria donde se ubica
  //Guardamos la dirección en un apuntador de tipo caracter
  carSalto=strchr (linea, '\n');
  //se sustituye el salto de linea por el fin de cadena si es que no es null
  if(carSalto){
	printf("\nSalto de linea encontrado en la linea de la palabra %s, cambiando...\n",linea);
    *carSalto = '\0';  //accedemos al contenido con el operador de indirección(*) y guardamos
	printf("\nNueva linea %s, cambiando...\n",linea);
  }
}

void main(){
	FILE *archivoInidice=fopen("indices.txt","r");
	FILE *archivoLibros=fopen("Libro.txt","r");
	int indice, indiceLibros=1, i;
	int posicionLineaLibrosInicial;
	int posicionLineaLibrosLimiteSup;
	int arregloIndices[255]={0};
	char listaTitulosLibros[33][100]={'\0'};
	char lineaLibro[100];
	char linea[10]={'\0'};
	char valores[4]={'\0'};
	char itemBuscado[100]="Anecdota de un dia";
	int exito=0;
	if(archivoInidice==NULL && archivoLibros==NULL){
		puts("No se puede abrir el archivo\n");
		exit(-1);
	}else{
		while(feof(archivoInidice)==0){
			fgets(linea,5,archivoInidice);
			//Se recorre la linea para convertir los caracteres numericos en un arreglo
			//llamado valores que al final será convertido a entero con atoi (array to int)
			for(indice=0; indice < strlen(linea); indice++){
				valores[indice]=linea[indice+1];
			}
			//Se usa el valor ascii de la letra para almacenar la posicion donde inicia  
			// el primer titulo del libro con dicha letra inicial
			arregloIndices[(int)linea[0]]=atoi(valores); //atoi ---> array to int ()   sprintf
		}
		
		//Se lee la lista de libros y se transfiere a un arreglo de dos dimensiones (un lista de cadenas)
		while(feof(archivoLibros)==0){
			fgets(listaTitulosLibros[indiceLibros],100,archivoLibros);
			retirarCaracterSaltoDeLinea(listaTitulosLibros[indiceLibros]);
			indiceLibros++;
		}
		
		//elegir el indice de busqueda:
		//Primero preguntamos si el primer caracter se encuentra
		//indexado(es decir si existe almenos un libro con esa letra inicial) sino para que desperdiciar recursos
		if(arregloIndices[(int)itemBuscado[0]]>0){
			posicionLineaLibrosInicial=arregloIndices[(int)itemBuscado[0]];  //indice inicial
			posicionLineaLibrosLimiteSup=arregloIndices[(((int)itemBuscado[0])+1)]; //inidice final
			for(i=posicionLineaLibrosInicial; i<posicionLineaLibrosLimiteSup; i++ ){
				printf("Se esta comparando la cadena libro %s con item %s \n",listaTitulosLibros[i],itemBuscado);
				if(strcmp(listaTitulosLibros[i],itemBuscado)==0){
					printf("El elemento fue encontrado en la linea(posicion) %d\n",i);
					exito=1;
					break;
				}
			}
			if(exito==0)
				puts("El item buscado no se encuentra");
		} else{
			puts("El item buscado no se encuentra");
		}	
		
	}

	fclose(archivoInidice);
	fclose(archivoLibros);
}