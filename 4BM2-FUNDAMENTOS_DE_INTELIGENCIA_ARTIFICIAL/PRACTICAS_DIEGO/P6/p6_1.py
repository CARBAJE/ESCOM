from tkinter import *
import os

tk = Tk()
tk.title("PRACTICA 06 - FIA")

def consultar_esp():
    especie = especieinput.get()
    with open("input.txt", "w") as file:
        file.write(f"about({especie}).")
    os.system(f"swipl animalia.pl < input.txt > output.txt")
    result = ""
    with open ("output.txt", "r") as file:
        result = file.readlines()
        aux = ""
        for x in range (0, len(result)):
            cosa = cosa + "\n" + str(result[x]).replace("\n", "")
    textResult.delete("1.0", "end")
    textResult.insert(INSERT, str(cosa))

    for i in result:
        if "imagen" in i :
            image_path = i.split("(")[1].split(")")[0]
            break
        else:
            image_path = "Cat.png"
    
    image = PhotoImage(file=image_path)
    image_label.configure(image = image)
    image_label.image = image

titleLabel = Label(text="PRACTICA 06 - FIA", bg = "cyan", font=("Arial", 30))
titleLabel.pack()

especieLabel