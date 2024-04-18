//Imprimir cada termino de la serie "n2+(n-1)2+(n-2)2+...(3)2+(2)2+(1)2" y su suma.
//Jose Emiliano Carrillo Barreiro.

#include <stdio.h>
#include <stdlib.h>

void serieN(int n , int *);

int main(){
    int n , suma = 0;
    printf("Ingrese el tamanio de la serie: ");
    scanf("%d" , &n);
    
    serieN(n , &suma);

    return 0;
}

void serieN(int n , int *suma){
    if(n == 1){
        printf("%d" , n);
        *suma = *suma + 1;
        printf("\nLa suma es: %d" , *suma);
    }
    if(n != 1){
        printf("%d ," , n*n);
        *suma = *suma + (n*n);
        serieN( n - 1 , suma);
    }
}