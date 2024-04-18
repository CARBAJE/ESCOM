function valores_clase = obtenerValoresClase(imagen, clase_actual)
    valores_clase = impixel(imagen, clase_actual(1,:), clase_actual(2,:));
end