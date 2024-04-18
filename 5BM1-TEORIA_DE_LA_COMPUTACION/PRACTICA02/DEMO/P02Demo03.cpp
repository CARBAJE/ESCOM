#include <iostream>
#include <fstream>
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

int main() {
    Estado estadoQ0 = {0, {{'0', 0}, {'0', 1}, {'1', 0}}};
    Estado estadoQ1 = {1, {{'1', 2}}};
    Estado estadoQ2 = {2, {}};

    Automata automata = {{estadoQ0, estadoQ1, estadoQ2}, 0, 3, 2};

    std::string cadena;
    std::cout << "Ingrese una cadena binaria: ";
    std::cin >> cadena;

    auto rutas = encontrarRutas(automata, cadena, 0, 0, {});

    std::ofstream archivo("rutas.txt");
    if (archivo.is_open()) {
        if (!rutas.empty()) {
            archivo << "Se encontraron las siguientes rutas para la cadea <<"<<cadena<<">>:\n";
            for(auto& ruta : rutas) {
                archivo << "Ruta: ";
                for(int i = ruta.size() - 1; i >= 0; --i) {
                    archivo << 'Q' << ruta[i];
                    if(i != 0) archivo << " -> ";
                }
                archivo << "\n";
            }
            std::cout << "Se han guardado las rutas en el archivo 'rutas.txt'.\n";
        } else {
            std::cout << "No se encontraron rutas."<<std::endl;
            archivo << "No se encontraron rutas.\n";
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo para escribir las rutas.\n";
    }

    return 0;
}
