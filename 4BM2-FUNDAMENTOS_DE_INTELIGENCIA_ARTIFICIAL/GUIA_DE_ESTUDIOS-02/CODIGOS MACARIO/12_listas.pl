
% Operaciones sobre listas


% Verifica si un elemento pertenece a la lista
% ?- pertenece(c,[a,b,c])

pertenece(E,[E|_]).
pertenece(E,[_|T]):-pertenece(E,T).

% Calcula la longitud de una lista
% ?- longitud([a,b,c],N).

longitud([],0).
longitud([_|Y],Len):-longitud(Y,Len1),Len is Len1+1.


% Unir dos listas en una tercera
% ?- concatenar([a,b],[c,d],L).

concatenar([],L,L).
concatenar([X|L1],L2,[X|L3]):-concatenar(L1,L2,L3).

% Encuentrea el enesimo elemento de la lista
% ?- enesimo(X,3,[a,b,c,d]).     Se obtiene 'c'

enesimo(X,1,[X|_]).
enesimo(X,N,[_|L]):-R is N-1, enesimo(X,R,L).

% Genera nueva lista sin el elemento indicado

quitar(X,[X|T],T).
quitar(X,[Y|T],[Y|T1]) :-quitar(X,T,T1).


% Simula una PILA
% ?- push([1,2,3],E,L).
% ?- pop([1,2,3],E,L).


push(P,E, [E|P]).
pop([H|T],H, T).



%Obtiene la suma de los elementos de una lista
%?- suma([1,2,3,4], S).

suma([],0).
suma([H|T],S):-suma(T,S1),S is S1+H.

% Obtiene el promedio de los elementos de la lista
promedio(L,P):-suma(L,S), longitud(L,Len),P is S/Len.


% Agregar un elemento al final de una lista
% ?- agregar_final([a,b],c,L).

agregarFinal([],E,[E]).
agregar_final([C|R],E,[C|RL]) :- agregar_final(R,E,RL).

%  Invertir una lista
%  ?-de_reversa([1,2,3],L).

de_reversa([X],[X]).
de_reversa([C|R],L) :- de_reversa(R,RI), agregar_final(RI,C,L).


% Verifica si una lista esta ordenada

ordenada([]).
ordenada([_]).
ordenada([X,Y|L]):- X @=< Y, ordenada([Y|L]).

% Verifica si el argumento es una lista
% ?- es_lista([a]).
es_lista([]).
es_lista([_|T]):-es_lista(T).

%Imprime los elementos de una lista un elemento por renglón
imprime([]).
imprime([H|T]):-writeln(H),imprime(T).


%Obtiene el último elementos de una lista
ultimo([X],X).
ultimo([_|T],X):-ultimo(T,X).

% Verifica si la lista es palindroma
palindroma(L):-de_reversa(L,L).














