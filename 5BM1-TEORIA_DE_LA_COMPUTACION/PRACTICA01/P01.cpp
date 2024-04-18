/*
INSTITUTO POLITECNICO NACIONAL.
ESCUELA SUPERIOR DE COMPUTO.
CICLO: 2024-02.
GRUPO: 5BM1.
ALUMNO: Carrillo Barreiro José Emiliano.
*/

#include "PRACTICA01.h"

// Función para generar combinaciones y calcular unos
void generarCombinaciones(std::ofstream& archivo1, std::ofstream& archivo2, int len, int& i, char simbolo0, char simbolo1, std::string prefix = "", int unos = 0) {
    if (len == 0) {
        return;
    }
    for (char c : {simbolo0, simbolo1}) {
        std::string newPrefix = prefix + c;
        archivo1 << newPrefix << ",";
        archivo2 << i << ',' << unos + (c == simbolo1) << std::endl;
        i++;
        generarCombinaciones(archivo1, archivo2, len - 1, i, simbolo0, simbolo1, newPrefix, unos + (c == simbolo1));
    }
}


void mostrarBarraProgreso(int& progreso, int& total) {
    // Calcular el porcentaje completado
    float porcentaje = (static_cast<float>(progreso) / total) * 100;

    // Imprimir la barra de progreso
    std::cout << "[" << std::setw(3) << static_cast<int>(porcentaje) << "%] [";
    int numChars = static_cast<int>(porcentaje / 2);
    for (int i = 0; i < 50; ++i) {
        if (i < numChars) {
            std::cout << "#";
        } else {
            std::cout << " ";
        }
    }
    std::cout << "]\r";
    std::cout.flush();
}