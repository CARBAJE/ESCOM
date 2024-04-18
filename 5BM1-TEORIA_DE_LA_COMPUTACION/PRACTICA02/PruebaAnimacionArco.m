clc
clear
close all;

figure
for i=1 : 1 :4
    clf
    hold on;
    dibujarArco(5*(pi/3), ( (5-i)*pi/3 ) / 100, 3, [0, 0], 0);
    pause(1);
end