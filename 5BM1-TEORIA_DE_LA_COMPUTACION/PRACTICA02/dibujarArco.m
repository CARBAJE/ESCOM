function dibujarArco(theta_start, theta_end, radio, centro, opcion)
    % Definir el número de puntos para dibujar el arco
    num_points = 100;

    % Calcular las coordenadas (x, y) del arco
    theta = linspace(theta_start, theta_end, num_points);
    x_arc = centro(1) + radio * cos(theta);
    y_arc = centro(2) + radio * sin(theta);

    % Dibujar el arco en un plot cartesiano
    if opcion == 0 
        plot(centro(1) + radio * cos(theta) , centro(2) + radio * sin(theta), 'r', 'LineWidth', 3);
    elseif opcion == 1
        plot(x_arc, y_arc, 'k', 'LineWidth', 3);
    end

    hold on;

    % Calcular el punto final del arco
    x_end = centro(1) + radio * cos(theta_end);
    y_end = centro(2) + radio * sin(theta_end);

    % Calcular las coordenadas de los otros dos vértices del triángulo
    x_vertice1 = x_end - radio/2 * cos(theta_end - pi/9);  % Desplazado 30 grados
    y_vertice1 = y_end + radio/2 * sin(theta_end - pi/9);
    x_vertice2 = x_end - radio/2 * cos(theta_end - pi/3);  % Desplazado -30 grados
    y_vertice2 = y_end + radio/2 * sin(theta_end - pi/3);
    
    if opcion == 0 
        % Dibujar líneas desde el punto final del arco hasta los vértices del triángulo
        plot([x_end, x_vertice1], [y_end, y_vertice1], 'r', 'LineWidth', 3);
        plot([x_end, x_vertice2], [y_end, y_vertice2], 'r', 'LineWidth', 3);
    elseif opcion == 1
        % Dibujar líneas desde el punto final del arco hasta los vértices del triángulo
        plot([x_end, x_vertice1], [y_end, y_vertice1], 'k', 'LineWidth', 3);
        plot([x_end, x_vertice2], [y_end, y_vertice2], 'k', 'LineWidth', 3);
    end

    axis equal;  % Para asegurar que la escala de los ejes sea igual
end
