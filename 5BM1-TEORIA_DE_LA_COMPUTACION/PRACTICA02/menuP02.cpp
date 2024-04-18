#include "PRACTICA02.h"

void menu(int& error) {
    bool repetir = true;
    int opcion = 1;
    std::string cadena = "";
    Automata automata = crearAutomata();


    while(repetir){
        std::cout<<"BIENVENIDO A LA PRACTICA 01."<<std::endl;
        std::cout<<"OPCIONES A REALIZAR"<<std::endl;
        std::cout<<"1- Ingresar cadena."<<std::endl;
        std::cout<<"2- Generar cadena random."<<std::endl;
        std::cout<<"3- Ejecutar Programa."<<std::endl;
        std::cout<<"0- Salir del Programa."<<std::endl;

        opcion = ingresarOpcion();

        switch (opcion) {
        case 0:
            std::cout<<"Gracias Por usar el programa..."<<std::endl;
            repetir = false;
            break;
        case 1:
            cadena = solicitarCadena();
            break;
        case 2:
            cadena = generarCadena();
            break;
        case 3:
            if (!cadena.empty()) {
                ejecucion(cadena, automata);
                opcionAnimarP02(error);
            }else {
                std::cout<<"Favor de ingresar (generar) una cadena binaria al programa..."<<std::endl;
            }
            break;
        default:
            std::cout<<"Favor de indicar una opcion valida...."<<std::endl;
        }
    }
}

int ingresarOpcion(){
    int opcion= 5;
    std::cout << "Ingrese la opcion deseada: ";
    std::cin >> opcion;

    return opcion;
}

void ejecucion(std::string cadena, Automata automata){
    // Iniciar el cronómetro
    auto start = std::chrono::high_resolution_clock::now();

    //Generar el vector de rutas posibles al estado final para la cadena
    auto rutas = encontrarRutas(automata, cadena, 0, 0, {});

    // Detener el cronómetro
    auto stop = std::chrono::high_resolution_clock::now();

    //Calcular el tiempo transcurrido
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop-start);

    // Calcular minutos, segundos y milisegundos
    auto milliseconds = duration.count() % 1000;
    auto seconds = (duration.count() / 1000) % 60;
    auto minutes = (duration.count() / (1000 * 60)) % 60;

    //Mostrar iteraciones y tiempo cronometro
    std::cout << "Tiempo transcurrido: " << duration.count() << " milisegundos" << std::endl;

    guardarRutasEnArchivo(rutas, "rutas.txt", cadena);
}