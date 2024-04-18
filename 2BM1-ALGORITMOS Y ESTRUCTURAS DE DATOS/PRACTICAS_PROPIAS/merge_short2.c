#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void merge(int*array , int begin , int mid , int end){
    int i = begin , j = mid+1 , k = 0 ;
    int* output = (int*) calloc(end-begin+1 , sizeof(int));

    while(i<=mid && j<=end){
        if(array[i] <= array[j]){
            output[k] = array[i];
            k++; i++;
        }
        else if(array[i] >= array[j]){
            output[k] = array[j];
            k++; j++;
        }
    }

    while(i<=mid){
        output[k] = array[i];
        k++; i++;
    }
    while(j<=end){
        output[k] = array[j];
        k++; j++;
    }

    for(i = begin ; i <= end ; i++){
        array[i] = output[i-begin];
    }
}

void merge_sort(int*array , int begin , int end){
    if(begin < end){
        int mid = (end+begin) /2;
        
        merge_sort(array , begin , mid);
        merge_sort(array , mid+1 , end);
        merge(array , begin , mid , end);
    }
}

void imprimir_array(int* array , int begin , int end){
    for(begin = 0 ; begin < end ; begin++)
        printf("%d\t" , array[begin]);
}

void generar_array(int* array , int begin , int end){
    srand(time(NULL));
    for(begin ; begin < end ; begin++ )
        array[begin] = rand() % (999-0+1);
}

int main(int arrgc , char** argv){
    int n = 7;
    int* array = (int*) calloc (n , sizeof(int));

    generar_array(array , 0 , n);
    printf("ARREGLO DADO:\n");
    imprimir_array(array , 0 , n);
    merge_sort(array , 0 , n-1);
    printf("\nARREGLO ORDENADO:\n");
    imprimir_array(array , 0 , n);

    return 0;
}