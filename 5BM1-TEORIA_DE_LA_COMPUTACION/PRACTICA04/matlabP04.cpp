#include "PRACTICA04.h"

void EjecutarMatlabP04(std::string& ruta, int& error) {
    error = system(ruta.c_str());

    // Verificar si la ejecución fue exitosa
    if (error == 0) {
        std::cout << "La ruta se ejecuto correctamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar la ruta." << std::endl;
    }

    // Esperar un tiempo adicional
    std::cout << "Esperando 30 segundos antes de pasar al siguiente paso del programa..." << std::endl;
    sleep(5); // Espera 20000 milisegundos (equivalente a 20 segundos)
}