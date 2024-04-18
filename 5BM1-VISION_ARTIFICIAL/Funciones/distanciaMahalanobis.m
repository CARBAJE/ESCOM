function valor = distanciaMahalanobis(vector_caracteristicas, clases, imagen)
    num_clases = numel(clases);
    dist_total = zeros(1, num_clases); % Inicialización con ceros
    for i = 1:num_clases
        clase_actual = clases{i};
        valores_clase = obtenerValoresClase(imagen, clase_actual);
        media = mean(valores_clase, 'omitnan');
        covarianza = cov(valores_clase, 'omitrows');
        dist = sqrt((vector_caracteristicas - media) * pinv(covarianza) * (vector_caracteristicas - media)');
        dist_total(i) = dist; % Asignación de la distancia calculada en la posición correspondiente
    end
    min_dist = min(min(dist_total));
    valor = find(dist_total == min_dist);
end
