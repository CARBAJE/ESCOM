function arreglo_imagenes = pruebaExamen()
    % Carga la imagen
    imagen = imread("C:\Users\emicr\Downloads\sophie-Gz3iikctfEw-unsplash.jpg");
    
    % Extraer los canales rojo y azul
    canalRojo = imagen(:,:,1);
    canalVerde = imagen(:,:,2);
    canalAzul = imagen(:,:,3);
    
    % Imagenes en un unico color RGB
    soloRojo = zeros(size(imagen), 'uint8');
    soloRojo(:,:,1) = canalRojo;
    
    soloVerde = zeros(size(imagen), 'uint8');
    soloVerde(:,:,2) = canalVerde;
    
    soloAzul = zeros(size(imagen), 'uint8');
    soloAzul(:,:,3) = canalAzul;
    
    % Imagenes en un unico color CMY
    soloMagenta = imagen;
    soloMagenta(:,:,2) = 0;
    
    soloCyan = imagen;
    soloCyan(:,:,1) = 0;
    
    soloAmarillo = imagen;
    soloAmarillo(:,:,3) = 0;
    
    % Imagen en negro blanco y grises
    imgGris = cat(3, uint8(mean(imagen, 3)), rgb2gray(imagen), rgb2gray(imagen));
    imgNegro = zeros(size(imagen), 'uint8');
    imgBlanco =  255 * ones(size(imagen), 'uint8');
    
    % Obtén el tamaño de las imágenes individuales
    [filas, columnas, ~] = size(imagen);
    
    % Crea una imagen en blanco para el arreglo
    arreglo_imagenes = uint8(zeros(filas*3, columnas*3, 3));
    
    
    % Coloca las imágenes en el arreglo
    arreglo_imagenes(1:filas, 1:columnas, :) = soloCyan;
    arreglo_imagenes(1:filas, columnas+1:2*columnas, :) = soloMagenta;
    arreglo_imagenes(1:filas, 2*columnas+1:3*columnas, :) = soloAmarillo;
    arreglo_imagenes(filas+1:2*filas, 1:columnas, :) = soloRojo;
    arreglo_imagenes(filas+1:2*filas, columnas+1:2*columnas, :) = soloVerde;
    arreglo_imagenes(filas+1:2*filas, 2*columnas+1:3*columnas, :) = soloAzul;
    arreglo_imagenes(2*filas+1:3*filas, 1:columnas, :) = imgNegro;
    arreglo_imagenes(2*filas+1:3*filas, columnas+1:2*columnas, :) = imgBlanco;
    arreglo_imagenes(2*filas+1:3*filas, 2*columnas+1:3*columnas, :) = imgGris;
    

end