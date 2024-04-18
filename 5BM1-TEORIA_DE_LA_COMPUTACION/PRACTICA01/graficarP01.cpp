#include "PRACTICA01.h"

void graficar(int& error){
    std::string ruta = "matlab -r \"run('/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA01/graficoMatlab.m')\"";

    error = system(ruta.c_str());

    // Verificar si la ejecución fue exitosa
    if (error == 0) {
        std::cout << "La ruta se ejecuto correctamente." << std::endl;
    } else {
        std::cerr << "Error al ejecutar la ruta." << std::endl;
    }
}