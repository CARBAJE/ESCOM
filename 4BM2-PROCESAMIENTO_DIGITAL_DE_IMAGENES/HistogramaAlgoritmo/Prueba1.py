import cv2
from matplotlib import pyplot as plt

def plot_demo(image):
    #La función de nuvel de numpy es reducir la matriz multidimensional a una matriz unidimensional
    plt.hist(image.ravel(), 256, [0, 256])
    plt.show ("Histograma")


def image_hist_demo(image):
    color = {"blue", "green", "red"}
    #La función  enumerate () se usa para combinar un objeto de datos que se puede atravesar (como una lista, tupla o cadena) en una secuencia de índice, y se enumeran los subíndices y datos al mismo tiempo. Generalmente se usa en un bucle for.
    for i, color in enumerate(color):
        hist = cv2.calcHist([image], [i], None, [256], [0, 256])
        plt.plot(hist, color=color)
        plt.xlim([0, 256])
    plt.show()


if __name__ == "__main__":
    img = cv2.imread("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-PROCESAMIENTO_DIGITAL_DE_IMAGENES\\HistogramaAlgoritmo\\Imagenes\\IMG01.jpg")
    cv2.namedWindow("input image", cv2.WINDOW_AUTOSIZE)
    cv2.imshow("input image", img)
    plot_demo(img)
    image_hist_demo(img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()