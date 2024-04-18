//JOSE EMILIANO CARRILLO BARREIO
//OSCAR HUERTA VILLANUEVA
#include "a10.h"

void Menu(){
    srand(time(NULL));
    int n;
    printf("Ingrese la cantidad de operaciones a realizar(MIN 1 , MAX 18): ");
    fflush(stdin);
    scanf("%i", &n);
    if(n > 18 && n < 0){
        printf("Ingrese una opcion valida.\n");
    }
    printf("\n");
    Arbol raiz = crear();
    InsercionDatos(n-- , raiz);

    int opcion = 0; 
    printf("Ingrese la opcion que desee realizar:\n");
    puts("1-Ejecutar en pre-orden las evaluaciones.");
    puts("2-Ejecutar en pos-orden las evaluaciones. ");
    scanf("%i" , &opcion);
    switch(opcion){
        case 1:
            preorden(raiz);
        break;
        case 2:
            posorden(raiz);
        break;
        case 3: 
            inorden(raiz);
    }
}

Arbol crear(){
    char expresion;
    Dato valor;
    printf("Ingrese la expresion posfija a guardar y realizar:\n");
        fflush(stdin);
        gets(expresion);
        valor.operacion = expresion;
        valor.valor = rand()% 18-1+1;
        Arbol a = crearNodo(valor);
        Arbol raiz = CrearArbol(a ,valor , a-> izq , a-> der);
}

void InsercionDatos(int n , Arbol* raiz){
    if(n > 0){
        char expresion;
        Dato valor;
        printf("Ingrese la expresion posfija a guardar y realizar:\n");
        fflush(stdin);
        gets(expresion);
        valor.operacion = expresion;
        valor.valor = rand()% 18-1+1;
        insertarNodoArbol(raiz , valor);
        InsercionDatos(n-- , raiz);   
    }
}