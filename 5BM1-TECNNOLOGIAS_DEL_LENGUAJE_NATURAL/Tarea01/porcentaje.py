from funciones import leerImagenBmp
from funciones import leerImagenesBmpEnCarpeta

# Obtener las dimensiones de la imagen
ancho, alto, datosImagen = leerImagenBmp(r"number-cls\0\0_ (80).bmp")

suma = 0

pruebas = leerImagenesBmpEnCarpeta(r".\number-cls\5")
for ruta, _, _, datosImagen2 in pruebas:
    # Iterar sobre cada píxel
    for y in range(alto):
        for x in range(ancho):
            # Calcular el índice en los datos de la imagen
            indice = (y * ancho + x) * 3  # Se multiplica por 3 para considerar los 3 canales (RGB)

            # Obtener el valor del píxel en la posición (x, y) de ambas imágenes
            pixel_imagen = tuple(datosImagen[indice:indice+3])
            pixel_comparacion = tuple(datosImagen2[indice:indice+3])  # Extraer los valores RGB de los datos de la imagen

            # Comparar los píxeles
            if pixel_imagen == pixel_comparacion:
                suma=suma+1

    porcentaje = 100*(suma/(ancho*alto))
    suma = 0
    if( porcentaje > 97.55 ):
        print('Las imagen "'+ruta+'" tiene un '+str(porcentaje)+' porciento de similitud, ergo representan al mismo numero')
        break
    else:
        print('Las imagen "'+ruta+'" tiene un '+str(porcentaje)+' porciento de similitud, ergo NO representan al mismo numero')