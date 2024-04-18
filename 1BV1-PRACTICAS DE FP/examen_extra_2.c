//José Emiliano Carrillo Barreiro
//Triangulo
#include <stdio.h>
#include <stdlib.h>

void generar(char* , int* , char*);
void imprimir();

int main(){
    int n = 0; 
    char c = 'O';

    printf("Ingrese el tamanio que quiere para su triangulo: ");
    scanf("%i", &n);
    fflush(stdin);
    printf("Ingrese el caracter que quiere que tenga su triangulo: ");
    scanf("%c" , &c);

    char* array = (char*) calloc (n , sizeof(char));
    for(int i = 0 ; i < n ; i++){
        array[i] = c;
    }

    generar(array , &n , &c);
    imprimir(array , &n , &c);

    return 0;
}

void generar(char* triangulo, int* n, char* c){
    for(int i = 0 ; i < *n ; i++){
        triangulo[i] = *c;
    }
}

void imprimir(char* triangulo, int* n, char* c){
    for(int count = 0 ; count < *n ; count++){
        for(int i = 0; i <= count ; i++){
            printf("%c\t" , triangulo[i]);
        }
        printf("\n");
    }
}