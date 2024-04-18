package tipos;

public class Aves extends Carnes{
    private double proteinas;
    private double grasasSaturadas;

    public Aves(String nombre){
        super(nombre);
        proteinas = 0;
        grasasSaturadas = 0;
    }
    public double getgrasasSaturadas(){
        return grasasSaturadas;
    }
    public double getproteina(){
        return proteinas;
    }
    public void setgrasasSaturadas(double grasasSaturadas){
        this.grasasSaturadas = grasasSaturadas;
    }
    public void setvproteinas(double proteinas){
        this.proteinas = proteinas;
    }
    public void vender(double cantidad){
        super.vender(cantidad);
        System.out.println("El ave "+nombre+" tiene un precio por kilo de: "+precio+
        ".\nUsted esta comprando: "+cantidad+" el precio total de su compra es: "
        +precio*(cantidad - grasasSaturadas/100)+"\n");
    }
}
