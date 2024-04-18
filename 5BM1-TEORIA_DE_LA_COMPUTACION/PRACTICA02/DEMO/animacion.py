import turtle
import time

# Configuración inicial
turtle.setup(width=600, height=400)
turtle.Screen().bgcolor('black')
turtle.speed(0)
turtle.width(10)
turtle.hideturtle()

# Definición de los estados y transiciones
estados = ['Estado 1', 'Estado 2', 'Estado 3']
transiciones = {
    'Estado 1': 'Estado 2',
    'Estado 2': 'Estado 3',
    'Estado 3': 'Estado 1'
}

# Función para dibujar el estado actual
def dibujar_estado(estado_actual):
    turtle.clear()
    for estado in estados:
        turtle.penup()
        if estado == estado_actual:
            turtle.fillcolor("green")  # Relleno para el estado actual
        else:
            turtle.fillcolor("white")  # Sin relleno para otros estados
        turtle.goto(-150 + estados.index(estado) * 150, 100)
        turtle.begin_fill()
        turtle.pendown()
        turtle.circle( 50)
        turtle.end_fill()
        turtle.penup()
        turtle.goto(-150 + estados.index(estado) * 150, 80)
        turtle.write(estado, align='center', font=('Times New Roman', 12, 'normal'))

# Función para dibujar las conexiones entre estados
def dibujar_conexiones():
    for i in range(len(estados)):
        turtle.penup()
        turtle.goto(-150 + i * 150, 50)
        turtle.pendown()
        turtle.goto(-150 + (i+1) % len(estados) * 150, 50)

# Función principal
def main():
    estado_actual = 'Estado 1'
    while True:
        dibujar_estado(estado_actual)
        #dibujar_conexiones()
        time.sleep(1)
        estado_actual = transiciones[estado_actual]

# Ejecución del programa
if __name__ == "__main__":
    main()
