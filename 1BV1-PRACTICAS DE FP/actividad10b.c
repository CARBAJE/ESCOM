// Generación de numeros primos gemelos (diferencia entre ellos de 2, ejemplo: 3 y 5), dado el intervalo [A:B]
//José Emiliano Carrillo Barreiro
#include <stdio.h>

int main()
{
    int min=4, max=10, numprim = 0;

    while(min<=max)
    {
        if(min%2 != 0)
        {
            numprim = min+2;

            if(numprim%2 != 0)
                printf("%i, ",numprim);
        }
        min = numprim++;
    } 
}