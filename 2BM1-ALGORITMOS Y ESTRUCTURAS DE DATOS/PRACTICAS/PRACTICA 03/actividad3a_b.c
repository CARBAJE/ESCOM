#include "actividad3a_b.h"

void generar_array(int*a , int n){
    for(int i=0 ; i<n ; i++)
        a[i] = rand() % 459655 +1;
}

void imprimir_array(int*a , int n){
    for(int i= 0 ; i < n ; i++)
        printf("%d\t",a[i]);
}

void imprimir_array_p(int*a , int n){
    for(int i= 0 ; i < n ; i++){
            if(a[i]%2 == 0)
                printf("%d\t",a[i]);
        }
}

void imprimir_array_ip(int*a , int n){
    for(int i= 0 ; i < n ; i++){
            if(a[i]%2 != 0)
                printf("%d\t",a[i]);
    }
}

void selection_sort(int*a , int n){
    int temp = 0;
    for(int i = 0 ; i < n-1 ; i++){
        for(int j=i+1 ; j <= n-1 ; j++){
                if(a[i] > a[j]){
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
    }
}

void insertion_sort(int*a , int n){
    int i = 0 , j = 0;
    int pivote = 0;
    for(i = 1 ; i < n ; i++ ){
        pivote = a[i];
        j = i - 1;
        while(j >= 0 && pivote > a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = pivote;
    }
}

void inicio(int argc, char** argv){
    srand(time(NULL));
    int n = m;
    int* array = (int*) calloc(n, sizeof(int));

    generar_array(array, n);
    puts("Array sin ordenar:");
    imprimir_array(array ,n);
    selection_sort(array, n);
    puts("\nPares ordenados:");
    imprimir_array_p(array, n);
    insertion_sort(array , n);
    puts("\nInpares ordenados:");
    imprimir_array_ip(array, n);
}