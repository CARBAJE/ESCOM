/* COLA DINÁMICA */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Nodo{
    int valor;  //Puede ser otro TDA
    struct Nodo* nodoSiguiente;
};
//Nivel 3
typedef struct{
    struct Nodo* cabe;
    struct Nodo* final;
    int cursor;
}Cola;

Cola* crearCola(int* error);
bool ColaIsEmpty(Cola q, int* error);
void ColaCima(Cola q, int* error);
void EnColar(Cola *q, int* error, struct Nodo dato); 
void DesenColar(Cola *q, int * error,struct Nodo *datoExtraido);
void vaciarCola(Cola *q, int* error);
void destruirCola(Cola *q, int* error);
void recorrerCola(Cola *q, int *error);  
void buscarEnCola(Cola *q, int * error, struct Nodo dato); 
void SelectionSort(Cola *q, int * error);