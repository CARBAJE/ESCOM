//Genera 2000 votos correspondientes a las letras w, x, y, z.  Imprime los 2000 votos e indica las frecuencias de cada uno.
// José Emiliano Carrillo Barreiro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char l1 = 'w' , l2 = 'x' , l3 = 'y' , l4 = 'z', lv= 0;
    int cl1=0 , cl2=0 , cl3=0 , cl4=0 ;
    int n = 2000;
    srand(time(NULL));

    for(n ; n>0 ; n--)
    {
     lv = rand() % ('z'-'v') +119;

     printf("%c ", lv); 

     if(lv == 'w')
        cl1++;

     if(lv == 'x')
        cl2++;

     if(lv == 'y')
        cl3++;

     if(lv == 'z')
        cl4++;

    }
    printf("\n El numero de veces que se repitio %c fue de: %i", l1, cl1 );
    printf("\n El numero de veces que se repitio %c fue de: %i", l2, cl2 );
    printf("\n El numero de veces que se repitio %c fue de: %i", l3, cl3 );
    printf("\n El numero de veces que se repitio %c fue de: %i", l4, cl4 );

    return 0; 
}