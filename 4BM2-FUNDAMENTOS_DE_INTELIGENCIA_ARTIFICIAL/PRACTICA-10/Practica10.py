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

dataFrame = pd.read_csv('PRACTICAKNN.csv')

#Gets the characteristics of interest
X = dataFrame[["LifeExpectancy","PIBPerCapital","CO2Emissions",]]

for k in range(2,10):
    silhouette_visualizer(skl.KMeans(k, random_state=42), X, colors='yellowbrick')

#The Elbow
model = skl.KMeans()
visualizer = KElbowVisualizer(model, k=(1, 10))

visualizer.fit(X)
visualizer.show()

plot.show()


k = int(input("Indique el número de clusters k: "))

#Initial for the clustering algorithm with the user-specified parameter K
kMeansModel = skl.KMeans(n_clusters=k)

#Upload data
kMeansModel.fit(X)

#Gets the centroids
centroids = kMeansModel.cluster_centers_


#Gets a list with the data labels
label = kMeansModel.predict(X)

#Add to data frame a column for classification labels
dataFrame['label'] = label

#Visualization of two clusters
fig = plot.figure()
ax = fig.add_subplot(projection='3d')

ax.set_xlabel('LifeExpectancy')
ax.set_ylabel('PIBPerCapital')
ax.set_zlabel('CO2Emissions')

ax.scatter(dataFrame.loc[dataFrame['label'] == 0, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 0, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 0, 'CO2Emissions'],
           c="cyan")
ax.scatter(dataFrame.loc[dataFrame['label'] == 1, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 1, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 1, 'CO2Emissions'],
           c="blue")
ax.scatter(dataFrame.loc[dataFrame['label'] == 2, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 2, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 2, 'CO2Emissions'],
           c="green")
ax.scatter(dataFrame.loc[dataFrame['label'] == 3, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 3, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 3, 'CO2Emissions'],
           c="yellow")
ax.scatter(dataFrame.loc[dataFrame['label'] == 4, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 4, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 4, 'CO2Emissions'],
           c="orange")
ax.scatter(dataFrame.loc[dataFrame['label'] == 5, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 5, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 5, 'CO2Emissions'],
           c="hotpink")
ax.scatter(dataFrame.loc[dataFrame['label'] == 6, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 6, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 6, 'CO2Emissions'],
           c="red")
ax.scatter(dataFrame.loc[dataFrame['label'] == 7, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 7, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 7, 'CO2Emissions'],
           c="violet")
ax.scatter(dataFrame.loc[dataFrame['label'] == 8, 'LifeExpectancy'],
           dataFrame.loc[dataFrame['label'] == 8, 'PIBPerCapital'],
           dataFrame.loc[dataFrame['label'] == 8, 'CO2Emissions'],
           c="purple")
plot.show()
dataFrame.to_csv('datos-agupados-eight.csv', encoding='ISO-8859-1')
