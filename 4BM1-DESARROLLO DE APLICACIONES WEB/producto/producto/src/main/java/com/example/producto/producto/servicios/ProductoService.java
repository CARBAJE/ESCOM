package com.example.producto.producto.servicios;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.example.producto.producto.Entidades.Producto;
import com.example.producto.producto.repositorios.ProductoRepository;

import java.util.List;
import java.util.Optional;

@Service
public class ProductoService {

    @Autowired
    private ProductoRepository productoRepository;

    public List<Producto> obtenerTodosLosProductos() {
        return productoRepository.findAll();
    }

    public Producto obtenerProductoPorId(Long id) {
        Optional<Producto> productoOptional = productoRepository.findById(id);
        return productoOptional.orElse(null);
    }

    public Producto crearProducto(Producto producto) {
        // Puedes realizar validaciones u operaciones adicionales aquí antes de guardar
        return productoRepository.save(producto);
    }

    public Producto actualizarProducto(Long id, Producto producto) {
        // Verifica si el producto existe antes de actualizar
        if (productoRepository.existsById(id)) {
            producto.setIdProducto(id);
            return productoRepository.save(producto);
        }
        return null; // Puedes manejar la lógica en caso de que el producto no exista
    }

    public void eliminarProducto(Long id) {
        productoRepository.deleteById(id);
    }
}
