#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <unistd.h>
#include <iomanip>
#include <math.h>
#include <algorithm>
//#include "matplotlibcpp.h"

//funciones
void graficar(int&);
void opcionGraficar(int&);
void medirTiempoP01(std::chrono::high_resolution_clock::time_point);
void mostrarBarraProgreso(int&, int&);
void generarCombinaciones(std::ofstream&, std::ofstream&, int, int&, char, char, std::string, int);
void ejecucion(int&, int, char&, char&);
void ingresarPotencia(int&);
void randomPotencia(int&);
void ingresarCaracteres(char&, char&);
int ingresarOpcionP01();
void menu(int&);
int main();