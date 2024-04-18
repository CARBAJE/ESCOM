#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct{
    int indice;
    char nombre[20];
    int poblacion;
    char idioma[20];
}Pais;

#define TAM_BD 38

Pais* scan(FILE*);
void printTDA(Pais[]);
void MergePais_sort(Pais* , int , int);
void MergePais(Pais* , int , int , int);
int BinarySearch_Pais(Pais[] , int , int , char*);
void EncontrarElemento(Pais*);
int MenuPais();

Pais* scan(FILE* BD ){
    Pais* array = (Pais*) calloc ( TAM_BD , sizeof(Pais) );
    char nombre[20] = {0};
    char idioma[20] = {0};
    int pblcn = 0 , ind = 0;

    for(int i = 0 ; i < TAM_BD && !feof(BD) ; i++){
        fflush(stdin);
        fscanf(BD ,"%d  %s  %d  %s",&ind , &nombre , &pblcn , &idioma);
        array[i].indice = ind;
        array[i].poblacion = pblcn;
        strcpy(array[i].nombre , nombre);
        strcpy(array[i].idioma , idioma);
    }
    fclose(BD);
    return array;
}

void printTDA(Pais array[]){
    printf("\nELEMENTOS EN EL ARREGLO\n");
    for(int i = 0 ; i < TAM_BD ; i++){
        printf("%i\n%s\n%.2i\n%s\n\n", array[i].indice , array[i].nombre , array[i].poblacion , array[i].idioma);
    }
}

void MergePais_sort(Pais* array , int begin , int end){
    if(begin < end){
        int mid = (begin + end) / 2;

        MergePais_sort(array , begin , mid);
        MergePais_sort(array , mid+1 , end);
        MergePais(array , begin , mid , end);
    }
}

void MergePais(Pais* array , int begin , int mid , int end){ 
    int i = begin , j = mid+1 , k = 0;
    Pais* output = (Pais*) calloc(end-begin+1 , sizeof(Pais));

    while( i <= mid  &&  j <= end){
        ///printf("%i\t" , k);
        if(strcmp(array[i].nombre , array[j].nombre) <= 0){
            output[k] = array[i];
            k++ ; i++;
        }
        else if(strcmp(array[i].nombre , array[j].nombre) >= 0){
            output[k] = array[j];
            k++ ; j++;
        }
    }
    ///printf("%i\t" , k);

    while( i <= mid){
        output[k] = array[i];
        k++ ; i++;
        ///printf("%i\t" , k);
    }
    while( j <= end){
        output[k] = array[j];
        k++ ; j++;
        ///printf("%i\t" , k);
    }
    ///printf("\n");

    for(i = begin ; i <= end ; i++){
        array[i] = output[i-begin];
        ///printf("%i\t", i);
    }
    ///printf("\n\n");
}

int BinarySearch_Pais(Pais array[], int begin, int end, char* elemento){
    MergePais_sort(array , begin , end);
    int mid = 0; 
    while(begin <= end){
        mid = (end+begin) / 2;
        if(strcmp(array[mid].nombre , elemento) == 0)
            return mid;

        if(strcmp(array[mid].nombre , elemento) < 0)
            begin = mid+1;

        if(strcmp(array[mid].nombre , elemento) > 0)
            end = mid-1;
    }
    return -1;
}

void EncontrarElemento(Pais* array){
    char elemento[20];
    printf("Ingrese el pais que quiere buscar: ");
    fflush(stdin);
    scanf("%s",&elemento);
    int i = BinarySearch_Pais(array , 0 , TAM_BD , elemento);
    if(i <= -1 && i >= TAM_BD)
        printf("El Pais no se encuentra en la base de datos.\n\n");
    else if(i >= 0 && i < TAM_BD ){
    printf("El pais %s , se encuentra en el indice: %i\n" , elemento , array[i].indice);
    printf("Elementos pertenecientes a la linea %i:\n", array[i].indice);
    printf("%i\n%s\n%i\n%s\n", array[i].indice , array[i].nombre , array[i].poblacion , array[i].idioma);
    }
}

int MenuPais(){
    int opcion = 0 , i = 0;
    FILE* BD = fopen("C:\\Users\\lenovo\\Desktop\\CODIGOS FUENTES\\2BM1-ALGORITMOS Y ESTRUCTURAS DE DATOS\\PRACTICAS\\BD_Paises_ y_poblacion.txt","r");
    Pais* array = scan(BD);

    printf("Ingrese la opcion que desea realizar: ");
    while(opcion < 5){
        printf("MenuPais:\n");
        printf("1-Imprimir array sin ordenar\n");
        printf("2-Imprimir array ordenada\n");
        printf("3-Encontrar un pais de la array\n");
        printf("0-Terminar programa\n");
        printf("Ingrese la opcion a realizar: ");
        fflush(stdin);
        scanf("%i" , &opcion);

        switch(opcion){
            case 0:
                return 0;
            break;

            case 1:
                printTDA(array);
            break;

            case 2:
                MergePais_sort(array , 0 , TAM_BD-1);
                printTDA(array);
            break;

            case 3:
            MergePais_sort(array , 0 , TAM_BD-1);
                EncontrarElemento(array);
            break;

            default:
                printf("Ingrese una opcion valida.\n");
            break;
        }
    }
}

int main(int argc , char** argv){
    MenuPais();
}