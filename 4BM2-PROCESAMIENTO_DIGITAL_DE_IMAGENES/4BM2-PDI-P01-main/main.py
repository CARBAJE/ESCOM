import cv2
import numpy as np
import matplotlib.pyplot as plt

def filtroPromedioPesado(img):

    # Define el tamaño del kernel (ventana de promedio)
    kernel_size = 5  # Puedes ajustar este valor según tus necesidades

    # Crea un kernel de pesos uniformes para el filtro de promedio ponderado
    kernel = np.ones((kernel_size, kernel_size), np.float32) / (kernel_size * kernel_size)

    # Aplica el filtro de promedio ponderado
    filtered_image = cv2.filter2D(img, -1, kernel)

    cv2.imwrite("C:\\Users\\lenovo\\Desktop\\4BM2-PDI-P01-main\\Resultados\\R3V.jpg", filtered_image)

    # Muestra ambas imágenes en un solo plot
    plt.figure(figsize=(12, 6))

    plt.subplot(1, 2, 1)
    plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title('Imagen Original')
    plt.axis('off')

    plt.subplot(1, 2, 2)
    plt.imshow(cv2.cvtColor(filtered_image, cv2.COLOR_BGR2RGB))
    plt.title('Imagen Filtrada')
    plt.axis('off')

    plt.show()

    return filtered_image

def main():
    # Leer la imagen
    img = cv2.imread('Resultados/leftEcualizadaV.jpg')
    filtroPromedioPesado(img)

if __name__ == "__main__":
    main()