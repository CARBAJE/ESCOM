#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>
#include <windows.h>
//#include <mutex>
//#include <thread>

// Definición de la estructura de los Estados
struct Estado{
    int id;
    std::vector<std::pair<char, int>> transiciones; // Transiciones: (símbolo, estado_destino)
};

// Definición de la estructura del autómata
struct Automata {
    std::vector<Estado> grafo;
    int numEstados;
    int estadoFinal;
};

//Funcion para realizar la animacion
void animarP02(int&);

//Funcion para solicitar al usuario la animacion
void opcionAnimarP02(int&);

// Función para encontrar todas las rutas al estado final que terminan en "01" usando DFS
std::vector<std::vector<int>> encontrarRutas(const Automata& automata, const std::string& cadena, int i, int posicion, std::vector<int> ruta_actual);

// Función para guardar las rutas en un archivo de texto
void guardarRutasEnArchivo(const std::vector<std::vector<int>>&, const std::string&, std::string);

//Funcion para ejecutar la secunecia de funciones del programa
void ejecucion(std::string, Automata);

//Función para generar una cadena binaria aleatoria de tamaño aleatorio (entre uno y cien)
std::string generarCadena();

//Función para solicitar al usuario la cadena
std::string solicitarCadena();

//Funcion para ingresar la opcion:
int ingresarOpcion();

//Función para generar el autómata y definir sus trancisiones
Automata crearAutomata();

//Funcion para crear los estados del Automata
std::vector<Estado> crearEstado();

//Función menu
void menu(int&);

//Función main
int main();