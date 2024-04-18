import cv2
import numpy as np
from matplotlib import pyplot  as plt

#Resize Image to put in the window
def ResizeWithAspectRatio(image, width=None, height=None, inter=cv2.INTER_AREA):
    dim = None
    (h, w) = image.shape[:2]

    if width is None and height is None:
        return image
    if width is None:
        r = height / float(h)
        dim = (int(w * r), height)
    else:
        r = width / float(w)
        dim = (width, int(h * r))

    return cv2.resize(image, dim, interpolation=inter)

def main():
    # reads an input image 
    img = cv2.imread('C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-PROCESAMIENTO_DIGITAL_DE_IMAGENES\\HistogramaAlgoritmo\\Imagenes\\IMG01.jpg',0)
    imgBW = img.copy()

    # find frequency of pixels in range 0-255 
    histr = cv2.calcHist([imgBW],[0],None,[256],[0,256])

    # resize = ResizeWithAspectRatio(image, height=1280) # Resize by height 
    imgBW_R = ResizeWithAspectRatio(imgBW, width=480)
    img_R = ResizeWithAspectRatio(img, width=480) # Resize by width OR

    # show the plotting graph of an image 
    plt.plot(histr)

    plt.show()

    cv2.imshow("Prueba01",imgBW_R)
    cv2.imshow("Prueba02",img_R)

    cv2.waitKey(0)
    cv2.destroyAllWindows()