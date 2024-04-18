package com.ipn.mx.servicios;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.stereotype.Service;

import com.ipn.ms.entidades.Documento;
import com.ipn.mx.Repositorio.DocumentoRepositorio;

@Service
public class DocumentoServiceImpl implements DocumentoServicio{
	
	@Autowired
	DocumentoRepositorio documentoRepository;

	@Override
	public Documento guardarArchivo(MultipartFile archivo) throws IOException {
		String nombreDelArchivo =
			StringUtils.cleanPath(archivo.getOriginalFilename());
		Documento documento = Documento.builder().setNombreDocumento(nombreDelArchivo)
				.setTipoDocumento(archivo.getContentType()).setDatosDocumento(archivo.getBytes() )
				.build();
		
		return documento;
	}

	@Override
	public Optional<Documento> descargarArchivo(Long id) throws FileNotFoundException {
		Optional <Documento> archivo = documentoRepository.findById(id);
		if(archivo.isPresent()) {
			return archivo;
		}
		throw new FileNotFoundException("El archivo no existe");
		return Optional.empty();
	}

}
