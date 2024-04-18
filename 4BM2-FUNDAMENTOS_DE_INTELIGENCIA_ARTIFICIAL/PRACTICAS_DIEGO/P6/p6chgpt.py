from tkinter import *
import os

root = Tk()
root.title("Práctica 06 - FIA")
image_label = Label(root, width=150, height=150)
scrollbar = Scrollbar(root)
scrollbar.pack( side = RIGHT, fill = Y )

image_path = ""
textoaux = "Escriba un animal del listado!"

def consult_specie():
    specie = especieInput.get()
    with open("input.txt", "w") as file:        
        file.write(f"about({specie}).")
    os.system(f"swipl animalia.pl < input.txt > output.txt")
    result = ""
    with open("output.txt", "r") as file:
        result = file.readlines()
        cosa = ""
        for x in range(0, len(result)):
            cosa = cosa + "\n" +str(result[x]).replace("\n", "")
    textResult.delete("1.0", "end")
    textResult.insert(INSERT, str(cosa)[:-7])
    
    for r in result:
        if "imagen" in r:
            image_path = r.split("(")[1].split(")")[0]
            break
    else:
        textResult.delete("1.0", "end")
        textResult.insert(INSERT, str(textoaux))
        image_path = "Cat.png"  

    image = PhotoImage(file=image_path)
    image_label.configure(image=image)
    image_label.image = image

titleLabel = Label(
    text="PRACTICA 06 - FIA 4BM1 \nEQUIPO:",
    bg="white",
    font=("Impact", 30)
)

titleLabel.pack()

equipolabel = Label(
    text="CORONA REYES MAURICIO DASSEL\nMARTINEZ MENDEZ DIEGO\nPACHECO SANCHEZ RODRIGO\n",
    bg="white",
    font=("Arial", 12)
)

equipolabel.pack()

espdisp = Label(
    text="ESPECIES DISPONIBLES:",
    bg="white",
    font=("Impact", 12)
)
espdisp.pack()

listaespecies = Label(
    text="vicugna_vicugna\nlama_guanicoe\nlama_pacos\ncanis_lupus_familiaris\ncanis_rufus\ncanis_latrans\nbabyrousa_babyrussa\nsus_scrofa\npan_troglodytes\ngorilla_gorilla\npongo_pygmaeus\npuma_concolor\npanthera_pardus\nleopardus_geoffroyi\nelephas_maximus\nequus_caballus\nceratotherium_simum\nursus_arctos\nursus_maritimus\nailuropoda_melanoleuca\nnoctilio_albiventri    ", 
    bg="white", 
    font=("Arial",8),
    justify="left",
    borderwidth=(2), 
    relief="groove"
)
listaespecies.pack()

especieLabel = Label(
    text="\nEspecie:",
    font=("Arial", 16),
    bg="white",
)
especieLabel.pack()

especieInput = Entry(width=30)
especieInput.pack()

btnConsultar = Button(
    text="Informacion",
    font=("Arial", 16),
    command=consult_specie
)
btnConsultar.pack()

textResult = Text(
    width=50,
    height=5,
    font=("Arial", 12)
)
textResult.pack()
image_label.pack()
root.config(bg="white")
root.mainloop()