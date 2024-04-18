#include "PRACTICA01.h"
#include "PRACTICA03.h"
#include "PRACTICA04.h"

int main() {
    srand(time(NULL));
    //Variables propias del programa
    int error = 0;
    int iteraciones = 0;
    int opcion = 0;

    //Variables PRACTICA01
    int potencia;
    char s0 = '#';
    char s1 = '.';

    //Variables PRACTICA03
    std::string cadena = "";
    Tablero tablero = crearTablero(0);
    Tablero tablero2 = crearTablero(1);

    //Variables PRACTICA04
    std::string rutaCSV = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/TablaEstadosP04.csv";
    AutomataP04 automataP04 = crearAutomataP04(rutaCSV);
    std::string URL = "";
    std::string rutaAutomata = "matlab -r \"run('/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/GraficoAutomata.m')\"";

    std::cout << "EL numero de Iteraciones es: " << iteraciones << std::endl;
    while(opcion < 4) {
        std::cout << std::endl;

        opcion = rand() % (4 - 1 + 1) + 1;

        std::cout << "------------";
        std::cout << "La opcion fue el 'PROGRAMA 0" << opcion <<"' se procede a ejecutar...";
        std::cout << "------------" << std::endl;
        switch(opcion) {
            case 1:
                randomPotencia(potencia);
                ejecucion(potencia, 1, s0, s1);
                graficar(error);
                break;
            case 2:
                cadena = generarCadenaP03("");
                ejecucionP03(cadena, tablero, tablero2, error);
                animarP03(error);
                break;
            case 3:
                ejecucionP04(URL, automataP04, error);
                EjecutarMatlabP04(rutaAutomata, error);
                break;
            case 4:
                std::cout << "#-#-#-#-#-#____GRACIASPOR USAR EL PROGRAMA____#-#-#-#-#-#"<<std::endl;
                break;
        }
        std::cout << "Ejecutado el 'PROGRAMA 0" << opcion << std::endl;
    iteraciones+=1;
    }

    return error;
}
