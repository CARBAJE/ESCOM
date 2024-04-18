%Base de conocimiento

alumno('20090001','Alvarez Vega David',[10,8,5,9]).
alumno('85090134','Macario Hernandez Cruz',[5, 6, 7, 8]).

%Reglas

consulta(Boleta):-alumno(Boleta,Nombre,Califs),longitud(Califs,Len),Len > 0,
		  suma_lista(Califs,S), Promedio is S/Len,
		  nl,format('Nombre:  ~s', Nombre),
		  nl,format('Promedio:  ~g', Promedio).

longitud([],0).
longitud([_|Y],Len):-longitud(Y,Len1),Len is Len1+1.

suma_lista([],0).
suma_lista([H|T],S):-suma_lista(T,S1),S is S1+H.

