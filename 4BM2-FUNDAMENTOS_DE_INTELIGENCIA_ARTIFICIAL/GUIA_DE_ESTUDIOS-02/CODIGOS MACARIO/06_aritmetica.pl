cls:-write('[\e[2J').

sumar:-writeln(' Dame un número: '), read(A),
       writeln(' Dame otro número: '), read(B),
       C is A+B,
       format('La suma es: ~g',C).

sumar(A, B):-C is A+B, format('La suma es: ~g',C).

sumar(A, B, C):- C is A+B.

potencia(X, N, P):-P is X^N.

residuo(A, B, M):- M is A mod B.

par(N):-M is N mod 2, M = 0.

raiz(X, R):-X >= 0, R is sqrt(X).


imc(P, E, I):- E > 0, P > 0, I is P/E^2.

imc:-writeln('Cálculo del índice de masa corporal'),
     writeln('Indique su peso en Kg:'), read(P),
     writeln('Indique su estatura en Metros:'), read(E),
     imc(P, E, I), format('\nEl IMC es ~g',I).


convertir(C, F):-F is C*(9/5)+32.


