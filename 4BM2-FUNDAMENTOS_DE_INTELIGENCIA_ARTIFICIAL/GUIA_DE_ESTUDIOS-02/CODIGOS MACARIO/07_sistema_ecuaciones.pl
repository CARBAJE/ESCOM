%===========================
% Identificacion
%===========================
% Descripcion: Sistema de ecuaciones de primer grado
% Autor:
% Fecha:
%===========================


main:-nl,cls,writeln('Resolucion de un sistema de ecuaciones:\n'),
	 writeln('A1x + B1y = C1'),
	 writeln('A2x + B2y = C2\n'),
	 write('Indique el valor de A1:'),read(A1),
	 write('Indique el valor de B1:'),read(B1),
	 write('Indique el valor de C1:'),read(C1),
	 write('Indique el valor de A2:'),read(A2),
	 write('Indique el valor de B2:'),read(B2),
	 write('Indique el valor de C1:'),read(C2),
	 sistema_ecuaciones(A1,B1,C1,A2,B2,C2).

cls:-write('[\e[2J').

sistema_ecuaciones(A1,B1,C1,A2,B2,C2):-
	 Delta  is (A1*B2-A2*B1),
         ((Delta = 0,writeln('\nSin solucion, son rectas paralelas'));
	  (Delta \= 0,DeltaX is (C1*B2-C2*B1),
	   DeltaY is (A1*C2-A2*C1),
           X is DeltaX/Delta,
	   Y is DeltaY/Delta,
	   writeln('\nSoluciones:'),
	   format('\nx = ~g',X),
	   format('\ny = ~g',Y))).

%Probar con:
%  4x + 3y = 11
%  5x - 2y = 8
%
%  x = 2, y = 1
%





