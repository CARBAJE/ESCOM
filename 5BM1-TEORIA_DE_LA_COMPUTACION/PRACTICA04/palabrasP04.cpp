#include "PRACTICA04.h"
//std::vector<std::pair<std::string, std::pair<int, int>>>
ListaPalabras encontrarPalabrasReservadas(const AutomataP04& automataP04, const ListaPalabras& palabrasEnArchivo) {
    ListaPalabras palabras_encontradas;
    std::unordered_set<int> estados_finales(automataP04.EstadoP04Final.begin(), automataP04.EstadoP04Final.end());
    std::ofstream archivo("rutaAutomata.txt");
    int posicion = automataP04.EstadoP04Inicial;
    bool transicionEncontrada = false;

    for (const auto& palabra : palabrasEnArchivo.lista) {
        const std::string& palabraActual = palabra.cadena;
        for(int i = 0 ; i < palabraActual.size() ; i++){
            transicionEncontrada = false;
            for(auto& transicion : automataP04.grafo[posicion].transiciones){
                if (palabraActual[i] == transicion.first) {
                    archivo << 'q' << posicion << "--";
                    archivo << '{' << palabraActual[i] << '}' << std::endl;
                    posicion = transicion.second;
                    transicionEncontrada = true;
                }
            }
            if(!transicionEncontrada){
                break;
            }
        }
        if(estados_finales.count(posicion)){
            palabras_encontradas.lista.push_back(palabra);
        }
        posicion = automataP04.EstadoP04Inicial;
    }
    archivo.close();

    return palabras_encontradas;
}
