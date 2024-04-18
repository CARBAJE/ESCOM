package com.practica3;//cambiado

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
    private final int dim = 12;
    private int number_samples;

    private ImageIcon robot1;
    private ImageIcon robot2;
    private ImageIcon robotIcon;
    private ImageIcon plantaIcon;
    private ImageIcon actualIcon;
    private ImageIcon baseIcon;
    private ImageIcon migaja;
    private ImageIcon cluster_3;
    private ImageIcon cluster_2;
    private ImageIcon cluster_1;

    private Agente wall_e;
    private Agente eva;

    private final BackGroundPanel fondo = new BackGroundPanel(new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/surface.jpg"));

    private final JMenu settings = new JMenu("Opciones");
    private final JRadioButtonMenuItem robotmalo = new JRadioButtonMenuItem("Robotmalo");
    private final JRadioButtonMenuItem planta = new JRadioButtonMenuItem("Planta");
    private final JRadioButtonMenuItem baseplanta = new JRadioButtonMenuItem("Base");

    public Escenario() {
        this.setContentPane(fondo);
        this.setTitle("Agentes");
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        this.setBounds(50, 50, dim * 50 + 35, dim * 50 + 85);
        initComponents();
    }

    private void initComponents() {
        ButtonGroup settingsOptions = new ButtonGroup();
        settingsOptions.add(planta);
        settingsOptions.add(robotmalo);
        settingsOptions.add(baseplanta);

        JMenuBar barraMenus = new JMenuBar();
        JMenu file = new JMenu("Programa");
        JMenuItem run = new JMenuItem("Correr");

        JMenuItem exit = new JMenuItem("Salir");

        this.setJMenuBar(barraMenus);
        barraMenus.add(file);
        barraMenus.add(settings);
        file.add(run);
        file.add(exit);
        settings.add(baseplanta);
        settings.add(robotmalo);
        settings.add(planta);

        robot1 = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/walli.jpg");
        robot1 = new ImageIcon(robot1.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        robot2 = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/eva.png");
        robot2 = new ImageIcon(robot2.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        robotIcon = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/robomalo.jpg");
        robotIcon = new ImageIcon(robotIcon.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        plantaIcon = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/botaplanta.jpg");
        plantaIcon = new ImageIcon(plantaIcon.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        cluster_3 = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/botaplanta.jpg");
        cluster_3 = new ImageIcon(cluster_3.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        cluster_2 = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/botaplanta.jpg");
        cluster_2 = new ImageIcon(cluster_2.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        cluster_1 = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/botaplanta.jpg");
        cluster_1 = new ImageIcon(cluster_1.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        baseIcon = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/base.jpg");
        baseIcon = new ImageIcon(baseIcon.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        migaja = new ImageIcon("C:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICAS_DIEGO/p3/imagenes/rastro.jpg");
        migaja = new ImageIcon(migaja.getImage().getScaledInstance(50, 50, java.awt.Image.SCALE_SMOOTH));

        //Crear el map de cluster
        HashMap< Integer, ImageIcon> cluster = new HashMap<>();
        cluster.put(9, cluster_3);
        cluster.put(6, cluster_2);
        cluster.put(3, cluster_1);

        this.setLayout(null);
        formaPlano();

        exit.addActionListener(evt -> gestionaSalir(evt));
        run.addActionListener(evt -> gestionaRun(evt));
        robotmalo.addItemListener(evt -> gesRobomalo(evt));
        planta.addItemListener(evt -> gestionaSample(evt));
        baseplanta.addItemListener(evt -> gestionaMotherShip(evt));

        class MyWindowAdapter extends WindowAdapter {

            public void windowClosing(WindowEvent eventObject) {
                goodBye();
            }
        }
        addWindowListener(new MyWindowAdapter());

        wall_e = new Agente("wall_e", robot1, matrix, tablero, baseIcon, migaja, cluster);
        eva = new Agente("eva", robot2, matrix, tablero, baseIcon, migaja, cluster);

        wall_e.companiero = eva;
        eva.companiero = wall_e;
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
                tablero[i][j].setBounds(j * 50 + 10, i * 50 + 10, 50, 50);
                tablero[i][j].setBorder(BorderFactory.createDashedBorder(Color.black));
                tablero[i][j].setOpaque(false);
                this.add(tablero[i][j]);

                tablero[i][j].addMouseListener(new MouseAdapter() {
                    @Override
                    public void mousePressed(MouseEvent e) {
                        insertaObjeto(e);
                        if (actualIcon == robotIcon) {
                            matrix[row][col] = 1;
                        } else if (actualIcon == plantaIcon) {
                            matrix[row][col] = 12;
                            number_samples++;
                            wall_e.objetivo = number_samples * 4;
                            eva.objetivo = number_samples * 4;
                        } else if (actualIcon == baseIcon) {
                            matrix[row][col] = 2;
                            wall_e.yBase = row;
                            wall_e.xBase = col;

                            eva.yBase = row;
                            eva.xBase = col;
                        };
                    }

                });
            }
        }
    }

    private void gesRobomalo(ItemEvent eventObject) {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if (opt.isSelected()) {
            actualIcon = robotIcon;
        } else {
            actualIcon = null;
        }
    }

    private void gestionaSample(ItemEvent eventObject) {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if (opt.isSelected()) {
            actualIcon = plantaIcon;
        } else {
            actualIcon = null;
        }
    }

    private void gestionaMotherShip(ItemEvent eventObject) {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if (opt.isSelected()) {
            actualIcon = baseIcon;
        } else {
            actualIcon = null;
        }
    }

    private void gestionaRun(ActionEvent eventObject) {
        if (!wall_e.isAlive()) {
            wall_e.start();
        }
        if (!eva.isAlive()) {
            eva.start();
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
