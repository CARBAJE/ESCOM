package com.ipn.mx.servicios;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Optional;

import com.ipn.ms.entidades.Documento;
import org.springframework.web.multipart.*;

public interface DocumentoServicio {
	public Documento guardarArchivo(MultipartFile archivo) throws IOException;
	
	public Optional<Documento> descargarArchivo(Long id) throws FileNotFoundException;
}
