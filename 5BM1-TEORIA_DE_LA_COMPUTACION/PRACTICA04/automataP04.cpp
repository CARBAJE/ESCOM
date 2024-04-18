#include "PRACTICA04.h"

//Función para generar el autómata y definir sus trancisiones
AutomataP04 crearAutomataP04(std::string rutaArchivo) {
    AutomataP04 nuevo;
    std::vector<std::vector<int>> TablaEstados = leerCSV(rutaArchivo);
    nuevo.grafo = crearEstadoP04(TablaEstados);

    for(std::vector<int>& fila : TablaEstados){
        if(fila[17] == 1){
            nuevo.EstadoP04Final.push_back(fila[0]);
        }
    }
    nuevo.EstadoP04Inicial = TablaEstados[0][0];
    return nuevo;
}
//Función para generar el AutomataP04 y definir sus trancisiones
std::vector<EstadoP04> crearEstadoP04(std::vector<std::vector<int>> TablaEstados) {
    std::vector<EstadoP04> grafo;
    for(int i = 0 ; i < TablaEstados.size() ; i++){
        grafo.push_back({TablaEstados[i][0], {
                {'e', TablaEstados[i][1]},
                {'s', TablaEstados[i][2]},
                {'c', TablaEstados[i][3]},
                {'u', TablaEstados[i][4]},
                {'l', TablaEstados[i][5]},
                {'a', TablaEstados[i][6]},
                {'t', TablaEstados[i][7]},
                {'d', TablaEstados[i][8]},
                {'i', TablaEstados[i][9]},
                {'n', TablaEstados[i][10]},
                {'r', TablaEstados[i][11]},
                {'o', TablaEstados[i][12]},
                {'f', TablaEstados[i][13]},
                {'m', TablaEstados[i][14]},
                {'z', TablaEstados[i][15]},
                {' ', TablaEstados[i][16]}
            }
        });
    }

    return grafo;
}