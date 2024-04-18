#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <mutex>
#include <thread>

// Definición de la estructura del autómata
struct Automata {
    int numEstados;
    int estadoFinal;
    std::vector<std::vector<std::pair<char, int>>> transiciones; // Transiciones: (símbolo, estado_destino)
};

// Función para encontrar todas las rutas al estado final con respecto a una cadena usando DFS
void encontrarRutasDFS(const Automata& automata, int estadoActual, std::vector<char>& rutaActual, std::vector<std::vector<char>>& rutasFinales, const std::string& cadena, std::vector<bool>& visitado, std::mutex& mtx) {
    visitado[estadoActual] = true;

    // Verificar si la ruta actual coincide con la cadena
    if (rutaActual.size() <= cadena.size() && std::equal(rutaActual.rbegin(), rutaActual.rend(), cadena.rbegin())) {
        std::lock_guard<std::mutex> lock(mtx);
        rutasFinales.push_back(rutaActual);
    }

    // Recorrer todas las transiciones desde el estado actual
    for (const auto& transicion : automata.transiciones[estadoActual]) {
        int estadoDestino = transicion.second;
        char simbolo = transicion.first;

        if (!visitado[estadoDestino]) {
            rutaActual.push_back(simbolo);
            encontrarRutasDFS(automata, estadoDestino, rutaActual, rutasFinales, cadena, visitado, mtx);
            rutaActual.pop_back();
        }
    }

    visitado[estadoActual] = false;
}



// Función para guardar las rutas en un archivo de texto
void guardarRutasEnArchivo(const std::vector<std::vector<char>>& rutasFinales, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        for (const auto& ruta : rutasFinales) {
            for (char simbolo : ruta) {
                archivo << simbolo << " ";
            }
            archivo << std::endl;
        }
        archivo.close();
        std::cout << "Las rutas se han guardado correctamente en el archivo: " << nombreArchivo << std::endl;
    } else {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
    }
}

// Función para verificar si una cadena cumple con el autómata y guardar las rutas en un archivo de texto
void verificarCadena(const Automata& automata, const std::string& cadena, const std::string& nombreArchivo) {
    std::vector<std::vector<char>> rutasFinales; // Almacenará todas las rutas al estado final que terminan en "01"
    std::vector<bool> visitado(automata.numEstados, false); // Para realizar un seguimiento de los estados visitados durante el DFS
    std::mutex mtx; // Mutex para garantizar la exclusión mutua al acceder a las rutas finales

    std::cout << "Rutas encontradas durante la busqueda:" << std::endl;
    for (int estadoInicial = 0; estadoInicial < automata.numEstados; ++estadoInicial) {
        std::vector<char> rutaInicial;
        encontrarRutasDFS(automata, estadoInicial, rutaInicial, rutasFinales, cadena, visitado, mtx);
    }



    for (const auto& ruta : rutasFinales) {
        for (char simbolo : ruta) {
            std::cout << simbolo << " ";
        }
        std::cout << std::endl;
    }

    // Verificar si la cadena lleva al estado final
    bool alcanzaEstadoFinal = false;
    int estadoActual = 0;
    std::cout << "Procesando la cadena:" << std::endl;
    for (char c : cadena) {
        std::cout << "Simbolo actual: " << c << std::endl;
        bool encontrado = false;
        for (const auto& transicion : automata.transiciones[estadoActual]) {
            if (transicion.first == c) {
                estadoActual = transicion.second;
                encontrado = true;
                std::cout << "Transicion: " << estadoActual << std::endl;
                break;
            }
        }
        if (!encontrado) {
            std::cout << "La cadena no cumple con el automata." << std::endl;
            return;
        }
        if (estadoActual == automata.estadoFinal) {
            alcanzaEstadoFinal = true;
            break;
        }
    }

    if (alcanzaEstadoFinal) {
        std::cout << "La cadena cumple con el automata y alcanza el estado final." << std::endl;
        guardarRutasEnArchivo(rutasFinales, nombreArchivo);
    } else {
        std::cout << "La cadena no alcanza el estado final del automata." << std::endl;
    }
}

int main() {
    Automata automata;
    automata.numEstados = 3; // El autómata tiene 3 estados
    automata.estadoFinal = 2; // El estado final es el estado 2
    automata.transiciones.resize(3); // Inicializamos el vector de transiciones con el número de estados

    // Definir las transiciones del autómata
    automata.transiciones[0].push_back({'0', 0}); // Transición de 0 a sí mismo con input 0
    automata.transiciones[0].push_back({'1', 0}); // Transición de 0 a sí mismo con input 1
    automata.transiciones[0].push_back({'0', 1}); // Transición de 0 al estado 1 con input 0
    automata.transiciones[1].push_back({'1', 2}); // Transición de 1 al estado final con input 1

    std::string cadena;
    std::cout << "Ingrese una cadena de caracteres (0 y 1): ";
    std::cin >> cadena;

    std::string nombreArchivo = "rutas.txt";
    verificarCadena(automata, cadena, nombreArchivo);

    return 0;
}