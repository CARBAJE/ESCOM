/*
INSTITUTO POLITECNICO NACIONAL.
ESCUELA SUPERIOR DE COMPUTO.
CICLO: 2024-02.
GRUPO: 5BM1.
ALUMNO: Carrillo Barreiro José Emiliano.
*/
#include <iostream>
#include <string>
#include <fstream>
//Imprime epsilon => '\u03B5'
// Función para generar las combinaciones de longitud 'len' del alfabeto {'#', '.'}
void generarCombinaciones(std:: ofstream& archivo, int len, int& i, std::string prefix = "") {
    if (len == 0) {
        // Si hemos alcanzado la longitud deseada, terminar la función
        return;
    }

    // Iterar sobre cada símbolo del alfabeto y generar las combinaciones recursivamente
    for (char c : {'#', '.'}) {
        std::string newPrefix = prefix + c;
        archivo << newPrefix << ", ";
        i++;
        generarCombinaciones(archivo, len - 1, i, newPrefix);
    }
}

int main() {
    int potencia;
    int iteraciones = 1;

    // Solicitar al usuario la potencia deseada
    std::cout << "Ingrese la potencia deseada: ";
    std::cin >> potencia;

    //Crear y abrir un archivo
    std::ofstream archivo("salidaPractica1.txt");

    // Generar las combinaciones de longitud creciente del alfabeto {'#', '.'}
    archivo << "\u03B5" << ", ";
    generarCombinaciones(archivo, potencia , iteraciones);
    std::cout<<"Numero de iteraciones realizadas: "<<iteraciones<<std::endl;

    //Cerrar el archivo
    archivo.close();

    return 0;
}
