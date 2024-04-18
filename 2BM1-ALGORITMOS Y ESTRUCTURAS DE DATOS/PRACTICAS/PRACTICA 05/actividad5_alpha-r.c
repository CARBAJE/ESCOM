#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM_RANDOM 80

int MenuRandom();
void random(int*);
void MergeRandom_sort(int* , int , int);
void MergeRandom(int* , int , int , int);
int sequential_search(int* , int , int);

int sequential_search(int* array , int tam , int elemento){
    //printf("\nelemento es : %i\n", elemento);
    for(int i = 0 ; i < tam ; i++){
        /*printf("dato en el indice[%i] : %i\n", i , array[i]);
        printf("elemento a buscar es : %i\n", elemento);*/
        if(elemento == array[i]){
            //printf("\nelemento %i encontrado en : %i\n",  elemento , i);
            return i;
        }
    }
    return -1;
}

void MergeRandom(int*array , int begin , int mid , int end){
    int i = begin , j = mid+1 , k = 0 ;
    int* output = (int*) calloc(end-begin+1 , sizeof(int));
    if(output == NULL){
        perror("NO HAY ESPACIO EN MEMORIA");
    }
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
        /*if(begin == 0 && end == TAM-1)
            printf("%i\t%i\n", i ,array[i]);*/
    }
}

void MergeRandom_sort(int*array , int begin , int end){
    if(begin < end){
        int mid = (end+begin) /2;
        MergeRandom_sort(array , begin , mid);
        MergeRandom_sort(array , mid+1 , end);
        MergeRandom(array , begin , mid , end);
    }
}

void random(int* array){
    int an=0;
    int i=0;

    an = (2 * an + 1) % (int) pow(2 , 32);
    
    while(i < TAM_RANDOM){
        an = (2 * an + 1) % (int) pow(2 , 32); //Linear Congruential Generator or XORshift ¿?
        if(an <= 19 && 0 <= an){
            array[i] = an;
            //printf("%i\t%d\n", i ,array[i]);
            i++;
        }
    }
}
int MenuRandom(){
    int* array = (int*) calloc (TAM_RANDOM , sizeof(int));
    if(array == NULL){
        perror("NO HAY MEMORIA DISPONIBLE");
        return -1;
    }
    else {
    random(array);
    int numero=0;
    int indice = 0;
    
    printf("Ingrese el numero que quiere encontrar: ");
    fflush(stdin);
    scanf("%i", &numero);
    
    //printf("SI PASE EL SCANF MI NINO");
    MergeRandom_sort(array , 0 , TAM_RANDOM-1);
    
    indice = sequential_search(array , TAM_RANDOM , numero);
    printf("Numero encontrado en el indice: %i\n", indice);
    
    return 0;
    }
}