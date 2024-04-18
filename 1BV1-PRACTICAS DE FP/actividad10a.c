//Generación de N números primos
//José Emiliano Carrillo Barreio
#include <stdio.h>

int main()
{
    int n = 0 , count = 10;

    printf("Ingrese la cantidad de numeros primos que desea conocer:");
    scanf("%i", &count);
    
    for(n, count; count>=0; n++)
    {
        if(n%2 != 0)
        {
            printf("%i, ", n); count--;
        }
    }
}