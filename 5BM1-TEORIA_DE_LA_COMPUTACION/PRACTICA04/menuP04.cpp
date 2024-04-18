#include "PRACTICA04.h"

void menuP04(int& error) {
    bool repetir = true;
    int opcion = 1;
    std::string rutaCSV = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/TablaEstadosP04.csv";
    std::string URL = "";
    AutomataP04 automataP04 = crearAutomataP04(rutaCSV);

    while(repetir) {
        std::cout<<"BIENVENIDO A LA PRACTICA 03."<<std::endl;
        std::cout<<"OPCIONES A REALIZAR"<<std::endl;
        std::cout<<"1- Ingresar URL."<<std::endl;
        std::cout<<"2- Ejecutar Programa."<<std::endl;
        std::cout<<"0- Salir del Programa."<<std::endl;

        opcion = ingresarOpcionP04();

        switch (opcion) {
        case 0:
            std::cout<<"Gracias Por usar el programa..."<<std::endl;
            repetir = false;
            break;
        case 1:
            URL = solicitarCadenaP04();
            break;
        case 2:
            ejecucionP04(URL, automataP04, error);
            break;
        default:
            std::cout<<"Favor de indicar una opcion valida...."<<std::endl;
        }
    }
}

int ingresarOpcionP04() {
    int opcion= 5;
    std::cout << "Ingrese la opcion deseada: ";
    std::cin >> opcion;

    return opcion;
}

void ejecucionP04(std::string URL, AutomataP04 automataP04, int& error){
    //Generar el archivo que guardara la URL
    std::string archivoURL = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/URL.txt";
    std::string rutaLeerPW = "matlab -r \"run('/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/leerPagWebs.m')\"";
    if(!URL.empty()){
        guardarURL(URL, archivoURL);
        EjecutarMatlabP04(rutaLeerPW, error);
    }

    std::string rutaAWeb = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/textoWEB.txt";

    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();

    //Obtener las palabras dentro del archivo de la pagina web
    ListaPalabras paginaWeb = leerArchivo(rutaAWeb);

    //Generar el vector de jugadas posibles al estado final para la cadena
    auto palabras = encontrarPalabrasReservadas(automataP04, paginaWeb);
    // Detener el cronómetro y mostrar el tiempo transcurrido
    medirTiempoP04(start);

    //Guardamos las 'Palabras Reservadas' (PR) en un archivo
    guardarPREnArchivo(palabras, "palabrasEncontradas.txt", URL);

    std::string rutaAutomata = "matlab -r \"run('/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/GraficoAutomata.m')\"";
    opcionAnimarP04(rutaAutomata, error);
}

void medirTiempoP04(std::chrono::high_resolution_clock::time_point& start) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto milliseconds = duration.count() % 1000;
    auto seconds = (duration.count() / 1000) % 60;
    auto minutes = (duration.count() / (1000 * 60)) % 60;

    std::cout << "Tiempo transcurrido: " << minutes << " minutos, " << seconds << " segundos, " << milliseconds << " milisegundos" << std::endl;
}
