//Dado un numero entero ingresado por el usuario, indique si es múltiplo de 2, de 3 y 5.
#include <stdio.h>

int main()
{
    int n;
    int M2, M3, M5;

    printf("Escriba el numero que desee conocer su multiplo");
    scanf("%i", &n);

    M2 = n % 2;
    M3 = n % 3;
    M5 = n % 5;

    if(M2 == 0 && M3 == 0 && M5 == 0)
        printf("El numero %i es multiplo de 2, 3 y de 5", n);

    if(M2 != 0 && M3 != 0 && M5 != 0)
        printf("El numero %i no es multiplo de 2, 3 ni 5", n);

        if(!(M2 == 0 && M3 == 0 && M5 == 0))
        printf("El numero %i no es multiplo simultaneo de 2, 3 y de 5", n);

    return 0;
}