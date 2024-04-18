package com.clases2;

public class Restaurante {
    String nombre, platoDia;
    int numComensales , cantPlatillos , maxComensales;
    float porcOcupado;

    public void Constructor(String nombre, String platoDia, 
    int numComensales, int cantPlatillos, int maxComensales,
    float porcOcupado){
        this.nombre = nombre;
        this.platoDia = platoDia;
        this.numComensales = numComensales;
        this.cantPlatillos = cantPlatillos;
        this.maxComensales = maxComensales;
        this.porcOcupado = porcOcupado;
    }
    public int AgregarComensal(int num){
        numComensales += num;
        return numComensales;
    }
    public float Porcentaje(){
        float porcent = 100 * (numComensales/maxComensales);
        return porcent;
    }
    public void Informe(){
        System.out.println("Nombre del Restaurante: "+nombre+
        "\nPlato del Dia: "+platoDia+"\nNumero de comensales"+numComensales+
        "\nCantidad de Platillos: "+cantPlatillos+"\nComensales Maximos: "+maxComensales+
        "Porcentaje Ocupado: "+porcOcupado);
    }
}   
