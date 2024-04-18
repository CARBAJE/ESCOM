package practica2;
public class cuentaInversion {
    String id, nombre;
    Double balance, tarifa;
    public void Constructor(String id, String nombre, Double balance, Double tarifa){
        this.balance=balance;
        this.id = id;
        this.nombre=nombre;
        this.tarifa=tarifa;
    }
    public Double calcularIntereses(){
        Double interes;
        interes = balance*tarifa;
        balance = balance+interes;
        return interes;
    }
    public Double obtenerBalance(){
        return balance;
    }
    public void Deposito (Double cantidad){
        balance = balance+cantidad;
    }
    public boolean Retiro (Double cantidad){
        if(cantidad < balance){
            balance=balance-cantidad;
            return true;
        } else {
            return false;
        }
    }
    public void balance(){
        System.out.println("ID: "+id+" nombre: "+nombre+" balance: "+balance+" tarifa: "+tarifa);
    }
}
