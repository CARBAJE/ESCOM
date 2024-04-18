#include "ListaC.h"

void CrearLista(int* error){
    Lista l;
    *l = NULL;
    int tam = 0;
    printf("Ingrese el numero de nodos que compongan la lista: ");
    scanf("%i", &tam);
    if(tam > 0){
        MenuLista(l , tam, error);
    }
    else{
        printf("Ingrese un valor positivo mayor a cero.\n");
        CrearLista(error);
    }
}

void InsertarIzquierda(Lista l , Dato valor , int* error){
    struct Nodo* nodo = (struct Nodo*) calloc(1 , sizeof(struct Nodo));
    struct Nodo* aux = *l;
    if(nodo != NULL){
        nodo -> dato = valor;
        nodo -> nodoSiguiente = aux;
        nodo -> posicion = 0;
    }
    *l = nodo;
    if(aux  != NULL){
        UpdatePosicion(aux , l);
    }
    else{
        nodo -> posicion = 0;
    }
    *error = 0;
}

void InsertarDerecha(Lista l , Dato valor , int* error){
    if(*l == NULL){
        InsertarIzquierda(l , valor , error);
    }
    else{
        struct Nodo* nodo = (struct Nodo*) calloc (1 , sizeof(struct Nodo));
        if(nodo != NULL){ //Manera de no tener un if dentro de otro if¿?
            struct Nodo* aux = *l;
            nodo -> dato = valor;
            nodo -> nodoSiguiente = *l;
            while(aux -> nodoSiguiente != *l){
                aux = aux -> nodoSiguiente;
            }
            aux -> nodoSiguiente = nodo;
            nodo -> posicion = (aux -> posicion) + 1;
        }
        else{
            perror("NO HAY SUFICIENTE MEMORIA\n");
            *error = -2;
        }
    }
    *error = 0;
}

void InsertarPosicion(Lista l , Dato valor, int pos, int* error){
    int flag = -1;
    struct Nodo* aux = *l;
    struct Nodo* aux2;
    if(*l != NULL){
        flag = 0;
    }
    else if(*l == NULL || pos == 0 && flag == 0){
        InsertarIzquierda(l , valor , error);
    }
    if(RecorrerLista(aux) == pos && flag == 0){
        InsertarDerecha(l , valor , error);
        flag--;
    }
    if(RecorrerLista(aux) > pos && pos > 0 && flag == 0){
        struct Nodo* nodo = (struct Nodo*) calloc (1 , sizeof(struct Nodo));
        while(aux -> posicion  != pos){
            aux2 = aux;
            aux = aux -> nodoSiguiente;
        }
        nodo -> dato = valor;
        nodo -> nodoSiguiente = aux;
        nodo -> posicion = aux -> posicion;
        aux2 -> nodoSiguiente = nodo;
        UpdatePosicion(aux , l);
    }
    *error = 0; 
}

Dato ExtraerIzquierda(Lista l , int* error){
    if(IsEmpty(l , error)){
        perror("NO HAY DATOS A EXTRAER\n");
        *error = -3;
    }
    else{
        struct Nodo* aux = *l;
        Dato valor_e = aux -> dato;
        *l = aux -> nodoSiguiente;
        aux -> nodoSiguiente = NULL;
        //NUevo codigo para circular
        aux = NULL;
        struct Nodo* aux2 = *l;
        while(aux2 -> nodoSiguiente != NULL){
            aux2 = aux2 -> nodoSiguiente;
        }
        aux2 -> nodoSiguiente = *l;
        //Fin del nuevo codigo
        free(aux);
        ResetPosicion(*l);
        *error = 0;
        return valor_e;
    }
}

Dato ExtraerDerecha(Lista l, int* error){
    if(IsEmpty(l , error)){
        perror("NO HAY DATOS A EXTRAER\n");
        *error = -3;
    }
    else{
        struct Nodo* aux1 = *l;
        struct Nodo* aux2;
        while(aux1 -> nodoSiguiente != NULL){
            aux2 = aux1;
            aux1 = aux1 -> nodoSiguiente;
        }
        Dato valor_e = aux1 -> dato;
        aux2 -> nodoSiguiente = NULL;
        free(aux1);
        *error = 0;
        return valor_e;
    }
}

Dato ExtraerPosicion(Lista l, int pos, int* error){
    int flag = -1;
    struct Nodo* aux = *l;
    if(IsEmpty(l , error)){
        perror("NO HAY DATOS A EXTRAER\n");
        *error = -3;
    }
    else{
        flag = 0;
    }
    if(pos == 0 && flag == 0){
        ExtraerIzquierda(l , error);
        flag--;
    }
    printf("LLEGUE AQUI\n"); /////////////////////////////////////
    if(RecorrerLista(aux) == pos && flag == 0){
        ExtraerDerecha(l , error);
        flag--;
    }
    printf("LLEGUE AQUI\n"); /////////////////////////////////////
    if(RecorrerLista(aux) > pos && pos > 0 && flag == 0){
        struct Nodo* aux1 = *l;
        struct Nodo* aux2;
        while(aux1 -> posicion != pos){
            aux2 = aux1;
            aux1 = aux1 -> nodoSiguiente;
        }
        Dato valor_e = aux1 -> dato;
        aux2 -> nodoSiguiente = aux1 -> nodoSiguiente;
        aux1 -> nodoSiguiente = NULL;
        ResetPosicion(aux2 -> nodoSiguiente); //NO ESTA RECETEANDO LAS POSICIONES
        free(aux1);       
        *error = 0;
        return valor_e;
    }
}

bool IsEmpty(Lista l , int* error){
    if(*l == NULL){
        *error = -3;
        return true;
    }
    return false;
}

int RecorrerLista(struct Nodo* nodo){
    struct Nodo* aux = nodo;
    int  i;
    for(i = 0 ; aux != NULL ; i++){ // BUCLE INFINITO
        aux = aux -> nodoSiguiente;
        //printf("%i ", i);
    }
    //printf("%i" , i);
    return i;
}

void UpdatePosicion(struct Nodo* nodo , Lista l){
    do{
        nodo -> posicion += 1;
        nodo = nodo -> nodoSiguiente;
    }while(nodo != *l);
}

void ResetPosicion(struct Nodo* nodo){
    struct Nodo* aux = nodo;
    //printf("LLEGUE AQUI"); /////////////////////////////////////
    do{
        nodo -> posicion -= 1;
        nodo = nodo -> nodoSiguiente;
    }while(aux != nodo);
}

void ImprimirLista(Lista l , int* error){
    struct Nodo* aux = *l;
    if(!IsEmpty(l , error)){
        do{
            printf("Datos en poscion[%i]: %i\n", aux->posicion , aux->dato);
            aux = aux -> nodoSiguiente;
        }while(aux  != *l);
    }
    else{
        perror("SIN ELEMENTOS EN LA LISTA A IMPRIMIR");
        *error = -3;
    }
}

void VaciarLista(Lista l , int* error){
    int i = 0;
    while(!IsEmpty(l , error)){
        Dato extraido = ExtraerIzquierda(l , error);
        printf("Dato extraido en la posicion [%i] fue: %i\n", i , extraido);
        i++;
        *error = 0;
    }
}

void DestruirLista(Lista l , int* error){
    if(IsEmpty(l , error)){
        printf("Desteruyendo Lista...\n");
        free(l);
    }
    else if(!IsEmpty(l , error)){
        printf("Libere la informacion antes de destruir la lista.\n");
    }
}