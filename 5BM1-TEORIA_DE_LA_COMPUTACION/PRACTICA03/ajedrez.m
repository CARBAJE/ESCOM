clc;
clear;
close all;

%Leer CSV
J01 = readmatrix("J01.csv");
J02 = readmatrix("J02.csv");

FichaJ01 = imread("C:\Users\emicr\Pictures\stikers vscode\Mythra1_1.png");
FichaJ02 = imread("C:\Users\emicr\Pictures\stikers vscode\pyra1_1.png");

longitudJugada = size(J01, 2); % Cantidad de columnas
% longitudJugada = size(J01, 1); %Cantidad de columnas en la matriz

n = 4; % Número de filas y columnas
ruta = [4, 1; 4, 2; 4, 3; 4, 4; 3, 1; 3, 2; 3, 3; 3, 4; 2, 1; 2, 2; 2, 3; 2, 4; 1, 1; 1,2; 1, 3; 1, 4]; % Coordenadas de las casillas en la ruta
ruta2 = [4, 1; 4, 2; 4, 3; 4, 4; 3, 1; 3, 2; 3, 3; 3, 4; 2, 1; 2, 2; 2, 3; 2, 4; 1, 1; 1,2; 1, 3; 1, 4]; 
figure;

posicion = ruta2(1, :);

% Dibujar los cuadrados del tablero
for i = 1:n
    for j = 1:n
        if mod(i+j,2) == 0 % Si la suma de fila y columna es par, color rojo
            color = [1, 0, 0];
        else % Si la suma de fila y columna es impar, color negro
            color = [0, 0, 0];
        end
        rectangle('Position', [j-1, i-1, 1, 1], 'FaceColor', color);
    end
end

% Etiquetar filas y columnas
for i = 1:n
    text(-0.5, i-0.5, char('a' + i - 1), 'HorizontalAlignment', 'Center', 'VerticalAlignment', 'Middle');
    text(i-0.5, -0.5, num2str(i), 'HorizontalAlignment', 'Center', 'VerticalAlignment', 'Middle');
end

% Dibujar la ruta y los círculos
for i = 1:size(J01(1,:), 2)-1
    line([ruta(J01(i, 1), 2)-0.5, ruta(J01(i+1,1), 2)-0.5], [ruta(J01(i,1), 1)-0.5, ruta(J01(i+1, 1), 1)-0.5], 'Color', 'w', 'LineWidth', 2);
    line([ruta2(J02(i, 1), 2)-0.5, ruta(J02(i+1,1), 2)-0.5], [ruta(J02(i,1), 1)-0.5, ruta(J02(i+1, 1), 1)-0.5], 'Color', 'b', 'LineWidth', 2);
end

% Establecer límites del eje y aspecto
axis equal off;
axis([0 n 0 n]);

% Animación del movimiento a lo largo de la ruta "salteada"
k1 = 1 ;
k2 = 1;
i2 = 1;
for i = 1 :size(J01(1,:), 2)
    current_pos = ruta(J01(k1,i), : ); % Posición final de la casilla siguiente
    current_pos2 = ruta(J02(k2,i), : ); % Posición final de la casilla siguiente
    h = viscircles([current_pos(2)-0.5, current_pos(1)-0.5], 0.2, 'Color', 'w'); % Dibujar el círculo en la posición final
    h2 = viscircles([current_pos2(2)-0.5, current_pos2(1)-0.5], 0.2, 'Color', 'cyan'); % Dibujar el círculo en la posición final
    pause(0.5); % Esperar un tiempo antes de pasar a la siguiente casilla
    delete(h); % Eliminar el círculo en la posición final
    delete(h2); % Eliminar el círculo en la posición final

    i2 = i;
    contadorIgualdades = 1;
    while J01(k1+1,i) == J02(k2+1,i2)
        if randi([0,1])
            k1 = k1 + 1;
        elseif contadorIgualdades == 9
            i2 = i2 -1;
        else
            k2 =+ 1;
        end
        contadorIgualdades = contadorIgualdades+ 1;
    end
      
end
% % Animación del movimiento a lo largo de la ruta "fluida" (se agrega un
% for con los para que en la transicion de cada posicion se actualice poco
% a poco y asi parece fluido 
% for i = 1:size(ruta, 1)-1
%     % Animar el movimiento desde la casilla actual a la siguiente casilla
%     for t = 0:0.1:1 % Pasos de tiempo de 0 a 1
%         current_pos = ruta(i,:) + t * (ruta(i+1,:) - ruta(i,:));
%         h = viscircles([current_pos(2)-0.5, current_pos(1)-0.5], 0.2, 'Color', 'red'); % Dibujar el círculo en la posición actual
%         pause(0.1); % Esperar un tiempo antes de actualizar la posición
%         delete(h); % Eliminar el círculo en la posición actual para animar el movimiento
%     end
% end