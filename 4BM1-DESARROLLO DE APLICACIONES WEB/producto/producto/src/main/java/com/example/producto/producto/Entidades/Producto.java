package com.example.producto.producto.Entidades;

import java.math.BigDecimal;
import java.util.Set;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.JoinTable;
import jakarta.persistence.ManyToMany;
import jakarta.persistence.Table;

@Entity
@Table(name = "producto" , schema = "public")
public class Producto {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long idProducto;

    @Column(name = "nombreProducto",nullable = false)
    private String nombreProducto;

    @Column(nullable = false)
    private String descripcionProducto;

    @Column(nullable = false)
    private BigDecimal precioProducto;

    @ManyToMany
    @JoinTable(
        name = "producto_categoria", schema = "public",
        joinColumns = @JoinColumn(name = "idProducto"),
        inverseJoinColumns = @JoinColumn(name = "idCategoria")
    )
    private Set<Categoria> categorias;

    @Column(nullable = false)
    private int existenciaProducto;

    // Otros atributos y métodos getter/setter

    // Getters y setters
    public Long getIdProducto() {
        return idProducto;
    }

    public void setIdProducto(Long idProducto) {
        this.idProducto = idProducto;
    }

    public String getNombreProducto() {
        return nombreProducto;
    }

    public void setNombreProducto(String nombreProducto) {
        this.nombreProducto = nombreProducto;
    }

    public String getDescripcionProducto() {
        return descripcionProducto;
    }

    public void setDescripcionProducto(String descripcionProducto) {
        this.descripcionProducto = descripcionProducto;
    }

    public BigDecimal getPrecioProducto() {
        return precioProducto;
    }

    public void setPrecioProducto(BigDecimal precioProducto) {
        this.precioProducto = precioProducto;
    }

    public Set<Categoria> getCategorias() {
        return categorias;
    }

    public void setCategorias(Set<Categoria> categorias) {
        this.categorias = categorias;
    }

    public int getExistenciaProducto() {
        return existenciaProducto;
    }

    public void setExistenciaProducto(int existenciaProducto) {
        this.existenciaProducto = existenciaProducto;
    }
}
