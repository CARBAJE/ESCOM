package com.clases2;
public class Main{
    public static void main(String[] args){
        CentroComercial plaza = new CentroComercial(null);
        plaza.setDomicilio("Periferico Norte");
        plaza.setSuperficie(60000);
        plaza.setNombre("Plaza Santa Fe");
        plaza.setTelefono("5598748445");
        plaza.setNumTiendas(120);
        plaza.setNumPlantas(2);
        plaza.setTienda(null);
        plaza.setRestaurante(null);
        plaza.setEstacionamiento(null);
        plaza.abrirCentroComercial();
        plaza.informe();

        Estacionamiento estacionamiento = new Estacionamiento();
        estacionamiento.Constructor(0, 999, 3, 333, 3000, 0.0);
        estacionamiento.IngresarCarro(10);
        estacionamiento.setPorcLlenado(0.0);
        estacionamiento.Informe();
        Restaurante restaurante = new Restaurante();
        restaurante.Constructor("Vapiano", "Pasta Alfredo", 50, 70, 140, 30.0f);
        restaurante.AgregarComensal(10);
        restaurante.setPorcOcupado(30.0f);
        restaurante.Informe();
        TiendaDepartamental tienda = new TiendaDepartamental();
        tienda.Constructor("Palacio de Hierro", "Relojeria", 2, 15, 14330, 24660);
        tienda.CambiarProducto("Joyeria");
        tienda.informe();
    }

}
