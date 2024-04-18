from tkinter import *;
import os;

root = Tk()
root.title("Animal Expert System")

root.config(bg="black")


def consult_specie():
    global especieInput,textResult,labelImg
    specie = especieInput.get()
    with open("input.txt", "w") as file:
        file.write(f"about({specie}).")
        os.system(f"swipl animalia.pl < input.txt > output.txt")
        result = ""
    with open("output.txt", "r") as file:
        result = file.readlines()
    for r in result:
        if "imagen" in r:
            a = r.split("(")[1]
    src = a.split(")")[0]
    print(src)
    image2 = PhotoImage(
    file=f"img/{src}"
    )
    labelImg.configure(
    image=image2
    )
    labelImg.image = image2
    textResult.delete("1.0","end")
    textResult.insert(INSERT,str(result[:-3]))

textResult = Text(
width=45,
height=10
)
textResult.place(
x=270,
y=300
)

frame = Frame()
frame.pack(
fill="both",
expand=True
)

frame.config(
width=600,
height=500,
bg="white"
)

# #qqqqqqqqqq
# titleLabel = Label(
# text="Animal Cola System",
# bg="red",
# font=("Impact",100)
# )

# titleLabel.place(
# x=220,
# y=20
# )


# resimage = PhotoImage(file="Cat2.png")
# labelImg = Label(image=resimage)

# labelImg.place(x=200,y=50)


especieInput = Entry(width=21)
especieInput.place(x=50,y=300)


# specieLabel = Label(
# text="Especie",
# bg="blue",
# font=("Impact",100)
# )

# specieLabel.place(x=50,y=280)


eleccion = IntVar()


btnSpecie = Radiobutton(
text="Conocer especie",
width=18,
bg="white",
font=("Impact",18),
value=1,
variable=eleccion
)

btnSpecie.place(x=50,y=350)


btnListAll = Radiobutton(
text="Listar Especies",
width=18,
bg="white",
font=("Impact",18),
value=2,
variable=eleccion
)

btnListAll.place(
x=50,
y=380
)

def list_species():
    global textResult
    animals = ["vicugna_vicugna",
    "lama_guanicoe",
    "lama_pacos",
    "canis_lupus_familiaris",
    "canis_rufus",
    "canis_latrans",
    "babyrousa_babyrussa",
    "sus_scrofa",
    "pan_troglodytes",
    "gorilla_gorilla",
    "pongo_pygmaeus",
    "puma_concolor",
    "panthera_pardus",
    "leopardus_geoffroyi",
    "elephas_maximus",
    "equus_caballus",
    "ceratotherium_simum",
    "ursus_arctos",
    "ursus_maritimus",
    "ailuropoda_melanoleuca",
    "noctilio_albiventri"]
    textResult.delete("1.0","end")
    textResult.insert(END,str(animals))

def consulta():
    global eleccion,root
    if eleccion.get()==1:
        consult_specie(especieInput)
    if eleccion.get()==2:
        list_species()


def consult_specie(specie):
    with open("input.txt", "w") as file:
        file.write(f"about({specie}).")
    os.system(f"swipl animalia.pl < input.txt > output.txt")
    result = ""
    with open("output.txt", "r") as file:
        result = file.readlines()

        
consultar = Button(
text="Consultar !",
width=17,
command=consulta
)

consultar.place(
x=50,
y=320
)

# Run
root.mainloop()