#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
#include <chrono>
#include <random>
#include <unistd.h>
#include <unordered_set>
#include <regex>

// Definición de la estructura de los EstadoP04s
struct EstadoP04 {
    int id;
    std::vector<std::pair<char, int>> transiciones; // Transiciones: (símbolo, EstadoP04_destino)
};

// Definición de la estructura del autómata
struct AutomataP04 {
    std::vector<EstadoP04> grafo;
    int EstadoP04Inicial;
    std::vector<int> EstadoP04Final;
};

//ListaPalabras
struct Palabra{
    std::string cadena;
    std::pair<int, int> coordenada;
};

struct ListaPalabras{
    std::vector<Palabra> lista;
};

//Funcion para realizar la animacion
void EjecutarMatlabP04(std::string&, int&);

//Funcion para solicitar al usuario la animacion
void opcionAnimarP04(std::string&, int&);

// Función para encontrar todas las Jugadas al EstadoP04 final que terminan en "01" usando DFS
ListaPalabras encontrarPalabrasReservadas(const AutomataP04&, const ListaPalabras&);

// Función para guardar las Jugadas en un archivo de texto
void guardarPREnArchivo(ListaPalabras, const std::string&, std::string&);

//Funcion para medir el tiempo
void medirTiempoP04(std::chrono::high_resolution_clock::time_point&);

//Funcion para ejecutar la secunecia de funciones del programa
void ejecucionP04(std::string, AutomataP04, int&);

//Funcion para almacenar la URL en un archivo
void guardarURL(std::string& URL, std::string& archivoURL);

//Funcion para leer un archivo de texto y devolver cada palabra dentro del texto junto con su posicion en x y y
ListaPalabras leerArchivo(const std::string& nombreArchivo);

//Funcion para leer y guardar la tabla de estados del automata
std::vector<std::vector<int>> leerCSV(std::string);

//Función para generar una cadena binaria aleatoria de tamaño aleatorio (entre uno y cien)
std::string generarCadenaP04(std::string);

//Función para solicitar al usuario la cadena
std::string solicitarCadenaP04();

//Funcion para ingresar la opcion:
int ingresarOpcionP04();

//Función para generar el autómata y definir sus trancisiones
AutomataP04 crearAutomataP04(std::string);

//Funcion para crear los EstadoP04s del AutomataP04
std::vector<EstadoP04> crearEstadoP04(std::vector<std::vector<int>>);

//Función menu
void menuP04(int&);

//Función main
int main();