//Serie
//José Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>

void generar(int* , float*);
void imprimir(int* , float*);

int main(){
    int n=0;

    printf("Ingrese el numero de elementos que desee dar a la serie: ");
    scanf("%i" , &n);

    float* serie = (float*) calloc( (n+1) , sizeof(float) );

    generar(&n , serie);
    imprimir(&n , serie);

    return 0;
}

void generar(int* n , float* s){
    float suma= 0;

    for(int i = 0; i < *n ; i++){
        if( (i%2 != 0) || i==0 )
            s[i] = ((float)1 / (i+1)) ;

        if( (i%2 == 0) && (i != 0))
            s[i] = - ((float)1 / (i+1));
        
        suma = (float)s[i] + suma;
        printf("%f\t" , s[i]);
    }
    s[*n] = suma;
}

void imprimir(int* n , float* s){

    printf("\nla serie queda asi:\n");

    for(int i = 0; i < *n ; i++){
        if( (i%2 != 0)){
            if(i==0)
                printf("1 +\t");
            if(i != 0)
                printf("1/%i -\t" , (i+1) );
        }

        if(i%2 == 0)
            printf("1/%i +\t" , (i+1) );
        
    }
    printf("\nLa suma de todos los terminos de la serie da %f", s[*n]);
}