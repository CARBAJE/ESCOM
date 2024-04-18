function clase_pred = probabilidadMaxima(vector_caracteristicas, clases, imagen)
    num_clases = numel(clases);
    probabilidades = zeros(1, num_clases);
    for i = 1:num_clases
        clase_actual = clases{i};
        valores_clase = obtenerValoresClase(imagen, clase_actual);
        media = mean(valores_clase, 'omitnan');
        covarianza = cov(valores_clase, 'omitrows');
        dist = sqrt((vector_caracteristicas - media) * pinv(covarianza) * (vector_caracteristicas - media)');
        det_cov = det(covarianza);
        probabilidad = (1/(sqrt((2*pi)^size(vector_caracteristicas, 2) * det_cov))) * exp(-0.5*dist);
        probabilidades(i) = probabilidad;
    end
    [~, clase_pred] = max(max(probabilidades));
end