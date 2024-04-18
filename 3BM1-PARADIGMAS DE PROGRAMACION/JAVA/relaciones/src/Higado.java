public class Higado{
    private int estado; //Escala de uno a diez entre mejor el estado mayor la cantidad.
    private boolean operado;
    private int procesoLiquido; //Escala de uno a diez entre mejor el estado mayor la cantidad.
    private boolean daniado;

    public Higado(){
        estado = 10;
        operado = false;
        procesoLiquido = 10;
        daniado = false;
    }

    public boolean Operacion(){
        estado = 10;
        daniado = false;
        return true;
    }

    public void Cuidado(){
        if(estado < 10)
            estado++;
        if(procesoLiquido < 10)
            procesoLiquido++;
    }

    public void Maluso(){
        if(daniado = false)
            daniado = true;
    }

    public void informe(){
        System.out.println("Informe del estado:\nEstado: "+estado+"\nHa sido operado: "+operado+
        "\nProcesamiento de liquidos: "+procesoLiquido+"\nEsta daniado: "+daniado);
    }
}