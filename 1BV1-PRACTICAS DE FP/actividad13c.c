//Matriz. Arreglo de dos dimensiones con numeros consecutivos.
//José Emiliano Carrillo Barreiro.
#include <stdio.h>

int main(){
    int f = 0 , c = 0;
    int nf = 0, nc = 0;
    int num = 0;

    printf("Programa que crea matrices con numeros consecutivos.\n");
    printf("Ingrese el numero de filas que quiere que tenga la Matriz: ");
    scanf("%i", &nf);
    printf("Ingrese el numero de columnas que quiere que tenga la Matriz: ");
    scanf("%i", &nc);

    printf("La matriz formada fue:\n\n");
    for(f = 0; f < nf ; f++){
        for(c = 0; c < nc ; c++){
            printf(" %i ", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}