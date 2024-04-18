function opcion = menu()
    %Menu de la practica 01

    sprintf('Ingrese una de las siguientes opciones del programa: ')
    sprintf('1-Ingrese el numero de clases que desee en su progrma.')
    sprintf('2-Meter el centroide de clases manualmente.')
    sprintf('3-Meter el centroide de clases automatico')
    sprintf('4-Ingresar la cantidad de representantes por clase.')
    sprintf('5-Calcular por Euclidiana')
    sprintf('6-Calcular por Mahalanobis')
    sprintf('7-')

    opcion = input('Ingrese la opcion a realizar: ');

    switch opcion
        case 1
            nClases = numeroClases();
        case 2
            centroides = obetenerCentroidesM(nClases);
        case 3
            centroides = obtenerCentroidesA(nClases);
        case 4
            nRepresentantes = obtenerRepresentantes(nClases);
        case 5
            dEuclidiana = distanciaEuclidiana;
        case 6
            dMahalanobis = clasificadorMahalanobis
        otherwise
                sprintf('INGRESE UNA OPCION VALIDA');
            