# -*- coding: utf-8 -*-
"""
Created on Sun Nov  5 19:24:04 2023

@author: unknown
"""


from swiplserver import PrologMQI


def query_swi_prolog(consulta):

    with PrologMQI() as mqi:
        with mqi.create_thread() as prolog_thread:
            prolog_thread.query("consult('marcos-animalia.pl')")
            result = prolog_thread.query(consulta)
            return result
    
#main

r1 = query_swi_prolog("clases(Clases)");
clases = r1[0].get('Clases')
print("\n=================")
print("Todas las Clases:")
print("=================")
for c in clases:
    print(c)
 
r2  = query_swi_prolog("todas_propiedades(Props)")
propiedades = r2[0].get('Props')
print("\n===============================")    
print("Todas las propiedades")
print("===============================")
print(propiedades)

r3  = query_swi_prolog("tiene_propiedad(tiene(exoesqueleto),Tienen)")
clases_prop = r3[0].get('Tienen')
print("\n===============================")    
print("Clases que: tiene(exoesqueleto)")
print("===============================")
for cp in clases_prop:
    print(cp)

r4  = query_swi_prolog("consulta_por_propiedades([ tiene(hocico_grande),tiene(trasero_luminoso)], Select)")
select = r4[0].get('Select')   
print("\n==============================================")    
print("tiene(hocico_grande) o tiene(trasero_luminoso)")
print("==============================================")
for s in select:
    print(s)

r5  = query_swi_prolog("es_hoja(luciernaga)")
print("\n=======================================")
print("Es luciernaga una clase de más bajo nivel?")    
print(r5)    