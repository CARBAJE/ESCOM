//Programa suma

#include <stdio.h>

int main()
{
    int num1, num2;
    int suma;

    printf("Ingresa un numero");
    scanf("%i", &num1);
    printf("ingresa un numero");
    scanf("%i", &num2);
    suma = num1+num2;
    printf("la suma es: %i\n", suma);
    return 0;
}