#include <stdio.h>

int main()
{
    int n;
    int u, d, c;

    printf("Escriba un numero de tres digitos");
    scanf("%i",&n);

    u = n % 10;
    d = ((n-u) % 100) / 10;
    c = ((n - d*10 - u) / 100);

    printf("El numero invertido en digitos es: %i%i%i", u, d, c);
return 0;
}