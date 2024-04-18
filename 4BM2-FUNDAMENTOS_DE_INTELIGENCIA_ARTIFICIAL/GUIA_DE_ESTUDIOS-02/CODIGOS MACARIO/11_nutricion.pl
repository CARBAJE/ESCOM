% Base de conocimiento, Coloque aquí los predicados para representar el
% conocimiento

% Alimentos
fruta('manzana',52).
fruta('papaya',45).
lacteo('leche entera',68).
cereal('pan de trigo integral',216).
ensalada('pepino',85).
bebida('jugo de naranja',45).

%Reglas
%

% El desayuno consta de fruta+lacteo+cereal

desayuno(F,L,C, Tk):-fruta(F,Kf),lacteo(L,Kl), cereal(C,Kc),
                        Tk is Kf+Kl+Kc.


% El almuerzo consta de ensalada+bebida

almuerzo(E,B,Tk):-ensalada(E,Ke),bebida(B,Kb), Tk is Ke+Kb.


% Ciclo principal

main:-repeat,
      pinta_menu,
      read(Opcion),
      ( (Opcion=1,doImc,fail);
	(Opcion=2,doDieta,fail);
	(Opcion=3,!)).

% Muestra el menú

pinta_menu:-nl,nl,
      writeln('===================================='),
      writeln('         DRA. MIKU HATSUNE'),
      writeln('          Médica Virtual'),
      writeln('   <<  Experta en Nutrición  >>'),
      writeln('===================================='),
      nl,writeln('       MENU PRINCIPAL'),
      nl,write('1 Calcular indice de masa corporal'),
      nl,write('2 Recomendar una dieta saludable'),
      nl,write('3 Salir'),
      nl,write('================================='),
      nl,write('Indique una opcion válida:').

% Regla para calcular IMC

doImc:-nl, write('================================='),nl,
       write('Elegiste: Calculo del Indice de Masa Corporal\n'),nl,
       write('Indique su peso en Kilogramos:'),read(Peso),
       write('Indique su estatura en Metros:'),read(Estatura),Estatura > 0,
       write('Indique su genero (1/Male, 2/Female):'),read(Sexo),
       IND is Peso/(Estatura*Estatura),
       nl,format('Su indice de masa corporal es: ~g',IND),
       nl, write('DIAGNOSTICO: '),
        (  (Sexo=1,IND<17,write('USTED PADECE DESNUTRICION!'));
	   (Sexo=1,IND>=17,IND<20,write('USTED TIENE BAJO PESO!\n')) ).

% Regla para recomendar dietas

doDieta:-nl,writeln('Elegiste: Nutriologo Artificial').



















