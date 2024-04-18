#include "ListaDDoble.h"

void InsertarDerecha(Lista l , struct Nodo* nodo , Dato valor , int* error){
    if(*l == NULL){
        InsertarIzquierda(l , nodo , valor , error);
    }
    else{
        nodo = (struct Nodo*) calloc (1 , sizeof(struct Nodo));
        if(nodo != NULL){ 
            struct Nodo* aux = *l;
            nodo -> dato = valor;
            nodo -> sig = NULL;
            while(aux -> sig != NULL){
                aux = aux -> sig;
            }
            nodo -> ant = aux;
            aux -> sig = nodo;
            nodo -> posicion = (aux -> posicion) + 1;
            *error = 0;
        }
        else{
            perror("NO HAY SUFICIENTE MEMORIA");
            *error = -2;
        }
    }
}