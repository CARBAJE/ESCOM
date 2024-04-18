import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import javax.swing.border.*;

public class PROYECTOPARADIGMASCHIDO {
    private static int numeroPedido = 1;
    private static Restaurante restaurante;
    private static List<Platillo> platillos = new ArrayList<>();

    public static void main(String[] args) {

        restaurante = new Restaurante("GUSTEAUS", "Paris", "01-800-GUSTEAUS");
        Repartidor repartidor = new Repartidor("Oscar", "Casa", "A pie", 15, 4);
        Cliente cliente = new Cliente("Diego", "Casa tambienajajs", "Tarjeta de credito");

        Comida comida1 = new Comida("Rabioli", 120);
        Bebida bebida1 = new Bebida("Vinito", 100000);
        Postre postre1 = new Postre("Croissant", 50);

        restaurante.getPlatillos().add(comida1);
        restaurante.getPlatillos().add(bebida1);
        restaurante.getPlatillos().add(postre1);

        GradientBackgroundFrame frame = new GradientBackgroundFrame();
        frame.setLayout(null);
        frame.setSize(700, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Font font1 = new Font("Arial", Font.BOLD, 30);
        Color color = Color.white;

        Font font2 = new Font("Arial", Font.BOLD, 18);
        Color color2 = Color.lightGray;

        Font font3 = new Font("Arial", Font.BOLD, 10);

        JLabel label = new JLabel("MENU PRINCIPAL");
        label.setBounds(270, 50, 200, 30);
        label.setFont(font2);
        label.setForeground(color);

        JLabel labelres = new JLabel("! B I E N V E N I D O !");
        labelres.setBounds(200, 20, 300, 30);
        labelres.setFont(font1);
        labelres.setForeground(color);

        JLabel labelcli = new JLabel("CLIENTES");
        labelcli.setBounds(80, 70, 180, 30);
        labelcli.setFont(font2);
        labelcli.setForeground(color);

        JLabel labeladmin = new JLabel("ADMINISTRADORES");
        labeladmin.setBounds(440, 70, 180, 30);
        labeladmin.setFont(font2);
        labeladmin.setForeground(color);

        JButton btnMostrarMenu = new JButton("Menu");
        btnMostrarMenu.setBounds(30, 110, 180, 30);
        btnMostrarMenu.addActionListener(e -> mostrarMenu());
        btnMostrarMenu.setBackground(Color.WHITE);
        btnMostrarMenu.setOpaque(true);
        btnMostrarMenu.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JButton btnRealizarPedido = new JButton("Hacer Pedido");
        btnRealizarPedido.setBounds(30, 150, 180, 30);
        btnRealizarPedido.addActionListener(e -> realizarPedido());
        btnRealizarPedido.setBackground(Color.WHITE);
        btnRealizarPedido.setOpaque(true);
        btnRealizarPedido.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JButton btnmostrarres = new JButton("Ver datos del restaurante");
        btnmostrarres.setBounds(200, 250, 220, 30);
        btnmostrarres.addActionListener(e -> mostrarDatosRestaurante());
        btnmostrarres.setBackground(Color.WHITE);
        btnmostrarres.setOpaque(true);
        btnmostrarres.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JButton btnSalir = new JButton("Salir");
        btnSalir.setBounds(265, 300, 70, 30);
        btnSalir.addActionListener(e -> System.exit(0));
        btnSalir.setBackground(Color.WHITE);
        btnSalir.setOpaque(true);
        btnSalir.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JButton btnRegistrarRepartidores = new JButton("Nuevo Repartidor");
        btnRegistrarRepartidores.setBounds(435, 110, 180, 30);
        btnRegistrarRepartidores.addActionListener(e -> registrarRepartidores());
        btnRegistrarRepartidores.setBackground(Color.WHITE);
        btnRegistrarRepartidores.setOpaque(true);
        btnRegistrarRepartidores.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JButton btnRegistrarPlatillo = new JButton("Nuevo Platillo");
        btnRegistrarPlatillo.setBounds(435, 150, 180, 30);
        btnRegistrarPlatillo.addActionListener(e -> registrarPlatillo());
        btnRegistrarPlatillo.setBackground(Color.WHITE);
        btnRegistrarPlatillo.setOpaque(true);
        btnRegistrarPlatillo.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JButton btnmodificarDatosRestaurante = new JButton("Modificar Datos Restaurante");
        btnmodificarDatosRestaurante.setBounds(410, 190, 220, 30);
        btnmodificarDatosRestaurante.addActionListener(e -> modificarDatosRestaurante());
        btnmodificarDatosRestaurante.setBackground(Color.WHITE);
        btnmodificarDatosRestaurante.setOpaque(true);
        btnmodificarDatosRestaurante.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createEmptyBorder(5, 10, 5, 10),
                BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                        BorderFactory.createEmptyBorder(5, 10, 5, 10))));

        JLabel duenios = new JLabel("C E O `S: ");
        duenios.setBounds(450, 290, 300, 30);
        duenios.setForeground(color2);
        duenios.setFont(font3);
        JLabel integ1 = new JLabel("CARRILLO BARREIRO JOSE EMILIANO");
        integ1.setBounds(450, 300, 300, 30);
        integ1.setFont(font3);
        integ1.setForeground(color2);
        JLabel integ2 = new JLabel("ESCOBAR MONTOYA PARTICIO ESTRELLA");
        integ2.setBounds(450, 310, 300, 30);
        integ2.setFont(font3);
        integ2.setForeground(color2);
        JLabel integ3 = new JLabel("HUERTA VILLANUEVA OSCAR");
        integ3.setBounds(450, 320, 300, 30);
        integ3.setFont(font3);
        integ3.setForeground(color2);
        JLabel integ4 = new JLabel("MARTINEZ MENDEZ DIEGO");
        integ4.setBounds(450, 330, 300, 30);
        integ4.setFont(font3);
        integ4.setForeground(color2);

        frame.add(label);
        frame.add(labelres);
        frame.add(btnMostrarMenu);
        frame.add(btnRealizarPedido);
        frame.add(btnRegistrarRepartidores);
        frame.add(btnRegistrarPlatillo);
        frame.add(btnmodificarDatosRestaurante);
        frame.add(btnmostrarres);
        frame.add(labelcli);
        frame.add(labeladmin);
        frame.add(btnSalir);
        frame.add(integ1);
        frame.add(integ2);
        frame.add(integ3);
        frame.add(integ4);
        frame.add(duenios);

        frame.setVisible(true);

    }

    public static String obtenerRepartidorAleatorio() {
        String[] repartidores = { "Repartidor 1", "Repartidor 2", "Repartidor 3", "Repartidor 4" };
        Random random = new Random();
        int indiceAleatorio = random.nextInt(repartidores.length);
        return repartidores[indiceAleatorio];
    }

    public static void mostrarMenu() {
        StringBuilder menu = new StringBuilder("Menú:\n");

        for (Platillo platillo : restaurante.getPlatillos()) {
            menu.append("- ").append(platillo.getNombre()).append(" - $").append(platillo.getPrecio());
            menu.append(" (").append(platillo.getTipo()).append(")\n");
        }
        JOptionPane.showMessageDialog(null, menu.toString(), "Menú de " + restaurante.getNombre(),
                JOptionPane.PLAIN_MESSAGE);
    }

    public static void mostrarDatosRestaurante() {
        StringBuilder datosres = new StringBuilder(" ");

        datosres.append("-Nombre: ").append(restaurante.getNombre()).append("\n-Direccion: ")
                .append(restaurante.getDireccion()).append("\n-Telefono:").append(restaurante.getTelefono());

        JOptionPane.showMessageDialog(null, datosres.toString(), "Información de" + restaurante.getNombre(),
                JOptionPane.PLAIN_MESSAGE);
    }

    public static void realizarPedido() {
        String nombreCliente = JOptionPane.showInputDialog(null, "Nombre del cliente:");
        String domicilio = JOptionPane.showInputDialog(null, "Domicilio de entrega:");
        String metodoPago = JOptionPane.showInputDialog(null, "Método de pago:");

        mostrarMenu();

        String platillos = JOptionPane.showInputDialog(null,
                "Ingrese los platillos que quiere consumir (Separe con una coma): ");
        String platillosElegidos = JOptionPane.showInputDialog(null,
                "Ingrese las cantidades de los platillos (Separe con una coma):");

        Random random = new Random();
        String repartidorAsignado = obtenerRepartidorAleatorio();

        String mensajePedido = "Pedido realizado:\n\n" +
                "Número de pedido: " + numeroPedido + "\n" +
                "Cliente: " + nombreCliente + "\n" +
                "Domicilio de entrega: " + domicilio + "\n" +
                "Método de pago: " + metodoPago + "\n" +
                "Platillos elegidos: " + platillos + "" + "\n" +
                "Cantidad: " + platillosElegidos + "" + "\n" +
                "Repartidor asignado: " + repartidorAsignado;

        JOptionPane.showMessageDialog(null, mensajePedido, "Pedido Realizado", JOptionPane.INFORMATION_MESSAGE);
        numeroPedido++;
    }

    public static void registrarRepartidores() {
        String nombreRepartidor = JOptionPane.showInputDialog(null, "Nombre del repartidor:");
        String medioTransporte = JOptionPane.showInputDialog(null, "Medio de transporte:");
        String tiempoLlegada = JOptionPane.showInputDialog(null, "Tiempo estimado de llegada: (minutos) ");
        String calificacion = JOptionPane.showInputDialog(null, "Calificación de eficiencia:");

        JOptionPane.showMessageDialog(null, "Repartidor registrado:\n\n" +
                "Nombre: " + nombreRepartidor + "\n" +
                "Medio de transporte: " + medioTransporte + "\n" +
                "Tiempo estimado de llegada: " + tiempoLlegada + "\n" +
                "Calificación de eficiencia: " + calificacion,
                "Repartidor Registrado", JOptionPane.INFORMATION_MESSAGE);
    }

    public static void registrarPlatillo() {
        String tipoPlatillo = JOptionPane.showInputDialog(null, "Tipo de platillo (comida, bebida, postre):");
        String nombrePlatillo = JOptionPane.showInputDialog(null, "Nombre del platillo:");
        int precio = Integer.parseInt(JOptionPane.showInputDialog(null, "Precio del platillo:"));

        System.out.println(tipoPlatillo);
        Platillo platillo;
        if (tipoPlatillo.equalsIgnoreCase("comida")) {
            platillo = new Comida(nombrePlatillo, precio);
        } else if (tipoPlatillo.equalsIgnoreCase("bebida")) {
            platillo = new Bebida(nombrePlatillo, precio);
        } else if (tipoPlatillo.equalsIgnoreCase("postre")) {
            platillo = new Postre(nombrePlatillo, precio);
        } else {
            JOptionPane.showMessageDialog(null, "Tipo de platillo inválido", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        restaurante.getPlatillos().add(platillo);

        JOptionPane.showMessageDialog(null, "Platillo registrado:\n\n" +
                "Tipo de platillo: " + tipoPlatillo + "\n" +
                "Nombre: " + nombrePlatillo + "\n" +
                "Precio: " + precio,
                "Platillo Registrado", JOptionPane.INFORMATION_MESSAGE);

        mostrarMenu();
    }

    public static void modificarDatosRestaurante() {
        String nombreRestaurante = JOptionPane.showInputDialog(null, "Nuevo nombre del restaurante:");
        String direccion = JOptionPane.showInputDialog(null, "Nueva dirección del restaurante:");
        String telefono = JOptionPane.showInputDialog(null, "Nuevo teléfono del restaurante:");

        JOptionPane.showMessageDialog(null, "Datos del restaurante actualizados:\n\n" +
                "Nombre: " + nombreRestaurante + "\n" +
                "Dirección: " + direccion + "\n" +
                "Teléfono: " + telefono,
                "Datos del Restaurante Registrados", JOptionPane.INFORMATION_MESSAGE);

    }

}

class Repartidor extends Persona {
    private String medioTransporte;
    private int tiempoLlegada;
    private int calificacion;

    public Repartidor(String nombre, String domicilio, String medioTransporte, int tiempoLlegada, int calificacion) {
        super(nombre, domicilio);
        this.medioTransporte = medioTransporte;
        this.tiempoLlegada = tiempoLlegada;
        this.calificacion = calificacion;
    }

    public String getMedioTransporte() {
        return medioTransporte;
    }

    public void setMedioTransporte(String medioTransporte) {
        this.medioTransporte = medioTransporte;
    }

    public int getTiempoLlegada() {
        return tiempoLlegada;
    }

    public void setTiempoLlegada(int tiempoLlegada) {
        this.tiempoLlegada = tiempoLlegada;
    }

    public int getCalificacion() {
        return calificacion;
    }

    public void setCalificacion(int calificacion) {
        this.calificacion = calificacion;
    }
}

abstract class Platillo {
    private String nombre;
    private int precio;

    public Platillo(String nombre, int precio) {
        this.nombre = nombre;
        this.precio = precio;
    }

    public String getNombre() {
        return nombre;
    }

    public int getPrecio() {
        return precio;
    }

    public abstract String getTipo();
}

class Cliente extends Persona {
    private String metodoPago;

    public Cliente(String nombre, String domicilio, String metodoPago) {
        super(nombre, domicilio);
        this.metodoPago = metodoPago;
    }

    public String getMetodoPago() {
        return metodoPago;
    }

    public void setMetodoPago(String metodoPago) {
        this.metodoPago = metodoPago;
    }
}

class Restaurante {
    private String nombre;
    private String direccion;
    private String telefono;
    private List<Platillo> platillos;

    public Restaurante(String nombre, String direccion, String telefono) {
        this.nombre = nombre;
        this.direccion = direccion;
        this.telefono = telefono;
        this.platillos = new ArrayList<>();
    }

    public String getNombre() {
        return nombre;
    }

    public String getDireccion() {
        return direccion;
    }

    public String getTelefono() {
        return telefono;
    }

    public List<Platillo> getPlatillos() {
        return platillos;
    }

    public void agregarPlatillo(Platillo platillo) {
        platillos.add(platillo);
    }
}

class Pedido {
    private static int contadorPedidos = 1;
    private int numeroPedido;
    private String cliente;
    private String domicilio;
    private String metodoPago;
    private List<String> platillos;
    private List<String> platillosElegidos;

    public Pedido(String cliente, String domicilio, String metodoPago, List<String> platillos) {
        this.numeroPedido = ++contadorPedidos;
        this.cliente = cliente;
        this.domicilio = domicilio;
        this.metodoPago = metodoPago;
        this.platillos = platillos;
    }

    public int getNumeroPedido() {
        return numeroPedido;
    }

    public String getCliente() {
        return cliente;
    }

    public String getDomicilio() {
        return domicilio;
    }

    public String getMetodoPago() {
        return metodoPago;
    }

    public List<String> getPlatillos() {
        return platillos;
    }

    public List<String> getPlatillosElegidos() {
        return platillosElegidos;
    }
}

abstract class Persona {
    protected String nombre;
    protected String domicilio;

    public Persona(String nombre, String domicilio) {
        this.nombre = nombre;
        this.domicilio = domicilio;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public String getDomicilio() {
        return domicilio;
    }

    public void setDomicilio(String domicilio) {
        this.domicilio = domicilio;
    }
}

class Bebida extends Platillo {
    public Bebida(String nombre, int precio) {
        super(nombre, precio);
    }

    @Override
    public String getTipo() {
        return "Bebida";
    }
}

class Postre extends Platillo {
    public Postre(String nombre, int precio) {
        super(nombre, precio);
    }

    @Override
    public String getTipo() {
        return "Postre";
    }
}

class Comida extends Platillo {
    public Comida(String nombre, int precio) {
        super(nombre, precio);
    }

    @Override
    public String getTipo() {
        return "Comida";
    }
}

// Diseño bonito si q si

class GradientBackgroundFrame extends JFrame {

    public GradientBackgroundFrame() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 300);
        setTitle("Proyecto Final - Paradigmas de Programacion - 4BM1");

        ImageIcon icon = new ImageIcon("C:\\Users\\diego\\OneDrive\\Documentos\\3er Semetre\\PARADIGMAS\\PP\\capi.png");
        setIconImage(icon.getImage());

        GradientPanel gradientPanel = new GradientPanel();
        setContentPane(gradientPanel);
    }

    private class GradientPanel extends JPanel {

        @Override
        protected void paintComponent(Graphics g) {
            Graphics2D g2d = (Graphics2D) g;

            // Coordenadas del gradiente
            int x1 = 0;
            int y1 = 0;
            int x2 = getWidth();
            int y2 = getHeight();

            // Colores del gradiente
            Color color1 = Color.BLUE;
            Color color2 = Color.RED;

            // Crear el gradiente
            GradientPaint gradient = new GradientPaint(x1, y1, color1, x2, y2, color2);

            // Aplicar el gradiente al fondo
            g2d.setPaint(gradient);
            g2d.fillRect(x1, y1, x2, y2);
        }
    }
}
