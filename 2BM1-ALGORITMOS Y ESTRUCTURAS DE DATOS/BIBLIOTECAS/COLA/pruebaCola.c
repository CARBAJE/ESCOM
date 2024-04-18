#include "Cola.h"

int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    Cola *c=CrearCola(&error);
    struct Nodo dato;
    puts("¿Cuantos valores quieres agregar a la cola?");
    fflush(stdin);
    scanf("%d",&cantidadDatos);
    for(int i=0; i<cantidadDatos; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&dato.dato);
        Encolar(c, dato, &error);
    }
    ConsultarHead(*c, &error);
    VaciarCola(c ,&error);
    return error;
}
