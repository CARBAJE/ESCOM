public class Persona { //Clase principal
    //Atributos
    private Cabeza choya;
    private Corazon cora;
    private Brazo brazos;
    private Higado higado;
    private Pierna pierna;
    private int paradigmas;

    //Constructor/es
    public Persona(Brazo brazos , Pierna pierna){ //Recibimos argumentos cuando exista una Agregación
        choya = new Cabeza(); //Composición
        cora = new Corazon(); //Composición
        higado = new Higado();
        this.pierna = pierna;
        this.brazos = brazos; //Agregación
        paradigmas=0;
    }

    //SET
    public void setParadigmas(int paradigmas) {
        this.paradigmas = paradigmas;
    }
    public void setBrazos(Brazo brazos) {
        this.brazos = brazos;
    }
    public void setChoya(Cabeza choya) {
        this.choya = choya;
    }
    public void setCora(Corazon cora) {
        this.cora = cora;
    }
    public void setHigado(Higado higado){
        this.higado = higado;
    }
    public void SetPierna(Pierna pierna){
        this.pierna = pierna;
    }

    //GET
    public Brazo getBrazos() {
        return brazos;
    }
    public Cabeza getChoya() {
        return choya;
    }
    public Corazon getCora() {
        return cora;
    }
    public int getParadigmas() {
        return paradigmas;
    }
    public Pierna getPierna(){
        return pierna;
    }
    public Higado getHigado(){
        return higado;
    }

    //Métodos
    public void nacer(){
        System.out.println("Ya nací");
    }
    public void crecer(){
        System.out.println("Estoy creciendo");
    }
    public String estudiarParadigmas(){
        System.out.println("Estoy estudiando paradigmas");
        paradigmas++;
        if(paradigmas>3) return "Ahí la llevas";
        else return "Necesitas estudiar más";
    }
    public void vacionar(){
        System.out.println("Ando de vacaciones");
    }
}
