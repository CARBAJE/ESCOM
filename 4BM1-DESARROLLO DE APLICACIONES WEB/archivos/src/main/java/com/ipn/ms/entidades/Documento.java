package com.ipn.ms.entidades;


import jakarta.persistence.*;
import lombok.*;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Builder
@Entity
@Table(name = "Documetno" , schema = "public")
public class Documento {

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long idDocumento;
	
	private String nombreDocumento;
	private String tipoDocumento;
	
	@Lob
	@Column(name = "datosDocumentos", length = 16777215)
	private byte[] datosDocummento;

	public Long getIdDocumento() {
		return idDocumento;
	}

	public void setIdDocumento(Long idDocumento) {
		this.idDocumento = idDocumento;
	}

	public String getNombreDocumento() {
		return nombreDocumento;
	}

	public void setNombreDocumento(String nombreDocumento) {
		this.nombreDocumento = nombreDocumento;
	}

	public String getTipoDocumento() {
		return tipoDocumento;
	}

	public void setTipoDocumento(String tipoDocumento) {
		this.tipoDocumento = tipoDocumento;
	}

	public byte[] getDatosDocummento() {
		return datosDocummento;
	}

	public void setDatosDocummento(byte[] datosDocummento) {
		this.datosDocummento = datosDocummento;
	}
}
