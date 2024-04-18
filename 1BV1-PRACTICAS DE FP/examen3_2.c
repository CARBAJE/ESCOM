//Cifrado de mensaje
//José Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decifrado(char* , char* , int*);
void impresion(char* , char* , int*);

int main(){
    char* frase = (char*) calloc (100 , sizeof(char));
    
    printf("Ingresa la frase a decifrar: ");
    gets(frase);

    int l = strlen(frase);
    char* frase_d = (char*) calloc (l , sizeof(char));

    decifrado(frase , frase_d , &l);
    impresion(frase , frase_d , &l);

    return 0;
}

void decifrado(char* f , char* f_d , int* l){
    int count = 0;
    char c;

    for(int i = 0; i < *l ; i++){
        c = f[i];
        if( (c = f[i+1]) && (c != 0) ){
            f[i] = 0;
            f[i+1] = 0;
        }
    }
}

void impresion(char* f , char* f_d , int* l){
    printf("la frase: '%s' decifrada queda como:\n", f);
    for(int i = 0 ; i < *l ; i++){
        if(f_d[i] != 0){
            printf("%c" , f_d[i]);
        }
    }
}