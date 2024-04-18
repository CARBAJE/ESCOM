//Generar un arreglo de n caracteres
//José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int n = 0, i = 0;
    srand(time(NULL));

    printf("Ingrese el tamanio que quiere dar al arreglo: ");
    scanf("%i", &i); printf("\n\n");

    char array[i];
    n = i;

    for(i = 0 ; i < n ; i++){
        array[i] = rand() % ('~' - '!') + '!';
        printf("%c ", array[i]);

    }
    printf("\n\n");

    printf("Los caracteres correspondientes a letras son:\n");
    for(i = 0 ; i < n ; i++){
        if( (array[i] >= 'A' && array[i]<= 'Z') || (array[i] >= 'a' && array[i] <= 'z')){
            printf("%c ,", array[i]);
        }
    }
    printf("\n\n");

    printf("Los caracteres correspondientes a numeros son:\n");
    for(i = 0 ; i < n ; i++){
        if(array[i] >= '0' && array[i]<= '9'){
            printf("%c ,", array[i]);
        }
    }
    printf("\n\n");

    printf("Los caracteres correspondientes a signos son:\n");
    for(i = 0 ; i < n ; i++){
        if(  (array[i] >= '!' && array[i]<= '/') || (array[i] >= ':' && array[i] <= '@') ){
            printf("%c ", array[i]);
        }
        if((array[i] >= '[' && array[i] <= '`') || ( array[i] >= '{' && array[i <= '~']))
            printf("%c ", array[i]);
    }
    printf("\n\n");

    printf("Los caracteres correspondientes a vocales son:\n");
    for(i = 0 ; i < n ; i++){
        if( (array[i] == 'A' || array[i] == 'a' ) || (array[i] == 'E' || array[i] == 'e' ) )
            printf("%c ,", array[i]);

        if( (array[i] == 'I' || array[i] == 'i' ) || (array[i] == 'O' || array[i] == 'o' ) )
            printf("%c ,", array[i]);

        if( array[i] == 'U' || array[i] == 'u' )
            printf("%c ,", array[i]);
    }
    printf("\n\n");

    return 0;
    }