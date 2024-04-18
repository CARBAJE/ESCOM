//Estructura DO WHILE
#include <stdio.h>

int main()
{
    int n=600;

//Los numeros del 600 al 2560
    do{
        printf("%d, ",n);
        n++;
    }while(n<=2560);
    printf("\n\n");

//Los numeros impares entr 6700 y -890
    n = 6700;
    do{
        if(n%2 != 0)
        printf("%d, ",n);

        n--;
    }while(n>=-890);
    printf("\n\n");

//Imprimir 700 a 0, cada 6 numeros.
    n = 700;
    do{
        printf("%d, ", n);
        n-=6;
    }while(n>=0);
    printf("\n\n");

//Imprimir los primeros 35 multiplos de 3 y 2 simultanemanete
    n = 0;
    int count = 0;

    do{
        if(n%2==0 && n%3==0)
        {
        printf("%d, ",n);
        count++;
        }
        n++;
    }while(count<35);
    printf("\n\n");

//Imprimirlas letras del abecedario de la Z a la A, en mayusculas.
    char l = 'z';

    do{
        printf("%c");
        l--;
    }while(l>='a');



    return 0;
}