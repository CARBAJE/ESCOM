#include "PRACTICA02.h"

void animarP02(int& error) {
    std::string ruta = "MATLAB -r run('C:\\Users\\emicr\\Documents\\CODIGOS_FUENTES\\5BM1-TEORIA_DE_LA_COMPUTACION\\PRACTICA02\\animacion.m')";

    error = system(ruta.c_str());

    // Verificar si la ejecución fue exitosa
    if (error == 0) {
        std::cout << "La ruta se ejecuto correctamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar la ruta." << std::endl;
    }

    // Esperar un tiempo adicional
    std::cout << "Esperando 15 segundos antes de iniciar la animacion de MATLAB..." << std::endl;
    Sleep(15000); // Espera 10000 milisegundos (equivalente a 10 segundos)
}