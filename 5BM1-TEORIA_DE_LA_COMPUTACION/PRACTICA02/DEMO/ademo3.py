import turtle
import math

# Función para dibujar un círculo en la posición (x, y) con radio r
def draw_circle(x, y, r):
    t.penup()
    t.goto(x, y - r)
    t.pendown()
    t.circle(r)

# Función para dibujar una línea entre dos puntos (x1, y1) y (x2, y2)
def draw_line(x1, y1, x2, y2):
    t.penup()
    t.goto(x1, y1)
    t.pendown()
    t.goto(x2, y2)

# Función para dibujar una flecha al final de una línea
def draw_arrow(x1, y1, x2, y2):
    t.penup()
    t.goto(x2, y2)
    t.pendown()
    angle = math.degrees(math.atan2(y2 - y1, x2 - x1))
    t.setheading(angle)
    t.left(45)
    t.forward(20)
    t.penup()
    t.goto(x2, y2)
    t.pendown()
    t.setheading(angle)
    t.right(45)
    t.forward(20)

# Calcular la posición de los puntos en la circunferencia de los círculos
def calculate_circle_points(x, y, r, angle):
    x_point = x + r * math.cos(math.radians(angle))
    y_point = y + r * math.sin(math.radians(angle))
    return x_point, y_point

# Crea una pantalla
screen = turtle.Screen()

# Crea un objeto Turtle
t = turtle.Turtle()

# Dibuja dos círculos
circle1_x, circle1_y, circle1_r = -100, 0, 50
circle2_x, circle2_y, circle2_r = 100, 0, 50

draw_circle(circle1_x, circle1_y, circle1_r)
draw_circle(circle2_x, circle2_y, circle2_r)

# Calcular los puntos de intersección de las circunferencias
distance_between_centers = math.sqrt((circle2_x - circle1_x)**2 + (circle2_y - circle1_y)**2)
angle = math.degrees(math.acos((circle1_r**2 + distance_between_centers**2 - circle2_r**2) / (2 * circle1_r * distance_between_centers)))

# Calcular los puntos de inicio y fin de la línea
start_x, start_y = calculate_circle_points(circle1_x, circle1_y, circle1_r, angle)
end_x, end_y = calculate_circle_points(circle2_x, circle2_y, circle2_r, 180 - angle)

# Dibujar la línea entre los dos puntos
draw_line(start_x, start_y, end_x, end_y)

# Dibujar la flecha al final de la línea
draw_arrow(start_x, start_y, end_x, end_y)

# Mantén la ventana abierta hasta que la cierres
screen.mainloop()
