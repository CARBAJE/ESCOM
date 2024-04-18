%
% Recursividad
%

factorial(0,1).
factorial(N,F):- N > 0, N1 is N-1, factorial(N1,F1), F is N*F1.



























multiplica(A,1,M):- M is A.
multiplica(A,B,M):- B > 1, B1 is B-1, multiplica(A,B1,M1), M is M1+A.




potencia(_,0,1).
potencia(X,P,Y):- P > 0, P1 is P-1, potencia(X,P1,Y1), Y is Y1*X.


fibonacci(0,0).
fibonacci(1,1).
fibonacci(X,Y):-X>1, X1 is X - 1, fibonacci(X1,Y1),
		     X2 is X - 2, fibonacci(X2,Y2),
		     Y is Y1 + Y2.





































