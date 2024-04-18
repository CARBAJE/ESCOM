from tkinter import *
import os

root = Tk()
root.title("Práctica 06 - FIA")
root.iconbitmap("images/pk.ico")
root.maxsize(700,770)

especieslista="\npuma\nleopardo\ngato_montes\nelefante_asiatico\ncaballo\nrinoceronte_blanco\noso_pardo\noso_polar\npanda\nmurcielago\nvicugna\nguanaco\nllama\nperro\nlobo_rojo\ncoyote\nbabirusa\njabalí\nchimpancé\ngorila\norangutan"

Label(root,  text="PRACTICA 06 - FIA 4BM1 \nEQUIPO:", bg="white", font=("Helvetica Bold", 25)).grid(pady=5, row=0, column=0, columnspan=7)
Label(root, text="CARRILLO BARREIRO JOSE EMILIANO\nESCOBAR MONTOYA PATRICIO\n", bg="white", font=("Helvetica Bold", 15)).grid( pady=5, row=1, column=0, columnspan=7)
Label(root,text="Ingresa una especie: ", bg="white", font=("Helvatical bold", 15)).grid( pady=5, row=2, column=0)


Label(root, text="Especies disponibles: ", bg="white", font=("Arial bold", 15)).grid(pady=5, row=2, column=3)
listaesp =Label(root, justify=LEFT,text=especieslista)
listaesp.config(bg="white")
listaesp.grid(pady=5, row=1, rowspan = 7, column= 3)

especieInput = Entry(root, width=30)
especieInput.config(highlightbackground="gray", highlightcolor="black", highlightthickness=2)
especieInput.grid(pady=20, row=3, column=0)

textResult = Text(
    width=50,
    height=5,
    font=("Arial", 12)
)
textResult.grid(pady=5, row=5, column=0)

image_label = Label(root)
image_label.grid(pady=40, row=6, column=0)
image_path = "images/QuestionBlock.png"  
image = PhotoImage(file=image_path)
image_label.image = image
image_label.configure(image=image, height=200, width=200, bg="white")

textoaux = "Escriba un animal del listado!"

def buscar():
    specie = especieInput.get()
    with open("input.txt", "w") as file:        
        file.write(f"about({specie}).")
    os.system(f"swipl especies.pl < input.txt > output.txt")
    result = ""
    with open("output.txt", "r") as file:
        result = file.readlines()
        cosa = ""
        for x in range(0, len(result)):
            cosa = cosa + "\n" +str(result[x]).replace("\n", " ").replace("(", " ").replace(")", " ").replace("_", " ").replace("imagen","").replace(".png", "")
    textResult.delete("1.0", "end")
    textResult.insert(INSERT, str(cosa)[:-11])
    textResult.config(highlightbackground="black", highlightthickness=2)
    
    for r in result:
        if "imagen" in r:
            image_path = r.split("(")[1].split(")")[0]
            break
    else:
        textResult.insert(INSERT, str(textoaux))
        image_path = "pk.png"  

    image = PhotoImage(file="images/"+image_path)
    image_label.image = image
    image_label.configure(image=image, height=200, width=200, highlightbackground="gray", highlightthickness=2)
    
btnConsultar = Button(
    text="Buscar",
    font=("Arial", 16),
    command=buscar
).grid(pady=5, row=4, column=0)

root.config(bg="white")
root.mainloop()