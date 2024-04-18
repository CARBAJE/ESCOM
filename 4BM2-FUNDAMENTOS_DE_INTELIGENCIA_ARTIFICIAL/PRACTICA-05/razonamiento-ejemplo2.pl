% Ejemplo de implementación de sistema experto
% Créditos: https://sergioc2005.tripod.com/intart/Pract7SistExpertProlog06.pdf

:- dynamic conocido/1.


main:-bienvenida,
      nl,write('Menu'),nl,
      nl,write('1 Consulta al médico'),
      nl,write('2 Salir'),
      nl,nl,write('Indica tu opcion:'),
      read(Opcion),nl,
      Opcion=1,consulta,
      nl,writeln('Gracias por utilizar este programa\n').

bienvenida:-writeln('\nBienvenido al Consultorio del Dr. Simio'),
            writeln('==========================================='),
            writeln('\nPuedo hacer un prediagnóstico pero no soy'),
            writeln('un médico de verdad, por lo que si usted'),
            writeln('se siente mal, acuda a un médico titulado.').

consulta:-limpia_memoria_de_trabajo,
          writeln("\nLe haré algunas preguntas conteste con 'si' o 'no'\n"),
          haz_diagnostico(X),
          escribe_diagnostico(X),
          ofrece_explicacion_diagnostico(X).

consulta:-write('No hay suficiente conocimiento para elaborar un diagnostico.').


% Busca una enfermedad, la propone como hipotesis y trata de probar las
% premisas (los sintomas que caracterizan la enfermedad)

haz_diagnostico(Diagnosis):-obten_hipotesis_y_sintomas(Diagnosis, ListaDeSintomas),
	        prueba_presencia_de(Diagnosis, ListaDeSintomas).

obten_hipotesis_y_sintomas(Diagnosis, ListaDeSintomas):-rules(enfermedad(Diagnosis), sintomas(ListaDeSintomas)).

prueba_presencia_de(_, []).
prueba_presencia_de(Diagnosis, [Head | Tail]):- prueba_verdad_de(Diagnosis, Head),prueba_presencia_de(Diagnosis, Tail).

% Verifica si el sintoma esta en la memoria de trabajo
prueba_verdad_de(_, Sintoma):- conocido(Sintoma).

% Si no esta el sintoma en la memoria pregunta sobre
% presencis del sintoma en el paciente
prueba_verdad_de(Diagnosis, Sintoma):- not(conocido(is_false(Sintoma))),
	                               pregunta_sobre(Diagnosis, Sintoma, Reply),
				       Reply = si.
% Hace la pregunta
pregunta_sobre(Diagnosis, Sintoma, Reply):- write('Es verdad que usted '),
	                                    write(Sintoma), write('? '),
					    read(Respuesta),
					    process(Diagnosis, Sintoma, Respuesta, Reply).

% Procesa la respuesta y agrega el hecho a la
% memoria de trabajo si la respuesta es si o no
% en case de que sea 'porque' explica la razón
%
process(_, Sintoma, si, si):- asserta(conocido(Sintoma)).
process(_, Sintoma, no, no):- asserta(conocido(is_false(Sintoma))).
process(Diagnosis, Sintoma, porque, Reply):- nl,
write('Estoy investigando la hipotesis siguiente: '),
write(Diagnosis), write('.'), nl, write('Para esto necesito saber si '),
write(Sintoma), write('.'), nl, pregunta_sobre(Diagnosis, Sintoma, Reply).
process(Diagnosis, Sintoma, Respuesta, Reply):- Respuesta \== no,
Respuesta \== si, Respuesta \== porque, nl,
write('Debes contestar si, no o porque.'), nl,
pregunta_sobre(Diagnosis, Sintoma, Reply).


% Escribe el diagnostico encontrado
escribe_diagnostico(Diagnosis):- write('\nEl diagnostico es '),
write(Diagnosis), write('.'), nl.

% Explica por qué llegó a la conclusion
ofrece_explicacion_diagnostico(Diagnosis):-
pregunta_si_necesita_explicacion(Respuesta),
actua_consecuentemente(Diagnosis, Respuesta).
pregunta_si_necesita_explicacion(Respuesta):-
write('\nQuieres que justifique este diagnostico? '),
read(RespuestaUsuario),
asegura_respuesta_si_o_no(RespuestaUsuario, Respuesta).

% Utilerias

asegura_respuesta_si_o_no(si, si).
asegura_respuesta_si_o_no(no, no).
asegura_respuesta_si_o_no(_, Respuesta):- write('Debes contestar si o no.'),
pregunta_si_necesita_explicacion(Respuesta).
actua_consecuentemente(_, no).
actua_consecuentemente(Diagnosis, si):- rules(enfermedad(Diagnosis), sintomas(ListaDeSintomas)),
		      write('\nSe determino este diagnostico porque se encontraron los siguentes sintomas:\n '), nl,
                       escribe_lista_de_sintomas(ListaDeSintomas).
escribe_lista_de_sintomas([]).
escribe_lista_de_sintomas([Head | Tail]):-write(Head), nl, escribe_lista_de_sintomas(Tail).


% La memoria de trabajo guarda el conocimiento adquirido
% de las respuestas del usuario

limpia_memoria_de_trabajo:- retractall(conocido(_)).


% BaseConocimientos: diagnosticos y sintomas

rules(enfermedad('gastritis'),
      sintomas(['tiene dolor agudo en vientre',
                'tiene diarrea',
                'tiene muchos gases (p2)'])).
rules(enfermedad('sarampion'),
      sintomas(['esta cubierto de puntos',
		'tiene temperatura alta',
                'tiene ojos rojos',
		'tiene tos seca'])).
rules(enfermedad('malaria'),
      sintomas(['tiene temperatura alta',
		'tiene dolor en las articulaciones',
		'tiembla violentamente',
		'tiene escalofrios'])).
rules(enfermedad('influenza'),
      sintomas(['tiene dolor en las articulaciones',
	        'tiene mucho estornudo',
                'tiene dolor de cabeza'])).
rules(enfermedad('gripe'),
      sintomas(['tiene cuerpo cortado',
                'tiene dolor de cabeza',
	        'tiene temparatura alta'])).
rules(enfermedad('tifoidea'),
      sintomas(['tiene falta de apetito',
		'tiene temperatura alta',
		'tiene dolor abdominal',
		'tiene dolor de cabeza',
		'tiene diarrea'])).











