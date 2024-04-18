/* Imprime las siguientes series:
   A) 2, 5, 7, 10, 12, 15, ... 1800       (Hasta 1800)
   B)  2000, 1995, 1996, 1991, 1992, 1987, .... 0 (Hasta 0)*/
// José Emiliano Carrillo Barreiro
#include <stdio.h>

int main()
{
    //A) 2, 5, 7, 10, 12, 15, ... 1800       (Hasta 1800)

    int n=2, m=5;

    for(n, m; n<=1800 && m<=1800; n+=5, m+=5)
    {
        printf("%i, %i, ", n, m);
    }

    printf("\n\n");

    //B)  2000, 1995, 1996, 1991, 1992, 1987, .... 0 (Hasta 0)*/

    n = 2000;

    for(n; n>=0; n-=5)
    {
        printf("%i, ",n);

        while(n%2 != 0)
        {
            n+=1; 
            printf("%i, ", n);
        }
    }
}