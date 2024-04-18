// Imprime todos los datos m y n que cumplen:  m^4 + 5n^2 < 640
// José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <math.h>

int main()
{
    char c = '*';
    int n = 40, h = 0, l = 0;

    while(h<n)
    {
        for(l=0, n; l<=n; l++)
            printf("%c  ", c);
        printf("\n");
        h++;
    }

    return 0;
}