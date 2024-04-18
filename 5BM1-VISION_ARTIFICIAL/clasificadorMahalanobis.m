function clase = clasificadorMahalanobis(clusters, vector)
    % programa para calcular distancia mahalanobis
    % 1/n{X-mk)(X-mk)^T}

    num_clusters = size(clusters, 3);
    
    % graficando las clases
    colors = ['r', 'b', 'g', 'c', 'm', 'y']; % Definir colores para graficar
    for i = 1:num_clusters
        plot(clusters(1,:,i), clusters(2,:,i), [colors(i), 'o'], 'MarkerSize', 10, 'MarkerFaceColor', colors(i))
        hold on
    end
    plot(vector(1,:), vector(2,:), 'mh', 'MarkerSize', 10, 'MarkerFaceColor', 'm')
    legend(cellstr(strcat('clase', num2str((1:num_clusters)') ) ) )

    % clasificador de la toma de decisiones
    media = zeros(2, num_clusters);
    sigma = zeros(2, 2, num_clusters);
    dist = zeros(1, num_clusters);
    
    for i = 1:num_clusters
        media(:,i) = mean(clusters(:,:,i), 2);
        sigma(:,:,i) = (1/size(clusters,2)) * (clusters(:,:,i) - media(:,i)) * (clusters(:,:,i) - media(:,i))';
        dist(i) = (vector - media(:,i))' * sigma(:,:,i) * (vector - media(:,i));
    end
    
    [~, clase] = min(dist);
end
