//estructura
//Jose Emiliano Carrillo Barreiro

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}fechas;

typedef struct{
    char autor[30];
    char titulo[30];
    char editorial[30];
    fechas fecha;

}libros;

void imprimir(libros);

int main(){
    libros libro1;

    printf("Ingrese el autor del libro: ");
    gets(libro1.autor);
    printf("ingrese el titulo del libro: ");
    gets(libro1.titulo);
    printf("ingrese la editorial del libro: ");
    gets(libro1.editorial);
    printf("Ingrese la fecha del libro por dia, mes y año de prestacion.\n");
    printf("Ingrese el dia: ");
    scanf("%i" , &libro1.fecha.dia);
    printf("Ingrese el mes: ");
    scanf("%i" , &libro1.fecha.mes);
    printf("Ingrese el anio: ");
    scanf("%i" , &libro1.fecha.anio);
    
    imprimir(libro1);
    return 0;
}

void imprimir(libros l1){
    printf("Autor: %s\n" , l1.autor);
    printf("Titulo: %s\n" , l1.titulo);
    printf("Editorial: %s\n" , l1.editorial);
    printf("Fecha (dd/mm/aa): %i/%i/%i\n" , l1.fecha.dia , l1.fecha.mes , l1.fecha.anio);
}