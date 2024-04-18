package tipos;

public class App {

    public static void main(String[] args){
        Pescado salmon = new Pescado("salmon");
        Roja ribeye = new Roja("Rib Eye");
        Aves zorsal = new Aves("zorsal");
        
        salmon.setcantidad(100);
        ribeye.setcantidad(80);
        zorsal.setcantidad(50);

        salmon.setprecio(150);
        ribeye.setprecio(220);
        zorsal.setprecio(335);

        salmon.setgrasasInsaturadas(90);
        ribeye.setgrasasSaturadas(220);
        zorsal.setgrasasSaturadas(350);

        salmon.vender(70);
        ribeye.vender(60);
        zorsal.vender(45);

    }
}