clc
clear all
close all
warning off all

a = imread('prueba01.jpg');
figure(1)
imshow(a)
colores = ['b', 'g', 'r', 'c', 'm', 'y', 'k'];

num_clases = input('Ingrese el número de clases que desea crear: ');

clases = cell(1, num_clases); % Crear celdas para almacenar las clases

rep_clase = input('Ingrese el número de representantes para las clases: ');

for i = 1:num_clases
    fprintf('Captura el punto para la clase %d en la imagen :\n', i);
    [inicia_en_X, inicia_en_Y] = ginput(1);
    
    hold on; 
  
    plot(inicia_en_X, inicia_en_Y, 'ro', 'MarkerSize', 7, 'LineWidth', 2);
    legend("show"); 
    %hold off; 
    
    dispercion_en_X = input(['Ingresa la dispersion en X para la clase ', num2str(i), ': ']);
    dispercion_en_Y = input(['Ingresa la dispersion en Y para la clase ', num2str(i), ': ']);
    x = randn(1, rep_clase) * dispercion_en_X + inicia_en_X;
    y = randn(1, rep_clase) * dispercion_en_Y + inicia_en_Y;
    clases{i} = [x; y]; % Almacenar cada clase en una celda
    hold on; 
    scatter(clases{i}(1,:), clases{i}(2,:), 'filled', 'MarkerFaceColor', colores(i));
    legend("show");
end
% 
% for i = 1:num_clases
%     hold on; 
%     scatter(clases{i}(1,:), clases{i}(2,:), 'filled', 'MarkerFaceColor', colores(i));
%     legend("show");
% end

while true
    clf; 
    imshow(a)
    hold on; 
    for i = 1:num_clases
    scatter(clases{i}(1,:), clases{i}(2,:), 'filled', 'MarkerFaceColor', colores(i));
    legend("show");
    end
    disp('haga click en la imagen para el vector desconocido'); 
    [vx, vy] = ginput(1);
    vector = [vx; vy];
    plot([vector(1) vx], [vector(2) vy], 'cx', 'MarkerSize',10,'LineWidth',3);
    legend("show"); 
    vector_rgb = impixel(a, vx, vy)
    hold off

    % Calcular la distancia euclidiana entre el vector y cada punto en valores_rgb_clase
    tipo_distancia = input('¿Qué tipo de distancia desea calcular? (1: Euclidiana, 2: Mahalanobis 3:Probabilidad Maxima)  ');
    
    if tipo_distancia == 1
        dist_total = [];
        for i = 1:num_clases
            clase_actual = clases{i};
            % Obtener los valores RGB de todos los puntos en la clase
            valores_rgb_clase = impixel(a, clase_actual(1,:), clase_actual(2,:));
            media = mean(valores_rgb_clase, 1);
            % Calcular la distancia euclidiana
            distancia = sqrt((vector_rgb(1) - media(1))^2 + (vector_rgb(2) - media(2))+(vector_rgb(3) - media(3))^2);            
            dist_total = [dist_total, distancia];
        end
        min_dist = min(dist_total); % Buscar la mínima distancia
        valor = find(dist_total == min_dist); % Encontrar el índice de la mínima distancia

    elseif tipo_distancia == 2
        dist_total = [];
        for i = 1:num_clases
            clase_actual = clases{i};
            % Obtener los valores RGB de todos los puntos en la clase
            valores_rgb_clase = impixel(a, clase_actual(1,:), clase_actual(2,:));
            % Calcular la media y la matriz de covarianza de la clase
            media = mean(valores_rgb_clase, 1);
            covarianza = cov(valores_rgb_clase);
            % Calcular la distancia mahalanobis
            dist = sqrt((vector_rgb - media) * inv(covarianza) * (vector_rgb - media)');
            dist_total = [dist_total, dist];
        end
        min_dist = min(dist_total); % Buscar la mínima distancia
        valor = find(dist_total == min_dist); % Encontrar el índice de la mínima distancia
    elseif tipo_distancia == 3

    probabilidades = zeros(1, num_clases);
        for i = 1:num_clases
            clase_actual = clases{i};
            % Obtener los valores RGB de todos los puntos en la clase
            valores_rgb_clase = impixel(a, clase_actual(1,:), clase_actual(2,:));
            % Calcular la media y la matriz de covarianza de la clase
            media = mean(valores_rgb_clase, 1);
            covarianza = cov(valores_rgb_clase);
            % Calcular la distancia mahalanobis
            dist = sqrt((vector_rgb - media) * inv(covarianza) * (vector_rgb - media)');
            det_cov = det(covarianza);
            % Calcular la probabilidad
            probabilidad = (1/(2*pi*sqrt(det_cov))) * exp(-0.5*dist);
            probabilidades(i) = probabilidad;
        end
        % Determinar la clase con la mayor probabilidad
        [max_prob, clase_pred] = max(probabilidades)
        valor = clase_pred;    
    
    end
      
    disp(['El vector desconocido pertenece a la clase ', num2str(valor)]);
    % plot(vector(1), vector(2), 'ko', 'MarkerSize', 10, 'LineWidth', 2);
    % legend('show');

    continuar = input('¿Desea usar otro vector? (S/N): ', 's');
    if ~strcmpi(continuar, 's')
        break; % Salir del bucle si la respuesta no es 's'
    end
end