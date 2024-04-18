#include <stdio.h>

int main()
{
    //Imprime 10 al 100 de 5 en 5.
    for(int n=10 ; n<=100 ; n+=5)
        printf("%d, ", n);
    printf("\n \n");

    //Imprime 500 al 400 de 2 en 2.
    for(int n=500 ; n>=400 ; n-=2)
        printf(", %d", n);
    printf("\n \n");

    //imprime los primor 50 multiplos de 4.
    for(int n = 0 ; n<=50 ; n++)
        printf(", %d", n*4);    
    printf("\n\n");

    //Imprime los 5 multiplos de 5 y 3 entre -200 y -400
    for(int n=-200; n>=-400 ; n--)
        if( n%5 == 0 || n%3 == 0)
            printf(", %d", n ); 
    return 0;
}