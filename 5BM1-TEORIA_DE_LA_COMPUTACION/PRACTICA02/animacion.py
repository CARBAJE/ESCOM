import turtle
import csv
import time
import math


# Configuración inicial
turtle.setup(width=600, height=400)
screen = turtle.Screen()
screen.bgcolor('black')
turtle.speed(0)
turtle.width(5)  # Ancho del borde de los estados
turtle.hideturtle()

# Definición de los estados
estados = ['Estado 1', 'Estado 2', 'Estado 3']

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

# Función para dibujar el estado actual
def dibujar_estado(estado_actual, caracter, screen_width, screen_height):
    turtle.clear()
    for estado in estados:
        turtle.penup()
        if estado == estado_actual:
            turtle.fillcolor("green")  # Relleno para el estado actual
            turtle.pencolor("red")  # Color del borde para el estado actual
        else:
            turtle.fillcolor("white")  # Sin relleno para otros estados
            turtle.pencolor("blue")  # Color del borde para otros estados
        x = -screen_width / 2 + (estados.index(estado) * (screen_width / (len(estados) - 1))) + (screen_width / (2 * len(estados)))
        y = 0  # Centrar verticalmente en la pantalla
        turtle.goto(x, y)
        turtle.begin_fill()
        turtle.pendown()
        turtle.circle(50)
        turtle.end_fill()
        turtle.penup()
        turtle.goto(x, y - 20)
        turtle.color("white")  # Color del texto en blanco
        turtle.write(caracter, align='center', font=('Times New Roman', 12, 'normal'))

# Función para dibujar la flecha de transición
# Función para dibujar la flecha de transición
def dibujar_transicion(estado_actual, estado_destino, screen_width):
    if estado_actual == "Estado 3":
        return  # No hacer nada si el estado actual es "Estado 3"

    # Calcular la posición x e y del estado actual y destino
    x1 = -screen_width / 2 + estados.index(estado_actual) * (screen_width / (len(estados) - 1)) + screen_width / (2 * len(estados))
    x2 = -screen_width / 2 + estados.index(estado_destino) * (screen_width / (len(estados) - 1)) + screen_width / (2 * len(estados))
    y = 100 - 50  # 100 es la posición y del estado, 50 es el radio del círculo del estado

    # Calcular el ángulo de la flecha
    angle = math.atan2(y, x2 - x1)

    # Calcular las coordenadas del punto de destino de la flecha centrado en el estado destino
    dest_x = x2 - 50 * math.cos(angle)  # 50 es la longitud del radio del estado destino
    dest_y = y - 50 * math.sin(angle)
    angle = math.atan2(dest_y - y, dest_x - x1)# Calcular el ángulo de la flecha

    # Dibujar la flecha de transición
    turtle.penup()
    turtle.goto(x1, y)
    turtle.pendown()
    turtle.pencolor("green")  # Color de la flecha verde
    if estado_actual != estado_destino:
        turtle.setheading(math.degrees(angle))
        turtle.goto(dest_x, dest_y)
        # Dibujar la cabeza de flecha
        turtle.right(135)
        turtle.forward(20)
        turtle.backward(20)
        turtle.left(270)
        turtle.forward(20)
        turtle.backward(20)
        turtle.right(135)
    else:  # Dibujar una curva hacia el mismo estado de origen
        radio = 50
        angulo = 270
        turtle.circle(-radio, angulo)

def main():
    # Obtener el ancho y el alto de la pantalla
    screen_width = screen.window_width()
    screen_height = screen.window_height()
    with open('rutaGraficar.csv', newline='') as csvfile:
        reader = csv.reader(csvfile)
        for row in reader:
            caracter, estado_actual = row
            estado_actual = estados[int(estado_actual)]
            dibujar_estado(estado_actual, caracter, screen_width, screen_height)
            if len(estados) > 1:
                estado_siguiente = estados[(estados.index(estado_actual) + 1) % len(estados)]
                dibujar_transicion(estado_actual, estado_siguiente, screen_width)
            time.sleep(1)

# Ejecución del programa
if __name__ == "__main__":
    main()