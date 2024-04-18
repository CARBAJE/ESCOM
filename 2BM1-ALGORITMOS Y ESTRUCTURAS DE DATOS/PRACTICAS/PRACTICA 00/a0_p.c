#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void generar(int);
void imprimir(int , char*);

int main(int argc , char* argv){
    generar(argc);
}

void generar(int ascii){

    ascii = 256;
    char* c = (char*) calloc (ascii , sizeof(char));
    if(c == NULL){
        perror("NO HAY SUFICIENTE MEMORIA");
        exit(1);
    }

    for(int i = 0 ; i < ascii ; i++){
        c[i] = i ; 
    }

    imprimir(ascii , c);
}

void imprimir(int v, char* c){
    for(int i = 0; i < v ; i++){
        printf("%d\t - %x\t - %c\t", i , i , c[i]);
    }
}