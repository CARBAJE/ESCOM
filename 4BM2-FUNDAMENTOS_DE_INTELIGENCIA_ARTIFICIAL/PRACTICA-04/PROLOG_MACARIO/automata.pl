inicial(q0).
final(q0).

delta(q0, 0, q1).
delta(q0, 1, q2).

delta(q1, 0, q0).
delta(q1, 1, q3).

delta(q2, 0, q3).
delta(q2, 1, q0).

delta(q3, 0, q2).
delta(q3, 1, q1).

aceptar(L):-inicial(Q), aceptar(L,Q).

aceptar([],Q):-final(Q).
aceptar([X|Y], Q):-delta(Q, X, Q1), aceptar(Y, Q1).

%Consulta:  -? aceptar([0,0,1,1]).





