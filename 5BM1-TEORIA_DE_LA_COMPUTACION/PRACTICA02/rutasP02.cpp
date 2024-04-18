#include "PRACTICA02.h"

std::vector<std::vector<int>> encontrarRutas(const Automata& automata, const std::string& cadena, int i, int posicion, std::vector<int> ruta_actual){
    std::vector<std::vector<int>> rutas;

    if(i >= cadena.size()){ // Si hemos alcanzado el final de la cadena
        if(automata.estadoFinal == posicion) {
            ruta_actual.push_back(posicion);
            rutas.push_back(ruta_actual);
        }
        return rutas;
    }

    for(auto transicion : automata.grafo[posicion].transiciones){
        if(cadena[i] == transicion.first){
            // Llamada recursiva para explorar la transición
            auto nuevas_rutas = encontrarRutas(automata, cadena, i+1, transicion.second, ruta_actual);
            for(auto& ruta : nuevas_rutas) {
                ruta.push_back(posicion);
                rutas.push_back(ruta);
            }
        }
    }

    return rutas;
}