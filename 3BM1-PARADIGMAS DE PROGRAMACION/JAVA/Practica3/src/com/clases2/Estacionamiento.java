package com.clases2;

public class Estacionamiento {
    int numCarros , maxCarros, niveles , maxCarroPerNivel;
    double superficie , porcLlenado;


    public void Constructor(int numCarros , int maxCarros , 
    int niveles , int maxCarroPerNivel  ,double superficie , 
    double porcLLenado ){
        this.numCarros = numCarros;
        this.maxCarros = maxCarros;
        this.niveles = niveles;
        this.maxCarroPerNivel = maxCarroPerNivel;
        this.superficie = superficie;
        this.porcLlenado = porcLLenado;    
    }
    public int IngresarCarro(int num){
        numCarros += num;

        return num;
    }
    public double Porcentaje(){
        double porcentaje;
        porcentaje = 100* (numCarros / maxCarros); 
        return porcentaje;
    }
    public void Informe(){
        System.out.println("Numero de Carros: "+numCarros+
        "\nMaximo de Carros: "+maxCarros+"\nPisos: "+niveles+
        "\nCarros maximos por nivel: "+maxCarroPerNivel+
        "\nSuperficie(m2): "+superficie+"\nPorcentaje de saturación: "+porcLlenado);
    }
}
