#include <stdio.h>

int main()
{
    int n1, n2, n3;

    printf("ingresa tres numeros");
    scanf("%i %i %i", &n1, &n2, &n3);

    if(n1>0 && n2>0 && n3>0)
        printf("los numeros: %i, %i, %i comparten mismo signo simultaneamente", n1, n2, n3);
    if(n1<0 && n2<0 && n3<0)
        printf("los numeros: %i, %i, %i comparten mismo signo simultaneamente", n1, n2, n3);
    if(!(n1>0 && n2>0 && n3>0) && !(n1<0 && n2<0 && n3<0))
        printf("los numeros: %i, %i, %i no comparten mismo signo simultaneamente", n1, n2, n3);
return 0;
}