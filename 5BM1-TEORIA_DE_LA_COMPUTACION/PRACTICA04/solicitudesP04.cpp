#include "PRACTICA04.h"

std::string solicitarCadenaP04() {
    std::string cadena;
    bool verificacion;
    do {
        std::cout << "Ingrese una cadena (URL): ";
        std::cin >> cadena;

        // Expresión regular para validar URL
        std::regex url_regex("(http|https)://.*");

        verificacion = std::regex_match(cadena, url_regex);

        if (!verificacion) {
            std::cout << "La cadena ingresada no es una URL válida." << std::endl;
            std::cout << "Intentelo nuevamente." << std::endl;
        }

    } while(!verificacion);

    return cadena;
}

std::vector<std::vector<int>> leerCSV(std::string nombreArchivo) {
    std::vector<std::vector<int>> datos;
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return datos;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::vector<int> fila;
        std::stringstream ss(linea);
        std::string valor;

        while (std::getline(ss, valor, ',')) {
            try {
                if (!valor.empty())
                    fila.push_back(std::stoi(valor));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Valor no válido en el archivo CSV." << std::endl;
            }
        }

        datos.push_back(fila);
    }

    archivo.close();
    return datos;
}

void guardarURL(std::string& URL, std::string& archivoURL) {
    std::ofstream archivo(archivoURL);
    if(archivo.is_open()){
        archivo << URL;
        archivo.close();
        std::cout << "El URL se guardo exitosamente en el archio" << std::endl;
    }else
        std::cout << "No se pudo abrir el archivo" << std::endl;
}

ListaPalabras leerArchivo(const std::string& nombreArchivo) {
    ListaPalabras palabrasEnArchivo;

    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
        return palabrasEnArchivo;
    }

    std::string linea;
    int posY = 1;
    while (std::getline(archivo, linea)) {
        int posX = 1;
        std::istringstream iss(linea);
        std::string palabra;
        while (iss >> palabra) {
            palabrasEnArchivo.lista.push_back({palabra, {posX, posY}});
            posX += palabra.length() + 1; // Suma la longitud de la palabra más un espacio
        }
        posY++; // Avanza a la siguiente línea
    }

    archivo.close();
    return palabrasEnArchivo;
}

//PR = Palabra Reservada
void guardarPREnArchivo(ListaPalabras palabras, const std::string& nombreArchivo, std::string& URL) {
    std::ofstream archivo(nombreArchivo);
    if(archivo.is_open()) {
        if(!palabras.lista.empty()) {
            archivo << "Se encontraron las siguientes palabras reservadas (junto sus coordenadas) dentro de la URL '" << URL << "'"<<std::endl;
            for(auto& palabra : palabras.lista) {
                archivo << "Palabra: "<<palabra.cadena;
                archivo << "\tCoordenada en X: "<< palabra.coordenada.first << "\tCoordenada en Y: " << palabra.coordenada.second;
                archivo << std::endl;

                std::cout<< "Palabra: "<<palabra.cadena;
                std::cout << "\tCoordenada en X: "<< palabra.coordenada.first << "\tCoordenada en Y: " << palabra.coordenada.second;
                std::cout << std::endl;
            }
        std::cout << "Se han guardado las palabras en el archivo "<<nombreArchivo<<".txt'"<<std::endl;
        } else {
            std::cout << "No se encontraron palabras reservadas para la pagina web con URL: " << URL << std::endl;
            archivo << "No se encontraron palabras reservadas para la pagina web con URL: " << URL << std::endl;
        }
    } else
        std::cout << "No se pudo abrir el archivo" << std::endl;
}

void opcionAnimarP04(std::string& ruta, int& error) {
    char opcion = 'Y';
    std::cout<<"Desea Graficar el resultado(Y[y]/N[n]): ";
    std::cin>>opcion;
    if (opcion=='Y' || opcion=='y')
        EjecutarMatlabP04(ruta, error);
}