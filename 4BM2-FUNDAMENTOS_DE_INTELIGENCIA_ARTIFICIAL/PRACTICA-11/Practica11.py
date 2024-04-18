# -*- coding: utf-8 -*-
"""
Created on Thu Jun  8 11:42:18 2023

@author:
"""

import pandas as pd
from matplotlib import pyplot as plt
import sklearn.tree as skl
from sklearn.tree import plot_tree
from sklearn.preprocessing import LabelEncoder


#Adquiere los datos desde un archivo csv usando biblioteca PANDAS
dataframe = pd.read_csv(r'Pactica11.csv', encoding='ISO-8859-1')

#Preprocesamiento (Transformar valores categóricos a numéricos)
AgeRange=LabelEncoder()
Gender=LabelEncoder()
BloodPressure=LabelEncoder()
Cholesterol=LabelEncoder()
Medicine=LabelEncoder()

dataframe['AgeRange']=AgeRange.fit_transform(dataframe['AgeRange'])
dataframe['Gender']=Gender.fit_transform(dataframe['Gender'])
dataframe['BloodPressure']=BloodPressure.fit_transform(dataframe['BloodPressure'])
dataframe['Cholesterol']=Cholesterol.fit_transform(dataframe['Cholesterol'])
dataframe['Medicine']=Medicine.fit_transform(dataframe['Medicine'])

#Prepara los datos
features_cols=['AgeRange','Gender','BloodPressure','Cholesterol']
X=dataframe[features_cols]
y=dataframe.Medicine

#Entrenamiento
tree = skl.DecisionTreeClassifier(criterion='gini')
tree.fit(X,y)

# Visualización
px = 1/plt.rcParams['figure.dpi']  # Pixel en pulgadas
fig = plt.figure(figsize=(1000*px, 1000*px))
_ = plot_tree(tree, feature_names=features_cols, class_names=['No', 'Yes'], filled=True)

plt.show()


# Probar el Modelo

dfprueba = pd.DataFrame()
dfprueba[ 'AgeRange'] = [1] # rain
dfprueba[ 'Gender'] = [0] # cool
dfprueba[ 'BloodPressure'] = [0] # high
dfprueba[ 'Cholesterol'] =[0] # strong

prediccion = tree.predict(dfprueba)

print('Resultado de la prueba')
print('**********************')
print('Con los datos')
print(dfprueba)
print('\nSe recomienda:')
if(prediccion[0]==0):
    print('Tomar Medicina A')
else:
    print('Tomat Medicina B')
print("**********************")

