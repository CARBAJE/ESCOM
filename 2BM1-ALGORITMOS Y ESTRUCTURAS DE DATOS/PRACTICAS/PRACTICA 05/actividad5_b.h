#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

typedef struct{
    int indice;
    char nombre[20];
    int poblacion;
    char idioma[20];
}Pais;

#define TAM_BD 38
#define TAM_RANDOM 80

int MenuRandom();
void random(int*);
void MergeRandom_sort(int* , int , int);
void MergeRandom(int* , int , int , int);
int sequential_search(int* , int , int);

Pais* scan(FILE*);
void printTDA(Pais[]);
void MergePais_sort(Pais* , int , int);
void MergePais(Pais* , int , int , int);
int BinarySearch_Pais(Pais[] , int , int , char*);
void EncontrarElemento(Pais*);
int MenuPais();

int menu(int);