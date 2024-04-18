%Base de conocimientos basada en marcos

frame(animal,subclase_de(objeto),propiedades([puede(sentir), puede(respirar)])).
frame(insecto,subclase_de(animal), propiedades([tiene(exoesqueleto)])).
frame(reptil,subclase_de(animal), propiedades([tiene(escamas),tiene(sangre_fria)])).
frame(luciernaga,subclase_de(insecto), propiedades([tiene(trasero_luminoso)])).
frame(caiman,subclase_de(reptil), propiedades([tiene(hocico_grande)])).

%Reglas de inferencia
subc(C1,C2):- frame(C1,subclase_de(C2),_).
subc(C1,C2):- frame(C1,subclase_de(C3),_),subc(C3,C2).
subclase(X):-frame(X,subclase_de(_),_).

%Para consultar propiedades use: propiedadesc(luciernaga, L).
propiedadesc(objeto,_):-!.
propiedadesc(X,Z):-frame(X,subclase_de(Y),propiedades(P)),propiedadesc(Y,P1), append(P,P1,Z).

%Para consultar todas las clases representadas en los frames
clases(L):-findall(X,frame(X,subclase_de(_),propiedades(_)),L).

%Para consultar todas las subclases de una una clase
subclases_de(X,L):-findall(C1,subc(C1,X),L).

%Para consultar todas las superclases de una clase
superclases_de(X,L):-findall(C1,subc(X,C1),L).

%Para consultar qué objetos tienen UNA propiedad determinada
tiene_propiedad(P,Objs):-frame(X,_,propiedades(L)),member(P,L),subclases_de(X,S),select(X,Objs,S),!.

%Obtiene todas las propiedades de todos los objetos
todas_propiedades(L):-findall(P,frame(_,_,propiedades(P)),NL), flatten(NL,L).

% Obtiene una lista de clases con los objetos que tienen la propiedades
% de la lista de entrada en P
consulta_por_propiedades(P,C):-consulta(P,C1),list_to_set(C1,C2),sort(C2,C).

consulta([],[]).
consulta([H|T],C):-consulta(T,C1), tiene_propiedad(H,C2),append(C1,C2,C).

%Es hoja (regresa verdadero si la clase no tiene subclases)
%
es_hoja(Clase):-subclases_de(Clase,L),L = [].







