% Cargar la imagen
imagen = imread("C:\Users\emicr\Pictures\WALLPAPERS\porco-rosso-watercolour[1].jpg");

% Convertir la imagen a espacio de color RGB
imagen_rgb = im2double(imagen);

% Obtener los canales de color RGB
canal_rojo = imagen_rgb(:,:,1);
canal_verde = imagen_rgb(:,:,2);
canal_azul = imagen_rgb(:,:,3);

% Calcular los canales CMY
canal_cian = 1 - canal_rojo;
canal_magenta = 1 - canal_verde;
canal_amarillo = 1 - canal_azul;

% Calcular los canales de negro, blanco y escala de grises
canal_negro = min(imagen_rgb, [], 3);
canal_blanco = max(imagen_rgb, [], 3);
canal_gris = rgb2gray(imagen_rgb);

% Crear la matriz 5x3 de imágenes resultantes
imagen_resultante = zeros(size(imagen, 1), size(imagen, 2), 5, 3);

% Asignar las imágenes a la matriz
imagen_resultante(:,:,1,1) = canal_cian;
imagen_resultante(:,:,2,1) = canal_magenta;
imagen_resultante(:,:,3,1) = canal_amarillo;
imagen_resultante(:,:,1,2) = canal_rojo;
imagen_resultante(:,:,2,2) = canal_verde;
imagen_resultante(:,:,3,2) = canal_azul;
imagen_resultante(:,:,1,3) = canal_negro;
imagen_resultante(:,:,2,3) = canal_blanco;
imagen_resultante(:,:,3,3) = canal_gris;

% Mostrar la imagen compuesta
figure;
for i = 1:3
    for j = 1:3
        subplot(3, 3, (i-1)*3 + j);
        imshow(imagen_resultante(:,:,i,j));
        title(sprintf('Canal %d, Fila %d, Columna %d', j, i, j));
    end
end
