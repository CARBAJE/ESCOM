#include <stdio.h>

int main()
{
    short n;
    short nfabs;

    printf("Ingrese su numero");
    scanf("%d", &n);

    if(n < 0)
    {
        nfabs = n*-1;
        printf("El valor absoluto de %d es |%d|",n, nfabs);
    }
    else
        printf("El valor absoluto de %d es |%d|", n, n);
return 0;
}