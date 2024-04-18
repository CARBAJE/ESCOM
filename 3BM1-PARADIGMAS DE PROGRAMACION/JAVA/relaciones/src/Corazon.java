public class Corazon {
    private String ventriculos;
    private String auriculas;
    private String ahorta;

//Constructor/es
public Corazon(){
    ventriculos="Bien";
    auriculas="Bien";
    ahorta="Bien";
}

//SET
public void setAhorta(String ahorta) {
    this.ahorta = ahorta;
}
public void setAuriculas(String auriculas) {
    this.auriculas = auriculas;
}
public void setVentriculos(String ventriculos) {
    this.ventriculos = ventriculos;
}

//GET
public String getAhorta() {
    return ahorta;
}
public String getAuriculas() {
    return auriculas;
}
public String getVentriculos() {
    return ventriculos;
}

//Métodos
public void bombear(){
    System.out.println("Esta bombeando");
}

public void paroCardiaco(){
    System.out.println("Estas sufriendo un paro cardiáco");
}

public void reanimar(){
    System.out.println("Se ha reanimado tu corazón");
}

}
