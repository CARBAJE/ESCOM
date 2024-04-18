/*Implemenración de funciones de archivos .h*/
#include "biblioteca.h"

/*
    Funcion recursiva que imprime un arreglo
    @param arreglo Es un arreglo con 10 elementos
*/
void imprimirArreglo(int* arreglo, int pos){
    if(pos<TAM){
        printf("Pos %d =%d\n", pos, arreglo[pos]);
        imprimirArreglo(arreglo,++pos);
    }
}

void inicioOperacion(int argc, char** argv){
    int arreglo[TAM]={0};
    FILE* archivo=fopen("datos.txt","r+");
    if(archivo==NULL){
        perror("No se pudo abrir el archivo datos.txt");
        exit(1);
    }
    for(int i=0; i<TAM; i++){
        fflush(stdin);
        fscanf(archivo,"%d*[^\n]", &arreglo[i]);
    }
    imprimirArreglo(arreglo,0);
    fclose(archivo);
}



