import cv2
import numpy as np
import matplotlib.pyplot as plt
import ecualizacionUniforme as eu 
import main as fpp
import FiltroOperadorPrewit as fop

def main():
    # Leer la imagen
    img = cv2.imread(r'C:\\Users\\lenovo\\Desktop\\4BM2-PDI-P01-main\\Imagenes\\left.jpg')

    # Convertir la imagen a escala de grises
    imgGrayScale = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    #outV, outH = fop.prewitt_filter( ( fpp.main( eu.ecualizacionUniforme(imgGrayScale) ) ) , K_size = 3)
    r1 = eu.main(imgGrayScale)
    cv2.imwrite("C:\\Users\\lenovo\\Desktop\\4BM2-PDI-P01-main\\Resultados\\R1V.jpg", r1)
    r2 = fpp.main(r1)
    cv2.imwrite("C:\\Users\\lenovo\\Desktop\\4BM2-PDI-P01-main\\Resultados\\R2V.jpg", r2)
    outV, outH = fop.prewitt_filter(r2, K_size=3)

    # Mostrar comparaciones de resultados
    #eu.mostrarComparacion(img, imgGrayScale, outV)

    # Guardar la imagen vertical (out_v) en un archivo JPEG
    cv2.imwrite("C:\\Users\\lenovo\\Desktop\\4BM2-PDI-P01-main\\Resultados\\RV.jpg", outV)

    # Guardar la imagen horizontal (out_h) en un archivo JPEG
    cv2.imwrite("C:\\Users\\lenovo\\Desktop\\4BM2-PDI-P01-main\\Resultados\\RH.jpg", outH)

    # Crear una figura y subtramas
    fig, axs = plt.subplots(1, 2, figsize=(10, 5))

    # Mostrar la imagen vertical en la primera subtrama
    axs[0].imshow(outV, cmap='gray')
    axs[0].set_title('Vertical')

    # Mostrar la imagen horizontal en la segunda subtrama
    axs[1].imshow(outH, cmap='gray')
    axs[1].set_title('Horizontal')

    # Mostrar el título de la figura
    fig.suptitle('Imágenes Prewitt')

    # Ajustar el espacio entre subtramas
    plt.tight_layout()

    # Mostrar la figura
    plt.show()

    #Cerrar figuras
    plt.close()
