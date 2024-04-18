//Solicitudes
#include "PRACTICA01.h"

void ingresarPotencia(int& potencia){
    std::cout << "Ingrese la potencia deseada: ";
    std::cin >> potencia;
}
void randomPotencia(int& potencia){
    srand(time(0));
    potencia = rand() % (20 - 0 + 1) + 0;
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
    std::cout<<"Desea Graficar el resultado(Y[y]/N[n]): ";
    std::cin>>opcion;
    if (opcion=='Y' || opcion=='y')
        graficar(error);
}