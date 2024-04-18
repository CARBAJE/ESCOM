//Matriz Diagonal. Arreglo de dos dimensiones con numeros consecutivos.
//José Emiliano Carrillo Barreiro.
#include <stdio.h>

int main(){
    int nf = 0, nc = 0;
    int f= 0 , c = 0 ;
    int num = 1, val=0;

    printf("Programa que crea matrices diagonales con numeros consecutivos.\n");
    printf("Ingrese el numero de filas que quiere que tenga la Matriz: ");
    scanf("%i", &nf);
    printf("Ingrese el numero de columnas que quiere que tenga la Matriz: ");
    scanf("%i", &nc);

    int nt = nf * nc;
    int columnas[nt];

    printf("La matriz formada fue:\n\n");
    for(c = 0; c < nt ; c++){
        if(f == c){
            columnas[c] = num;
            num++;
        }
        else{
            columnas[c] = 0;
        }
    }

    for(c = 0; c < nt ; c++){
        for(c = 0; c < nc ; c++){
            printf(" %i ", columnas[c]);
        }
        printf("\n");
    }

    return 0;
}