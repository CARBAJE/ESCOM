#include<stdio.h>

void fun1(char animal[]);

int main(){
    char animal[30];
    printf("Ingrese su animal favorito: ");
    scanf("%s",animal);
   
    fun1(animal);
   
    return 0;
}

void fun1(char animal[])
{
    char trag[10][40]={"uno se murio en la nieve","Uno se fue con Pinocho",
    "Uno se subio en un cohete","Uno se comio un cien pies","Uno se mató de un brinco","Uno se perdio en el teatro",
    "Uno se lo llevó Andres","Uno se murio de tos","Uno se lo llevo Bruno","Al que quedaba lo mato   una bicicleta"};
   
    for(int n=0 ; n<10; n++){
        printf("Yo tenia %i %s \n",10-n , animal);
        printf("Yo tenia %i %s \n",10-n , animal);
        printf("%s \n",trag[n]);
        printf("Nada mas me quedan %i %s \n",10-n , animal);
        printf("\n");
    }
       
}
