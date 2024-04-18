/*
    PILA DINÁMICA
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
                Tabla de errores
        Variable        Estado      Descripción
        error           -1          Nodo nulo
        error           -2          Pila nula
        error           -3          Pila vacia
        error           0           Sin errores
*/
struct NodoP{
    int valor;  //--> Puede ser otro TDA
    struct NodoP* nodoAnterior;
};
//Nivel 3
typedef struct{
    struct NodoP* cima;
    int cursor;
}Pila;
Pila* crearPila(int* error);
void consultarCima(Pila p, int* error);
void apilar(Pila *p, int* error, struct NodoP dato);//push
void desapilar(Pila *p, int* error,struct NodoP *datoExtraido);
bool isEmpty(Pila p, int* error);
void vaciarPila(Pila *p, int* error);
void destruirPila(Pila* p, int* error);