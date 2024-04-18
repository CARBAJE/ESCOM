import turtle
import math

def dibujar_arco(radio, angulo):
    turtle.speed(0)  # Establecer la velocidad más rápida
    turtle.penup()    # Levantar el lápiz
    turtle.goto(-radio, 0)  # Moverse al punto de inicio del arco
    turtle.pendown()  # Bajar el lápiz

    longitud_arco = 2 * math.pi * radio * (angulo / 360)  # Calcular la longitud del arco
    n_lados = int(longitud_arco / 3) + 1  # Determinar el número de lados para dibujar el arco
    paso_longitud = longitud_arco / n_lados  # Calcular la longitud de cada paso

    angulo_por_paso = angulo / n_lados  # Calcular el ángulo de cada paso

    for _ in range(n_lados):
        turtle.forward(paso_longitud)  # Avanzar
        turtle.right(angulo_por_paso)  # Girar hacia la derecha

    turtle.penup()  # Levantar el lápiz al final
    turtle.done()   # Terminar

# Ejemplo de uso
radio = 100
angulo = 180
dibujar_arco(radio, angulo)
