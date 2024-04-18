# -*- coding: utf-8 -*-
"""
Created on Mon May 22 17:26:53 2023

@author: 
"""

import matplotlib.pyplot as plot
import pandas as pd
import sklearn.cluster as skl
from yellowbrick.cluster import KElbowVisualizer
from yellowbrick.cluster import silhouette_visualizer

dataframe = pd.read_csv('datos-prueba3.csv')

#Obtiene las caracteristicas de interés
X = dataframe[['x1', 'x2','x3']]

for k in range(2,10):
    silhouette_visualizer(skl.KMeans(k, random_state=42), X, colors='yellowbrick')

#El Codo


model = skl.KMeans()
visualizer = KElbowVisualizer(model, k=(1, 10))

visualizer.fit(X) 
visualizer.show() 

plot.show()


k = int(input("Indique el número de clusters k: "))

#Inicialización para algoritmo de clustering con el parámetro K indicado por el usuario
kmeansModel = skl.KMeans(n_clusters=k)

#Carga los datos
kmeansModel.fit(X)

#Obtiene los centroides
centroides = kmeansModel.cluster_centers_


#Obtiene una lista con las etiquetas de los datos
etiqueta = kmeansModel.predict(X)


#Agrega al frame de datos una columna para las etiquetas de clasificación
dataframe['etiqueta'] = etiqueta

#Visualización de 2 clusters
fig = plot.figure()
ax = fig.add_subplot(projection='3d')

ax.set_xlabel('x1')
ax.set_ylabel('x2')
ax.set_zlabel('x3')    
 
ax.scatter(dataframe.loc[dataframe['etiqueta'] == 0, 'x1'],
           dataframe.loc[dataframe['etiqueta'] == 0, 'x2'],
           dataframe.loc[dataframe['etiqueta'] == 0, 'x3'],
           c="blue")
ax.scatter(dataframe.loc[dataframe['etiqueta'] == 1, 'x1'],
           dataframe.loc[dataframe['etiqueta'] == 1, 'x2'],
           dataframe.loc[dataframe['etiqueta'] == 1, 'x3'],
           c="hotpink")

plot.show()

dataframe.to_csv('datos-agupados.csv', encoding='ISO-8859-1')
