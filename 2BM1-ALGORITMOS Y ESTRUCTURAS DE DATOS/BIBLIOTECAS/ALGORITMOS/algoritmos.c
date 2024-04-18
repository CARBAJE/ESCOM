#include "algoritmos.h"

void selection_sort(int* array , int tam){
    int temp = 0;
    for(int i = 0 ; i < tam-1 ; i++){
        for(int j=i+1 ; j <= tam-1 ; j++){
                if(array[i] > array[j]){
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
    }
}

void insertion_sort(int* array , int tam){
    int i = 0 , j = 0;
    int pivote = 0;
    for(i = 1 ; i < tam ; i++ ){
        pivote = array[i];
        j = i - 1;
        while(j >= 0 && pivote > array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = pivote;
    }
}

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

void bubble_sort(int* array , int tam){
    int temp;
    for(int i = 0 ; i < tam-1 ; i++){
        for(int j = 0 ; j < tam - i - 1 ; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int sequential_search(int* array , int tam , int elemento){
    for(int i = 0 ; i < tam ; i++){
        if(elemento == array[i])
            return i;
    }
    return -1;
}

int binary_search(int* array, int begin, int end, int elemento){
    int mid = 0; 
    while(begin < end){
        mid = (end+begin) / 2;
        if(array[mid] == elemento)
            return mid;
        if(elemento < array[mid])
            begin = mid+1;

        if(elemento > array[mid])
            end = mid-1;
    }
}
int* indexedSequential_search(int* array, int elemento){
    int tam = sizeof(array);
    int GN = 3; // GN is a group number that is number of elements in a group
    int elementos[GN] , indices[GN];
    int i = 0 , j = 0 , set = 0 , indice = 0;
    int start = 0 , end = 0;

    for(i ; i < tam ; i+= GN){
        elementos[indice] = array[i];
        indices[indice] = i;
        indice++;
    }

    if(elemento < elementos[0]){
        printf("Elemento no almacenado en el arreglo");
        exit(0);
    }
    else if(elemento >= elementos[0]){
        for(i = 1 ; i <= indice ; i++){
            if(elemento <= elementos[i]){
                start = indices[i-1];
                end = indices[i];
                set = 1;
                break;
            }
        }
    }
    if(set == 0){
        start = indices[GN-1];
        end = GN;
    }
    for(i = start ; i <= end ; i++){
        if(elemento == array[i]){ 
            j = 1;
            break;
        }
    }
    if(j == 1){
        printf("El indice encontrado fue: %d", i);
        return &array[i];
    }
    else
        printf("No encontrado");
}