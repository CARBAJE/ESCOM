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
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include <windows.h>
//#include "matplotlibcpp.h"

//funciones
void graficar(int&);
void opcionGraficar(int&);
void generarCombinaciones(std:: ofstream&, int, int&, char&, char&, std::string );
void ingresarPotencia(int&);
void randomPotencia(int&);
void ingresarCaracteres(char&, char&);
int ingresarOpcion();
void menu(int&);
int main();

void graficar(int& error){
    std::string ruta = "MATLAB -r run('C:\\Users\\emicr\\Documents\\CODIGOS_FUENTES\\5BM1-TEORIA_DE_LA_COMPUTACION\\PRACTICA01\\UNICO\\graficoMatlab.m')";

    error = system(ruta.c_str());
    
    // Verificar si la ejecución fue exitosa
    if (error == 0) {
        std::cout << "La ruta se ejecutó correctamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar la ruta." << std::endl;
    }

    // Esperar un tiempo adicional (por ejemplo, 5 segundos)
    std::cout << "Esperando 5 segundos antes de cerrar MATLAB..." << std::endl;
    Sleep(5000); // Espera 5000 milisegundos (equivalente a 5 segundos)
}

void generarCombinaciones(std:: ofstream& archivo, int len, int& i, char& simbolo0, char& simbolo1, std::string prefix = "") {
    if (len == 0) {
        // Si hemos alcanzado la longitud deseada, terminar la función
        return;
    }

    std::vector<int> count_ones; // Vector para almacenar la cantidad de unos en cada palabra

    // Iterar sobre cada símbolo del alfabeto y generar las combinaciones recursivamente
    for (char c : {simbolo0, simbolo1}) {
        std::string newPrefix = prefix + c;
        archivo << newPrefix << ",";

        int ones = 0;
        for (char ch : newPrefix) {
            if (ch == simbolo1) {
                ones++;
            }
        }
        count_ones.push_back(ones); // Agregar la cantidad de unos al vector
        i++;

        generarCombinaciones(archivo, len - 1, i, simbolo0, simbolo1, newPrefix);
    }
}

void ingresarPotencia(int& potencia){
    std::cout << "Ingrese la potencia deseada: ";
    std::cin >> potencia;
}
void randomPotencia(int& potencia){
    srand(time(0));
    potencia = rand() % (28 - 0 + 1) + 0;
    std::cout<< "la potencia escogida de manera aleatoria fue: "<<potencia<<"."<<std::endl;
}
void ingresarCaracteres(char& simbolo0, char& simbolo1){
    std::cout << "Ingrese el simbolo cero para el alfabeto deseado: ";
    std::cin >> simbolo0;
    std::cout << "Ingrese el simbolo uno para el alfabeto deseado: ";
    std::cin >> simbolo1;
}
void opcionGraficar(int& error){
    char opcion = 'Y';
    std::cout<<"Desea Graficar el resultado(Y/N): ";
    std::cin>>opcion;
    if (opcion=='Y')
        graficar(error);
}

void menu(int& error){
    int flag =-1;
    int potencia = 0;
    int iteraciones = 1;
    char simbolo0 = '#';
    char simbolo1 = '.';

    while(flag != 0){
        std::cout<<"BIENVENIDO A LA PRACTICA 01."<<std::endl;
        std::cout<<"OPCIONES A REALIZAR"<<std::endl;
        std::cout<<"1- Ingresar potencia."<<std::endl;
        std::cout<<"2- Dar potencia random."<<std::endl;
        std::cout<<"3- Cambiar caracteres."<<std::endl;
        std::cout<<"4- Ejecutar Programa."<<std::endl;
        std::cout<<"0- Salir del Programa."<<std::endl;

        flag = ingresarOpcion();

        switch(flag){
            case 0:
                std::cout<<"GRACIAS POR USAR EL PROGRAMA."<<std::endl;
                std::cout<<"ADIOS."<<std::endl;
                return;
                break;
            case 1:
                ingresarPotencia(potencia);
                break;
            case 2:
                randomPotencia(potencia);
                break;
            case 3:
                ingresarCaracteres(simbolo0, simbolo1);
                break;
            case 4:
                //Crear y abrir un archivo
                std::ofstream archivo("salidaPractica1.txt");
                //Empezar cronometro
                std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
                // Generar las combinaciones de longitud creciente del alfabeto
                archivo << "\u03B5" << ",";
                generarCombinaciones(archivo, potencia, iteraciones, simbolo0, simbolo1, "");
                //Terminar Cronometro
                std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
                //Calcular el tiempo transcurrido
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);
                //Mostrar iteraciones y tiempo cronometro
                std::cout<<"Numero de iteraciones realizadas: "<<iteraciones<<std::endl;
                std::cout << "Tiempo transcurrido: " << duration.count() << " milisegundos" << std::endl;
                // Cerrar el archivo
                archivo.close();

                opcionGraficar(error);
                
                break;

        }
    }
}

int ingresarOpcion(){
    int opcion= 5;
    std::cout << "Ingrese la opcion deseada: ";
    std::cin >> opcion;

    return opcion;
}
int main(){
    int error = 0;
    menu(error);

    return error;
}
