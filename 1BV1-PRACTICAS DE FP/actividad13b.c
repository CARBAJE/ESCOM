//Producto Cruz de Vectores
//José Emiliano Carrillo Barreiro
#include <stdio.h>

int main(){

    int i=0 , n = 2;
    int x[i] , y[i] , z[i];
    int px = 1 , py = 1 , pz = 1 ;
    int pp = 0;

    printf("Programa para calcular producto cruz de dos vectores.\n");

    for(i=0 ; i < n ; i++){
        printf("Digite los valores para las variables X , Y , Z del vector.\n");
        printf("Digite el valor da X: ");
        scanf("%i", &x[i]);
        printf("Digite el valor da Y: ");
        scanf("%i", &y[i]);
        printf("Digite el valor da Z: ");
        scanf("%i", &z[i]);
    }

    px = (y[0] * z[1]) - ( z[0] * y[1]);
    py = (x[0] * z[1]) - ( z[0] * x[1]);
    pz = (x[0] * y[1]) - ( y[0] * x[1]);
    
    pp = px - py + pz;

    printf("El vector resultante del producto punto de los vectores esta compuesto por:\n");
    printf("La magnitud que es de: %i\n", pp );
    printf("Sus cordenasdas (X , Y , Z) que son:( %i , %i, %i)", px , py , pz);

    return 0;
}