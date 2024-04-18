#include "PRACTICA02.h"

//Función para generar el autómata y definir sus trancisiones
Automata crearAutomata(){
    Automata nuevo;
    nuevo.grafo = crearEstado();
    nuevo.numEstados = 3;
    nuevo.estadoFinal = 2;

    return nuevo;
}
//Función para generar el autómata y definir sus trancisiones
std::vector<Estado> crearEstado(){
    Estado estadoQ0 = {0, {{'0', 0}, {'0', 1}, {'1', 0}}};
    Estado estadoQ1 = {1, {{'1', 2}}};
    Estado estadoQ2 = {2, {}};

    std::vector<Estado> grafo = {estadoQ0, estadoQ1, estadoQ2};

    return grafo;
}