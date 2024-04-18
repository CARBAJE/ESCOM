package com.ipn.mx.Repositorio;

import org.springframework.data.jpa.repository.JpaRepository;

import com.ipn.ms.entidades.Documento;

public interface DocumentoRepositorio extends JpaRepository<Documento, Long> {

}
