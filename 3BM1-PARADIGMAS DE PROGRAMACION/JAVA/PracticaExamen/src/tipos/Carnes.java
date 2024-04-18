package tipos;

public class Carnes {
    protected double cantidad;
    protected double precio;
    protected String nombre;

    public Carnes(String nombre){
        this.nombre = nombre;
        cantidad = 0;
        precio = 0;
    }
    public double getcantidad(){
        return cantidad;
    }
    public double getprecio(){
        return precio;
    }
    public void setcantidad(double cantidad){
        this.cantidad = cantidad;
    }
    public void setprecio(double precio){
        this.precio = precio;
    } 
    public void vender(double cantidad){
        this.cantidad -= cantidad;
        System.out.println("La cantidad vendida fue: "+cantidad+
        "\nLa cantidad que queda es: "+this.cantidad+"\n");
    }
}
