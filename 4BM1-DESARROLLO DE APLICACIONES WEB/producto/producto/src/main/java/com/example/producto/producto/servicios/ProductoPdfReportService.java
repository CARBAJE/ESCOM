package com.example.producto.producto.servicios;
import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;
import com.example.producto.producto.Entidades.Producto;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;

@Service
public class ProductoPdfReportService {

    @Autowired
    private ProductoService productoService;

    public byte[] generatePdfReport() throws DocumentException, IOException {
        List<Producto> productos = productoService.obtenerTodosLosProductos();

        ByteArrayOutputStream baos = new ByteArrayOutputStream();

        try {
            Document document = new Document();
            PdfWriter.getInstance(document, baos);
            document.open();

            for (Producto producto : productos) {
                // Agrega los datos del producto al PDF
                document.add(new Paragraph("ID: " + producto.getIdProducto()));
                document.add(new Paragraph("Nombre: " + producto.getNombreProducto()));
                document.add(new Paragraph("Descripción: " + producto.getDescripcionProducto()));
                document.add(new Paragraph("Precio: " + producto.getPrecioProducto()));
                document.add(new Paragraph("-----"));
            }

            document.close();
        } catch (Exception e) {
            throw new DocumentException("Error al generar el informe PDF", e);
        }

        return baos.toByteArray();
    }
}
