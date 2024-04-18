public class Pierna {
    private int numPies;
    private int estadoRodilla;
    private boolean daniada;
    private float grosorMuslos;

    public Pierna(){
        numPies = 1;
        estadoRodilla = 10;
        daniada = false;
        grosorMuslos = 60;
    }

    public boolean Doblar(){
        if(estadoRodilla > 3)
            return true;
        System.out.println("No se pudo llevar a cabo. Checa tu Rodilla.\n");
        return false;
    }

    public boolean Apoyar(){
        if(numPies == 1)
            return true;
        return false;
    }

    public void Daño(){
        estadoRodilla--;
        daniada = true;
    }

    public void Operacion(){
        if(daniada == true){
            if(grosorMuslos < 75){
                daniada = false;
                grosorMuslos-=5;

            }
            else
                System.out.println("No es apto a una operacion");
        }
        
    }
}
