#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TAM 123
//const int TAM = 123

typedef struct{
    float altura;
    char nombre[50];
    int telefono;
    char pais_origen[20];
}Persona;

void selection_sort(Persona*);
void insertion_sort(Persona*);
void merge_sort(Persona*, int , int);
void merge(Persona* , int , int , int);
void bubble_sort(Persona*);
void scan(FILE* , Persona* , int);
void printTDA(Persona* , int);
int menu(int , char**);