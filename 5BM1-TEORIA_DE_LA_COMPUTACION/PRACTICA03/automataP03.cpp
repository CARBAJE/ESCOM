#include "PRACTICA03.h"

//Función para generar el autómata y definir sus trancisiones
Tablero crearTablero(int numJugador) {
    Tablero nuevo;
    nuevo.grafo = crearCasilla();
    if(numJugador == 0) {
        nuevo.casillaInicial = 0;
        nuevo.casillaFinal = 15;
    } else if(numJugador == 1) {
        nuevo.casillaInicial = 3;
        nuevo.casillaFinal = 12;
    }

    return nuevo;
}
//Función para generar el tablero y definir sus trancisiones
std::vector<Casilla> crearCasilla() {
    Casilla CasillaQ0  = { 0, { {'r', 1}, {'r', 4}, {'w', 5} } }; //
    Casilla CasillaQ01 = { 1, { {'r', 4}, {'r', 6}, {'w', 0}, {'w', 2}, {'w', 5} } };//
    Casilla CasillaQ02 = { 2, { {'r', 1}, {'r', 3}, {'r', 6}, {'w', 5}, {'w', 7} } };//
    Casilla CasillaQ03 = { 3, { {'r', 6}, {'w', 2}, {'w', 7} } };//
    Casilla CasillaQ04 = { 4, { {'r', 1}, {'r', 9}, {'w', 0}, {'w', 5}, {'w', 8} } };//
    Casilla CasillaQ05 = { 5, { {'r', 1}, {'r', 4}, {'r', 6}, {'r', 9}, {'w', 0}, {'w', 2}, {'w', 8}, {'w', 10} } };//
    Casilla CasillaQ06 = { 6, { {'r', 1}, {'r', 3}, {'r', 9}, {'r', 11}, {'w', 2}, {'w', 5}, {'w', 7}, {'w', 10} } };//
    Casilla CasillaQ07 = { 7, { {'r', 3}, {'r', 6}, {'r', 11}, {'w', 2}, {'w', 10} } };//
    Casilla CasillaQ08 = { 8, { {'r', 4}, {'r', 9}, {'r', 12}, {'w', 5}, {'w', 13} } };//
    Casilla CasillaQ09 = { 9, { {'r', 4}, {'r', 6}, {'r', 12}, {'r', 14}, {'w', 5}, {'w', 8}, {'w', 10}, {'w', 13} } };//
    Casilla CasillaQ10 = {10, { {'r', 6}, {'r', 9}, {'r', 11}, {'r', 14}, {'w', 5}, {'w', 7}, {'w', 13}, {'w', 15} } };//
    Casilla CasillaQ11 = {11, { {'r', 6}, {'r', 14}, {'w', 7}, {'w', 10}, {'w', 15} } };//
    Casilla CasillaQ12 = {12, { {'r', 9}, {'w', 8}, {'w', 13} } };//
    Casilla CasillaQ13 = {13, { {'r', 9}, {'r', 12}, {'r', 14}, {'w', 8}, {'w', 10} } };//
    Casilla CasillaQ14 = {14, { {'r', 9}, {'r', 11}, {'w', 10}, {'w', 13}, {'w', 15} } };//
    Casilla CasillaQ15 = {15, { {'r', 11}, {'r', 14}, {'w', 10} } };//

    std::vector<Casilla> grafo = {CasillaQ0, CasillaQ01, CasillaQ02, CasillaQ03, CasillaQ04, CasillaQ05, CasillaQ06,
    CasillaQ07, CasillaQ08, CasillaQ09, CasillaQ10, CasillaQ11, CasillaQ12, CasillaQ13, CasillaQ14, CasillaQ15};

    return grafo;
}