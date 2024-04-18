#ALumnos:
#Carrillo Barreiro Jose Emiliano
#Escobar Montoya Patricio

import random
import items
import matplotlib.pyplot as plt

rutaArchivo = "listaItems.txt"

#Restriccion 01: Limite de peso
maxPeso = 30 #libras
#Restriccion 02: Limite de cantidade de items
maxItems = 10
#Restriccion 03: Minima cantidad de ciertos objetos
restriccion03 = {
    "LovePotion" : 3,
    "SkivingSnackbox" : 2,
}

#Parametros del algoritmo genetico
Poblacion = 10
NumGeneraciones = 50
CruzaProb = 0.85
MutacionProb = 0.1

#Obtenemos los items del archivo y creamos un arreglo de los items
listaItems =[]
with open(rutaArchivo, "r") as archivo:
    for linea in archivo:
        nuevaLinea = linea.strip()
        nuevaLinea = nuevaLinea.split(" ")
        id, nombre, peso, precio = nuevaLinea[0], nuevaLinea[1], nuevaLinea[2], nuevaLinea[3]
        item = items.Item(int(id), nombre, float(peso), int(precio))
        listaItems.append(item)
        #print(item.id, item.nombre, item.peso, item.precio)
        #print()

#Creamos una solucion "cromosomas" sin validar
def crearSolucion(listaI):
    solucion = []
    for i in range(0, len(listaI)):
        #Restriccion 03: Minima cantidad de ciertos objetos
        if listaI[i].nombre == "LovePotion":
            solucion.append(random.randint(3,maxItems))
        elif listaI[i].nombre == "SkivingSnackbox":
            solucion.append(random.randint(2,maxItems))
        else:
            solucion.append(random.randint(0,maxItems))
    return solucion

#Validamos la solucion respecto a la <<Restriccion01>>
def validarSolucion(listaI, listaSol, pesoMax):
    pesoTotal = 0
    for i in range(0,len(listaSol)):
        pesoTotal += listaSol[i] * listaI[i].peso
        if pesoTotal > pesoMax:
            return False
    for i, item in enumerate(listaI):
        if item.nombre in restriccion03 and listaSol[i] < restriccion03[item.nombre]:
            return False
    return True

#Calculamos el valor de la solucion
def CalcularValor(listaI, listaSol):
    valorTotal = 0
    for i in range(0, len(listaSol)):
        valorTotal += listaSol[i] * listaI[i].precio
    return valorTotal

#Checamos si dos soluciones son iguales
def checarDupicidad_enSoluciones(sol1, sol2):
    for i in range(0, len(sol1)):
        if sol1[i] != sol2[i]:
            return False
    return True

#Creamos la poblacion inicial
def poblacionInicial(numIntegrantes, listaI, pesoMax):
    poblacion = []
    i = 0
    while i < numIntegrantes:
        solucion = crearSolucion(listaI)
        if validarSolucion(listaI, solucion, pesoMax):
            if len(poblacion) == 0:
                poblacion.append(solucion)
                i += 1
            else:
                anidar = True
                for j in range(0, len(poblacion)):
                    if checarDupicidad_enSoluciones(solucion, poblacion[j]):
                        anidar = False
                        break
                if anidar:
                    poblacion.append(solucion)
                    #print(solucion)
                    i += 1
    return poblacion

#Seleccionamos un par de soluciones para ser padres
def seleccionRuleta(poblacion, listaI):
    ValorTotalPoblacion = 0
    for solucion in poblacion:
        ValorTotalPoblacion += CalcularValor(listaI, solucion)

    solucionesProb = []
    for solucion in poblacion:
        solucionesProb.append(CalcularValor(listaI, solucion) / ValorTotalPoblacion)

    PadresSeleccionados = []
    while True:
        probAcomulada = 0
        numRand = random.random()
        for i, prob in enumerate(solucionesProb):
            probAcomulada += prob
            if numRand <= probAcomulada:
                padreSeleccionado = poblacion[i]
                if not PadresSeleccionados or not checarDupicidad_enSoluciones(PadresSeleccionados[-1], padreSeleccionado):
                    PadresSeleccionados.append(padreSeleccionado)
                break
        if len(PadresSeleccionados) == 2:
            break
    return PadresSeleccionados

