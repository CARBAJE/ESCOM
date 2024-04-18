//VOCALES ELIMINAR
//Jose Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generador(char* , char* , int*);
void imprimir(char* , char* , int*);

int main(){
    char* palabra = (char*) calloc(50 , sizeof(char));
    char* consonantes = (char*) calloc(50 , sizeof(char));
    int contador = 0;
    printf("Ingrese una palabra para quitar sus vocales: ");
    gets(palabra);

    generador(palabra , consonantes , &contador);
    imprimir(palabra , consonantes , &contador);

    return 0;
}

void generador(char* pal , char* cons , int* c){

    for(int i=0 ; i < 50 ; i++){
        if(( ((pal[i] == 'a') || (pal[i] == 'e') )|| ( (pal[i] == 'i') || (pal[i] == 'o') ) ) || (pal[i] == 'u')){
            (*c)++;
        }

        if(( ((pal[i] != 'a') && (pal[i] != 'e') ) && ( (pal[i] != 'i') && (pal[i] != 'o') ) ) && (pal[i] != 'u')){
            cons[i] = pal[i];
        }
    }

    for(int i = 0; i < 50 ; i++){
        for(int j = i+1 ; j < 50 ; j++){
            if (cons[i] == cons[j]){
                cons[j] == 0;
            }
        }
    }
}

void imprimir(char* pal , char* cons , int* cont){
    printf("Las veces que se encontro vocales en la palabra '%s' fue de: %i" , pal, *cont);
    printf("Las consonantes de la palabra son: ");
    for(int i = 0 ; i < 50 ; i++){
        if(cons[i] != 0)
            printf("%c", cons[i]);
    }
}