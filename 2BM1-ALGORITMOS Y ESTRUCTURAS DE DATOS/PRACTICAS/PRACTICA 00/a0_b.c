#include "a0_b.h"

void generar_funcion(char* ascii_c){
    
    ascii_c = '\0' ;
    ascii_c = (char*) calloc (ASCII_MAX , sizeof(char));

    if(ascii_c == NULL){
        perror("No hay suficiente memoria.");
        exit(1);
    }

    for(int i = 0; i < ASCII_MAX ; i++){
        ascii_c[i] = i;
    }

    imprimir_funcion(ascii_c);
}

void imprimir_funcion(char* ascii_c){
    FILE* archivo = fopen("a0_txt.txt","w+");

    if(archivo == NULL){
        perror("No se pudo abrir el archivo datos.txt");
        exit(1);
    }
    for(int i = 0; i < ASCII_MAX ; i++){
        fprintf(archivo, "%i\t -\t %x\t -\t %c\n",i , ascii_c[i]);
        printf("%i\t -\t %x\t -\t %c\n",i , ascii_c[i]);
    }

    fclose(archivo);
}