package com.ipn.mx.controladores;

import java.io.FileNotFoundException;
import java.io.IOException;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import com.ipn.ms.entidades.Documento;
import com.ipn.mx.dto.RespuestaDTO;
import com.ipn.mx.servicios.DocumentoServicio;

@RestController
@RequestMapping("apiDocumentos/documento")
public class DocumentoControlador {
	@Autowired
	DocumentoServicio service;
	
	@PostMapping("/subirArchivo")
	public ResponseEntity<RespuestaDTO> subirArchivo(@RequestParam ("archivo") MultipartFile archivo) throws IOException{
		service.guardarArchivo(archivo);
		return ResponseEntity.status(HttpStatus.OK).body(new RespuestaDTO("Archivo subido satisfactoriamente"));
	}
	
	@GetMapping("/descargarDocumento/{id}")
	public ResponseEntity<byte[]> descargarDocumento(@PathVariable Long id) throws FileNotFoundException{
		Documento documento = service.descargarArchivo(id).get();
		return ResponseEntity.status(HttpStatus.OK).header(HttpHeaders.CONTENT_TYPE, documento.getTipoDocumento()).
				header(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename=\""+documento.getNombreDocumento()+"\"").
				body(documento.getDatosDocummento());
	}
	
}
