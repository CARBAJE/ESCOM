%===========================
% Identificación
%===========================
% Descripción: Base de conocimientos
% Autor: 
% Fecha: 
%===========================

%===========================
% Sección de Hechos
%===========================

entrada(sopa_fideos,116).
entrada(crema_poblana,92).
entrada(sopa_maruchan,343).
platillo(milanesa,308).
platillo(pechuga_asada,109).
postre(chongos,167).
postre(flan_napolitano,293).
postre(capirotada,571).


% Escriba una regla que recomiende dietas saludables, considerandose
% saludable si la suma de kilocalorias de entrada,platillo y postre
% debe ser menor a 600 (Esto es solo a manera de ejemplo por lo tanto no
% se apega a la realidad)


%======================
% Sección de Reglas de Inferencia
%======================

% Regla con argumentos
%
dieta_saludable(Entrada, Platillo, Postre):-entrada(Entrada,K_Entrada),
               platillo(Platillo,K_Platillo),
	       postre(Postre,K_Postre),
	       K_Total is K_Entrada + K_Platillo + K_Postre,
               K_Total < 600.



% Regla sin argumentos, muestra todas las dietas que encuentra
dieta_saludable:-entrada(Entrada,K_Entrada),platillo(Platillo,K_Platillo),
	         postre(Postre,K_Postre),
	         K_Total is K_Entrada + K_Platillo + K_Postre,
		 K_Total < 600,
		 nl, format('Comer ~s con ~s y ~s es muy saludable, la suma de calorías es ~g \n<<Press Enter>>'
                 ,[Entrada, Platillo, Postre, K_Total]),
                 get_single_char(_), fail.















