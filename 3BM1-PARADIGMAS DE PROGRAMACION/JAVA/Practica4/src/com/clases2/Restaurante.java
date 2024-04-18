package com.clases2;

public class Restaurante {
    String nombre, platoDia;
    int numComensales , cantPlatillos , maxComensales;
    float porcOcupado;
    /**
     * 
     * @param nombre
     * @param platoDia
     * @param numComensales
     * @param cantPlatillos
     * @param maxComensales
     * @param porcOcupado
     */
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
    /**
     * 
     * @param num
     * @return numComensales
     */
    public int AgregarComensal(int num){
        numComensales += num;
        return numComensales;
    }
    public void setPorcOcupado(float porcOcupado) {
        porcOcupado = 100 * ((float) numComensales / maxComensales); 
        this.porcOcupado = porcOcupado;
    }
    public void Informe(){
        System.out.println("\n------------------Restaurante------------------");    
        System.out.println("\nNombre del Restaurante: "+nombre+
        "\nPlato del Dia: "+platoDia+"\nNumero de comensales: "+numComensales+
        "\nCantidad de Platillos: "+cantPlatillos+"\nComensales Maximos: "+maxComensales+
        "\nPorcentaje Ocupado: "+porcOcupado);
        System.out.println("\n---------------------------------------------------");
    }
}   
