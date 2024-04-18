//ARREGLO NxN
//Jose Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar(int** , int* , int*);
void imprimir(int** , int* , int*);

int main(){
    srand(time(NULL));
    int n = 0 , ng = 0;

    printf("Ingrese la longitud que quiere que tenga el arreglo: ");
    scanf("%i" , &n);
    printf("Ingrese el numero de veces que quiera que de la vuelta el arreglo: ");
    scanf("%i" , &ng);

    int** arreglo = (int**) calloc(ng , sizeof(int*));
    for(int i = 0 ; i < ng ; i++){
        arreglo[i] = (int*) calloc(ng , sizeof(int));
    }

    generar(arreglo , &n , &ng);
    imprimir(arreglo , &n , &ng);

    return 0;
}

void generar(int** s , int* l , int* n){
    for(int i = 0 ; i < *l ; i++){
        for(int j = 0 ; j < *l ; j++){
            s[i][j] = rand() % (999 - 100) +100 + 1; 
        }
    }
}

void imprimir(int**serie , int*longi , int* gir){
    int m = 0;
    for(m , *gir ; (m < 4) && (*gir > 0) ; m++){
        switch(m){

            case 0:
                for(int i=0 ; i < *longi ; i++){
                    for(int j=0 ; j < *longi ; j++){
                        printf("%i\t" , serie[i][j]);
                    }
                    printf("\n");
                }
                (*gir)--;
            break;

            case 1:
                for(int i = 0; i < *longi ; i++){
                    for(int j= 0 ; j < *longi ; j++){
                        printf("%i\t" , serie[(*longi)-j-1][i]);
                    }
                    printf("\n");
                }
                (*gir)--;
            break;

            case 2:
                for(int i = 0; i < *longi ; i++){
                    for(int j= 0 ; j < *longi ; j++){
                        printf("%i\t" , serie[(*longi)-i-1][(*longi)-j-1]);
                    }
                    printf("\n");
                }
                (*gir)--;
            break;

            case 3:
                for(int i = 0; i < *longi ; i++){
                    for(int j= 0 ; j < *longi ; j++){
                        printf("%i\t" , serie[j][(*longi)-i-1]);
                    }
                    printf("\n");
                }
                (*gir)--;
                m = -1;
            break;
        }
        printf("\n");
    }

}