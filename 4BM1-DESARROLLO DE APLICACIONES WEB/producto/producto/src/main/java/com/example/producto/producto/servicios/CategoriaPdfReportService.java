package com.example.producto.producto.servicios;

import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.example.producto.producto.Entidades.Categoria;
import java.util.List;
import java.io.ByteArrayOutputStream;
import java.io.IOException;

@Service
public class CategoriaPdfReportService {

    @Autowired
    private CategoriaService categoriaService;

    public byte[] generatePdfReport() throws DocumentException, IOException {
        List<Categoria> categorias = categoriaService.obtenerTodasLasCategorias();

        ByteArrayOutputStream baos = new ByteArrayOutputStream();

        try {
            Document document = new Document();
            PdfWriter.getInstance(document, baos);
            document.open();

            for (Categoria categoria : categorias) {
                // Agrega los datos de la categoría al PDF
                document.add(new Paragraph("ID: " + categoria.getIdCategoria()));
                document.add(new Paragraph("Nombre: " + categoria.getNombreCategoria()));
                document.add(new Paragraph("Descripción: " + categoria.getDescripcionCategoria()));
                document.add(new Paragraph("-----"));
            }

            document.close();
        } catch (Exception e) {
            throw new DocumentException("Error al generar el informe PDF", e);
        }

        return baos.toByteArray();
    }
}
