//Imprime la serie fibonacci hasta n,  n dado por el usuario:  0, 1, 1, 2, 3, 5, 8, 13, 21, ...n
// José Emiliano Carrillo Barreiro
#include <stdio.h>

int main()
{
    double n1 = 0 , n2 = 0 , n3 = 0;
    int count = 0;

    printf("Ingresa la cantidad de numeros que quieres imprimir de la serie de fibonacci: ");
    scanf("%i", &count);

    while(count>=0)
    {
        n1 = n2 + n3; count--;
        printf("%.0f, ", n1);

        n2 = n1 + n3;
        if(n1==0)
            n2 = n1 + 1; count--;
        printf("%.0f, ", n2);

        n3 = n2 + n1; count--;
        printf("%.0f, ", n3);

    }
    return 0;
}