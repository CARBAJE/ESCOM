package com.clases2;
public class Estacionamiento {
    int numCarros , maxCarros, niveles , maxCarroPerNivel;
    double superficie , porcLlenado;
    /**
     * @param numCarros         Número de carros actual en el estacionamiento.
     * @param maxCarros         Máximo número de carros permitidos en el estacionamiento.
     * @param niveles           Número de niveles del estacionamiento.
     * @param maxCarroPerNivel  Máximo número de carros permitidos por nivel.
     * @param superficie        Superficie total del estacionamiento en metros cuadrados.
     * @param porcLlenado       Porcentaje de llenado actual del estacionamiento.
     */
    public void Constructor(int numCarros , int maxCarros , int niveles , int maxCarroPerNivel  ,double superficie , double porcLLenado ){
        this.numCarros = numCarros;
        this.maxCarros = maxCarros;
        this.niveles = niveles;
        this.maxCarroPerNivel = maxCarroPerNivel;
        this.superficie = superficie;
        this.porcLlenado = porcLLenado;    
    }
    /**
     * @param num
     * @return num
     */
    public int IngresarCarro(int num){
        numCarros += num;
        return num;
    }
    
    public void setPorcLlenado(double porcLlenado) {
        porcLlenado = 100* ((double) numCarros / maxCarros); 
        this.porcLlenado = porcLlenado;
    }
    public double getPorcLlenado() {
        return porcLlenado;
    }
    public void Informe(){
        System.out.println("\n------------------Estacionamiento------------------");
        System.out.println("Numero de Carros: "+numCarros+
        "\nMaximo de Carros: "+maxCarros+"\nPisos: "+niveles+
        "\nCarros maximos por nivel: "+maxCarroPerNivel+
        "\nSuperficie(m2): "+superficie+"\nPorcentaje de saturación: "+porcLlenado);
        System.out.println("---------------------------------------------------");  

    }
}
