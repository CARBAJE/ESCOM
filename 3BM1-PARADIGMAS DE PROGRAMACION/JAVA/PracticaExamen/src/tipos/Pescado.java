package tipos;

public class Pescado extends Carnes{
    private double proteinas;
    private double grasasInsaturadas;

    public Pescado(String nombre){
        super(nombre);
        proteinas = 0;
        grasasInsaturadas = 0;
    }
    public double getproteinas(){
        return proteinas;
    }
    public double getgrasasInsaturadas(){
        return grasasInsaturadas;
    }
    public void setproteinas(double proteinas){
        this.proteinas = proteinas;
    }
    public void setgrasasInsaturadas(double grasasInsaturadas){
        this.grasasInsaturadas = grasasInsaturadas;
    }
    public void vender(double cantidad){
        super.vender(cantidad);
        System.out.println("El pescado "+nombre+"tiene un precio por kilo de: "+precio+
        ".\nUsted esta comprando: "+cantidad+" el precio total de su compra es: "+cantidad*precio+"\n");
    }
}
