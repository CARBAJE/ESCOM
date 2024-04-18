% Reglas recursivas

oracion --> oracion_simple.
oracion --> oracion_simple, conjuncion, oracion.
oracion_simple --> sintagma_nominal,sintagma_verbal.
sintagma_nominal --> nombre.
sintagma_nominal --> articulo, nombre.
sintagma_verbal --> verbo, sintagma_nominal.
articulo --> [el].
nombre --> [gato].
nombre --> [perro].
nombre --> [pescado].
nombre --> [carne].
verbo --> [come].
conjuncion --> [y].
conjuncion --> [o].

% Consulta:
% phrase(oracion,[gato, come, pescado, y, perro, come, gato]).



