# Programa iniciado el 14 de octubre 2023
# Programa finalizado el 25 de octubre 2023
# Version 3.0
# Autor: Ulises Gachuz Davila

import cv2
import numpy as np
import matplotlib.pyplot as plt

def ecualizacionUniforme(imgGrayScale):
    # Definir el valor máximo y mínimo de niveles de grises (valores ideales)
    gmax = 255
    gmin = 0

    # Creacion diccionario de datos de valores de grises
    dValMatrizEscalaG = dict(zip(*np.unique(imgGrayScale, return_counts=True)))
    # print("\nDiccionario de datos:")
    # print(dValMatrizEscalaG)

    # Calcular la frecuencia acumulada
    frecuenciaAcumulada = np.cumsum(list(dValMatrizEscalaG.values())) / imgGrayScale.size

    # Algoritmo de ecualización uniforme
    matrizEcualizada = np.interp(imgGrayScale.flatten(), list(dValMatrizEscalaG.keys()), frecuenciaAcumulada * (gmax - gmin) + gmin)
    matrizEcualizada = matrizEcualizada.reshape(imgGrayScale.shape).astype(np.uint8)

    return matrizEcualizada

def debug(matrizEscalaGrises, matrizEcualizada, frecuenciaAcumulada, valorPrueba):
    # Imprimir la matriz escala de grises
    print("\nMatriz escala de grises:")
    print(matrizEscalaGrises)
    print(f"\nTamaño de la imagen: {matrizEscalaGrises.size}")

    # Imprimir la matriz ecualizada
    print("\nMatriz Ecualizada:")
    print(matrizEcualizada)

    # Imprimir la suma de frecuencia acumulativa hasta cierto valor de clave
    sumaFrecuenciaAcumulativa = frecuenciaAcumulada[valorPrueba]
    print(f"Suma acumulativa hasta {valorPrueba}: {sumaFrecuenciaAcumulativa}")

def mostrarComparacion(img, imgGrayScale, matrizEcualizada):
    # Creacion diccionario de datos de valores de grises
    dValMatrizEscalaG = dict(zip(*np.unique(imgGrayScale, return_counts=True)))
    # print("\nDiccionario de datos:")
    # print(dValMatrizEscalaG)

    # Obtener valores X y Y de la matrizEscalaGrises para mostrar su histograma
    clavesDEscalaG = list(dValMatrizEscalaG.keys())
    valoresDEscalaG = list(dValMatrizEscalaG.values())

    # Crear un subplot con 2 filas y 1 columna
    plt.subplot(2, 1, 1)
    plt.bar(clavesDEscalaG, valoresDEscalaG, width=1, edgecolor='red')
    plt.title('Histograma de la imagen original')
    plt.xlabel('Valor del píxel')
    plt.ylabel('Frecuencia')
    
    
    # Creacion de un diccionario de datos de la matriz ecualizada
    dValMatrizEcualizada = dict(zip(*np.unique(matrizEcualizada, return_counts=True)))

    # Obtener valores X y Y de la matrizEcualizada para mostrar su histograma
    clavesDEcualizada = list(dValMatrizEcualizada.keys())
    valoresDEcualizada = list(dValMatrizEcualizada.values())

    # Comparacion entre histogramas
    plt.subplot(2, 1, 2)
    plt.bar(clavesDEcualizada, valoresDEcualizada, width=1, edgecolor='red')
    plt.title('Histograma de la imagen ecualizada')
    plt.xlabel('Valor del píxel')
    plt.ylabel('Frecuencia')
    plt.suptitle('Comparación entre histogramas')
    plt.subplots_adjust(top=0.85, bottom=0.1, left=0.1, right=0.9, hspace=0.4, wspace=0.4)
    plt.show()

    # Comparacion entre imagenes resultantes
    plt.subplot(1, 3, 1), plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title('Original'), plt.xticks([]), plt.yticks([])

    plt.subplot(1, 3, 2), plt.imshow(imgGrayScale, cmap='gray')
    plt.title('Escala de grises'), plt.xticks([]), plt.yticks([])

    plt.subplot(1, 3, 3), plt.imshow(matrizEcualizada, cmap='gray')
    plt.title('Ecualización uniforme'), plt.xticks([]), plt.yticks([])
    plt.suptitle('Comparación entre imágenes')
    plt.show()

def main():
    # Leer la imagen
    img = cv2.imread(r'Resultados\\leftPrewitOut_h.jpg')

    # Convertir la imagen a escala de grises
    imgGrayScale = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Aplicar ecualización uniforme
    matrizEcualizada = ecualizacionUniforme(imgGrayScale)

    # Mostrar comparaciones de resultados
    mostrarComparacion(img, imgGrayScale, matrizEcualizada)
    
    # Guardar la imagen ecualizada
    cv2.imwrite('Resultados/leftEcualizadaH.jpg', matrizEcualizada)
    
    # Debug
    valorPrueba = 28
    # debug(imgGrayScale, matrizEcualizada, frecuenciaAcumulada, valorPrueba)

    return matrizEcualizada

if __name__ == "__main__":
    main()
