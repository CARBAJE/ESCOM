# -*- coding: utf-8 -*-
"""
Created on Sun Jun 11 21:25:13 2023

@author: 
"""

import matplotlib.pyplot as plot
import geopandas

world = geopandas.read_file(geopandas.datasets.get_path('naturalearth_lowres'))
ax = world.plot()



world[world.name == 'Mexico'].plot(color='lightgreen',ax=ax)
world[world.name == 'United States of America'].plot(color='green',ax=ax)
world[world.name == 'Egypt'].plot(color='violet',ax=ax)
world[world.name == 'Chad'].plot(color='rebeccapurple',ax=ax)


plot.show()