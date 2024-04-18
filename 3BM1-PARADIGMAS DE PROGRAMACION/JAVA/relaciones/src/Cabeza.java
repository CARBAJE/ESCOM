public class Cabeza {
    //Atributos
    private int cerebro; //Hace referencia al IQ
    private int ojos;
    private String nariz;
    private String boca;
    private int orejas;

    //Constructor/es
    public Cabeza(){
        cerebro=200;
        ojos=1; //tuerto
        nariz="respingada";
        boca="grande";
        orejas=1;
    }

    //SET
    public void setBoca(String boca) {
        this.boca = boca;
    }
    public void setCerebro(int cerebro) {
        this.cerebro = cerebro;
    }
    public void setNariz(String nariz) {
        this.nariz = nariz;
    }
    public void setOjos(int ojos) {
        this.ojos = ojos;
    }
    public void setOrejas(int orejas) {
        this.orejas = orejas;
    }
    
    //GET
    public String getBoca() {
        return boca;
    }
    public int getCerebro() {
        return cerebro;
    }
    public String getNariz() {
        return nariz;
    }
    public int getOjos() {
        return ojos;
    }
    public int getOrejas() {
        return orejas;
    }

    //Métodos
    public void leer(String libro){
        System.out.println("Leer: "+libro);
    }

    public void escucharmusica(String cancion){
        System.out.println("Estoy escuchando: "+cancion);
    }

    public void estudiar(String materia){
        System.out.println("Estoy estudiando: "+materia);
    }

    public void verTV(String programa){
        System.out.println("Estoy viendo: "+programa);
    }

}
