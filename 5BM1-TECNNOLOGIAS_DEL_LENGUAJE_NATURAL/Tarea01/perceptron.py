from funciones import *
import random

## Obtener Datos e Inicializar variables
carpeta_con_imagenes = r"./number-cls/0"
imagenes_bmp_en_carpeta = leerImagenesBmpEnCarpeta(carpeta_con_imagenes)
datos_entrenamiento = []

## Llamada a la función de validación
if not validar_dimensiones(imagenes_bmp_en_carpeta):
    exit()  # Sale del programa si las dimensiones no coinciden

# Preparar datos de entrenamiento
for ruta_imagen, _, _, _ in imagenes_bmp_en_carpeta:
    caracteristicas = convertir_aCaracteristicas(ruta_imagen)
    etiqueta = 1 if "0_" in ruta_imagen else 0  # Define tus etiquetas adecuadamente
    #print(ruta_imagen)
    datos_entrenamiento.append(caracteristicas + [etiqueta])

# Inicializar pesos aleatorios
num_caracteristicas = len(datos_entrenamiento[0]) - 1  # Excluye la etiqueta
pesos = [random.uniform(-1, 1) for _ in range(num_caracteristicas + 1)]  # +1 para el sesgo

# Parámetros del perceptrón
tasa_aprendizaje = 0.3
iteraciones_max = 1000

# Obtener la función de pérdida durante el entrenamiento
iteraciones, perdidas = obtener_funcion_perdida(datos_entrenamiento, pesos, tasa_aprendizaje, iteraciones_max)

# Graficar la función de pérdida
#graficar_funcion_perdida(iteraciones, perdidas)

# Mostrar pesos finales
print("Pesos finales:", pesos)

# Clasificación de nuevas imágenes
pruebas = leerImagenesBmpEnCarpeta(r".\number-cls\5")
for ruta_imagen, _, _, _ in pruebas:
    caracteristicas = convertir_aCaracteristicas(ruta_imagen)
    suma_ponderada = sum(w * x for w, x in zip(pesos[:-1], caracteristicas)) + pesos[-1]
    salida = 1 if suma_ponderada > 0 else 0
    print("Imagen:", ruta_imagen, "Predicción:", salida, " suma ponderada: ",suma_ponderada)