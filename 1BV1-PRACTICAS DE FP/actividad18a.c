//Imprimir cada dos datos hasta N
//José Emiliano Carrillo Barreiro
#include <stdio.h>

void datos(int n, int );

int main(){
    int n , i = 0;

    printf("Ingrese el dato numerico para la serie: ");
    scanf("%d" , &n);

    datos( n , i);

    return 0;
}

void datos(int n , int i){
    if(i == n || i == n+1)
        printf("%d, ", n);
    else{
        printf("%d, ", i);
        datos( n , i + 2);
    }
}