package agentes;

import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ItemEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.HashMap;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JRadioButtonMenuItem;

public class Escenario extends JFrame {

    private JLabel[][] tablero;
    private int[][] matrix;
    private final int dim = 15;
    private int number_samples;

    private ImageIcon pacman1;
    private ImageIcon pacman2;
    private ImageIcon obstaculo;
    private ImageIcon bola;
    private ImageIcon actualIcon;
    private ImageIcon nave;
    private ImageIcon migaja;
    private ImageIcon cluster_3;
    private ImageIcon cluster_2;
    private ImageIcon cluster_1;

    private Agente pacmanluis;
    private Agente pacmanAle;

    private final BackGroundPanel fondo = new BackGroundPanel(new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\surface.jpg"));

    private final JMenu settings = new JMenu("Opciones");
    private final JRadioButtonMenuItem Obstaculo = new JRadioButtonMenuItem("Obstaculo");
    private final JRadioButtonMenuItem bolita = new JRadioButtonMenuItem("Sample");
    private final JRadioButtonMenuItem navesita = new JRadioButtonMenuItem("Nave");

    public Escenario() {
        this.setContentPane(fondo);
        this.setTitle("Agentes");
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        this.setBounds(30, 30, dim * 30 + 35, dim * 30 + 85);
        initComponents();
    }

    private void initComponents() {
        ButtonGroup settingsOptions = new ButtonGroup();
        settingsOptions.add(bolita);
        settingsOptions.add(Obstaculo);
        settingsOptions.add(navesita);

        JMenuBar barraMenus = new JMenuBar();
        JMenu file = new JMenu("Programa");
        JMenuItem run = new JMenuItem("Correr");

        JMenuItem exit = new JMenuItem("Salir");

        this.setJMenuBar(barraMenus);
        barraMenus.add(file);
        barraMenus.add(settings);
        file.add(run);
        file.add(exit);
        settings.add(navesita);
        settings.add(Obstaculo);
        settings.add(bolita);

        pacman1 = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\wall-e.png");
        pacman1 = new ImageIcon(pacman1.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        pacman2 = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\eva.png");
        pacman2 = new ImageIcon(pacman2.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        obstaculo = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\brick.png");
        obstaculo = new ImageIcon(obstaculo.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        bola = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\sample.png");
        bola = new ImageIcon(bola.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        cluster_3 = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\sample4.png");
        cluster_3 = new ImageIcon(cluster_3.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        cluster_2 = new ImageIcon("4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-03/imagenes/sample3.png");
        cluster_2 = new ImageIcon(cluster_2.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        cluster_1 = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\sample2.png");
        cluster_1 = new ImageIcon(cluster_1.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        nave = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\mothership.png");
        nave = new ImageIcon(nave.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        migaja = new ImageIcon("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\Exclamation.png");
        migaja = new ImageIcon(migaja.getImage().getScaledInstance(30, 30, java.awt.Image.SCALE_SMOOTH));

        //Crear el map de cluster
        HashMap< Integer, ImageIcon> cluster = new HashMap<>();
        cluster.put(9, cluster_3);
        cluster.put(6, cluster_2);
        cluster.put(3, cluster_1);

        this.setLayout(null);
        formaPlano();

        exit.addActionListener(evt -> gestionaSalir(evt));
        run.addActionListener(evt -> gestionaRun(evt));
        Obstaculo.addItemListener(evt -> gesRobomalo(evt));
        bolita.addItemListener(evt -> gestionaSample(evt));
        navesita.addItemListener(evt -> gestionaMotherShip(evt));

        class MyWindowAdapter extends WindowAdapter {

            public void windowClosing(WindowEvent eventObject) {
                goodBye();
            }
        }
        addWindowListener(new MyWindowAdapter());

        pacmanluis = new Agente("pacmanluis", pacman1, matrix, tablero, nave, migaja,pacman1, cluster);
        pacmanAle = new Agente("pacmanAle", pacman2, matrix, tablero, nave, migaja,pacman2, cluster);

        pacmanluis.compañero = pacmanAle;
        pacmanAle.compañero = pacmanluis;
    }

    private void gestionaSalir(ActionEvent eventObject) {
        goodBye();
    }

    private void goodBye() {
        int respuesta = JOptionPane.showConfirmDialog(rootPane, "Desea salir?", "Aviso", JOptionPane.YES_NO_OPTION);
        if (respuesta == JOptionPane.YES_OPTION) {
            System.exit(0);
        }
    }

    private void formaPlano() {
        tablero = new JLabel[dim][dim];
        matrix = new int[dim][dim];

        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                int row = i;
                int col = j;
                matrix[i][j] = 0;
                tablero[i][j] = new JLabel();
                tablero[i][j].setBounds(j * 30 + 10, i * 30 + 10, 30, 30);
                tablero[i][j].setBorder(BorderFactory.createDashedBorder(Color.black));
                tablero[i][j].setOpaque(false);
                this.add(tablero[i][j]);

                tablero[i][j].addMouseListener(new MouseAdapter() {
                    @Override
                    public void mousePressed(MouseEvent e) {
                        insertaObjeto(e);
                        if (actualIcon == obstaculo) {
                            matrix[row][col] = 1;
                        } else if (actualIcon == bola) {
                            matrix[row][col] = 12;
                            number_samples++;
                            pacmanluis.objetivo = number_samples * 4;
                            pacmanAle.objetivo = number_samples * 4;
                        } else if (actualIcon == nave) {
                            matrix[row][col] = 2;
                            pacmanluis.yBase = row;
                            pacmanluis.xBase = col;

                            pacmanAle.yBase = row;
                            pacmanAle.xBase = col;
                        };
                    }

                });
            }
        }
    }

    private void gesRobomalo(ItemEvent eventObject) {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if (opt.isSelected()) {
            actualIcon = obstaculo;
        } else {
            actualIcon = null;
        }
    }

    private void gestionaSample(ItemEvent eventObject) {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if (opt.isSelected()) {
            actualIcon = bola;
        } else {
            actualIcon = null;
        }
    }

    private void gestionaMotherShip(ItemEvent eventObject) {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if (opt.isSelected()) {
            actualIcon = nave;
        } else {
            actualIcon = null;
        }
    }

    private void gestionaRun(ActionEvent eventObject) {
        if (!pacmanluis.isAlive()) {
            pacmanluis.start();
        }
        if (!pacmanAle.isAlive()) {
            pacmanAle.start();
        }
        settings.setEnabled(false);
    }

    public void insertaObjeto(MouseEvent e) {
        JLabel casilla = (JLabel) e.getSource();
        if (actualIcon != null) {
            casilla.setIcon(actualIcon);
        }
    }
}
