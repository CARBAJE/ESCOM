package com.ipn.mx.dto;

import lombok.*;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class RespuestaDTO {
	private String mensaje;
	
	public RespuestaDTO(String mensaje) {
		super();
		this.mensaje = mensaje;
	}

	public String getMensaje() {
		return mensaje;
	}

	public void setMensaje(String mensaje) {
		this.mensaje = mensaje;
	}
}
