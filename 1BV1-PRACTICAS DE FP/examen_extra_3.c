//Jose Emiliano Carrillo Barreiro
//Circunferencia y punto

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcular(int* , int* , int* , int* , int* );
void imprimir(int* , int* , int* , int* , int* , int*);

int main(){
    int r = 25;
    int h= 0 , k = 0;
    int x = 0 , y = 0;

    printf("Ingrese el las cordenadas del circulo: \n");
    printf("X del centro del circulo: ");
    scanf("%i", &h);
    fflush(stdin);
    printf("Y del centro del circulo: ");
    scanf("%i", &k);
    fflush(stdin);
    printf("\n");

    printf("Ingrese las cordenadas del punto: \n");
    printf("X del centro del punto: ");
    scanf("%i", &x);
    fflush(stdin);
    printf("Y del centro del punto: ");
    scanf("%i", &y );
    fflush(stdin);

    int res = calcular(&r , &h , &k , &x , &y);
    imprimir(&r , &h , &k , &x , &y , &res);
    return 0;
}

int calcular(int*r , int*h , int*k , int*x , int*y ){
    int res=0;
    float d = 0;
    
    d = (float) sqrt( pow( ( (*h)-(*x) ) , 2 ) + pow( ( (*k)-(*y) ) , 2 ) );
    printf("%f\n", d);

    if(d < *r){
        res = 1;
    }
    if(d == *r){
        res = 2;
    }
    if(d > *r){
        res = 3;
    }

    return res;
}

void imprimir(int* r, int* h, int* k, int* x, int* y, int* res){
    switch(*res){
        case 1:
            printf("El punto (%i,%i) esta dentro del circulo de %iu de radio con centro en: (%i,%i)", *x , *y , *r , *h , *k);
        break;

        case 2:
            printf("El punto (%i,%i) esta sobre la circunferencia del circulo de %iu de radio con centro en: (%i,%i)", *x , *y , *r , *h , *k);
        break;

        case 3:
            printf("El punto (%i,%i) esta fuera del circulo de %iu de radio con centro en: (%i,%i)", *x , *y , *r , *h , *k);
        break;        
    }
}