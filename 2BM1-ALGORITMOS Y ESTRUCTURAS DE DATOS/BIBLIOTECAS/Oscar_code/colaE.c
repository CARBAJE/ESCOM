#include "cola.h"
int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    Cola *q=crearCola(&error);
    struct Nodo dato;
    struct Nodo datoBuscar;
    datoBuscar.valor=3;
    puts("¿Cuantos valores quieres agregar a la cola?");
    fflush(stdin);
    scanf("%d",&cantidadDatos);
   for(int i=0; i<cantidadDatos; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&dato.valor);
        Encolar(q,&error,dato);
    }
    SelectionSort();
    colaCima(*q,&error);
    recorrerCola(q,&error); 
    buscarEnCola(q,&error,datoBuscar); 
    vaciarCola(q,&error); //para comprobar modifica la funcion de vaciar cola para que imprima el dato extraido :)
    return error;
}