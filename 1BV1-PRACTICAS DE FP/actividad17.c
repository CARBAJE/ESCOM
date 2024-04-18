//Realizar una matriz de filas (f) y columnas (c)e imprimirla de dif formas
//Jose emiliano Carrillo Barreio
#include <stdio.h>
#include <stdlib.h>

int funA(int *[] , int * , int *);
int funB(int ** , int * , int *);
int funC(int ** , int * , int *);
int funD(int ** , int * , int *);
int funE(int ** , int * , int *);
int funF(int ** , int * , int *);
int funG(int ** , int * , int *);

int main(){
	int f , c;
	
	printf("\nIngrese el numero de filas que quiere que tenga la matriz. ");
	scanf("%i", &f);
	printf("\nIngrese el numero de columnas que quiere que tenga la matriz. ");
	scanf("%i", &c);
	
	int** arr = (int**) malloc (f * sizeof(int*));
	for(int i = 0; i < f ; i++){
		arr[i] = (int*) calloc (c, sizeof(int));
	}
	
	funA(arr, &f , &c);
	funB(arr, &f , &c);
    printf("\n");

    funF(arr, &f , &c);
	printf("\n");

    funC(arr, &f , &c);
	funD(arr, &f , &c);	
	printf("\n");
	
    funE(arr, &f , &c);
    printf("\n");

    funA(arr, &f , &c);
	funB(arr, &f , &c);
    funG(arr, &f , &c);

	return 0;
}

int funA(int *a[], int *f , int *c){

	int num = 1;
	for(int i = 0; i < *f ; i++){
		for(int j = 0; j < *c ; j++){
			a[i][j] = num++;
		}
	}
	return 0;
}

int funB(int **a, int *f , int *c){
	
	for(int i = 0; i < *f ; i++){
		for(int j = 0; j < *c ; j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
		
}

int funF(int **a , int *f , int *c){
    
    for(int i = *f - 1; i >= 0 ; i--){
		for(int j = *c - 1; j >= 0 ; j--){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int funC(int **a, int *f , int *c){
	
	int num = 1;
	
	for(int j = 0; j < *c ; j++){
		for(int i = 0; i < *f ; i++){
			a[i][j] = num++;
		}
	}
	return 0;
		
}

int funD(int **a, int *f , int *c){
	
	for(int i = 0; i < *f ; i++){
		for(int j = 0; j < *c ; j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
		
}

int funE(int **a, int *f , int *c){

    int k = 0 , count = 0;
	
	for(int i = 0; i < *f ; i++){

        for(int j = 0; j < *c ; j++){
            
            if(j % 2 == 0){
                printf("%3d", a[i][j]);    
            }

            if(j % 2 != 0){
                k = ( *f - 1) - count;
                printf("%3d", a[k][j]);    
            }
            
        }
        count++;
        printf("\n");
	}
	return 0;
		
}