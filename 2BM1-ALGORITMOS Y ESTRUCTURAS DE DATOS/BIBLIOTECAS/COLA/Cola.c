#include "Cola.h"

Cola* CrearCola(int* error){
    Cola* nueva_cola = (Cola*) calloc(1,sizeof(Cola));
    if(nueva_cola == NULL){
        perror("NO HAY SUFICIENTE ESPACIO PARA LA CREACION DE LA COLA. LIBERE MEMORIA.\n");
        *error = -2;
        return NULL;
    }
    else{
        nueva_cola -> cabecera = NULL;
        nueva_cola -> final = NULL;
        nueva_cola -> cursor = 0;
        return nueva_cola;
    }
}
bool IsEmpty(Cola c, int* error){
    if(c.cabecera == NULL && c.final == NULL)
        return true;
    return false;
}
void ConsultarHead(Cola c, int* error){
    if(IsEmpty(c , error))
        puts("INGRESE DATOS A LA COLA");
    else
        printf("Dato en la cabecera: %d\n",c.cabecera->dato);
}
void Encolar(Cola* c, struct Nodo nuevo_nodo, int* error){
    struct Nodo* aux = (struct Nodo*) calloc(1, sizeof(struct Nodo));
    if(aux == NULL)
        perror("NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACIÓN. LIBERE MEMORIA\n");
    else{
        aux->dato = nuevo_nodo.dato;
        aux->nodo_siguiente = NULL;
        if(c->final != NULL)
            c->final->nodo_siguiente = aux;
        c->final = aux;
        if(c->cabecera == NULL)
            c->cabecera = aux;
        c->cursor++;
        *error = 0;
    }
}
void Desencolar(Cola* c, struct Nodo* nodo_extraido, int* error){
    if(IsEmpty(*c,error))
        puts("LA COLA ESTA VACIA.");
    else{
        struct Nodo* aux = c->cabecera;
        nodo_extraido -> dato = aux->dato;
        c->cabecera = c->cabecera->nodo_siguiente;
        aux->nodo_siguiente = NULL;
        c->cursor--;
        free(aux);
        *error = 0;
    }
}
void VaciarCola(Cola* c, int* error){
    while(!IsEmpty(*c, error)){
        struct Nodo nodo;
        Desencolar(c , &nodo , error);
        printf("Dato extraido: %d\n", nodo.dato);
    }
}
void DestruirCola(Cola* c, int* error){
    if(IsEmpty(*c , error))
        free(c);
    else
        puts("PRIMERO VACIE LA COLA");

}
void RecorrerCola(Cola* c, int* error){
    struct Nodo* aux = c->cabecera;
    while(aux != NULL)
        aux = aux->nodo_siguiente;
}