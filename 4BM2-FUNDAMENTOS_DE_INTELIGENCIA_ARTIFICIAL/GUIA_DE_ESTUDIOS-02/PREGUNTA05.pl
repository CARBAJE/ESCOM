
bienvenida:- writeln('Se realizará la suma de una lista en este programa.') ,
    suma([1 , 4 , 2 , 5 , 3] , S) ,
    write('La suma es: ') , writeln(S) ,
    write('A continuación se da el factorial de S: '),
    factorial(S , R) , writeln(R).

suma([] , 0).
suma([H|T], S) :- suma(T,S1) , S is H+S1.

factorial(0 , 1).
factorial(S , R) :- S1 is S-1 , factorial(S1 , R1) , R is S*R1.
