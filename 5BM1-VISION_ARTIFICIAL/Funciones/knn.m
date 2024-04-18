function valor = knn(vector_caracteristicas, clases, imagen)
    num_clases = numel(clases);
    rep_clase = size(clases{1}, 2);
    distancias_clase = zeros(num_clases, rep_clase);
    for i = 1:num_clases
        clase_actual = clases{i};
        valores_clase = obtenerValoresClase(imagen, clase_actual);
        for j = 1:rep_clase
            distancia = sqrt(sum((vector_caracteristicas - valores_clase(j,:)).^2));
            distancias_clase(i,j) = distancia;
        end
    end
    num_vecinos = input('Ingrese el número de vecinos: ');
    vector = distancias_clase(:)';
    vector_ordenado = sort(vector);
    valores_mas_pequenos = vector_ordenado(1:num_vecinos);
    indices_fila = zeros(1, num_vecinos);
    for i = 1:num_vecinos
        [fila, ~] = find(distancias_clase == valores_mas_pequenos(i),1);
        indices_fila(i) = fila;
    end
    valor = mode(indices_fila);
end