// Imprime todos los datos m y n que cumplen:  m^4 + 5n^2 < 640
// José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <math.h>

int main()
{
    int m=0, n=0;
    printf("Los valores en conjunto para m y n que cumplen ' m^4 + 5n^2 < 640' son: \n");

    for(m=0 , n; (pow(m , 4)) + 5*(pow(n , 2)) < 640; n++ )
        {printf("m=%i , n=%i ;", m, n);}
    printf("\n");
    
    for(m=1 , n=0; (pow(m , 4)) + 5*(pow(n , 2)) < 640; n++ )
        printf("m=%i , n=%i ;", m, n);
    printf("\n");
    
    for(m=2 , n=0; (pow(m , 4)) + 5*(pow(n , 2)) < 640; n++ )
        printf("m=%i , n=%i ;", m, n);
    printf("\n");

    for(m=3 , n=0; (pow(m , 4)) + 5*(pow(n , 2)) < 640; n++ )
        printf("m=%i , n=%i ;", m, n);
    printf("\n");
    
    for(m=4 , n=0; (pow(m , 4)) + 5*(pow(n , 2)) < 640; n++ )
        printf("m=%i , n=%i ;", m, n);
    printf("\n");

    for(m=5 , n=0; (pow(m , 4)) + 5*(pow(n , 2)) < 640; n++ )
        printf("m=%i , n=%i ;", m, n);
    printf("\n");
    
    return 0;
}