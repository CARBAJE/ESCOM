clear
clc
close all;

% Define los radios de los tres círculos
r1 = 3;
r2 = 3;
r3 = 3;

% Define las coordenadas de los centros de los círculos
centro1 = [0, 0];
centro2 = [10, 0];
centro3 = [20, 0];

% Crea una nueva figura
figure;
hold on; %Permite mantener diferentes figuras en un mismo plot

%% Dibuja el primer estado
rectangle('Position', [centro1(1)-r1, centro1(2)-r1, 2*r1, 2*r1], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'r' , LineWidth=3);
text(centro1(1) - r1/3.5, centro1(2), 'Q_0', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on');

quiver(centro1(1)+r1, centro1(2), centro2(1)-r2-2.5, centro2(2), 'r','ShowArrowHead','on', 'LineWidth', 3,'AutoScale','on', 'MaxHeadSize',5 );
text(centro1(1) + r1*1.4, centro1(2)+r1*.3, '0', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on');

%% Llamar a la función para dibujar un arco
dibujarArco(5*(pi/3), 1*pi/3, 3, [centro1(1)-r1, centro1(2)], 1);
text(centro1(1) - 1.8*r1, centro1(2)+r1*1.3, '0,1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on');

%% Dibuja el segundo estado
rectangle('Position', [centro2(1)-r2, centro2(2)-r2, 2*r2, 2*r2], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'g' , LineWidth=3);
text(centro2(1) - r1/3.5, centro2(2), 'Q_1', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on');

quiver(centro2(1)+r2, centro2(2), centro3(1)-4*r3-3.5, centro2(2), 'g', 'ShowArrowHead','on', 'LineWidth',3, 'AutoScale','on', 'MaxHeadSize',5)
text(centro2(1) + r2*1.4, centro2(2)+r2*.3, '1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on');

%% Dibuja el tercer estado
rectangle('Position', [centro3(1)-r3, centro3(2)-r3, 2*r3, 2*r3], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'b' , LineWidth=3);
rectangle('Position', [centro3(1)-1.7*(r3/2), centro1(2)-1.7*(r3/2), 1.7*r3, 1.7*r3], 'Curvature', [1, 1],'EdgeColor', 'b' , LineWidth=2);
text(centro3(1) - r3/3.5, centro1(2), 'Q_2', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on');

%% Mostrar cadena de entrada
text(centro1(1)+3 - r2/2, centro2(2)-2*r2, 'Cadena de entrada', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on');

%% Ajustes de los ejes y fondo del ploteo
axis equal;% Ajusta la relación de aspecto para que los círculos se vean como círculos
axis off;

grid off; % Activa la cuadrícula para una mejor visualización

%% Ajustes del titulo del ploteo

[titulo,subtitulo] = title('Animación Practica 02','Automata no Determinista', 'FontName','Tmes New Roman');
titulo.FontName = 'Times New Roman';
subtitulo.FontName = 'Times New Roman';
titulo.FontSize = 16;
titulo.FontWeight = "bold";
subtitulo.FontAngle = 'italic';
