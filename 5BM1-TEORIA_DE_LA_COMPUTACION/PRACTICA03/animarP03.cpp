#include "PRACTICA03.h"

void animarP03(int& error) {
    std::string ruta = "matlab -r \"run('/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA03/GraficoAutomata.m')\"";

    error = system(ruta.c_str());

    // Verificar si la ejecución fue exitosa
    if (error == 0) {
        std::cout << "La ruta se ejecuto correctamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar la ruta." << std::endl;
    }

    // Esperar un tiempo adicional
    std::cout << "Esperando 30 segundos antes de iniciar MATLAB..." << std::endl;

    ruta = "matlab -r \"run('/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA03/animacionP03.m')\"";

    error = system(ruta.c_str());

    // Verificar si la ejecución fue exitosa
    if (error == 0) {
        std::cout << "La ruta se ejecuto correctamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar la ruta." << std::endl;
    }
}