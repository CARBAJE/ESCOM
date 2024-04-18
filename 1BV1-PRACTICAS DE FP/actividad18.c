//Imprimir cada termino de la serie "n2+(n-1)2+(n-2)2+...(3)2+(2)2+(1)2" y su suma.
//Jose Emiliano Carrillo Barreiro.

#include <stdio.h>
void invertir(int , int);
void serieN(int n , int *);
void datos(int n, int );

int main(){
    int n , x = 0;
    int option = 0;

    printf("Ingrese un numero: ");
    scanf("%d" , &n);
    printf(" Opcion '1': Invertirlo.");
    printf("\n Opcion '2': Hacer una serie cuadratica hasta 1");
    printf("\n Opcion '3': Hacer una serie de pares hasta su numero.");
    printf("\n Indique que quiere hacer con este numero: ");

    while(option < 1 || option > 3){
        scanf("%d" , &option);
        if(option < 0 || option > 3)
            printf("Ingrese un numero en el rango solicitado. Vuelva a intentarlo: ");
    }

    switch(option){
        case 1:
            invertir(n , x);
        break;
        case 2:
            serieN(n , &x);
        break;
        case 3:
            datos(n , x);
        break;
    }
    return 0;
}

void invertir(int n , int inv){
    if( n == 0)
        printf("%d" , inv);
    if( n != 0 ){
        int r = n % 10;
        inv = (inv * 10) + r;
        invertir( n / 10 , inv);
    }
}

void serieN(int n , int *suma){
    if(n == 1){
        printf("%d" , n);
        *suma = *suma + 1;
        printf("\nLa suma es: %d" , *suma);
    }
    if(n != 1){
        printf("%d ," , n*n);
        *suma = *suma + (n*n);
        serieN( n - 1 , suma);
    }
}

void datos(int n , int i){
    if(i == n || i == n+1)
        printf("%d, ", n);
    else{
        printf("%d, ", i);
        datos( n , i + 2);
    }
}