#Cruzamos los padres
def cruzaUniforme(padre1, padre2, probU):
    hijo = []
    for genPadre1, genPadre2 in zip(padre1, padre2):
        if random.random() < probU:
            hijo.append(genPadre1)
        else:
            hijo.append(genPadre2)
    if validarSolucion(listaItems, hijo, maxPeso):
        return hijo
    else:
        return cruzaUniforme(padre1, padre2, probU)

#Mutacion (en representacion de genes tipo int)
def mutacion(solucion, intentos_maximos=100):
    solMutada = solucion[:]
    for _ in range(intentos_maximos):
        for i in range(len(solucion)):
            solMutada[i] = int(float(solMutada[i]) * random.random())

        if validarSolucion(listaItems, solMutada, maxPeso):
            return solMutada

    # Si no se encuentra una solución válida después de intentos_maximos, se devuelve la solución original
    return solucion

def ReemplazoMasDebil(hijo1, hijo2, padre1, padre2):
    soluciones = [hijo1, hijo2, padre1, padre2]
    aptos = []
    for i in range(len(soluciones)):
        valor = CalcularValor(listaItems,soluciones[i])
        aptos.append((soluciones[i], valor))

    mejor_solucion = None
    segunda_mejor_solucion = None
    mejor_valor = float('-inf')
    segundo_mejor_valor = float('-inf')

    for solucion, valor in aptos:
        if valor > mejor_valor:
            segunda_mejor_solucion = mejor_solucion
            segundo_mejor_valor = mejor_valor
            mejor_solucion = solucion
            mejor_valor = valor
        elif valor > segundo_mejor_valor and mejor_solucion != solucion:
            segunda_mejor_solucion = solucion
            segundo_mejor_valor = valor

    return mejor_solucion, segunda_mejor_solucion

def crearGeneracion(poblacion, mutaProb, cruzaProb, listaI):
    Generacion = []
    i = 0
    selSob = random.random()
    while i < len(poblacion):
        if random.random() < cruzaProb:
            padre1, padre2 = seleccionRuleta(poblacion, listaI)
            hijo1 = cruzaUniforme(padre1, padre2, 0.5)
            hijo2 = cruzaUniforme(padre1, padre2, 0.5)

            if random.random() < mutaProb:
                hijo1 = mutacion(hijo1)
                hijo2 = mutacion(hijo2)

            if selSob > 0.5:
                Generacion.extend([hijo1, hijo2])
            else:
                electo1, electo2 = ReemplazoMasDebil(hijo1, hijo2, padre1, padre2)
                Generacion.extend([electo1, electo2])
            i+=2
    return Generacion

def mejorSolucion(generacion, listaI):
    mejorVal = 0
    for i in range(len(generacion)):
        actual = int(CalcularValor(listaI, generacion[i]))
        if actual > mejorVal:
            mejorVal = actual
    return mejorVal

def algoritmoGenetico(pesoMax, tamPob, numGen, mutaProb, cruzaProb, listaI):
    listaMejoresVal = []
    poblacion = poblacionInicial(tamPob, listaI, pesoMax)
    #print(poblacion)
    print()
    for i in range(numGen):
        poblacion = crearGeneracion(poblacion, mutaProb, cruzaProb, listaI)
        listaMejoresVal.append(mejorSolucion(poblacion, listaI))

        print("Generacion:", i)
        #print(poblacion, " valorMax --> ", listaMejoresVal[-1])
        #print()
    return poblacion, listaMejoresVal

_, MejoresValores = algoritmoGenetico(pesoMax=maxPeso,
                                                    tamPob=Poblacion,
                                                    numGen=NumGeneraciones,
                                                    mutaProb=MutacionProb,
                                                    cruzaProb=CruzaProb,
                                                    listaI=listaItems)

#Graficamos el proceso
plt.plot(MejoresValores)
plt.xlabel('Generaciones')
plt.ylabel('Valores')
plt.title('Mejor valor por generacion')
plt.show()
