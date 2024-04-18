//programa suma 2

#include <stdio.h>

main(void)
{
    int n1, n2;
    int suma;

    printf("ingrese un numero");
    scanf("%i %i", &n1 , &n2);
    suma = n1+n2;
    printf("la suma es: %i\n", suma);
    return 0;
}