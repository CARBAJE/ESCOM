package com.example.producto.producto.servicios;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.example.producto.producto.Entidades.Categoria;
import com.example.producto.producto.repositorios.CategoriaRepository;
import java.util.List;
import java.util.Optional;

@Service
public class CategoriaService {

    @Autowired
    private CategoriaRepository categoriaRepository;

    public List<Categoria> obtenerTodasLasCategorias() {
        return categoriaRepository.findAll();
    }

    public Categoria obtenerCategoriaPorId(Long id) {
        Optional<Categoria> categoriaOptional = categoriaRepository.findById(id);
        return categoriaOptional.orElse(null);
    }

    public Categoria crearCategoria(Categoria categoria) {
        // Puedes realizar validaciones u operaciones adicionales aquí antes de guardar
        return categoriaRepository.save(categoria);
    }

    public Categoria actualizarCategoria(Long id, Categoria categoria) {
        // Verifica si la categoría existe antes de actualizar
        if (categoriaRepository.existsById(id)) {
            categoria.setIdCategoria(id);
            return categoriaRepository.save(categoria);
        }
        return null; // Puedes manejar la lógica en caso de que la categoría no exista
    }

    public void eliminarCategoria(Long id) {
        categoriaRepository.deleteById(id);
    }
}
