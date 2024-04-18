#include "ListaC.h"

int main(int argc , char** argv){
    int error = 0;
    MenuLista(&error);
    printf("Estado del error: %i", error);
    return error;
}