clear
clc
close all;

%% Paso 1:  Obtener la informacion
datos = leer_csv('rutaGraficar.csv'); % leemos nuestra ruta

% Define los radios de los tres círculos
r1 = 3;
r2 = 3;
r3 = 3;

% Define las coordenadas de los centros de los círculos
centro1 = [0, 0];
centro2 = [10, 0];
centro3 = [20, 0];

%% Paso 2: Dibujar el escenario
figure;
for k = 1 : size(datos, 1) 
    %Limpiamos la figura
    clf
    hold on;
    opcion = datos{k, 2}; % Usa {} en lugar de () para acceder al contenido de la celda
    
    % Mostrar cadena de entrada
    text(centro1(1)-10 - r2/2, centro2(2)-1.5*r2, 'La cadena de entrada fue:', 'FontName', 'Times New Roman', 'FontSize', 16, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
    for i = 1: k
        x_pos = centro1(1) - 10 - r2/2 + (i-1) * 0.5; % Ajusta la posición horizontal para cada caracter
        y_pos = centro2(2) - 2.2 * r2; % Ajusta la posición vertical
        if i == k
            text(x_pos, y_pos, datos{i,1}, 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
        else
            text(x_pos, y_pos, datos{i,1}, 'FontName', 'Times New Roman', 'FontSize', 10, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
        end
    end
    switch opcion
        case 0
            if datos{k+1, 2} == 0 
                % Dibuja el primer estado
                rectangle('Position', [centro1(1)-r1, centro1(2)-r1, 2*r1, 2*r1], 'Curvature', [1, 1], 'FaceColor', 'g','EdgeColor', 'r' , LineWidth=3);
                text(centro1(1) - r1/3.5, centro1(2), 'Q_0', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
                
                quiver(centro1(1)+r1, centro1(2), centro2(1)-r2-2.5, centro2(2), 'k','ShowArrowHead','on', 'LineWidth', 3,'AutoScale','on', 'MaxHeadSize',5 );
                
                text(centro1(1) + r1*1.4, centro1(2)+r1*.3, '0', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
                
                dibujarArco(5*(pi/3), pi/3, 3, [centro1(1)-r1, centro1(2)], 0);
                
                if datos{k,1} == '0'
                    text(centro1(1) - 1.8*r1, centro1(2)+r1*1.3, '0', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
                elseif datos{k,1} == '1'
                    text(centro1(1) - 1.8*r1, centro1(2)+r1*1.3, '1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
                end
                % Dibuja el segundo estado
                rectangle('Position', [centro2(1)-r2, centro2(2)-r2, 2*r2, 2*r2], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k' , LineWidth=3);
                text(centro2(1) - r1/3.5, centro2(2), 'Q_1', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
                
                quiver(centro2(1)+r2, centro2(2), centro3(1)-4*r3-3.5, centro2(2), 'k', 'ShowArrowHead','on', 'LineWidth',3, 'AutoScale','on', 'MaxHeadSize',5)
                text(centro2(1) + r2*1.4, centro2(2)+r2*.3, '1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
                
                % Dibuja el tercer estado
                rectangle('Position', [centro3(1)-r3, centro3(2)-r3, 2*r3, 2*r3], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k' , LineWidth=3);
                rectangle('Position', [centro3(1)-1.7*(r3/2), centro1(2)-1.7*(r3/2), 1.7*r3, 1.7*r3], 'Curvature', [1, 1],'EdgeColor', 'k' , LineWidth=2);
                text(centro3(1) - r3/3.5, centro1(2), 'Q_2', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            elseif datos{k+1,2} == 1
                % Dibuja el primer estado
                rectangle('Position', [centro1(1)-r1, centro1(2)-r1, 2*r1, 2*r1], 'Curvature', [1, 1], 'FaceColor', 'g','EdgeColor', 'r' , LineWidth=3);
                text(centro1(1) - r1/3.5, centro1(2), 'Q_0', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
                
                quiver(centro1(1)+r1, centro1(2), centro2(1)-r2-2.5, centro2(2), 'r','ShowArrowHead','on', 'LineWidth', 3,'AutoScale','on', 'MaxHeadSize',5 );
                text(centro1(1) + r1*1.4, centro1(2)+r1*.3, '0', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
                
                % Llamar a la función para dibujar un arco
                dibujarArco(5*(pi/3), 1*pi/3, 3, [centro1(1)-r1, centro1(2)], 1);
                text(centro1(1) - 1.8*r1, centro1(2)+r1*1.3, '0,1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
                
                % Dibuja el segundo estado
                rectangle('Position', [centro2(1)-r2, centro2(2)-r2, 2*r2, 2*r2], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'r' , LineWidth=3);
                text(centro2(1) - r1/3.5, centro2(2), 'Q_1', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
                
                quiver(centro2(1)+r2, centro2(2), centro3(1)-4*r3-3.5, centro2(2), 'k', 'ShowArrowHead','on', 'LineWidth',3, 'AutoScale','on', 'MaxHeadSize',5)
                text(centro2(1) + r2*1.4, centro2(2)+r2*.3, '1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
                
                % Dibuja el tercer estado
                rectangle('Position', [centro3(1)-r3, centro3(2)-r3, 2*r3, 2*r3], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k' , LineWidth=3);
                rectangle('Position', [centro3(1)-1.7*(r3/2), centro1(2)-1.7*(r3/2), 1.7*r3, 1.7*r3], 'Curvature', [1, 1],'EdgeColor', 'k' , LineWidth=2);
                text(centro3(1) - r3/3.5, centro1(2), 'Q_2', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            end
        case 1
            % Dibuja el primer estado
            rectangle('Position', [centro1(1)-r1, centro1(2)-r1, 2*r1, 2*r1], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'r' , LineWidth=3);
            text(centro1(1) - r1/3.5, centro1(2), 'Q_0', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            quiver(centro1(1)+r1, centro1(2), centro2(1)-r2-2.5, centro2(2), 'r','ShowArrowHead','on', 'LineWidth', 3,'AutoScale','on', 'MaxHeadSize',5 );
            text(centro1(1) + r1*1.4, centro1(2)+r1*.3, '0', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            % Llamar a la función para dibujar un arco
            dibujarArco(5*(pi/3), 1*pi/3, 3, [centro1(1)-r1, centro1(2)], 1);
            text(centro1(1) - 1.8*r1, centro1(2)+r1*1.3, '0,1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            % Dibuja el segundo estado
            rectangle('Position', [centro2(1)-r2, centro2(2)-r2, 2*r2, 2*r2], 'Curvature', [1, 1], 'FaceColor', 'g','EdgeColor', 'r' , LineWidth=3);
            text(centro2(1) - r1/3.5, centro2(2), 'Q_1', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            quiver(centro2(1)+r2, centro2(2), centro3(1)-4*r3-3.5, centro2(2), 'r', 'ShowArrowHead','on', 'LineWidth',3, 'AutoScale','on', 'MaxHeadSize',5)
            text(centro2(1) + r2*1.4, centro2(2)+r2*.3, '1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
            
            % Dibuja el tercer estado
            rectangle('Position', [centro3(1)-r3, centro3(2)-r3, 2*r3, 2*r3], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'r' , LineWidth=3);
            rectangle('Position', [centro3(1)-1.7*(r3/2), centro1(2)-1.7*(r3/2), 1.7*r3, 1.7*r3], 'Curvature', [1, 1],'EdgeColor', 'r' , LineWidth=2);
            text(centro3(1) - r3/3.5, centro1(2), 'Q_2', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
        case 2
            % Dibuja el primer estado
            rectangle('Position', [centro1(1)-r1, centro1(2)-r1, 2*r1, 2*r1], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k' , LineWidth=3);
            text(centro1(1) - r1/3.5, centro1(2), 'Q_0', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            quiver(centro1(1)+r1, centro1(2), centro2(1)-r2-2.5, centro2(2), 'k','ShowArrowHead','on', 'LineWidth', 3,'AutoScale','on', 'MaxHeadSize',5 );
            text(centro1(1) + r1*1.4, centro1(2)+r1*.3, '0', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            % Llamar a la función para dibujar un arco
            dibujarArco(5*(pi/3), 1*pi/3, 3, [centro1(1)-r1, centro1(2)], 1);
            text(centro1(1) - 1.8*r1, centro1(2)+r1*1.3, '0,1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            % Dibuja el segundo estado
            rectangle('Position', [centro2(1)-r2, centro2(2)-r2, 2*r2, 2*r2], 'Curvature', [1, 1], 'FaceColor', 'w','EdgeColor', 'k' , LineWidth=3);
            text(centro2(1) - r1/3.5, centro2(2), 'Q_1', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            quiver(centro2(1)+r2, centro2(2), centro3(1)-4*r3-3.5, centro2(2), 'k', 'ShowArrowHead','on', 'LineWidth',3, 'AutoScale','on', 'MaxHeadSize',5)
            text(centro2(1) + r2*1.4, centro2(2)+r2*.3, '1', 'FontName', 'Times New Roman', 'FontSize', 15, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','k');
            
            % Dibuja el tercer estado
            rectangle('Position', [centro3(1)-r3, centro3(2)-r3, 2*r3, 2*r3], 'Curvature', [1, 1], 'FaceColor', 'g','EdgeColor', 'r' , LineWidth=3);
            rectangle('Position', [centro3(1)-1.7*(r3/2), centro1(2)-1.7*(r3/2), 1.7*r3, 1.7*r3], 'Curvature', [1, 1],'EdgeColor', 'r' , LineWidth=2);
            text(centro3(1) - r3/3.5, centro1(2), 'Q_2', 'FontName', 'Times New Roman', 'FontSize', 20, 'FontAngle', 'italic', 'FontSmoothing', 'on', 'Color','r');
    end

    % Ajustes de los ejes y fondo del ploteo
    axis equal;% Ajusta la relación de aspecto para que los círculos se vean como círculos
    axis off;
    
    grid off; % Activa la cuadrícula para una mejor visualización
    
    % Ajustes del titulo del ploteo
    
    [titulo,subtitulo] = title('Animación Practica 02','Automata no Determinista', 'FontName','Tmes New Roman');
    titulo.FontName = 'Times New Roman';
    subtitulo.FontName = 'Times New Roman';
    titulo.FontSize = 16;
    titulo.FontWeight = "bold";
    subtitulo.FontAngle = 'italic';
    %Forzar a matlab a dibujar la figura justo en ese momento
    drawnow;
    pause(0.5);
    frameVector(k) = getframe;
end

%% Paso 3: Guardar la animacion
video = VideoWriter('animacionP02.m', 'MPEG-4');
video.FrameRate = 20;

%Abrir, guardar y cerrar el video
%open(video);
%writeVideo(video, frameVector);
%close(video);


%% Paso 4: Terminar el programa 
pause(5);
close all
%exit();

