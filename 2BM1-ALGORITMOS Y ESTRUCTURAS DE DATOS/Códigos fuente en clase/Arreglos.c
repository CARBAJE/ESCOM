/*
Problema: Guardar la siguiente tabla en memoria estática y dinámica:

      Nombre(char)     Edad (char)
        "X"               "Y"
        "Z"               "W"
        .... 10
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(){
    int tamTablas=0;
    puts("Cuantos nombres vas a registrar:");
    fflush(stdin);
    scanf("%d", &tamTablas);
    char** tablaNombre=NULL;
     char** tablaEdad=NULL;
    tablaNombre=(char **) calloc(tamTablas, sizeof(char*));
    tablaEdad=(char **) calloc(tamTablas, sizeof(char*));
    if(tablaNombre==NULL || tablaEdad==NULL){
        perror("No hay suficiente memoria");
        exit(1);
    }
    for(int t=0; t<tamTablas; t++){
        tablaNombre[t]=(char*) calloc(50, sizeof(char));
        tablaEdad[t]=(char*) calloc(3, sizeof(char));
        if(tablaNombre[t]==NULL || tablaEdad[t]==NULL){
            perror("No hay suficiente memoria");
            exit(1);
        }
    }

    char* tmp=(char*) calloc(50, sizeof(char));
    if(tmp==NULL){
        perror("No hay suficiente memoria para temp");
        exit(1);
    }
    for(int i=0; i<tamTablas; i++){
        fflush(stdin);
        puts("Dame un nombre:");
        gets(tmp);
        tablaNombre[i]=realloc(tablaNombre[i],strlen(tmp)*sizeof(char));
        if(tablaNombre[i]==NULL){
            perror("No hay suficiente memoria para realocar tabla Nombre");
            exit(1);
        }
        strcpy(tablaNombre[i],tmp);
        puts("Dame la edad:");
        fflush(stdin);
        gets(tmp);
        tablaEdad[i]=realloc(tablaEdad[i],strlen(tmp)*sizeof(char));
        if(tablaEdad[i]==NULL){
            perror("No hay suficiente memoria para realocar tabla Edad");
            exit(1);
        }

        strcpy(tablaEdad[i],tmp);
    }

    for(int j=0; j<tamTablas; j++){
        printf("Nombre: %s - Edad:%s \n", tablaNombre[j], tablaEdad[j]);
    }

    for(int i=0; i<tamTablas; i++){
        free(tablaNombre[i]);
        free(tablaEdad[i]);
    }
    free(tablaEdad);
    free(tablaNombre);
}
