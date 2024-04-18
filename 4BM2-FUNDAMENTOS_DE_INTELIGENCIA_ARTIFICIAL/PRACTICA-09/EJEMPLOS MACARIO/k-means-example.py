# -*- coding: utf-8 -*-
"""
Created on Wed Oct 27 12:35:35 2021

@author:
"""

import pandas as pd
import matplotlib.pyplot as plot
import sklearn.cluster as skl

#Adquiere los datos desde un archivo csv usando biblioteca PANDAS
dataframe = pd.read_csv(r'datos-salarios.csv', encoding='ISO-8859-1')
x = dataframe['Salario']
y = dataframe['Experiencia']


#Tomamos únicamente las características x,y para el set de entrenamiento
X = pd.DataFrame()
X['x'] = x
X['y'] = y

#Solicita al usuario el número de Clusters - Parámetro K
k = int(input("Indique el número de clusters k: "))

#Inicialización para algoritmo de clustering con el parámetro K indicado por el usuario
kmeansModel = skl.KMeans(n_clusters=k)

#Carga los datos
kmeansModel.fit(X)

#Obtiene los centroides
centroides = kmeansModel.cluster_centers_


#Obtiene una lista con las etiquetas de los datos
etiquetas = kmeansModel.predict(X)


#Agrega al frame de datos una columna para las etiquetas de clasificación
dataframe['clase_K-means'] = etiquetas

#Tabla de colores
colores =['red','orange','green','pink','blue'] 

colores_datos=[]
colores_centroides=[]

for row in etiquetas:
    colores_datos.append(colores[row])

for i in range(len(centroides)):
    colores_centroides.append(colores[i])

#Grafica de dispersión
ax = plot.axes()
ax.scatter(x, y, c=colores_datos, marker='o', s=40)
ax.scatter(centroides[:,0], centroides[:,1], c=colores_centroides, marker='+', s=200)
plot.xlabel('Salario k $USD Mensual')
plot.ylabel('Experiencia Años')
plot.title('K-Means Clustering Salarios vs Experiencia')
plot.grid(color='gray', linestyle='--', linewidth = 0.5)
plot.show()


dataframe.to_csv('salarios-agupados.csv', encoding='ISO-8859-1')