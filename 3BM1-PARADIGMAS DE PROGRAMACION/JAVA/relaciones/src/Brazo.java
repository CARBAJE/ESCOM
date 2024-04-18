public class Brazo {
    //Atributos
    private String antebrazo;
    private String triceps;
    private String biceps;
    private int mano;
    private int dedos;
    private int codo;

    //Constructor/es
    public Brazo(){ //Sin argumentos
        antebrazo="fuerte";
        triceps="grandes";
        biceps="mucho";
        mano=1;
        dedos=4;
        codo=2;
    }

    //Métodos
    //set (modificar/actualizar atributo)
    public void setAntebrazo(String antebrazo) {
        this.antebrazo = antebrazo;
    }
    public void setBiceps(String biceps) {
        this.biceps = biceps;
    }
    public void setCodo(int codo) {
        this.codo = codo;
    }
    public void setDedos(int dedos) {
        this.dedos = dedos;
    }
    public void setMano(int mano) {
        this.mano = mano;
    }
    public void setTriceps(String triceps) {
        this.triceps = triceps;
    }
    //get (obtener atributo)
    public String getAntebrazo() {
        return antebrazo;
    }
    public String getBiceps() {
        return biceps;
    }
    public int getCodo() {
        return codo;
    }
    public int getDedos() {
        return dedos;
    }
    public int getMano() {
        return mano;
    }
    public String getTriceps() {
        return triceps;
    }

    //Métodos
    public void subir(){
        System.out.println("Esta subiendo");
    }

    public void bajar(){
        System.out.println("Estas bajando");
    }

    public void cargar(){
        System.out.println("Estas cargando");
    }
}
