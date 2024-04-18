% Configurar el trazado
scatter_options = '.';

% Inicializar variables para el trazado
figure;

% Nombre del archivo y tamaño del bloque
nombre_archivo = 'salidaPractica1.csv';
block_size = 1e6; % Por ejemplo, lee el archivo en bloques de 1 millón de tuplas

% Abrir el archivo para lectura
fileID = fopen(nombre_archivo, 'r');

if fileID == -1
    error('No se pudo abrir el archivo.');
end

% Crear subplots
subplot(2, 1, 1);
hold on;

% Leer y graficar los datos en bloques
while ~feof(fileID)
    % Leer un bloque de datos del archivo
    data = textscan(fileID, '%f%f', block_size, 'Delimiter', ',', 'HeaderLines', 1);
    if isempty(data{1})
        break; % No hay más datos para leer, salir del bucle
    end
    
    % Trazar los datos del bloque actual
    scatter(data{1}, data{2}, scatter_options);
end

% Configurar etiquetas y título
xlabel('ID de cadena');
ylabel('Cantidad de puntos en la cadena');
title('Gráfico de la cantidad de puntos por cadena');

% Crear subplots para el logaritmo
subplot(2, 1, 2);
hold on;

% Reiniciar la lectura del archivo
frewind(fileID);

% Leer y graficar los datos en bloques con logaritmo
while ~feof(fileID)
    % Leer un bloque de datos del archivo
    data = textscan(fileID, '%f%f', block_size, 'Delimiter', ',', 'HeaderLines', 1);
    if isempty(data{1})
        break; % No hay más datos para leer, salir del bucle
    end
    
    % Aplicar el logaritmo a la cantidad de puntos
    data_log = log(data{2});
    
    % Trazar los datos del bloque actual con logaritmo
    scatter(data{1}, data_log, scatter_options);
end

% Configurar etiquetas y título para el subplot de logaritmo
xlabel('ID de cadena');
ylabel('Log(Cantidad de puntos en la cadena)');
title('Gráfico del logaritmo de la cantidad de puntos por cadena');

% Cerrar el archivo
fclose(fileID);

% Mostrar el gráfico
hold off;

pause(5);
close all;
exit();
