//PRRACTICA 3
//JOSÉ EMILIANO CARRILLO BARREIRO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generar_array(int*, int);
void imprimir_array(int*, int);
void imprimir_array_p(int*, int);
void imprimir_array_ip(int*, int);
void acomodar_array_p(int*, int);
void acomodar_array_ip(int* , int);

int main(int argc, char** argv){
    srand(time(NULL));
    int n = 1000;
    int* array = (int*) calloc(n, sizeof(int));

    generar_array(array, n);
    puts("Array sin ordenar:");
    imprimir_array(array ,n);
    acomodar_array_p(array, n);
    puts("\nPares ordenados:");
    imprimir_array_p(array, n);
    acomodar_array_ip(array , n);
    puts("\nInpares ordenados:");
    imprimir_array_ip(array, n);

    return 0;
}

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

void acomodar_array_p(int*a , int n){
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

void acomodar_array_ip(int*a , int n){
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