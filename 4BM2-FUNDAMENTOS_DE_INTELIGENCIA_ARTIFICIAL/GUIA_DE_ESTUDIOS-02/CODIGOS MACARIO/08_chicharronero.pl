%===========================
% Identificacion
%===========================
% Descripcion: Ecuacion cuadratica
% Autor:
% Fecha:
%===========================


main:-cls,writeln('Resolucion de una ecuacion de segundo grado:\n'),
	 writeln('AX^2 + BX + C = 0'),
	 write('Indique el valor de A:'),read(A),
	 write('Indique el valor de B:'),read(B),
	 write('Indique el valor de C:'),read(C),
	 chicharronero(A,B,C).

cls:-write('[\e[2J').

chicharronero(A,B,C):-D is B^2-4*A*C,
	     (( (D < 0 ; A = 0), writeln('Sin soluciones reales'));
		(D >= 0 , A \= 0,
		 R is sqrt(D),
		 X1 is (-B+R)/(2*A),
		 X2 is (-B-R)/(2*A),nl,
		 format('X1 = ~g',X1),
		 format('\nX2 = ~g',X2)) ).


% Probar con: 3x^2-5x+2=0
% A = 3, B = -5, C=2, X1 = 1, X2=2/3

















