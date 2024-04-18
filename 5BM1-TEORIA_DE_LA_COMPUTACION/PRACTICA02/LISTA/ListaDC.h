#ifndef LISTADOBLEC_H
#define LISTADOBLEC_H

#include <iostream>
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
    struct Nodo* nodoAnterior;
    struct Nodo* nodoSiguiente;
    int posicion;
};

typedef struct Nodo* Lista;

Lista CrearLista(int*);
void InsertarIzquierda(Lista&, Dato, int*);
void InsertarDerecha(Lista&, Dato, int*);
void InsertarPosicion(Lista, Dato, int, int*);
Dato ExtraerIzquierda(Lista, int*);
Dato ExtraerDerecha(Lista, int*);
Dato ExtraerPosicion(Lista, int, int*);
bool IsEmpty(Lista, int*);
void UpdatePosicion(Lista, struct Nodo*);
void ResetPosicion(Lista, struct Nodo*);
int RecorrerLista(Lista, struct Nodo*);
void ImprimirLista(Lista, int*);
void VaciarLista(Lista, int*);
void DestruirLista(Lista, int*);
void CopiarLista(Lista, int*);

#endif // LISTADOBLEC_H