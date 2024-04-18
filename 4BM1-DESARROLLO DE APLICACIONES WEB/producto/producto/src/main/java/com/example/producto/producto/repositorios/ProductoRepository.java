package com.example.producto.producto.repositorios;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;
import com.example.producto.producto.Entidades.Producto;

@Repository
public interface ProductoRepository extends JpaRepository<Producto, Long> {
    // Puedes agregar métodos personalizados aquí si es necesario
}
