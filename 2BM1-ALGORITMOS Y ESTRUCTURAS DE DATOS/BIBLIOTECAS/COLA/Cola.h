//COLA DINAMICA
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

 /*
                TABLA DE ERRORES
    VARIABLE    ESTADO      DESCRIPCIÓN 
    error       -1          NODO NULO
    error       -2          COLA NULA
    error       -3          COLA VACIA
    error       0           SIN ERROR
 */

typedef int Dato;

struct Nodo{
    Dato dato;
    struct Nodo* nodo_siguiente;
};

typedef struct{
    struct Nodo* cabecera;
    struct Nodo* final;
    int cursor;
}Cola;

Cola* CrearCola(int*);
bool IsEmpty(Cola , int*);
void ConsultarHead(Cola , int*);
void Encolar(Cola* , struct Nodo, int*);
void Desencolar(Cola* , struct Nodo* , int*);
void VaciarCola(Cola* , int*);
void DestruirCola(Cola* , int*);
void RecorrerCola(Cola* , int*);