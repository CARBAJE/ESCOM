//Jose Emiliano Carrillo Barreiro
//Potencias si math.h

#include <stdio.h>

int potencia(int* , int* );

int main(){
    int base=0 , exponente = 0;

    printf("Ingresa la base de la potencia: ");
    scanf("%i", &base);
    fflush(stdin);
    printf("Ingresa el exponente de la potencia: ");
    scanf("%i", &exponente);
    fflush(stdin);

    int r = potencia(&base , &exponente);

    printf("La potencia del numero: %i , elevado a la %i es de: %i", base , exponente , r);
    return 0;
}

int potencia(int* b, int* e){
    int r = 1;
    for(int i = 0 ; i < *e ; i++){
        r *= (*b);

        if(*e == 0){
            r = 1;
        }
    }

    return r;
}