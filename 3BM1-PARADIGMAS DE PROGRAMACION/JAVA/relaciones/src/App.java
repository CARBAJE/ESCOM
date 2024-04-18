public class App {
    public static void main(String[] args) throws Exception {
// Declarar a una persona
/* Persona tiene:
        Cabeza (Composición) (Porque no puede existir persona sin cabeza)
        Corazon (Cmposición) (Porque no puede existir persona sin corazón)
        Brazo (Agregación) (Si puede existir una persona sin uno o dos brazos)
*/ 
    //Brazo arm = new Brazo(); 
    //int m=0;
    //m=arm.mano; incorrecto porque es privado
    //m=arm.getMano();
    //System.out.println("No. de manos: "+m);

    Brazo arm = new Brazo(); //Se crea antes porque es de Agregación
    Pierna pierna = new Pierna();
    Persona persona = new Persona(arm , pierna);
    persona.nacer();
    persona.crecer();
    System.out.println(persona.estudiarParadigmas());
    persona.getCora().bombear();
    //arm.cargar();//nada más asi??
    persona.getBrazos().cargar();//Bravooo
    persona.getPierna().Apoyar();
    persona.getHigado().informe();
    persona.vacionar();
    }

    //Tarea: Desarrollar dos clases más para Agregar/Componer a Persona
        //Clase Higado (incluir mínimo 4 atributos y 4 métodos)
        //Clase Pierna (incluir mínimo 4 atributos y 4 métodos)
    //Nota: Ustedes determinen si es agregación o composición
    //Para el lunes
}
