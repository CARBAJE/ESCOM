function matriz = leer_csv(nombre_archivo)
    % Tamaño del bloque
    block_size = 1e6; % Por ejemplo, lee el archivo en bloques de 1 millón de tuplas

    % Abrir el archivo para lectura
    fileID = fopen(nombre_archivo, 'r');

    if fileID == -1
        error('No se pudo abrir el archivo.');
    end

    % Inicializar matriz para almacenar los datos
    matriz = [];

    % Leer los datos en bloques
    while ~feof(fileID)
        % Leer un bloque de datos del archivo
        data = textscan(fileID, '%d%d', block_size, 'Delimiter', ',', 'HeaderLines', 1);
        if isempty(data{1})
            break; % No hay más datos para leer, salir del bucle
        end

        % Crear la matriz de salida combinando la primera columna (chars_cell) y la segunda columna (data{2})
        matriz = [matriz; [num2cell(data{1}), num2cell(data{2})]];
    end

    % Cerrar el archivo
    fclose(fileID);
end
