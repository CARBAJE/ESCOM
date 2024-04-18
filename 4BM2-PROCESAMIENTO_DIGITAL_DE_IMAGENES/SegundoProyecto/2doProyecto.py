#Proyecto de clasificacion en areas forestes de la amazonas.
import cv2
import numpy as np

img = cv2.imread('amazonassPrueba.jpg',0)
cv2.imshow('Lena grayscale',img)
cv2.waitKey(0)