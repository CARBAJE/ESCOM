#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "pilaA.h"

typedef struct{
    int valor;
    char operacion[100];
} Dato;

//TDA Arbol BST
typedef struct Nodo{
    Dato info;
    struct Nodo* der;
    struct Nodo* izq;
    Pila p;
}Nodo_de_Arbol_BST;

typedef Nodo_de_Arbol_BST* Arbol;

Arbol crearNodo(Dato valorUsuario);
void nuevoArbol(Arbol* raiz, Dato valorUsuario, Arbol hIzq, Arbol hDer);
void eliminarArbol(Arbol* raiz);
void eliminarNodoArbol(Arbol* raiz, Dato valorEliminar);
void insertarNodoArbol(Arbol* raiz, Dato valorUsuario);
void buscarNodo(Arbol* raiz, Dato elementoBuscado, Arbol* nodoEncontrado);
void preOrden(Arbol raiz);
void posOrden(Arbol raiz);
void inOrden(Arbol raiz);
void reemplazar(Arbol* raiz);
void cantidadHojas(Arbol raiz , int* count);
void alturaArbol(Arbol* raiz, Dato elementoBuscado, Arbol* nodoEncontrado , int* count);