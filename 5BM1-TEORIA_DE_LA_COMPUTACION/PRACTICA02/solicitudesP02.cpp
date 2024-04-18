#include "PRACTICA02.h"

std::string solicitarCadena() {
    std::string cadena;
    bool verificacion;

    do{
        std::cout << "Ingrese una cadena binaria): ";
        std::cin >> cadena;

        for (char c : cadena)
        {
            verificacion = true;
            if(c < '0' || c > '1'){
                verificacion = false;

                std::cout << "La cadena ingresada esta compuesta de otros caracteres ademas de 0s y 1s."<<std::endl;
                std::cout << "Intentelo nuevamente."<<std::endl;
                break;
            }
        }

    }while(!verificacion);

    return cadena;
}

std::string generarCadena() {
    srand(time(NULL));
    int longitud = rand() % (100 - 1 + 1) + 1;
    std::string cadena(longitud,'0');

    for(int i = 0 ; i < cadena.size() ; i++){
        cadena[i] = rand() % ('1' - '0' +1) + '0';
    }
    std::cout<<"La cadena generade fue de longitud: "<<longitud<<" denotada como: "<<cadena<<std::endl;

    return cadena;
}

void guardarRutasEnArchivo(const std::vector<std::vector<int>>& rutas, const std::string& nombreArchivo, std::string cadena) {
    std::ofstream archivo(nombreArchivo);
    std::ofstream archivo2("rutaGraficar.csv");
    if (archivo.is_open() && archivo2.is_open()) {
        if (!rutas.empty()) {
            archivo << "Se encontraron las siguientes rutas para la cadea <<"<<cadena<<">>:\n";
            for(auto& ruta : rutas) {
                archivo << "Ruta: ";
                for(int i = ruta.size() - 1; i >= 0; --i) {
                    archivo << 'Q' << ruta[i];
                    archivo2 << cadena[ruta.size()-i-1] << ',' << ruta[i]<<std::endl;
                    if(i != 0) archivo << " -> ";
                }
                archivo << "\n";
            }
            std::cout << "Se han guardado las rutas en el archivo 'rutas.txt'.\n";
        } else {
            std::cout << "No se encontraron rutas."<<std::endl;
            archivo << "No se encontraron rutas.\n";
        }
        archivo.close();
        archivo2.close();
    } else {
        std::cout << "No se pudo abrir el archivo para escribir las rutas.\n";
    }

}

void opcionAnimarP02(int& error) {
    char opcion = 'Y';
    std::cout<<"Desea Graficar el resultado(Y[y]/N[n]): ";
    std::cin>>opcion;
    if (opcion=='Y' || opcion=='y')
        animarP02(error);
}