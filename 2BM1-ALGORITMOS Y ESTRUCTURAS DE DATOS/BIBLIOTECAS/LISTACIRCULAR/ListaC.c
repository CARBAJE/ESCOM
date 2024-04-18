#include "ListaC.h"

Lista CrearLista(int* error){
    Lista l = (Lista) calloc(1,sizeof(struct Nodo*));
    if(l == NULL){
        perror("NO HAY SUFICIENTE ESPACIO PARA LA CREACION DE LA LISTA. LIBERE MEMORIA");
        *error = -2;
        return NULL;
    }
    else{
        *l = NULL;
        return l;
    }
}
void InsertarIzquierda(Lista l, Dato valor,  int* error){
    struct Nodo* nuevo_nodo = (struct Nodo*) calloc (1,sizeof(struct Nodo));
    if(nuevo_nodo == NULL){
        perror("NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACION. LIBERE LA MEMORIA.");
        *error = -1;
    }
    else{
        if(*l == NULL)
            *l = nuevo_nodo;
        nuevo_nodo -> posicion = 0;
        nuevo_nodo -> dato = valor;
        nuevo_nodo -> nodoSiguiente = *l;
        *l = nuevo_nodo;
        printf("VALORES MANDADOS:\nPOS[%d]\tVAL:%d\nPOS[%d]\tVAL:%d\n",(*l)->posicion , (*l)->dato , nuevo_nodo->posicion , nuevo_nodo->dato);
        printf("VALORES EN NODO SIGUIENTE: PO[%d]\tVAL:%d\n", nuevo_nodo->nodoSiguiente->nodoSiguiente->posicion , nuevo_nodo->nodoSiguiente->nodoSiguiente->dato);
        UpdatePosicion(l , nuevo_nodo);
    }
}
void InsertarDerecha(Lista l, Dato valor, int* error){
    struct Nodo* nuevo_nodo = (struct Nodo*) calloc(1 , sizeof(struct Nodo));
    if(nuevo_nodo == NULL){
        perror("NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACION. LIBERE LA MEMORIA.");
        *error = -1;
    }
    else if(*l == NULL){
        InsertarIzquierda(l, valor, error);
    }
    else{
        struct Nodo* aux = *l;
        do{
            aux = aux -> nodoSiguiente;
        }while(aux->nodoSiguiente != *l);
        if(aux->nodoSiguiente == *l){
            printf("EL AUXILIAR ES IGUAL AL FINAL DE LA LISTA\n");
        }

        nuevo_nodo -> dato = valor;
        nuevo_nodo -> posicion = (aux->posicion) +1;
        nuevo_nodo -> nodoSiguiente = *l;
        aux -> nodoSiguiente = nuevo_nodo; 
    }
}
void InsertarPosicion(Lista l, Dato valor, int posicion , int* error){
    if(posicion == 0 || *l == NULL)
        InsertarIzquierda(l , valor , error);
    if(posicion == RecorrerLista(l , *l))
        InsertarDerecha(l , valor, error);
    if(posicion > 0 && posicion < RecorrerLista(l , *l)){
        struct Nodo* aux1 =*l;
        struct Nodo* aux2;
        struct Nodo* nuevo_nodo = (struct Nodo*) calloc(1, sizeof(struct Nodo));
        if(nuevo_nodo == NULL){
            perror("NO HAY SUFICIENTE MEMORIA PARA GUARDAR LA INFORMACION. LIBERE MEMORIA");
            *error = -1;
        }
        else{
            nuevo_nodo -> dato = valor;
            nuevo_nodo -> posicion = posicion;
            do{
                aux2 = aux1;
                aux1 = aux1->nodoSiguiente;
            }while(aux1->posicion != posicion);
            nuevo_nodo -> nodoSiguiente = aux1;
            aux2 -> nodoSiguiente = nuevo_nodo;
            UpdatePosicion(l , aux1);
            *error = 0;
        }
    }  
}
Dato ExtraerIzquierda(Lista l, int* error){
    if(!IsEmpty(l, error)){
        struct Nodo* aux1 = *l;
        Dato dato_extraido;
        dato_extraido = aux1 -> dato;
        *l = aux1 -> nodoSiguiente;
        aux1 -> nodoSiguiente = NULL;
        free(aux1);
        ResetPosicion(l , *l);
        return dato_extraido;
    }
    else
        puts("INGRESE DATOS A LA LISTA. ESTADO DE LISTA VACIA");

}
Dato ExtraerDerecha(Lista l, int* error){
    if(!IsEmpty(l, error)){
        struct Nodo* aux1 = *l;
        struct Nodo* aux2;
        Dato dato_extraido;
        do{
            aux2 = aux1;
            aux1 = aux1->nodoSiguiente;
        }while(aux1->nodoSiguiente != *l);
        dato_extraido = aux1->dato;
        aux2 ->nodoSiguiente = aux1 -> nodoSiguiente;
        aux1 -> nodoSiguiente = NULL;
        free(aux1);
        return dato_extraido;
    }
    else
        puts("INGRESE PRIMERO DATOS A LA LISTA ANTES DE EXTRAER");
}
Dato ExtraerPosicion(Lista l, int posicion, int* error){
    if(!IsEmpty(l , error)){
        Dato dato_extraido;
        if(posicion == 0)
            dato_extraido = ExtraerIzquierda(l , error);
        if(posicion == RecorrerLista(l , *l))
            dato_extraido = ExtraerDerecha(l , error);
        if(posicion > 0 && posicion < RecorrerLista(l , *l)){
            struct Nodo* aux1 =*l;
            struct Nodo* aux2;
            do{
                aux2 = aux1;
                aux1 = aux1->nodoSiguiente;
            }while(aux1->posicion != posicion);
            dato_extraido = aux1 -> dato;
            aux2 -> nodoSiguiente = aux1 -> nodoSiguiente;
            aux1 -> nodoSiguiente = NULL;
            free(aux1);
            ResetPosicion(l , aux2->nodoSiguiente);
            *error = 0;
            return dato_extraido;
        }
    }
    else
        puts("LA LISTA ESTA VACIA. INGRESE PRIMERO DATOS PARA EXTRAER");
}
bool IsEmpty(Lista l, int* error){
    if(*l == NULL){
        *error = -3;
        return true;
    }
    return false;
}
void UpdatePosicion(Lista l, struct Nodo* nodo){
    struct Nodo* aux = nodo;
    printf("VALORES MANDADOS:\nPOS[%d]\tVAL:%d\nPOS[%d]\tVAL:%d\n",(*l)->posicion , (*l)->dato , nodo->posicion , nodo->dato);
    do{
        aux -> posicion += 1;
        aux = aux -> nodoSiguiente;
    }while(aux->nodoSiguiente != *l);
}
void ResetPosicion(Lista l, struct Nodo* nodo){
    struct Nodo* aux = nodo;
    do{
        aux -> posicion -= 1;
        aux = aux -> nodoSiguiente;
    }while(aux->nodoSiguiente != *l);
}
int RecorrerLista(Lista l, struct Nodo* nodo){
    int i=0;
    struct Nodo* aux = nodo;
    do{
        aux = aux -> nodoSiguiente;
    }while(aux->nodoSiguiente != *l);
    return i;
}
void ImprimirLista(Lista l, int* error){
    struct Nodo* aux = *l;
    do{
        printf("Valor en posicion[%d]: %d", aux->posicion , aux->dato);
        aux = aux -> nodoSiguiente;
    }while(aux != *l);
}
void VaciarLista(Lista l, int* error){
    while(*l != NULL){
        Dato dato_extraido = ExtraerIzquierda(l, error);
        printf("EL valor extraido es: %d", dato_extraido);
    }
}
void DestruirLista(Lista l, int* error){
    if(IsEmpty(l,error))
        free(l);
    else
        puts("VACIE LA LISTA PRIMERO");
}
//void CopiarLIsta(Lista , int*);