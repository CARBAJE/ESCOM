class Palabra:
    def __init__(self, original, traduccion, contador):
        self.original = original
        self.traduccion = traduccion
        self.contador = contador
    def __str__(self):
        return f"Original: {self.original}, Traducción: {self.traduccion}, Contador: {self.contador}"