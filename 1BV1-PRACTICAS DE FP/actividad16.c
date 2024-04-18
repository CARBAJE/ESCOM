//Crear un programa que calcule el producto cruz y punto.
#include <stdio.h>
#include <stdlib.h>

void array_bii(int ** , int * , int *);
void val_asign(int ** , int * , int *);


int main(){
    int **array_bi , colum , fil;

    array_bii(array_bi , &colum , &fil);
    val_asign(array_bi , &colum , &fil);


    return 0;

}

void array_bii(int **array_bi , int *colum , int *fil){
    int x , y , i;

    printf("Ingrese la cantidad de vectores que quiere multiplicar: ");
    scanf("%i", &x );

    printf("Ingrese la cantidad de dimensiones que tendran los vectores (maxima 3 dimensiones): ");
    scanf("%i", &y );

    *colum = x;
    *fil = y;

    array_bi = (int**) malloc (sizeof(int*) *x);

    for(i = 0 ; i < y ; i++){
        array_bi[i] = (int*) malloc (sizeof(int) *y); 
    }
}

void val_asign(int **array_bi , int *colum , int *fil){
    int m= 0 , n= 0;
    char cord;
    
    for(m = 0 ; m < (*colum) ; m++){
        for(n = 0 ; n < (*fil) ; n++){
            switch( n ){
                case 0:
                    cord = 'x';
                break;
                
                case 1:
                    cord = 'y';
                break;
                
                case 2:
                    cord = 'z';
                break;

                default:
                    cord = 'E';
            }
            printf("Asigne un valor a la cordenada [%c] del vector[%d]:" , cord , m);
            scanf("%i" , &(array_bi[m][n]));
        }
    }
}