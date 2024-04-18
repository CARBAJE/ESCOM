//Genera n números aleatorios e indica cuál es el elemento mayor y el promedio de los datos.
// José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n = 100;
    int max=1;
    int suma=0;
    int prom=0;
    srand (time(NULL));
    int nn = n;

    for(n; n>=0; n--)
    {
        int alt_n = rand();

        printf("%i, ", alt_n);

        if(alt_n>max)
        {
            max = alt_n;
        }

        suma = suma + alt_n;
    }
    prom = suma / nn;

    printf("\nEl numero de mayor magnitud generado fue: %i", max);
    printf("\nEl promedio de todos los datos es: %i", prom);
    
    return 0;
}