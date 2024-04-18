clc;
clear;
close all;

clc;
clear;
close all;

% Definir las coordenadas de los puntos
x = [0, 255, 0, 0, 255, 255, 0, 255];
y = [0, 255, 0, 255, 0, 255, 255, 0];
z = [0, 255, 255, 0, 0, 0, 255, 255];

% Etiquetas para los puntos
etiquetas = {'Black', 'White', 'Green', 'Red', 'Blue', 'Magenta', 'Cyan', 'Yellow'};

% Colores para los puntos
colores = [0 0 0; 1 1 1; 0 1 0; 1 0 0; 0 0 1; 1 0 1; 0 1 1; 1 1 0;];

% Graficar los puntos en 3D con etiquetas y colores diferentes
scatter3(x, y, z, 100, colores, 'filled');
text(x, y, z, etiquetas, 'FontSize', 8, 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle');
xlabel('Eje X');
ylabel('Eje Y');
zlabel('Eje Z');
title('Gráfico 3D con 8 puntos');
grid on; % Habilitar la cuadrícula

% Colores para los puntos
colores = [0 0 0; 1 1 1; 0 1 0; 1 0 0; 0 0 1; 1 0 1; 0 1 1; 1 1 0];

% Crear todas las combinaciones posibles de colores
combinaciones_colores = dec2bin(0:2^size(colores, 1)-1) - '0';

% Crear una matriz para almacenar los resultados
tabla_verdad = cell(size(colores, 1), 2);

% Calcular las etiquetas para cada combinación de colores
for i = 1:size(colores, 1)
    color_actual = colores(i, :);
    etiqueta_actual = etiquetas{i};
    tabla_verdad{i, 1} = color_actual;
    tabla_verdad{i, 2} = etiqueta_actual;
end

% Mostrar la tabla de verdad
disp('Tabla de Verdad:');
disp('----------------');
disp('Colores           Etiquetas');
disp('-----------------------------');
for i = 1:size(tabla_verdad, 1)
    disp([mat2str(tabla_verdad{i, 1}) blanks(10) tabla_verdad{i, 2}]);
end

%Mostrar una imagen (brindada por una ruta) que sea un array 3*3, de tal manera que la primera
%linea (1*3) sea la imagen en el espacio CMY, lo cual significa que sean
%las clases 1, 2, 3 respectivamente.

%La segunda linea (2*3) sea el modelo RGB de la imagen, lo cual significa que sea la
%clase 4, 5, 6 respectivamente.

%La tervera linea (3*3) sea el espacio NEGRO, BLANCO, Grises, de la imagen. Lo cual
%significa que sean las clases 7, 8 y 9 respectivamente