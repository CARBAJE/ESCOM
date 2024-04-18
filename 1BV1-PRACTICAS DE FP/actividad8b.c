//Pedir al usuario los lados de un triángulo y decirle que tipo es

#include <stdio.h>

int main()
{
    int a, b, c;

   printf("Ingresa los tres lados de tu triangulo");
   scanf("%i %i %i", &a, &b, &c);

   if(a == b && b == c)
        printf("El triangulo es equilatero");

    if(a == b && b != c)
        printf("El triangulo es isoseles");

    if(b == c && c != a)
        printf("El triangulo es isoseles");

    if(a != b && c != b)
        printf("El triangulo es escaleno");

    return 0;

}