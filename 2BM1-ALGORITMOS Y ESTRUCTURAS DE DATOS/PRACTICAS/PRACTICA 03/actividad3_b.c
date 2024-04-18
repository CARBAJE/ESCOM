#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct{
    int alto;
    int ancho;
    char titulo[50];
    char fuente[30];
}Hoja;

typedef struct{
    Hoja hoja;
}Libro;

void insertion_sort();

int main(int argc , char** argv){
    char* path_ord = "C:\\Users\\lenovo\\Desktop\\CODIGOS FUENTES\\2BM1-ALGORITMOS Y ESTRUCTURAS DE DATOS\\actividad3b_BD_Ordenado.txt";
    char* path_BD = "C:\\Users\\lenovo\\Desktop\\CODIGOS FUENTES\\2BM1-ALGORITMOS Y ESTRUCTURAS DE DATOS\\actividad3b_BD_Libros.csv";

    FILE* archive_ord = fopen(path_ord , "w");
    FILE* archive_BD = fopen(path_BD , "r");

    if( archive_BD == NULL){
        perror("NO SE PUDO ABRIR EL ARCHIVO");
        exit(1);
    }
    
}