%===========================
% Identificacion
%===========================
% Descripcion: Relaciones familiares
% Autor:
% Fecha:
%===========================

%===========================
% Seccion de HECHOS
%===========================


% Semantica: progenitor(Padre o Madre, Hijo).

progenitor(abraham,isaac).
progenitor(isaac,esau).
progenitor(isaac,jacob).
progenitor(jacob,isacar).
progenitor(jacob,juda).
progenitor(jacob,levi).
progenitor(jacob,ruben).
progenitor(jacob,simeon).
progenitor(jacob,zabulon).
progenitor(jacob,jose).
progenitor(jacob,gad).
progenitor(jacob,aser).
progenitor(jacob,dan).
progenitor(jacob,neftali).
progenitor(jacob,benjamin).
progenitor(jose,efrain).
progenitor(jose,manases).

%======================
% Reglas de inferencia
%======================


% Semantica: hijo(Hijo, Padre).

hijo(X,Y):-progenitor(Y,X).

% Semantica: tio(Tio, Sobrino)

tio(T,S):-progenitor(Z,S),progenitor(A,Z),progenitor(A,T),not(progenitor(T,S)).


% Semantica descendiente(alguien, ancestro).

descendiente(X,Y):-progenitor(Y,X).
descendiente(X,Y):-progenitor(Z,X),descendiente(Z,Y).




