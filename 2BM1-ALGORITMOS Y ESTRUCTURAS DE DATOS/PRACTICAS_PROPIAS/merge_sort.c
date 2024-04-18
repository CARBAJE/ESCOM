#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

void merge(int* ,int* , int* , int , int , int);
void merge_sort(int* , int );
void imprimir(int* , int);

void imprimir(int* array , int tam){
    for(int i = 0 ; i < tam ; i++)
        printf("%d\t", array[i]);
}

void merge(int* array, int* arrayD , int* arrayI , int tamI , int tamD , int tam){
    int i = 0 , j = 0 , k = 0;

    while(i <= tamI && j <= tamD){
        if( (int)arrayI[i] <= (int)arrayD[j] ){
            array[k] = arrayI[i];
            i++ ;
            k++;
        }
        else if( (int)arrayI[i] >= (int)arrayD[j] ){
            array[k] = arrayD[j];
            j++ ;
            k++;
        }
    }    

    //Elementos restantes de la primera parte del arreglo
    while(j <= tamD){
        array[k] = arrayI[j];
        j++;
        k++;
    }

    //Elementos restantes de la segunda parte del arreglo
    while(i <= tamI){
        array[k] = arrayD[i];
        i++;
        k++;
    }
}

void merge_sort(int* array ,  int tam){
    if(tam >= 1){
        int i = 0;
        int mid = tam / 2;

        int* array_izq = (int*) calloc(mid , sizeof(int));
        int* array_der = (int*) calloc(tam-mid , sizeof(int));
        
        for(i = 0 ; i <= mid ; i++){
            array_izq[i] = array[i];
        }
        for(int k = 0 ; k < (tam-mid) ; k++){
            array_der[k] = array[i];
            i++;
        }
        merge_sort(array_izq , mid); //Primera mitad del arreglo
        merge_sort(array_der , tam-mid); //Segunda mitad del arreglo
        merge(array , array_der , array_izq , mid , tam-mid , tam); //ordenamiento
    }
}

int main(int argc , int argv){
    srand(time(NULL));
    int tam = 123;
    int* array = (int*) calloc(tam, sizeof(int));

    for(int i = 0 ; i < tam ; i++){
        array[i] = rand() % (999+1);
    }

    imprimir(array , tam);
    merge_sort( array , tam);
    printf("\nARREGLO ORDENADO:\n");
    imprimir(array , tam);

    return 0;
}