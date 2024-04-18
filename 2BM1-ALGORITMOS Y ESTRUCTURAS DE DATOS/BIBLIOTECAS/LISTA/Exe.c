#include "ListaC.h"

int main(int argc , char** argv){
    int error = 0;
    CrearLista(&error);
    printf("Estado del error: %i", error);
    return 0;
}