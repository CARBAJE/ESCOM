import numpy as np
import matplotlib.pyplot as plt

#Leemos el Dataset
dataset = np.loadtxt('casas.csv', delimiter=',',skiprows=1)

#Parametros
iteraciones = int(input("Ingrese el numero de iteraciones que desee: "))
porcenEntrenamiento = float(input("Ingrese el porcentaje de entrenamiento entre (0 y 0.9): "))
mezclarDatos = bool(input("Desea mesclar (0 o 1): "))
randState = int(input("Ingrese la semilla del rand: "))
alpha = float(input("Ingrese el valor de la taza de aprendizaje (alpha): "))

#Funciones
def barajearDs(shuffle, dataset):
    if shuffle:
        np.random.shuffle(dataset)
    return dataset

def VectorPesos(dataset):
    np.random.seed(randState)
    numCaracteristicas = dataset.shape[1] - 1
    pesosIniciales = np.zeros(numCaracteristicas + 1) #el 1 es el sesgo
    for i in range(numCaracteristicas):
        pesosIniciales[i+1] = float(input(f"Ingrese el valor inicial del peso {i}: "))

    print("Vector de pesos iniciales: ", pesosIniciales)

    return pesosIniciales

def dividirCVS(dataset, pEntrenamiento, shuffle):
    numEntrenamiento = int(pEntrenamiento * len(dataset))
    datos = barajearDs(shuffle, dataset)

    conjuntoTrain = datos[:numEntrenamiento]
    conjuntoTest = datos[numEntrenamiento:]

    print("El conjunto de entrenamiento es el siguiente:")
    print(conjuntoTrain)
    print("El conjunto de prueba es el siguiente:")
    print(conjuntoTest)

    return conjuntoTrain, conjuntoTest

def BatchGradientDescent(datos, datosTest, pesosI, alpha, iteraciones):
    peso = pesosI
    m = len(datos)
    n = len(pesosI)
    errorEstimacion = []
    listapredicciones = []

    for i in range(iteraciones):
        print("Iteracion: ", i)

        #calcular prediccion
        prediccion = np.dot(datosTest[:, :-1], peso[1:]) + peso[0]
        listapredicciones.append(prediccion)
        print("y_pred -> ", prediccion)

        #calcular el error
        error = prediccion - datosTest[:, -1]
        errorEstimacion.append(np.sum(abs(error)))
        print("Error de estimacion: ", errorEstimacion[-1])
        print(f"pesos: {peso[1:]}")

        #Actualizamos los pesos
        gradiente = np.dot(datosTest[:,:-1].T, error) / m
        peso[1:] -= alpha * gradiente
        peso[0] -= alpha * np.sum(error) / m

    return errorEstimacion, listapredicciones

def plot_regression_and_error(datos, predicciones, error_estimado):
    fig, axes = plt.subplots(2,1, figsize=(10, 10))

    # Graficar regresión lineal
    axes[0].scatter(datos[:, 1], datos[:, -1], color='blue', label='Datos reales')

    # Generar colores únicos
    colores = plt.cm.viridis(np.linspace(0, 1, len(predicciones)))

    for i, prediccion in enumerate(predicciones):
        axes[0].plot(datos[:, 1], prediccion, color=colores[i], label=f'Regresión lineal {i+1}')
    axes[0].set_title('Regresión lineal')
    axes[0].set_xlabel('X')
    axes[0].set_ylabel('Y')
    axes[0].legend()

    # Graficar error estimado
    axes[1].plot(range(1, len(error_estimado) + 1), error_estimado, color='green', marker='o')
    axes[1].set_title('Error estimado en cada iteración')
    axes[1].set_xlabel('Iteración')
    axes[1].set_ylabel('Error estimado')

    #Mostrar el sbuplot
    plt.tight_layout()
    plt.show()

def CaluclarBGD(dataset, i, shuffle, pTrain, a):
    conjuntoE, conjuntoP = dividirCVS(dataset, pTrain, shuffle)

    errorE, predicciones = BatchGradientDescent(conjuntoE,
                                                conjuntoP,
                                                VectorPesos(dataset),
                                                a,
                                                i)

    plot_regression_and_error(conjuntoP, predicciones, errorE)

    return errorE, predicciones

errorE, predicciones = CaluclarBGD(dataset = dataset,
                                   i = iteraciones,
                                   shuffle = mezclarDatos,
                                   pTrain = porcenEntrenamiento,
                                   a= alpha)
