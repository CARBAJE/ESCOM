
%Estado inicial del juego
start(state(bank(l,3,3),bank(r,0,0),boat_left)).

%Estado final del juego (estado al que debemos llegar.
goal(state(bank(l,0,0),bank(r,3,3),boat_right)).

%Estado 'a salvo' de los misioneros
safe_bank(bank(_,M,C)):- M=0,!; C=0,!; M>=C.

%Calcula el siguiente movimiento, de izquierda a derecha o de derecha a izquierda.
next_state(state(From1,To1,boat_left),state(From2,To2,boat_right)):- move(From1,To1,From2,To2).
next_state(state(To1,From1,boat_right),state(To2,From2,boat_left)):- move(From1,To1,From2,To2).

%Calcula el movimiento de forma que el resultado sea un estado 'a salvo'.
move(Bfrom1,Bto1,Bfrom2,Bto2):-
	Bfrom1=bank(BF,Mf1,Cf1),
	Bto1=bank(BT,Mt1,Ct1),
	Bfrom2=bank(BF,Mf2,Cf2),
	Bto2=bank(BT,Mt2,Ct2),
	member(DM/DC,[0/1,0/2,1/0,1/1,2/0]),
	Mf1>=DM,
	Cf1>=DC,
	Mf2 is Mf1-DM,
	Cf2 is Cf1-DC,
	safe_bank(Bfrom2),
	Mt2 is Mt1+DM,
	Ct2 is Ct1+DC,
	safe_bank(Bto2).

%Resuelve el juego almacenando en 'FoundPath' los movimientos realizados.
solve(Goal,Goal,FoundPath,FoundPath):- !. % Caso base
solve(State,_Goal,[_Current|Path],_FoundPath):- member(State,Path),!,fail. % Evita estados repetidos
solve(State1,Goal,Path,FoundPath):- next_state(State1,State2), solve(State2,Goal,[State2|Path],FoundPath).

%Escribe la solucion
print_path([]):-!,nl.
print_path([Current|Path]):- print_path(Path),print_state(Current).
print_state(state(BL,BR,BT)):- print_bank(BL),print_boat(BT),print_bank(BR),nl.
print_bank(bank(_,M,C)):- print_people(m,M,3),write(' '),print_people(c,C,3).
print_people(Chr,N,Tot):- print_chars(Chr,N),Empty is Tot-N,print_chars('-',Empty).
print_chars(_Chr,0):- !.
print_chars(Chr,N):- write(Chr),N1 is N-1,print_chars(Chr,N1).
print_boat(boat_left):- write(' \\__/        ').
print_boat(boat_right):- write('        \\__/ ').

%LLamada inicial para resolver el juego
solucion(FoundPath):-
	start(Start),
	goal(Goal),
	solve(Start,Goal,[Start],FoundPath),
	print_path(FoundPath).

















