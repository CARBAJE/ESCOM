//Pedir una frase al usuario
//José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    char frase[30];

    printf("Ingrese una frase:");
    gets(frase);
    printf("La frase que escrbio es: %s\n", frase);

    int i = 0 , count_min = 0 , count_space = 0 ;
    while(frase[i] != '\0'){
        if(islower(frase[i]))
            count_min++;

        if(isspace(frase[i]))
            count_space++;

        
        if(frase[i] == 'a')
            frase[i] = '4';

        if(frase[i] == 'o')
            frase[i] = '0';

        if(frase[i] == 's')
            frase[i] = '5';

        if(frase[i] == 'e')
            frase[i] = '3';
        
        i++;
    }
    printf("La frase, hecha la modificacion, queda asi:\n%s\n", frase);
    printf("La cantidad de minusculas son: %i\n", count_min);
    printf("La cantidad de espacios son: %i\n", count_space);

    return 0;
}