clc
clear
close all

% Especifica la ruta del archivo que contiene la URL
archivo_url = "/home/carbaje/Documents/CODIGOS_FUENTES/5BM1-TEORIA_DE_LA_COMPUTACION/PRACTICA04/URL.txt";

% Lee la URL desde el archivo de texto
fid = fopen(archivo_url, 'r');
url = fgetl(fid);
fclose(fid);

% Lee el contenido HTML desde la URL
html_content = webread(url);

% Extrae el texto visible del contenido HTML
text_content = lower(extractHTMLText(html_content));

% Especifica la ruta del archivo donde deseas almacenar el texto
archivo_destino = 'textoWEB.txt';

% Escribe el texto en el archivo destino
fid = fopen(archivo_destino, 'w');
fprintf(fid, '%s', text_content);
fclose(fid);

disp('Texto extraído y almacenado con éxito.');

close all;
exit();