clc
clear all
close all
warning off all

c1 = [1 2 1 4 3; 2 0 3 1 2];
c2 = [3 3 5 6 5; 4 7 2 5 0];
c3 = [7 6 9 8 7; 3 9 0 1 2];

% Crear una matriz tridimensional para almacenar todas las clases
clusters = cat(3, c1, c2, c3);

% Obtener las coordenadas del vector desconocido
vx = input('dame la coord en x=');
vy = input('dame la coord en y=');
vector = [vx; vy];

% Llamar a la función clasificadorMahalanobis
clase = clasificadorMahalanobis(clusters, vector);

sprintf('El vector desconocido pertenece a la clase %d', clase)
