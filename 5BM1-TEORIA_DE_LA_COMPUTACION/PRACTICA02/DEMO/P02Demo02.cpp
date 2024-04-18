#include <iostream>
#include <vector>
#include <string>

struct Estado {
    int id;
    std::vector<std::pair<char, int>> transiciones; // Transiciones: (símbolo, estado_destino)
};

struct Automata {
    std::vector<Estado> grafo;
    int posicion;
    int numEstados;
    int estadoFinal;
};

// Función para verificar si una cadena cumple con las condiciones del autómata
bool verificarCadena(const Automata& automata, const std::string& cadena, int i, int posicion) {
    //std::cout << "Debug: Verificando en el estado " << posicion << " con el símbolo " << cadena[i] << std::endl;

    if(i >= cadena.size()){ // Si hemos alcanzado el final de la cadena
        if(automata.estadoFinal == posicion) {
            return true;
        } else {
            return false;
        }
    }

    for(auto transicion : automata.grafo[posicion].transiciones){
        //std::cout << "Debug: Evaluando transición con símbolo " << transicion.first << " hacia el estado " << transicion.second << " con i = " << i << std::endl;
        if(cadena[i] == transicion.first){
            // Llamada recursiva solo si encontramos una transición válida
            if(verificarCadena(automata, cadena, i+1, transicion.second)) {
                return true;
            }
        }
    }

    // Si ninguna transición es válida
    return false;
}


int main() {
    Estado estadoQ0 = {0, {{'0', 0}, {'0', 1}, {'1', 0}}};
    Estado estadoQ1 = {1, {{'1', 2}}};
    Estado estadoQ2 = {2, {}};

    Automata automata = {{estadoQ0, estadoQ1, estadoQ2}, 0, 3, 2};

    std::string cadena = "01";
    std::cout << "Ingrese una cadena binaria: ";
    std::cin >> cadena;

    if (verificarCadena(automata, cadena, 0, 0)) {
        std::cout << "La cadena cumple con las condiciones del automata." << std::endl;
    } else {
        std::cout << "La cadena no cumple con las condiciones del automata." << std::endl;
    }

    return 0;
}
