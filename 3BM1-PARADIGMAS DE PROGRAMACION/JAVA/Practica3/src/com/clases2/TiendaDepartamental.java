package com.clases2;

public class TiendaDepartamental {
    String nomTienda;
    String producto;
    int pisos , cantDep;
    float areaTer , areaEsp;

    public void Constructor(String nomTienda , String producto ,
    int pisos, int cantDep, float areaTer, float areaEsp){
        this.nomTienda = nomTienda;
        this.producto = producto;
        this.pisos = pisos;
        this.cantDep = cantDep;
        this.areaTer = areaTer;
        this.areaEsp = areaEsp;
    }
    public void CambiarProducto(String producto){
        this.producto = producto;
    }
    public void informe(){
        System.out.println("Nombre de tienda: "+nomTienda+
        "\nProducto estrella. "+producto+"\nnNumero de pisos: "+pisos+
        "\nCantidad de Departamenots: "+cantDep+"Area del terreno(m2): "+areaTer+
        "\nArea total del edificio(m2): "+areaEsp);
    }
}
