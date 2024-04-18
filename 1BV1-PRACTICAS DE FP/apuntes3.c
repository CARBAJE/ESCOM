//Estructura WHILE
#include <stdio.h>

int main()
{
    int n=0, count=0;
    //Imprimir los num del 1 al 50 000
    while(n <= 50000 && n>=0)
    {
        printf("%d, ",n); 
        n++;
    }
    printf("\n \n");

    //Imprimir los numeros pares entre 670 y 890
    n=670;
    while(n>=670 && n<=890)
    {
        if(n%2 == 0)
        {
        printf("%d, ",n);
        }
        n++;
    }
    printf("\n \n");

    //numeros impares entre 0 y 4567
    n=0;
    while(n<=4567)
    {
        if(n%2 != 0)
        printf("%d, ",n);

        n++;
    }
    printf("\n\n");

    //Los primeros 50 numeros de 7.
    n=0;
    while(count<=50)
    {
        if(n%7 == 0)
        {
            printf("%d, ",n);
            count++;
        }
        n++;
    }
    printf("\n");

    n=0;
    while(n<=50)
    {
        printf("%d, ", n*7);
        n++;
    }
    printf("\n\n");

    //Los numeros de 5000 a -5000
    n = 5000;
    while(n>=-5000)
    {
        printf("%d, ",n);
        n--;
    }
    printf("\n\n");

    //Los números multiplos de 4 o 9 entre 10 000 y 20 000
    n = 10000;
    while(n<=20000)
    {
        if(n%4== 0 || n%9 == 0)
        printf("%d, ", n);

        n++;
    }

    return 0;
}