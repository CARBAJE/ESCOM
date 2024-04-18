package tipos;

public class Roja extends Carnes{
    private double grasasSaturadas;
    private String vitaminas;

    public Roja(String nombre){
        super(nombre);
        grasasSaturadas = 0;
        vitaminas = "Vitamina A";
    }
    public double getgrasasSaturadas(){
        return grasasSaturadas;
    }
    public String getvitaminas(){
        return vitaminas;
    }
    public void setgrasasSaturadas(double grasasSaturadas){
        this.grasasSaturadas = grasasSaturadas;
    }
    public void setvitaminas(String vitaminas){
        this.vitaminas = vitaminas;
    }
    public void vender(double cantidad){
        super.vender(cantidad);
        System.out.println("El corte de carne "+nombre+" tiene un precio por kilo de: "+precio+
        ".\nUsted esta comprando: "+cantidad+" el precio total de su compra es: "
        +precio*(cantidad + grasasSaturadas/100)+"\n");
    }
}
