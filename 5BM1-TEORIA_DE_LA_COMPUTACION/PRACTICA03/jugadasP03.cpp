#include "PRACTICA03.h"

std::vector<std::vector<int>> encontrarJugadas(const Tablero& tablero, const std::string& cadena, int i, int posicion, std::vector<int> jugada_actual){
    std::vector<std::vector<int>> jugadas;

    if(i >= cadena.size()){ // Si hemos alcanzado el final de la cadena
        if(tablero.casillaFinal == posicion) {
            jugada_actual.push_back(posicion);
            jugadas.push_back(jugada_actual);
        }
        return jugadas;
    }

    for(auto transicion : tablero.grafo[posicion].transiciones){
        if(cadena[i] == transicion.first){
            // Llamada recursiva para explorar la transición
            auto nuevas_jugadas = encontrarJugadas(tablero, cadena, i+1, transicion.second, jugada_actual);
            for(auto& jugada : nuevas_jugadas) {
                jugada.push_back(posicion);
                jugadas.push_back(jugada);
            }
        }
    }

    return jugadas;
}