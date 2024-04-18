import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # Importar la clase Axes3D
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier

# Recuperar datos
df = pd.read_csv(r'EJEMPLOS MACARIO/datos-salarios.csv')

# Especificar los datos y sus etiquetas
X = df[['Salario', 'Experiencia']]
y = df['Categoria']

# Para visualizar gráfica de dispersión tridimensional
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')  # Agregar la proyección tridimensional

# Puntos para cada categoría
ax.scatter(df.loc[df['Categoria'] == 'junior', 'Salario'],
           df.loc[df['Categoria'] == 'junior', 'Experiencia'],
           c="red",
           label="junior")
ax.scatter(df.loc[df['Categoria'] == 'semi senior', 'Salario'],
           df.loc[df['Categoria'] == 'semi senior', 'Experiencia'],
           c="orange",
           label="semi senior")
ax.scatter(df.loc[df['Categoria'] == 'senior', 'Salario'],
           df.loc[df['Categoria'] == 'senior', 'Experiencia'],
           c="green",
           label="senior")

# Etiquetas de ejes
ax.set_xlabel("Salary USD x Month")
ax.set_ylabel("Experience")
ax.set_zlabel("Category")
ax.legend()

# Calcular k
k = int(np.sqrt(X.shape[0]))

if k % 2 == 0:  # Hacer que K sea impar
    k = k + 1

knn = KNeighborsClassifier(n_neighbors=k)

knn.fit(X, y)

# Probar
print(f'\nProbar algoritmo con {k=}')
salario = float(input("Indique el salario mensual en miles de UD$: "))
experiencia = float(input("Indique la experiencia en años: "))

dfp = pd.DataFrame()
dfp['Salario'] = [salario]
dfp['Experiencia'] = [experiencia]

ax.scatter(dfp['Salario'],
           dfp['Experiencia'],
           np.max(df['Experiencia']) + 1,  # Asegurar que el punto esté en la parte superior
           c="black",
           marker='X',  # Usar un marcador diferente para el nuevo punto
           s=100)  # Tamaño del marcador

prediccion = knn.predict(dfp)

# Mostrar gráfica de dispersión tridimensional
plt.show()

print('\nCon los datos')
print(dfp)
print('La categoría predicha es:')
print(prediccion)
