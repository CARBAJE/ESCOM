:-dynamic noviazgo/2.

% Al declarar el predicado noviazgo como din�mico la m�quina de Prolog
% permitir� assert y retract


% Agregar un nevo noviazgo
nuevo_noviazgo(X,Y):-not(noviazgo(X,Y)), assert(noviazgo(X,Y)).

%Rompimiento
%
rompimiento(X,Y):-retract(noviazgo(X,Y));retract(noviazgo(Y,X)).


% Cambiar pareja a X
cambiar_pareja(X,Y):-noviazgo(X,_),retractall(noviazgo(X,_)),
	          ( not(noviazgo(_,Y)) ;(noviazgo(_,Y),
                    retractall(noviazgo(_,Y)))),
                    assert(noviazgo(X,Y)).

% listing muestra las cl�usulas
ver_noviazgos:-listing(noviazgo).

agregar_regla(R):-assert(R),listing(R).


