#include "Pila.h"

Pila* CrearPila(int* error){
    Pila* nueva_pila = (Pila*) calloc (1, sizeof(Pila));
    if(nueva_pila == NULL)
        perror("NO HAY SUFICIENTE ESPACIO PARA CREAR UNA PILA. LIBERE MEMORIA\n");
    else{
        nueva_pila->cima = NULL;
        nueva_pila->cursor = 0;
        return nueva_pila;
    }
    return NULL;
}
void ConsultarCima(Pila p, int* error){
    if(IsEmpty(p , error))
        puts("INGRESE PRIMERO DATOS A LA LISTA PARA DESAPILAR");
    else{
        printf("Dato de la cima es: %i\n", p.cima->dato);
    }
}
void Apilar(Pila* p, struct Nodo nuevo_nodo, int* error){
    struct Nodo* aux = (struct Nodo*) calloc(1, sizeof(struct Nodo));
    if(aux != NULL){
        aux -> dato = nuevo_nodo.dato;
        aux -> nodo_anterior = p->cima;
        p->cima = aux;
        p->cursor++;
        *error = 0;
    }
    else{
        perror("NO HAY SUFICIENTE ESPACIO PARA ALMACENAR LA INFORMACION. LIBERE MEMORIA\n");
        *error = -1;
    }
}
void Desapilar(Pila* p, struct Nodo* nodo_extraido, int* error){
    if(IsEmpty(*p , error))
        puts("INGRESE PRIMERO DATOS A LA LISTA PARA DESAPILAR");
    else{
        struct Nodo* aux = p->cima;
        nodo_extraido -> dato = aux ->dato;
        p->cima = p->cima->nodo_anterior;
        aux -> nodo_anterior = NULL;
        p->cursor--;
        free(aux);
        *error = 0;
    }
}
bool IsEmpty(Pila p, int* error){
    if(p.cima == NULL){
        *error = -3;
        return true;
    }
    else{
        *error = 0;
        return false;
    }
}
void VaciarPila(Pila* p, int* error){
    while(!IsEmpty(*p , error)){
        struct Nodo nodo;
        Desapilar(p, &nodo, error);
        printf("Valor extraido: %d\n", nodo.dato);
        *error = 0;
    }
}
void DestruirPila(Pila* p, int* error){
    if(IsEmpty(*p , error))
        free(p);
    else
        printf("PRIMERO VACIE LA PILA\n");
}