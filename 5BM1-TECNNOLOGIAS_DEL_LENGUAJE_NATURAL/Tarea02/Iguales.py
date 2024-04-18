from Palabra import Palabra

def diccionarioInicial():
    diccionario = []
    diccionario.append(Palabra("carro", "car", 0))
    diccionario.append(Palabra("manzana", "apple", 0))
    diccionario.append(Palabra("perro", "dog", 0))
    diccionario.append(Palabra("rojo", "red", 0))
    diccionario.append(Palabra("amanecer", "dawn", 0))
    diccionario.append(Palabra("alba", "dawn", 0))

    return diccionario

def solicitarPalabra():
    return input("Ingrese una palabra a traducir: ").lower()

def encontrarTraduccion(diccionario, palabra):
    traducciones = []
    for tupla in diccionario:
        if tupla.original == palabra:
            traducciones.append(tupla.traduccion)
        if tupla.traduccion == palabra:
            traducciones.append(tupla.original)
    return traducciones

def eliminarDuplicados(traducciones):
    temp = []
    for traduccion in traducciones:
        if traduccion not in temp:
            temp.append(traduccion)
    return temp

def actualizarContador(diccionario, traducciones):
    for palabra in traducciones:
        for el in diccionario:
            if palabra == el.original or palabra == el.traduccion:
                el.contador += 1

def solicitartraduccion():
    traduccion = input("Ingrese una palabra a traducir: ").lower()
    return traduccion

def anidarEntrada(diccionario, palabra):
    opcion = input("Desea ingresar la palabra al diccionario? [Y/n]")
    if opcion == 'Y' or opcion == 'y':
        diccionario.append(Palabra(palabra,solicitartraduccion(), 0))
    else:
        print(f"No se agregara la palabra: '{palabra}'")

def distanciaLevenshtein(cadena1, cadena2):
    if not cadena1:
        return len(cadena2)
    if not cadena2:
        return len(cadena1)

    costo = 0 if cadena1[0] == cadena2[0] else 1

    return min(distanciaLevenshtein(cadena1[1:], cadena2) + 1,
               distanciaLevenshtein(cadena1, cadena2[1:]) + 1,
               distanciaLevenshtain(cadena1[1:], cadena2[1:] + costo)
               )

def buscarSimiles(palabra, diccionario):
    listaSimiles = []
    for entrada in diccionario:
        listaSimiles.append((entrada.original, distanciaLevenshtein(palabra, entrada.original)))
        lista
    print(listaSimiles)

    listaSimiles.sort(key=lambda x: x[1])

    print(listaSimiles[:3])

    return listaSimiles[3]

def errorTipografico(palabra, diccionario):
    buscarSimiles(palabra, diccionario)


def buscarPalabra(diccionario, palabra):
    traducciones = eliminarDuplicados(encontrarTraduccion(diccionario, palabra))
    if traducciones:
        print(f"La palabra '{palabra}' tiene como traducciones: {', '.join(traducciones)}")
        actualizarContador(diccionario, traducciones)
    else:
        print("La palabra no tiene traducción en este diccionario.")
        errorTipografico(palabra, diccionario)
        anidarEntrada(diccionario, palabra)
    return traducciones, diccionario

traduccion, diccionario =buscarPalabra(diccionario=diccionarioInicial(),
                      palabra=solicitarPalabra())
for entrada in diccionario:
    print(entrada)
