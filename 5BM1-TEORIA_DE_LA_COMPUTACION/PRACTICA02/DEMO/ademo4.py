import turtle

# Pantalla
screen = turtle.Screen()
screen.bgcolor("black")

# Objeto Turtle
t = turtle.Turtle()
t.shape("turtle")
t.color("blue")
t.width(5)
t.speed(0)

t.penup()
t.goto(0,200)
t.pendown()

a = b = 0

while True:
    t.forward(a)
    t.right(b)
    a += 4
    b += 1
    if b == 210:
        break

t.hideturtle()
turtle.done()

#for line
#turtle.forward(100)