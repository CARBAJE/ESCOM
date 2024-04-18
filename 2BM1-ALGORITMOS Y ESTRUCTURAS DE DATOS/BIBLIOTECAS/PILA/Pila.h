 //PILA DINAMICA
 #include <stdio.h>
 #include <stdbool.h>
 #include <stdlib.h>

 /*
                TABLA DE ERRORES
    VARIABLE    ESTADO      DESCRIPCIÓN 
    error       -1          NODO NULO
    error       -2          PILA NULA
    error       -3          PILA VACIA
    error       0           SIN ERROR
 */

 typedef int Dato;

 struct Nodo{
    Dato dato;
    struct Nodo* nodo_anterior;
 };

 typedef struct{
    struct Nodo* cima;
    int cursor;
 }Pila;

Pila* CrearPila(int*);
void ConsultarCima(Pila , int*);
void Apilar(Pila* , struct Nodo, int*);
void Desapilar(Pila* , struct Nodo*, int*);
bool IsEmpty(Pila , int*);
void VaciarPila(Pila* , int*);
void DestruirPila(Pila* , int*);