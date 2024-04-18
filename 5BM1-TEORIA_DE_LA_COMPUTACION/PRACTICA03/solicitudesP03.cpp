#include "PRACTICA03.h"

std::string solicitarCadenaP03() {
    std::string cadena;
    bool verificacion;
    do {
        std::cout << "Ingrese una cadena (solo 'r' y 'w'): ";
        std::cin >> cadena;

        verificacion = true; // Inicializamos la verificación como verdadera

        for (char c : cadena) {
            if(c != 'r' && c != 'w') {
                verificacion = false; // Si encontramos un carácter distinto a 'r' o 'w', marcamos la verificación como falsa
                std::cout << "La cadena ingresada contiene caracteres que no son 'r' ni 'w'." << std::endl;
                std::cout << "Intentelo nuevamente." << std::endl;
                break; // Salimos del bucle
            }
        }

    } while(!verificacion); // Si la verificación es falsa, continuamos solicitando la cadena

    return cadena;
}


std::string generarCadenaP03(std:: string cadenaOriginal) {
    // Semilla para el generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    srand(time(NULL));

    std::string cadena;

    // Distribución para generar 'r' o 'w' aleatoriamente
    std::uniform_int_distribution<> dis(0, 1);

    int longitud = (cadenaOriginal.empty()) ? rand() % (15 - 5 + 1) + 5 : cadenaOriginal.size();

    for (int i = 0; i < longitud; ++i) {
        cadena += (dis(gen) == 0) ? 'r' : 'w';
    }
    cadena[cadena.size()-1] = (cadenaOriginal.empty()) ? 'w' : 'r';
    std::cout<<"La cadena generade fue de longitud: "<<longitud<<" denotada como: "<<cadena<<std::endl;

    return cadena;
}

void guardarJugadasEnArchivo(const std::vector<std::vector<int>>& rutas, const std::string& nombreArchivo, const std::string& nombreArchivoCSV, std::string cadena) {
    std::ofstream archivo(nombreArchivo);
    std::ofstream archivoCSV(nombreArchivoCSV);

    if (archivo.is_open() && archivoCSV.is_open()) {
        if (!rutas.empty()) {
            archivo << "Se encontraron las siguientes jugadas para la cadea <<"<<cadena<<">>:\n";
            for(auto& ruta : rutas) {
                archivo << "Ruta: ";
                for(int i = ruta.size() - 1; i >= 0; --i) {
                    archivo << 'Q' << ruta[i];
                    archivoCSV << ruta[i]+1;
                    if(i != 0) {
                        archivo << " -> ";
                        archivoCSV << ',';
                    }
                }
                archivo << "\n";
                archivoCSV << "\n";
            }
            std::cout << "Se han guardado las rutas en el archivo "<<nombreArchivo<<".txt'"<<std::endl;
            std::cout << "Se han guardado las rutas en el archivo "<<nombreArchivoCSV<<".csv'"<<std::endl;
        } else {
            std::cout << "No se encontraron rutas para la cadena: "<<cadena<<std::endl;
            archivo << "No se encontraron rutas para la cadena: "<<cadena<<std::endl;
        }
        archivo.close();
        archivoCSV.close();
    } else {
        std::cout << "No se pudo abrir el archivo para escribir las rutas.\n";
    }

}

void opcionAnimarP03(int& error) {
    char opcion = 'Y';
    std::cout<<"Desea Graficar el resultado(Y[y]/N[n]): ";
    std::cin>>opcion;
    if (opcion=='Y' || opcion=='y')
        animarP03(error);
}