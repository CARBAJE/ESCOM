clc
clear
close all
warning off all

imagen = pruebaExamen();
figure(1);
imshow(imagen)
colores = ['c', 'm', 'y', 'r', 'g', 'b', 'w', 'k', 'auto'];

num_clases = 9;

clases = cell(1, num_clases); % Crear celdas para almacenar las clases

rep_clase = input('Ingrese el número de representantes para las clases: ');

color = {'Cyan', 'Magenta', 'Amarillo', 'Rojo', 'Verde', 'Azul', 'Negro', 'Blanco', 'Gris'};

for i = 1:num_clases
    fprintf('Captura el punto para el color %s en la imagen :\n', color{i});
    [inicia_en_X, inicia_en_Y] = ginput(1);
    
    hold on; 
  
    plot(inicia_en_X, inicia_en_Y, 'ro', 'MarkerSize', 7, 'LineWidth', 2);
    legend("show"); 
    %hold off; 
    
    dispercion_en_X = 550;
    dispercion_en_Y = 330;
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
    imshow(imagen)
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
    vector_rgb = impixel(imagen, vx, vy);
    hold off

    tipo_distancia = input('¿Qué tipo de distancia desea calcular?\n 1. Euclidiana\n 2. Mahalanobis\n 3. Probabilidad Maxima\n 4. KNN\n Seleccione una opcion: ');

    switch tipo_distancia
        case 1
            valor = distanciaEuclidiana(vector_rgb, clases, imagen);
        case 2
            valor = distanciaMahalanobis(vector_rgb, clases, imagen);
        case 3
            valor = probabilidadMaxima(vector_rgb, clases, imagen);
        case 4
            valor = knn(vector_rgb, clases, imagen);
        otherwise
            disp('Opción inválida.');
    end

    disp(['El vector desconocido pertenece al color: ', color{valor}]);
    continuar = input('¿Desea usar otro vector? (S/N): ', 's');
    if ~strcmpi(continuar, 's')
        break;
    end
end


close all