#include "pila.h"

int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    Pila *p=CrearPila(&error);
    struct Nodo dato;
    puts("¿Cuantos valores quieres agregar a la pila?");
    fflush(stdin);
    scanf("%d",&cantidadDatos);
    for(int i=0; i<cantidadDatos; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&dato.dato);
        Apilar(p, dato, &error);
    }
    ConsultarCima(*p, &error);
    VaciarPila(p ,&error);
    return error;
}
