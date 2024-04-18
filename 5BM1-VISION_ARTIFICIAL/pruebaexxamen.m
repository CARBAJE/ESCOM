% Cargar la imagen
imagen = imread("C:\Users\emicr\Pictures\WALLPAPERS\porco-rosso-watercolour[1].jpg");

% Convertir la imagen a espacio de color RGB
imagen_rgb = im2double(imagen);

% Extraer los canales de color
canal_rojo = imagen_rgb(:,:,1);
canal_verde = imagen_rgb(:,:,2);
canal_azul = imagen_rgb(:,:,3);

% Crear una máscara para el color rojo
umbral_rojo = 0.8; % Umbral para el color rojo (ajústalo según sea necesario)
umbral_verde = 0.8;
mascara_rojo = (canal_rojo > umbral_rojo) & (canal_verde < 0.5) & (canal_azul < 0.5);
mascara_verde = (canal_rojo < 0.5) & (canal_verde > umbral_verde) & (canal_azul < 0.5);

% Aplicar la máscara al canal rojo
espectro_rojo = imagen_rgb;
espectro_rojo(:,:,2) = espectro_rojo(:,:,2) .* mascara_rojo;
espectro_rojo(:,:,3) = espectro_rojo(:,:,3) .* mascara_rojo;

%aplicar la mascara al canal verde
espectro_verde = imagen_rgb;
espectro_verde = espectro_verde(:,:,1) .* mascara_verde;
%espectro_verde = espectro_verde(:,:,3) .* mascara_verde;

% Mostrar la imagen con el espectro de color rojo
figure;
imshow(espectro_verde);
title('Espectro de color rojo en la imagen');
