import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D  # Importar la Class Axes3D
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier

#Data Collection
df = pd.read_csv(r'PRACTICAKNN.csv')

# Data and label Specifications.
X = df[['LifeExpectancy', 'PIBPerCapital' , 'CO2Emissions']]
y = df['Class']

#Tridimensional dispersion Graphic creation
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')  # 3D Projection

# Point per category
ax.scatter(df.loc[df['Class'] == 'Low_income', 'LifeExpectancy'],
           df.loc[df['Class'] == 'Low_income', 'PIBPerCapital'],
           df.loc[df['Class'] == 'Low_income', 'CO2Emissions'],
           c="red",
           label="Low_income")
ax.scatter(df.loc[df['Class'] == 'Lower_Middle_Income', 'LifeExpectancy'],
           df.loc[df['Class'] == 'Lower_Middle_Income', 'PIBPerCapital'],
           df.loc[df['Class'] == 'Lower_Middle_Income', 'CO2Emissions'],
           c="orange",
           label="Lower_Middle_Income")
ax.scatter(df.loc[df['Class'] == 'Upper_Middle_Income', 'LifeExpectancy'],
           df.loc[df['Class'] == 'Upper_Middle_Income', 'PIBPerCapital'],
           df.loc[df['Class'] == 'Upper_Middle_Income', 'CO2Emissions'],
           c="green",
           label="Upper_Middle_Income")
ax.scatter(df.loc[df['Class'] == 'High_Income', 'LifeExpectancy'],
           df.loc[df['Class'] == 'High_Income', 'PIBPerCapital'],
           df.loc[df['Class'] == 'High_Income', 'CO2Emissions'],
           c="blue",
           label="High_Income")

# Axes Labels
ax.set_xlabel("Life Expectancy")
ax.set_ylabel("PIBperCapital(USD)")
ax.set_zlabel("CO2Emissions")
ax.legend()

# Calculate k
k = int(np.sqrt(X.shape[0]))

if k % 2 == 0:  # Do K odd
    k = k + 1

knn = KNeighborsClassifier(n_neighbors=k)

knn.fit(X, y)

#Testing
print(f'\nProbar algoritmo con {k=}')
LifeExpectancy = float(input("Indique la esperanza de vida : "))
PIBPerCapital = float(input("Indique el PIBperCapital: "))
CO2Emissions = float(input("Indique la Emisión de Carbono por persona: "))


dfp = pd.DataFrame()
dfp['LifeExpectancy'] = [LifeExpectancy]
dfp['PIBPerCapital'] = [PIBPerCapital]
dfp['CO2Emissions'] = [CO2Emissions]

ax.scatter(dfp['LifeExpectancy'],
           dfp['PIBPerCapital'],
           np.max(df['CO2Emissions']) + 1,  # Assures that the point will be on the top
           c="black",
           marker='X',  #Use a different market for the next point
           s=100)  # Marker size

prediction = knn.predict(dfp)

# Show tridimensional dispersion graphic
plt.show()

print('\nCon los datos')
print(dfp)
print('La categoría predicha es:')
print(prediction)