#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <time.h>
#include <chrono>
#include <random>
#include <unistd.h>
//#include <mutex>
//#include <thread>

// Definición de la estructura de los Casillas
struct Casilla {
    int id;
    std::vector<std::pair<char, int>> transiciones; // Transiciones: (símbolo, Casilla_destino)
};

// Definición de la estructura del autómata
struct Tablero {
    std::vector<Casilla> grafo;
    int casillaInicial;
    int casillaFinal;
};

//Funcion para realizar la animacion
void animarP03(int&);

//Funcion para solicitar al usuario la animacion
void opcionAnimarP03(int&);

// Función para encontrar todas las Jugadas al Casilla final que terminan en "01" usando DFS
std::vector<std::vector<int>> encontrarJugadas(const Tablero&, const std::string&, int, int, std::vector<int>);

// Función para guardar las Jugadas en un archivo de texto
void guardarJugadasEnArchivo(const std::vector<std::vector<int>>&, const std::string&, const std::string&, std::string);

//Funcion para medir el tiempo
void medirTiempoP03(std::chrono::high_resolution_clock::time_point);

//Funcion para ejecutar la secunecia de funciones del programa
void ejecucionP03(std::string, Tablero, Tablero, int&);

//Funcion para crear una segunda cadena para el jugador dos a partir de la original o a partir de una nueva de manera random
std::string crearCadena2P03(std:: string);

//Función para generar una cadena binaria aleatoria de tamaño aleatorio (entre uno y cien)
std::string generarCadenaP03(std::string);

//Función para solicitar al usuario la cadena
std::string solicitarCadenaP03();

//Funcion para ingresar la opcion:
int ingresarOpcionP03();

//Función para generar el autómata y definir sus trancisiones
Tablero crearTablero(int );

//Funcion para crear los Casillas del Tablero
std::vector<Casilla> crearCasilla();

//Función menu
void menuP03(int&);

//Función main
int main();