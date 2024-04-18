package practica2;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        String id, nombre;
        Double balance, tarifa, cantidad, retiro;
        Scanner sc = new Scanner(System.in);
        System.out.println("Introduzca el id para el constructor:");
        id = sc.nextLine();
        System.out.println("Introduzca el nombre para el constructor:");
        nombre = sc.nextLine();
        System.out.println("Introduzca el balance para el constructor:");
        balance = sc.nextDouble();
        System.out.println("Introduzca la tarifa para el constructor:");
        tarifa = sc.nextDouble();
        System.out.println("Introduzca la cantidad a depositar:");
        cantidad = sc.nextDouble();
        cuentaInversion clase = new cuentaInversion();
        clase.Constructor(id, nombre, balance, tarifa);
        clase.Deposito(cantidad);
        System.out.println("Introduzca la cantidad a retirar:");
        retiro = sc.nextDouble();
        clase.Retiro(retiro);
        clase.calcularIntereses();
        clase.balance();
    }
}
