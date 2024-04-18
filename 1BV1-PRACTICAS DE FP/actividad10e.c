//Realizar figuras.
//José Emiliano Carrillo Barreiro.
#include <stdio.h>

int main()
{
    char c = '*';
    int n = 40, h = 0, l = 0;

    printf("Ingrese el numero de altura que quiere en sus figuras: ");
    scanf("%i", &n);

    //Cuadrado de tamaño "n" y caracter "c"
    while(h<n)
    {
        for(l=0, n; l<=n; l++)
            printf("%c  ", c);
        printf("\n");
        h++;
    }
    printf("\n\n");

    //Triángulo de tamaño "n" y caracter "c"
    h = 0;
    while(h<n)
    {
        for(l=0, h;l<= h; l++)
            printf("%c  ", c);
            
        printf("\n");
        h++;
    }
    printf("\n\n");
    //Triángulo espejo de tamaño "n" y caracter "c"
    h = 0; int lc = 0; 
    while(h<n)
    {
        for(n, lc = n; lc>(h + 1) ; lc-- )
            printf("   ", c);

        for(l=0, h;l<=h ; l++)
            printf("%c  ", c);

        printf("\n");
        h++;
        l--;
    }
    return 0;
}