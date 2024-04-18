clear
clc
close all;

%% Definiciones

%Leemos el CSV de las transiciones
data = readtable("/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/TablaEstadosP04.csv");
cabeceras = data.Properties.VariableNames;
% Definimos el radio para los estados
r = 2;

% Define los estados como un arreglo de matrices
estados = [
    [ 0,  0]; % Estado 0
    [10, 0]; % Estado 01
    [20,-10]; % Estado 02
    [25,-5]; % Estado 03
    [30,-10]; % Estado 04
    [35,-5]; % Estado 05
    [40,-10]; % Estado 06
    [45,-5]; % Estado 07
    [25,-10]; % Estado 08
    [30, -15]; % Estado 09
    [35,-20]; % Estado 10
    [40,-25]; % Estado 11
    [45,-30]; % Estado 12
    [45,-25]; % Estado 13
    [45,-20]; % Estado 14
    [45,-15]; % Estado 15
    [45,-10]; % Estado 16
    [10, 10]; % Estado 17
    [20, 20]; % Estado 18
    [30, 30]; % Estado 19
    [40, 40]; % Estado 20
    [50, 30]; % Estado 21
    [40, 30]; % Estado 22
    [20, 10]; % Estado 23
    [30, 10]; % Estado 24
    [40,20]; % Estado 25
    [50,20]; % Estado 26
    [50,10]; % Estado 27
    [10,-30]; % Estado 28
    [15,-30]; % Estado 29
    [20,-30]; % Estado 30
    [25,-30]; % Estado 31
    [30,-30]; % Estado 32
    [35,-30]; % Estado 33
    [10,-40]; % Estado 34
    [15,-40]; % Estado 35
    [20, -40]; % Estado 36
    [25,-40]; % Estado 37
    [30,-40]; % Estado 38
    [35,-40]; % Estado 39
    [40,-40] % Estado 40
];

% Dibujar el escenario
figure;
hold on;

%% Dibujar los círculos y las líneas de conexión al estado 0
for i = 1:size(estados, 1)
    centro = estados(i,:);
    rectangle('Position', [centro(1)-r, centro(2)-r, 2*r, 2*r], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k', 'LineWidth', 2);
    if ismember(i, [8, 17, 23, 28, 34, 41])
        rectangle('Position', [centro(1)-r+0.8, centro(2)-r+0.8, 1.2*r, 1.2*r], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k', 'LineWidth', 1);
    end
    text(centro(1) - r/3.5, centro(2), sprintf('%02d', i), 'FontName', 'Times New Roman', 'FontSize', 12, 'FontAngle', 'italic', 'Color','k');
    
    if i ~= 1
        % Calcular el punto de intersección entre la línea de conexión y el círculo del Estado 0
        p0 = estados(1,:);
        p1 = centro;
        d = sqrt((p1(1) - p0(1))^2 + (p1(2) - p0(2))^2);
        x = p0(1) + (p1(1) - p0(1)) * r / d;
        y = p0(2) + (p1(2) - p0(2)) * r / d;
        
        % Dibujar la conexión al Estado 0
        if ~ismember(i, [2,18,29,35])
            %text(centro(1)-r, centro(2), '\Sigma', 'Color', 'red');
            plot([centro(1)-r, x], [centro(2), y], 'r--', 'LineWidth', 2, 'Color', [1, 0, 0, 0.1], 'DisplayName','\Sigma');
        end
    end

    %obtener las transiciones
    filaTransiciones = data{i, 2:17};
    for j = 1 : numel(filaTransiciones)
        if filaTransiciones(j) ~= 0
            punto0 = centro;
            punto1 = estados(filaTransiciones(j) +1, :);
            dis = sqrt((punto1(1)-punto0(1)+r)^2 + (punto1(2)-punto0(2)-r)^2 );
            x1 = punto0(1) + (punto1(1) - punto0(1)) * r/dis;
            y2 = punto0(2) + (punto1(2) - punto0(2)) * r/dis;
             % Calcular el punto medio entre los puntos inicial y final de la línea
            medio_x = (centro(1) - r + punto1(1)) / 2;
            medio_y = (centro(2) + punto1(2)) / 2;
            
            % Obtener la cabecera correspondiente
            cabecera = cabeceras{j + 1};
            
            % Dibujar la conexión al estadoDestino
            if filaTransiciones(j) == 1 && i~=1
                plot([centro(1), punto1(1)], [centro(2), punto1(2)], 'm--', 'LineWidth', 2, 'Color', [1, 0, 1, 0.2], 'DisplayName', 'E');
                % Dibujar el texto en el punto medio de la línea
                %text(medio_x, medio_y+0.5, cabecera, 'Color', [1, 0, 1, 0.1], 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
            elseif filaTransiciones(j) == 28 && i~=1
                plot([centro(1), punto1(1)], [centro(2), punto1(2)], 'c--', 'LineWidth', 2, 'Color', [0, 1, 1, 0.1], 'DisplayName', 'C');
                %text(medio_x, medio_y+0.5, cabecera, 'Color', [0, 1, 1, 0.3], 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
            elseif filaTransiciones(j) == 17 && i~=1
                plot([centro(1), punto1(1)], [centro(2), punto1(2)], 'y--', 'LineWidth', 2, 'Color', [1, 1, 0, 0.1], 'DisplayName', 'R');
                %text(medio_x, medio_y+0.5, cabecera, 'Color', [1, 1, 0, 0.3], 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
            elseif filaTransiciones(j) == 34 && i~=1
                plot([centro(1), punto1(1)], [centro(2), punto1(2)], 'g--', 'LineWidth', 2, 'Color', [0, 1, 0, 0.1], 'DisplayName', 'M');
                %text(medio_x, medio_y+0.5, cabecera, 'Color', [0, 1, 0, 0.3], 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
            else
                plot([centro(1), punto1(1)], [centro(2), punto1(2)], 'b', 'LineWidth', 2, 'Color', [0, 0, 1, 1], 'DisplayName','Ruta');
                text(medio_x, medio_y+0.5, cabecera, 'Color', 'blue', 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
            end
        end
    end

end

legend('\Sigma', 'E', 'R', 'C', 'M');

%% Ajustes de los ejes y fondo del ploteo
axis equal;% Ajusta la relación de aspecto para que los círculos se vean como círculos
axis off;

grid off; % Activa la cuadrícula para una mejor visualización

%% Ajustes del titulo del ploteo

[titulo,subtitulo] = title('Automata Practica 04','Automata FInito Determinista', 'FontName','Tmes New Roman');
titulo.FontName = 'Times New Roman';
subtitulo.FontName = 'Times New Roman';
titulo.FontSize = 16;
titulo.FontWeight = "bold";
subtitulo.FontAngle = 'italic';

hold off;
%% Paso 4: Terminar el programa 
pause(10);
close all
exit();
