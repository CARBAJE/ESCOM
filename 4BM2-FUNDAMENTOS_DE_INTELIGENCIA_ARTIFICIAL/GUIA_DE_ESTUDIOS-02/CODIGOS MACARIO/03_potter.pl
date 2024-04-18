%===========================
% Identificación
%===========================
% Genalogía de Harry Potter
% Autor: J. K. Rowling
% Fecha: 07/09/2021
%===========================
%Sección de HECHOS
%===========================

%Atributos de objetos

hombre(james).
hombre(harry).
hombre(james_sirius).
hombre(albus_severus).
hombre(arthur).
hombre(fred).
hombre(george).
hombre(ron).
hombre(hugo).

mujer(lily).
mujer(ginny).
mujer(lily_luna).
mujer(molly).
mujer(hermione).
mujer(rose).

%Relaciones entre objetos

conyugue(james, lily).
conyugue(harry, ginny).
conyugue(molly, arthur).
conyugue(ron, hermione).

% Semántica:  progenitura(hijo, padre).
%
progenitura(harry,james).
progenitura(harry,lily).
progenitura(ginny,molly).
progenitura(ginny, arthur).
progenitura(ron,molly).
progenitura(ron, arthur).
progenitura(james_sirius,harry).
progenitura(james_sirius,ginny).
progenitura(albus_severus,harry).
progenitura(albus_severus,ginny).
progenitura(lily_luna, harry).
progenitura(lily_luna, ginny).
progenitura(fred, molly).
progenitura(fred, arthur).
progenitura(george, molly).
progenitura(george, arthur).
progenitura(rose, ron).
progenitura(rose, hermione).
progenitura(hugo, ron).
progenitura(hugo, hermione).

%===========================
%Sección de REGLAS
%===========================

% Semántica: esposa(la_esposa, el_esposo).
esposa(X,Y):-mujer(X),( conyugue(X,Y) ; conyugue(Y,X) ).
esposo(X,Y):-hombre(X), (conyugue(X,Y); conyugue(Y, X)).

% Semántica: los argumentos son hermanos
hermanos(X,Y):-progenitura(X,Z),
               progenitura(Y,Z),
               X\==Y.

% Semantica:  tio(tio, sobrino).
tio(T,S):-progenitura(S, P),
          hermanos(P, T).

% Semantica: descendiente(descendiente, ancestro).
%

descendiente(X, Y):-progenitura(X,Y). %Caso base
descendiente(X, Y):-progenitura(X,Z), descendiente(Z,Y).


%===========================
% FIN del código
%===========================

%findall(X, hombres(X), L).
%(Encuentra todos las X y las almacena en la lista X



























