import numpy as np
import matplotlib.pyplot as plt

# Función para leer el conjunto de datos
def leer_dataset(filename):
    return np.loadtxt(filename, delimiter=',', skiprows=1)

# Función para barajar el conjunto de datos si es necesario
def barajear_datos(shuffle, dataset):
    if shuffle:
        np.random.shuffle(dataset)
    return dataset

# Función para dividir el conjunto de datos en entrenamiento y prueba
def dividir_conjunto(dataset, porcentaje_entrenamiento, shuffle):
    num_entrenamiento = int(porcentaje_entrenamiento * len(dataset))
    datos = barajear_datos(shuffle, dataset)

    conjunto_entrenamiento = datos[:num_entrenamiento]
    conjunto_prueba = datos[num_entrenamiento:]

    return conjunto_entrenamiento, conjunto_prueba

# Función para inicializar los pesos del modelo
def inicializar_pesos(dataset):
    num_caracteristicas = dataset.shape[1] - 1
    pesos_iniciales = np.zeros(num_caracteristicas + 1) # El +1 es para el sesgo
    for i in range(num_caracteristicas):
        pesos_iniciales[i+1] = float(input(f"Ingrese el valor inicial del peso {i}: "))

    print("Vector de pesos iniciales: ", pesos_iniciales)

    return pesos_iniciales

# Función de descenso de gradiente en lotes (bgd)
def bgd(X_train, y_train, X_test, y_test, iteraciones, alpha):
    weight_vector = inicializar_pesos(X_train)
    vector_mistake = []
    vector_estimated = []
    vector_weights = []
    vector_real = []

    for _ in range(iteraciones):
        results = estimation_mistake(X_test, y_test, weight_vector)
        vector_mistake.append(results[0])
        vector_estimated.append(results[1])
        vector_real.append(results[2])
        vector_weights.append(weight_vector.copy())

        # Aquí se calcula y_pred para esta iteración
        y_pred = np.dot(X_test, weight_vector)

        print(f"Iteración {_+1}:")
        print("Pesos:", weight_vector)
        print("Error de estimación:", results[0])
        print("y_pred:", y_pred)

        for i, wi in enumerate(weight_vector):
            sum = np.dot(wi * X_train[:, 0] - y_train, X_train[:, 0])
            weight_vector[i] -= 2 * alpha * sum

    return vector_weights, vector_mistake, vector_estimated, vector_real


# Función para calcular el error de estimación y las predicciones
def estimation_mistake(X_test, y_test, weight_vector):
    estimation = 0
    num_rows = X_test.shape[0]
    y_estimated_vector = []
    y_real_vector = []

    for i in range(num_rows):
        y_estimated = np.dot(X_test[i], weight_vector)
        y_estimated_vector.append(y_estimated)
        y_real = y_test[i]
        y_real_vector.append(y_real)
        estimation += abs(y_real - y_estimated)

    return estimation, y_estimated_vector, y_real_vector

# Función para graficar la regresión y el error estimado en cada iteración
def plot_regression_and_error(datos, predicciones, error_estimado):
    # Graficar error estimado
    plt.figure(figsize=(10, 5))
    plt.plot(range(1, len(error_estimado) + 1), error_estimado, color='green', marker='o')
    plt.title('Error estimado en cada iteración')
    plt.xlabel('Iteración')
    plt.ylabel('Error estimado')
    plt.show()

# Función principal para calcular el descenso de gradiente en lotes y mostrar resultados
def calcular_bgd(dataset, iteraciones, porcentaje_entrenamiento, mezclar_datos, rand_state, alpha):
    conjunto_entrenamiento, conjunto_prueba = dividir_conjunto(dataset, porcentaje_entrenamiento, mezclar_datos)

    X_train = conjunto_entrenamiento[:, :-1]
    y_train = conjunto_entrenamiento[:, -1]
    X_test = conjunto_prueba[:, :-1]
    y_test = conjunto_prueba[:, -1]

    weights, mistakes, estimated, real = bgd(X_train, y_train, X_test, y_test, iteraciones, alpha)

    plot_regression_and_error(conjunto_prueba, estimated, mistakes)

    return mistakes, estimated

# Lectura del dataset
dataset = leer_dataset('Dataset_multivariable.csv')

# Parámetros de usuario
iteraciones = int(input("Ingrese el numero de iteraciones que desee: "))
porcenEntrenamiento = float(input("Ingrese el porcentaje de entrenamiento entre (0 y 0.9): "))
mezclarDatos = bool(int(input("Desea mesclar (0 o 1): ")))
randState = int(input("Ingrese la semilla del rand: "))
alpha = float(input("Ingrese el valor de la taza de aprendizaje (alpha): "))

np.random.seed(randState)
# Ejecución del descenso de gradiente en lotes y visualización de resultados
error_estimado, predicciones = calcular_bgd(dataset, iteraciones, porcenEntrenamiento, mezclarDatos, randState, alpha)
