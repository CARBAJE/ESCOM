//Frase Invertida 
//Jose Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int invertir(char* , char** , int*);
void imprimir(char* , char** , int* , int*);

int main(){
    char* frase = (char*) calloc (100 , sizeof(char));

    printf("Ingrese la frase que desee invertir: ");
    gets(frase);

    int l = strlen(frase);
    
    int n = 1;
    for(int i = 0 ; i  < l ; i++){
        if(frase[i] == ' '){
            n++;
        }
    }

    char** div_fras = (char**) calloc( n , sizeof(char*));
    for(int i = 0 ; i < n ; i++){
     div_fras[i] = (char*) calloc ( l , sizeof(char));   
    }

    int count =invertir(frase , div_fras , &l);
    imprimir(frase , div_fras , &l , &count);

    return 0;
}

int invertir(char* f , char** inv , int* l){

    int k = 0;
    int count = 0;

    for(int i = 0 ; i < *l ; i++){

        if(f[i] == ' '){

            for(int j = 0 ; j < (i-k) ; j++){

                inv[count][j] = f[k+j];
            }
            k = i+1;
            count++;
        }
        if(i == *l - 1){

            for(int m = i ; f[m] != ' ' ; m--){
                
                inv[count][m-k] = f[m]; 
            }

        }

    }

    return count;
}

void imprimir(char* f , char** inv , int* l , int* c){
    
    printf("La frase '%s' en su forma invertida queda:\n" , f);
    for(*c ; *c >= 0 ; (*c)--){
        printf("%s " , inv[*c]);
    }
}