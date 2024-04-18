clear
clc
close all;

%% Definiciones

%Leemos el CSV de las transiciones
data = readtable('TablaEstados.csv');
cabeceras = data.Properties.VariableNames;
% Definimos el radio para los estados
r = 2;

% Define los estados como un arreglo de matrices
estados = [
    [ 0,  0]; % Estado 0
    [10,  0]; % Estado 01
    [20,  0]; % Estado 02
    [30,  0]; % Estado 03
    [ 0,  10]; % Estado 04
    [10, 10]; % Estado 05
    [20, 10]; % Estado 06
    [30, 10]; % Estado 07
    [ 0, 20]; % Estado 08
    [10, 20]; % Estado 09
    [20, 20]; % Estado 10
    [30, 20]; % Estado 11
    [ 0, 30]; % Estado 12
    [10, 30]; % Estado 13
    [20, 30]; % Estado 14
    [30, 30]; % Estado 15
];

% Dibujar el escenario
figure;
hold on;

%% Dibujar los círculos y las líneas de conexión al estado 0
for i = 1:size(estados, 1)
    centro = estados(i,:);
    rectangle('Position', [centro(1)-r, centro(2)-r, 2*r, 2*r], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k', 'LineWidth', 2);
    if ismember(i, [13, 16])
        rectangle('Position', [centro(1)-r+0.8, centro(2)-r+0.8, 1.2*r, 1.2*r], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k', 'LineWidth', 1);
    end
    text(centro(1) - r/3.5, centro(2), sprintf('%02d', i), 'FontName', 'Times New Roman', 'FontSize', 12, 'FontAngle', 'italic', 'Color','k');

    %obtener las transiciones
    filaTransiciones = data{i, 2:end};
    for j = 1 : numel(filaTransiciones)
        if ~isnan(filaTransiciones(j))
            punto0 = centro;
            punto1 = estados(filaTransiciones(j) + 1, :);
            dis = sqrt((punto1(1)-punto0(1)+r)^2 + (punto1(2)-punto0(2)-r)^2 );
            x1 = punto0(1) + (punto1(1) - punto0(1)) * r/dis;
            y2 = punto0(2) + (punto1(2) - punto0(2)) * r/dis;
            % Calcular el punto medio entre los puntos inicial y final de la línea
            medio_x = (centro(1) - r + punto1(1)) / 2;
            medio_y = (centro(2) + punto1(2)) / 2;

            % Obtener la cabecera correspondiente
            cabecera = cabeceras{j + 1};

            % Dibujar la conexión al estadoDestino
            plot([centro(1), punto1(1)], [centro(2), punto1(2)], 'k', 'LineWidth', 2, 'Color', [0, 0, 0, 1], 'DisplayName','Ruta');
            text(medio_x+1, medio_y+1, cabecera, 'Color', 'black', 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
        end
    end
end


%% Ajustes de los ejes y fondo del ploteo
axis equal;% Ajusta la relación de aspecto para que los círculos se vean como círculos
axis off;

grid off; % Activa la cuadrícula para una mejor visualización

%% Ajustes del titulo del ploteo

[titulo,subtitulo] = title('Automata Practica 03','Automata Finito No Determinista', 'FontName','Tmes New Roman');
titulo.FontName = 'Times New Roman';
subtitulo.FontName = 'Times New Roman';
titulo.FontSize = 16;
titulo.FontWeight = "bold";
subtitulo.FontAngle = 'italic';

hold off;
%% Paso 4: Terminar el programa
pause(5);
close all
exit();
