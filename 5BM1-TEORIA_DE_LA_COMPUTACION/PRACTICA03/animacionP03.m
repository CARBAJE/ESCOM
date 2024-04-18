clc;
clear;
close all;

%% Paso 1: Obtener la informacion
%Leer CSV de las jugadas del  jugador uno y del jugador 2
J01 = readmatrix("J01.csv");
J02 = flipud(readmatrix("J02.csv"));

% Leer la imagen 
FichaJ01 = imread("/home/carbaje/Pictures/stickers/Mythra1_1.png");

FichaJ02 = imread("/home/carbaje/Pictures/stickers/pyra1_1.png");

%imfinfo("C:\Users\emicr\Pictures\stikers vscode\Mythra1_1.png")
%imfinfo("C:\Users\emicr\Pictures\stikers vscode\pyra1_1.png")

% Define el canal alfa y normalizamos al rango [0,1]
%canalAlfaFichaJ01 = double(FichaJ01(:, :, 1:4)) / 255;

% Corregir la orientación de las imágenes
FichaJ01 = flipud(FichaJ01);
FichaJ02 = flipud(FichaJ02);

% Obtener la cantidad de jugadas (columnas)
longitudJugada = size(J01, 2);

% Tamaño del Tablero nxn
n = 4;

% Numero de jugada a graficar (fila de la matriz)
k1 = 1 ;
k2 = 1;

%Matriz de las cordenadas de las casillas del tablero
ruta = [4, 1; 4, 2; 4, 3; 4, 4; 3, 1; 3, 2; 3, 3; 3, 4; 2, 1; 2, 2; 2, 3; 2, 4; 1, 1; 1,2; 1, 3; 1, 4];

%% Paso 2: Dibujar y animar los elementos del escenario:
figure;
for t = 1 : longitudJugada
    clf;
    axis equal off;
    % Ajustes del titulo del ploteo
    [titulo,subtitulo] = title('Animación Practica 03','Universo de Jugadas Ganadoras para dos jugadores', 'FontName','Tmes New Roman');
    titulo.FontName = 'Times New Roman';
    subtitulo.FontName = 'Times New Roman';
    titulo.FontSize = 16;
    titulo.FontWeight = "bold";
    subtitulo.FontAngle = 'italic';

    % Dibujar los cuadrados del tablero
    for i = 1:n
        for j = 1:n
            if mod(i+j,2) == 0 % Si la suma de fila y columna es par, color rojo
                color = [1, 0, 0];
            else % Si la suma de fila y columna es impar, color negro
                color = [1, 1, 1];
            end
            rectangle('Position', [j-1, i-1, 1, 1], 'FaceColor', color);
        end
    end

    % Colocar las Etiquetas de filas y columnas
    for i = 1:n
        text(-0.25, i-0.5, char('a' + i - 1), 'HorizontalAlignment', 'Center', 'VerticalAlignment', 'Middle');
        text(i-0.5, -0.25, num2str(i), 'HorizontalAlignment', 'Center', 'VerticalAlignment', 'Middle');
    end

    % Obtener la posición actual del jugador 1 y mostrar su ficha
    hold on
    posicionActualJ01 = ruta(J01(k1, t), :); 
    image([posicionActualJ01(2)-1, posicionActualJ01(2)], [posicionActualJ01(1)-1, posicionActualJ01(1)], FichaJ01);
    hold off
    
    % Obtener la posición actual del jugador 2 y mostrar su ficha
    posicionActualJ02 = ruta(J02(k2, t), :);
    % Esperar un corto tiempo antes de mostrar la ficha del jugador 2
    pause(0.5);
    hold on
    image([posicionActualJ02(2)-1, posicionActualJ02(2)], [posicionActualJ02(1)-1, posicionActualJ02(1)], FichaJ02);
    hold off
    
    %Forzar a matlab a dibujar la figura justo en ese momento
    %drawnow;
    pause(0.5)

    % Avanzar al siguiente movimiento de cada jugador
    if t < longitudJugada
        while true
            if ((ruta(J01(k2, t), 1) == ruta(J02(k2, t+1), 1) && ruta(J01(k2, t), 2) == ruta(J02(k2, t+1), 2)) || ...
               (ruta(J01(k2, t+1), 1) == ruta(J02(k2, t), 1) && ruta(J01(k2, t+1), 2) == ruta(J02(k2, t), 2)) ) && ...
               (ruta(J01(k2, t+1), 1) == ruta(J02(k2, t+1), 1) && ruta(J01(k2, t+1), 2) == ruta(J02(k2, t+1), 2))
                if randi([0,1])
                    k1 = k1+1;
                else
                    k2 = k2+1;
                end
            else
                break; % Sal del bucle si las rutas son diferentes
            end
        end
    end


end


pause (5);
close all;
exit();