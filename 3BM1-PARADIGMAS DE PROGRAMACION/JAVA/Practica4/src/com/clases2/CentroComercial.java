package com.clases2;

public class CentroComercial {
    private String domicilio;
    private double superficie;
    private String nombre;
    private String telefono; //extra
    private int numTiendas;  //extra 2
    private boolean abierto; //extra 3
    private int numPlantas; //extra 4
    private TiendaDepartamental tienda; //declacramos un objeto de tipo TiendaDepartamental
    private Restaurante restaurante; // declaramos un objeto de tipo Restaurante
    private Estacionamiento estacionamiento; //declaramos un objeto de tipo Estacionamiento 
    //CONSUCTOR
    /**
     * 
     * @param Res 
     */

    public CentroComercial(Restaurante Res) { //cuando haya una agregacion se le pasan argumentos en este caso sera restaurante
        domicilio = "";
        superficie = 0;
        nombre = "";
        telefono = "";
        numTiendas = 0;
        abierto = false;
        numPlantas = 0;
        tienda = new TiendaDepartamental(); //composición
        estacionamiento = new Estacionamiento(); //composición
        this.restaurante = Res; //agregación
        
    }
    //SETTERS
    public void setDomicilio(String dom) {
        domicilio = dom;
    }
    
    public void setSuperficie(double metros2) {
        superficie = metros2;
    }
    
    public void setNombre(String nom) {
        nombre = nom;
    }
       
    public void setTelefono(String tel) {
        telefono = tel;
    }
    public void setNumTiendas(int num) {
        numTiendas = num;
    }
    
    public void setNumPlantas(int numPlant) {
        this.numPlantas = numPlant;
    }
    public void setTienda(TiendaDepartamental tienda) {
        this.tienda = tienda;
    }
    public void setRestaurante(Restaurante restaurante) {
        this.restaurante = restaurante;
    }
    public void setEstacionamiento(Estacionamiento estacionamiento) {
        this.estacionamiento = estacionamiento;
    }
    
    //GETTERS
    public String getDomicilio() {
        return domicilio;
    }
    
    public double getSuperficie() {
        return superficie;
    }
    
    public String getNombre() {
        return nombre;
    }
    
    public String getTelefono() {
        return telefono;
    }
 
    public int getNumTiendas() {
        return numTiendas;
    }
    public int getNumPlantas() {
        return numPlantas;
    }
    public TiendaDepartamental getTienda() {
        return tienda;
    }
    public Restaurante getRestaurante() {
        return restaurante;
    }
    public Estacionamiento getEstacionamiento() {
        return estacionamiento;
    }

   //METODOS

    public boolean isAbierto() {
        return abierto;
    }//DEVUELVE EL VALOR DE LA VARIABLE ABIERTO 
    
    public void abrirCentroComercial() {
        abierto = true;
        System.out.println("El centro comercial ha abierto");
    }//CAMBIA EL VALOR DE LA VARIABLE ABIERTO A TRUE
    
    public void cerrarCentroComercial() {
        abierto = false;
        System.out.println("El centro comercial ha cerrado");
    }//CAMBIA EL VALOR DE LA VARIABLE ABIERTO A FALSE
    //Imprimimos los datos del centro comercial
    public void informe() {
        System.out.println("----------DATOS GENERALES-----------");
        System.out.println("\nNombre del centro comercial: " + nombre);
        System.out.println("\nDomicilio: " + domicilio);
        System.out.println("\nSuperficie: " + superficie);
        System.out.println("\nNumero de tiendas: " + numTiendas);
        System.out.println("\nNumero de plantas: " + numPlantas);
        System.out.println("\nTelefono: " + telefono);
        System.out.println("\nAbierto: " + abierto);
        System.out.println("\n------------------------------------\n");
    }
}
