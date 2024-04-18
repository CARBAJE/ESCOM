//LISTA DINAMICA
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
/*
                TABLA DE ERRORES
        VARIABLE    ESTADO  DESCRIPCIÓN
        error       -1      NODO NULO
        error       -2      LISTA NULA
        error       -3      LISTA VACIA
        error       0       SIN ERROR
*/

typedef int Dato;

struct Nodo{
    Dato dato;
    int posicion;
    struct Nodo* sig;
    struct Nodo* ant;
};

typedef struct Nodo** Lista;

void CrearLista(Lista , struct Nodo*, Dato ,int*);
bool IsEmpty(Lista , int*);
void InsertarIzquierda(Lista , struct Nodo* , Dato ,  int*);
void InsertarDerecha(Lista , struct Nodo* , Dato , int*);
void InsertarPosicion(Lista , struct Nodo* , Dato , int , int*);
Dato ExtraerIzquierda(Lista , int*);
Dato ExtraerDerecha(Lista , int*);
Dato ExtraerPosicion(Lista , int , int*);
void UpdatePosicion(struct Nodo*);
void ResetPosicion(struct Nodo*);
int RecorrerLista(struct Nodo*);
void VaciarLista(Lista);
void DestruirLista(Lista , int*);
void CopiarLista(Lista , int*);