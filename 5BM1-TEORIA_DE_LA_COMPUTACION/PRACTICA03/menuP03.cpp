#include "PRACTICA03.h"

void menuP03(int& error) {
    bool repetir = true;
    int opcion = 1;
    std::string cadena = "";
    Tablero tablero = crearTablero(0);
    Tablero tablero2 = crearTablero(1);


    while(repetir){
        std::cout<<"BIENVENIDO A LA PRACTICA 03."<<std::endl;
        std::cout<<"OPCIONES A REALIZAR"<<std::endl;
        std::cout<<"1- Ingresar cadena."<<std::endl;
        std::cout<<"2- Generar cadena random."<<std::endl;
        std::cout<<"3- Ejecutar Programa."<<std::endl;
        std::cout<<"0- Salir del Programa."<<std::endl;

        opcion = ingresarOpcionP03();

        switch (opcion) {
        case 0:
            std::cout<<"Gracias Por usar el programa..."<<std::endl;
            repetir = false;
            break;
        case 1:
            cadena = solicitarCadenaP03();
            break;
        case 2:
            cadena = generarCadenaP03("");
            break;
        case 3:
            if (!cadena.empty()) {
                ejecucionP03(cadena, tablero, tablero2, error);
                opcionAnimarP03(error);
            }else {
                std::cout<<"Favor de ingresar (o generar) una cadena binaria al programa..."<<std::endl;
            }
            break;
        default:
            std::cout<<"Favor de indicar una opcion valida...."<<std::endl;
        }
    }
}

int ingresarOpcionP03(){
    int opcion= 5;
    std::cout << "Ingrese la opcion deseada: ";
    std::cin >> opcion;

    return opcion;
}

void ejecucionP03(std::string cadena, Tablero tablero, Tablero tablero2, int& error){
    if(cadena[cadena.size()-1] == 'w') {
        //Generar la cadena para el jugador 2
        std::string cadena2 = generarCadenaP03(cadena);

        // Iniciar el cronómetro
        auto start = std::chrono::high_resolution_clock::now();

        //Generar el vector de jugadas posibles al estado final para la cadena
        auto rutas = encontrarJugadas(tablero, cadena, 0, tablero.casillaInicial, {});
        auto rutas2 = encontrarJugadas(tablero2, cadena2, 0, tablero2.casillaInicial, {});

        // Detener el cronómetro y mostrar el tiempo transcurrido
        medirTiempoP03(start);

        std::string rutaA01 = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA03/jugadas.txt";
        std::string rutaC01 = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA03/J01.csv";
        std::string rutaA02 = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA03/jugadas2.txt";
        std::string rutaC02 = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA03/J02.csv";

        guardarJugadasEnArchivo(rutas, rutaA01, rutaC01, cadena);
        guardarJugadasEnArchivo(rutas2, rutaA02, rutaC02, cadena2);
    } else
        std::cout << "La cadena no termina en un valor valido para generar rutas, ingrese otra cadena." << std::endl;
}

void medirTiempoP03(std::chrono::high_resolution_clock::time_point start) {
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto milliseconds = duration.count() % 1000;
    auto seconds = (duration.count() / 1000) % 60;
    auto minutes = (duration.count() / (1000 * 60)) % 60;

    std::cout << "Tiempo transcurrido: " << minutes << " minutos, " << seconds << " segundos, " << milliseconds << " milisegundos" << std::endl;
}