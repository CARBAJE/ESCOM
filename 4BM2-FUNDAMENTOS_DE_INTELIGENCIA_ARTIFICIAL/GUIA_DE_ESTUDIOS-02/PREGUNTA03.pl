%INICIO HECHOS
%PROGENITORES
progenitor(abraham , herb).
progenitor(abraham , homer).

progenitor(mona , homer).

progenitor(clancy , marge).
progenitor(clancy , patty).
progenitor(clancy , selma).

progenitor(jackie , marge).
progenitor(jackie , patty).
progenitor(jackie , selma).

progenitor(homer, bart).
progenitor(homer , lisa).
progenitor(homer , maggie).

progenitor(marge , bart).
progenitor(marge , lisa).
progenitor(marge , maggie).

progenitor(selma , ling).

%SEXO
es_hombre(abraham).
es_hombre(clancy).
es_hombre(herb).
es_hombre(homer).
es_hombre(bart).

es_mujer(mona).
es_mujer(jackie).
es_mujer(marge).
es_mujer(patty).
es_mujer(selma).
es_mujer(lisa).
es_mujer(maggie).
es_mujer(ling).
%FIN HECHOS
%INFERENCIAS
esta_en_matrimonio_con(X,Y) :- progenitor(X,Z) , progenitor(Y,Z), X\=Y.

es_tio(X , Y) :-es_hombre(X), progenitor(A , X) , progenitor(A , B) , progenitor(B , Y), X\=B.
es_tia(X , Y) :- es_mujer(X) , progenitor(A , X) , progenitor(A , B) , progenitor(B , Y) , X\=B.
es_primo_de(X , Y) :- es_hombre(X) , progenitor(A , X) , progenitor(B , A) , progenitor(B , C) , progenitor(C , Y) , A\=C.
es_prima_de(X , Y):- es_mujer(X) , progenitor(A , X) , progenitor(B , A) , progenitor(B , C) , progenitor(C , Y), A\=C.
es_consuegro_de(Y , X) :- esta_en_matrimonio_con(X , A) , progenitor(Y , A).
es_concu�o_de(Y , X) :- esta_en_matrimonio_con(X , A) , progenitor(B, A) , progenitor(B , Y), A \= Y.