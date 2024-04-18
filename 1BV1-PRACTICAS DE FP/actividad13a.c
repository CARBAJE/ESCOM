//Producto Punto de Vectores
//José Emiliano Carrillo Barreiro
#include <stdio.h>

int main(){

    int i=0 , n = 2;
    int x[i] , y[i] , z[i];
    int px = 1 , py = 1 , pz = 1 ;
    int pp = 0;

    printf("Programa para calcular producto punto de vectores.\n");
    printf("Ingrese el numero de vectores a multiplicar");
    scanf("%i" , &i);
    n = i;

    for(i=0 ; i < n ; i++){
        printf("Digite los valores para las variables X , Y , Z del vector.\n");
        printf("Digite el valor da X: ");
        scanf("%i", &x[i]);
        printf("Digite el valor da Y: ");
        scanf("%i", &y[i]);
        printf("Digite el valor da Z: ");
        scanf("%i", &z[i]);
    }

    for(i = 0 ; i < n  ; i++){
        px = px * x[i];
        py = py * y[i];
        pz = pz * z[i];
    }
    
    pp = px + py + pz;

    printf("El vector resultante del producto punto de los vectores esta compuesto por:\n");
    printf("La magnitud que es de: %i\n", pp );
    printf("Sus cordenasdas (X , Y , Z) que son:( %i , %i, %i)", px , py , pz);

    return 0;
}