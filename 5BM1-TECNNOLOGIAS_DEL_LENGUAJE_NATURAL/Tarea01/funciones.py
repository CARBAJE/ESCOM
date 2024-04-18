import os
import random
import matplotlib.pyplot as plt

def leerImagenBmp(nombre_archivo):
    with open(nombre_archivo, 'rb') as archivo:
        # Cabecera BMP (los primeros 54 bytes)
        cabecera = archivo.read(54)

        # Obteniendo el ancho y alto de la imagen
        ancho = int.from_bytes(cabecera[18:22], byteorder='little')
        alto = int.from_bytes(cabecera[22:26], byteorder='little')

        # Saltar al inicio de los datos de la imagen
        archivo.seek(int.from_bytes(cabecera[10:14], byteorder='little'))

        # Leer los datos de la imagen
        datosImagen = archivo.read()


    return ancho, alto, datosImagen

def leerImagenesBmpEnCarpeta(carpeta):
    imagenes_bmp = []
    for archivo in os.listdir(carpeta):
        if archivo.endswith(".bmp"):
            ruta_completa = os.path.join(carpeta, archivo)
            ancho, alto, datos = leerImagenBmp(ruta_completa)
            imagenes_bmp.append((ruta_completa, ancho, alto, datos))

    return imagenes_bmp

def validar_dimensiones(imagenes):
    for i in range(len(imagenes) - 1):  # Iterar hasta el penúltimo elemento
        ancho, alto, _ = imagenes[i][1:]  # Obtener dimensiones de la imagen actual
        siguiente_ancho, siguiente_alto, _ = imagenes[i + 1][1:]  # Obtener dimensiones de la siguiente imagen
        if (ancho, alto) != (siguiente_ancho, siguiente_alto):
            print("Las imágenes no tienen las mismas dimensiones")
            return False
    return True

# Función para convertir una imagen BMP en un vector de características
def convertir_aCaracteristicas(ruta_imagen):
    # Leer la imagen BMP y extraer características relevantes
    ancho, alto, datos = leerImagenBmp(ruta_imagen)
    return [ancho, alto]

# Función para obtener la función de pérdida durante el entrenamiento
def obtener_funcion_perdida(datos_entrenamiento, pesos, tasa_aprendizaje, iteraciones_max):
    iteraciones = []
    perdidas = []

    for iteracion in range(iteraciones_max):
        aprendiendo = False
        perdida_iteracion = 0
        random.shuffle(datos_entrenamiento)  # Mezcla los datos en cada iteración

        for datos in datos_entrenamiento:
            entradas = datos[:-1]  # Todas las características excepto la última (etiqueta)
            etiqueta_real = datos[-1]

            # Calcular salida del perceptrón
            suma_ponderada = sum(w * x for w, x in zip(pesos[:-1], entradas)) + pesos[-1]
            salida = 1 if suma_ponderada > 0 else 0

            # Calcular pérdida
            perdida_iteracion += (etiqueta_real - salida) ** 2

            # Actualizar pesos si es necesario
            if salida != etiqueta_real:
                error = etiqueta_real - salida
                for i in range(len(entradas)):
                    pesos[i] += tasa_aprendizaje * error * entradas[i]
                pesos[-1] += tasa_aprendizaje * error
                aprendiendo = True

        # Almacenar la pérdida de esta iteración
        iteraciones.append(iteracion)
        perdidas.append(perdida_iteracion)

        # Salir del bucle si no hay errores de clasificación
        if not aprendiendo or iteracion >= iteraciones_max:
            break

    return iteraciones, perdidas

# Función para graficar la función de pérdida
def graficar_funcion_perdida(iteraciones, perdidas):
    plt.plot(iteraciones, perdidas)
    plt.title('Función de pérdida durante el entrenamiento')
    plt.xlabel('Iteración')
    plt.ylabel('Pérdida')
    plt.show()
