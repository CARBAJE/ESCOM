#include "ListaC.h"

Lista CrearLista(int* error){
    Lista l = (Lista) calloc (1, sizeof(struct Nodo*));
    if(l == NULL){
        perror("NO HAY SUFICIENTE ESPACIO PARA CREAR LA LISTA. LIBERE MEMORIA");
        *error =-2;
        return NULL;
    }
    else{
        *l = NULL;
        *error = 0;
        return l;
    }
}
void InsertarIzquierda(Lista l , Dato valor ,  int* error){
    struct Nodo* nodo = (struct Nodo*) calloc(1, sizeof(struct Nodo));
    if(nodo == NULL){
        perror("NO HAY SUFICIENTE ESPACIO PARA ALMACENAR LA INFORMACIoN. LIBERE MEMORIA");
        *error =-1;
    }
    else{
        nodo->posicion = 0;
        nodo->dato = valor;
        if(*l == NULL){
            *l = nodo;
            (*l)->nodoSiguiente = *l;
        }
        else{
            struct Nodo* aux = UltimoNodo(l , error);
            nodo->nodoSiguiente = *l;
            aux->nodoSiguiente = nodo;
            *l = nodo;
            UpdatePosicion(l , nodo->nodoSiguiente);
        }
        *error = 0;
    }
}
void InsertarDerecha(Lista l, Dato valor,  int* error){
    struct Nodo* nodo = (struct Nodo*) calloc(1, sizeof(struct Nodo));
    if(nodo == NULL){
        perror("NO HAY SUFICIENTE ESPACIO PARA ALMACENAR LA INFORMACIoN. LIBERE MEMORIA");
        *error =-1;
    }
    else{
        if(*l == NULL)
            InsertarIzquierda( l, valor, error);
        else{
            struct Nodo* aux = UltimoNodo(l, error);
            nodo->posicion = (aux->posicion)+1;
            nodo->dato = valor;
            nodo->nodoSiguiente = aux->nodoSiguiente;
            aux->nodoSiguiente = nodo;
            *error = 0;
        }
    }
}
void InsertarPosicion(Lista l, Dato valor, int posicion, int* error){
    if(posicion == 0 || *l==NULL)
        InsertarIzquierda(l, valor, error);
    struct Nodo* ultimo = UltimoNodo(l, error);
    if( (posicion > ultimo->posicion  || ultimo->posicion == 0) && *l != NULL)
        InsertarDerecha(l, valor , error);
    if(posicion > 0 && posicion < ultimo->posicion && *l != NULL){
        struct Nodo* aux1 = *l;
        struct Nodo* aux2 = NULL;
        struct Nodo* nodo = (struct Nodo*) calloc(1, sizeof(struct Nodo));
        if(nodo != NULL){
            nodo->dato = valor;
            nodo->posicion = posicion;
            printf("LLEGUE HASTA AQUI\n");
            while(aux1->posicion < posicion){
                aux2 = aux1;
                aux1 = aux1->nodoSiguiente;
            }
            printf("LLEGUE HASTA AQUI\n");
            aux2->nodoSiguiente = nodo;
            nodo->nodoSiguiente = aux1;
            UpdatePosicion(l , nodo);
            *error = 0;
        }
        else{
            perror("NO HAY SUFICIENTE ESPACIO PARA ALMACENAR LA INFORMACIoN. LIBERE MEMORIA");
            *error =-1;
        }
    }
}
Dato ExtraerIzquierda(Lista l, int* error){
    if(*l != NULL){
        Dato extraido = (*l)->dato;
        struct Nodo* aux = *l;
        struct Nodo* aux2 = UltimoNodo(l , error);
        *l = (*l) -> nodoSiguiente;
        aux->nodoSiguiente = NULL;
        aux2 ->nodoSiguiente = *l;
        free(aux);
        ResetPosicion(l , *l);
        *error = 0;
        return extraido;
    }
    else{
        perror("NO HAY DATOS A EXTRAER, INGRESE DATOS");
        *error = -2;
    }
}
Dato ExtraerDerecha(Lista l, int* error){
    if(*l != NULL){
        struct Nodo* aux = UltimoNodo(l , error);
        Dato extraido = aux->dato;
        struct Nodo* aux2 = *l;
        while(aux2->nodoSiguiente != aux)
            aux2 = aux2 -> nodoSiguiente;
        aux2 -> nodoSiguiente = *l; 
        free(aux);
        *error = 0;
        return extraido;
    }
    else{
        perror("NO HAY DATOS A EXTRAER, INGRESE DATOS");
        *error = -2;
    }
}
Dato ExtraerPosicion(Lista l, int posicion, int* error){

}
bool IsEmpty(Lista l, int* error){

}

void UpdatePosicion(Lista l , struct Nodo* nodo){
    struct Nodo* aux = nodo;
    while(aux != (*l)){
        aux -> posicion += 1;
        aux = aux->nodoSiguiente;
    }
}
void ResetPosicion(Lista l, struct Nodo* nodo){
    struct Nodo* aux = nodo;
    do{
        aux -> posicion -= 1;
        aux = aux->nodoSiguiente;
    }while(aux != (*l));
}
int RecorrerLista(Lista l, struct Nodo* nodo){

}
struct Nodo* UltimoNodo(Lista l, int* error){
    struct Nodo* aux = (*l)->nodoSiguiente;
    while(aux->nodoSiguiente != *l){
        aux = aux->nodoSiguiente;
    }
    return aux;
}
void ImprimirLista(Lista l, int* error){
    struct Nodo* aux = *l;
    do{
        printf("POS[%i]\tVALOR: %i\n",aux->posicion , aux->dato);
        aux = aux->nodoSiguiente;
    }while(aux != *l);
}
void VaciarLista(Lista l, int* error){

}
void DestruirLista(Lista l, int* error){

}
//void CopiarLista(Lista l, int* error);