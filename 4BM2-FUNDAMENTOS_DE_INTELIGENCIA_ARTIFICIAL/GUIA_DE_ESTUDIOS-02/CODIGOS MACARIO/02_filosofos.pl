%Autor:
%Fecha:
%Introducción a Prolog

%Hechos

humano(socrates).
humano(platon).
humano(aristoteles).

% discipulo(discipulo, maestro).

discipulo(platon,socrates).
discipulo(aristoteles, platon).

%Reglas

mortal(X):-humano(X).

%Consultar   ?- mortal(socrates).

