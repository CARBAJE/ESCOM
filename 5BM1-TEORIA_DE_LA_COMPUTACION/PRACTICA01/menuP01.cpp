//menus
#include "PRACTICA01.h"
#include <chrono>

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

        flag = ingresarOpcionP01();

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
                ejecucion(potencia, iteraciones, simbolo0, simbolo1);
                opcionGraficar(error);
                break;

        }
    }
}

int ingresarOpcionP01(){
    int opcion= 5;
    std::cout << "Ingrese la opcion deseada: ";
    std::cin >> opcion;

    return opcion;
}

void ejecucion(int& potencia, int iteraciones, char& simbolo0, char& simbolo1){
    int total = 0;
    for (int i = 0; i <= potencia; i++)
        total += pow(2,i);

    //Crear y abrir un archivo
    std::ofstream archivo("/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA01/UniversoP01.txt");
    std::ofstream archivo2("/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA01/salidaPractica1.csv");

    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();

    // Generar las combinaciones de longitud creciente del alfabeto
    archivo << "\u03B5" << ",";
    archivo2<< "0,0" << std::endl;
    generarCombinaciones(archivo, archivo2, potencia, iteraciones, simbolo0, simbolo1, "", 0);

    // Detener el cronómetro y mostrar el tiempo transcurrido
    medirTiempoP01(start);

    //Mostrar iteraciones y tiempo cronometro
    std::cout<<"Numero de iteraciones realizadas: "<<iteraciones<<std::endl;

    // Cerrar el archivo
    archivo.close();
}

// Función para medir el tiempo transcurrido
void medirTiempoP01(std::chrono::high_resolution_clock::time_point start) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto milliseconds = duration.count() % 1000;
    auto seconds = (duration.count() / 1000) % 60;
    auto minutes = (duration.count() / (1000 * 60)) % 60;

    std::cout << "Tiempo transcurrido: " << minutes << " minutos, " << seconds << " segundos, " << milliseconds << " milisegundos" << std::endl;
}
