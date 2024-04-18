package agentes;

import java.awt.Color;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ItemEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
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

/**
 *
 * @author macario
 */
public class Escenario extends JFrame
{
    
    private JLabel[][] tablero;     
    private int[][] matrix;
    private final int dim = 15;

    private ImageIcon robot1;
    private ImageIcon robot2;
    private ImageIcon obstacleIcon;
    private ImageIcon sampleIcon;
    //añadido
    private ImageIcon sampleIcon2;
    private ImageIcon sampleIcon3;
    private ImageIcon sampleIcon4;
    private ImageIcon rastro;
    //
    private ImageIcon actualIcon;
    private ImageIcon motherIcon;
    
    private Agente wallE;
    private Agente eva;
   
    private final BackGroundPanel fondo = new BackGroundPanel(new ImageIcon
    ("c:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-01/imagenes/surface.jpg"));
    
    private final JMenu settings = new JMenu("Settigs");
    private final JRadioButtonMenuItem obstacle = new JRadioButtonMenuItem("Obstacle");
    private final JRadioButtonMenuItem sample = new JRadioButtonMenuItem("Sample");
    private final JRadioButtonMenuItem sample2 = new JRadioButtonMenuItem("Sample2");
    private final JRadioButtonMenuItem sample3 = new JRadioButtonMenuItem("Sample3");
    private final JRadioButtonMenuItem sample4 = new JRadioButtonMenuItem("Sample4");
    private final JRadioButtonMenuItem motherShip = new JRadioButtonMenuItem("MotherShip");
    
    public Escenario()
    {
        this.setContentPane(fondo);
        this.setTitle("Agentes");
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        this.setBounds(50,50,dim*30+35,dim*30+85);
        initComponents();
    }
        
    private void initComponents()
    {
        ButtonGroup settingsOptions = new ButtonGroup();
        settingsOptions.add(sample);
        settingsOptions.add(obstacle);       
        settingsOptions.add(motherShip);
        settings.add(sample);
        settings.add(sample2);
        settings.add(sample3);
        settings.add(sample4);
        
        JMenuBar barraMenus = new JMenuBar();
        JMenu file = new JMenu("File");
        JMenuItem run  = new JMenuItem("Run");
        
        JMenuItem exit   = new JMenuItem("Exit");
              
        this.setJMenuBar(barraMenus);
        barraMenus.add(file);
        barraMenus.add(settings);
        file.add(run);
        file.add(exit);
        settings.add(motherShip);
        settings.add(obstacle);
        settings.add(sample);
        settings.add(sample2);
        settings.add(sample3);
        settings.add(sample4);
            
        robot1 = new ImageIcon
        ("c:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-01/imagenes/wall-e.png");
        robot1 = new ImageIcon(robot1.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));
        
        robot2 = new ImageIcon
        ("c:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-01/imagenes/eva.png");
        robot2 = new ImageIcon(robot2.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));
        
        obstacleIcon = new ImageIcon
        ("c:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-01/imagenes/brick.png");
        obstacleIcon = new ImageIcon(obstacleIcon.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));
        
        sampleIcon = new ImageIcon
        ("c:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-01/imagenes/sample.png");
        sampleIcon = new ImageIcon(sampleIcon.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));

        sampleIcon2 = new ImageIcon
        ("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\sample2.png");
        sampleIcon2 = new ImageIcon(sampleIcon2.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));
        
        sampleIcon3 = new ImageIcon
        ("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\sample3.png");
        sampleIcon3 = new ImageIcon(sampleIcon3.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));

        sampleIcon4 = new ImageIcon
        ("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\sample4.png");
        sampleIcon4 = new ImageIcon(sampleIcon4.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));

        motherIcon = new ImageIcon
        ("c:/Users/lenovo/Desktop/CODIGOS_FUENTES/4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL/PRACTICA-01/imagenes/mothership.png");
        motherIcon = new ImageIcon(motherIcon.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));
        
        rastro = new ImageIcon
        ("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICA-03\\imagenes\\Exclamation.png");
        rastro = new ImageIcon(rastro.getImage().getScaledInstance(30,30,  java.awt.Image.SCALE_SMOOTH));

        this.setLayout(null);
        formaPlano();  
        
        exit.addActionListener(evt -> gestionaSalir(evt));
        run.addActionListener(evt -> gestionaRun(evt));
        obstacle.addItemListener(evt -> gestionaObstacle(evt));
        sample.addItemListener(evt -> gestionaSample(evt));
        //
        sample2.addItemListener(evt -> gestionaSample2(evt));
        sample3.addItemListener(evt -> gestionaSample3(evt));
        sample4.addItemListener(evt -> gestionaSample4(evt));
        //
        motherShip.addItemListener(evt -> gestionaMotherShip(evt));

              
            
        class MyWindowAdapter extends WindowAdapter
        {
            @Override
            public void windowClosing(WindowEvent eventObject)
            {
		goodBye();
            }
        }
        addWindowListener(new MyWindowAdapter());
        
        // Crea 2 agentes
        wallE = new Agente("Wall-E",robot1, matrix, tablero, false, rastro); 
        eva = new Agente("Eva",robot2, matrix, tablero, false, rastro); 
        
    }
        
    private void gestionaSalir(ActionEvent eventObject)
    {
        goodBye();
    }
        
    private void goodBye()
    {
        int respuesta = JOptionPane.showConfirmDialog(rootPane, "Desea salir?","Aviso",JOptionPane.YES_NO_OPTION);
        if(respuesta==JOptionPane.YES_OPTION) System.exit(0);
    }
  
    private void formaPlano()
    {
        tablero = new JLabel[dim][dim];
        matrix = new int[dim][dim];
        
        int i, j;

        for(i=0;i<dim;i++)
            for(j=0;j<dim;j++)
            {
                int fila = i;
                int columna = j;
                matrix[i][j]=0;
                tablero[i][j]=new JLabel();
                tablero[i][j].setBounds(j*30+10,i*30+10,30,30);
                tablero[i][j].setBorder(BorderFactory.createDashedBorder(Color.white));
                tablero[i][j].setOpaque(false);
                this.add(tablero[i][j]);
                
                tablero[i][j].addMouseListener(new MouseAdapter() // Este listener nos ayuda a agregar poner objetos en la rejilla
                    {
                        @Override
                        public void mousePressed(MouseEvent e) 
                        {
                            insertaObjeto(e);
                            //Codigo Añadido para dar valor a la casilla de la matriz
                            if(actualIcon == obstacleIcon) matrix[fila][columna]= 2; 
                            if(actualIcon == motherIcon) matrix[fila][columna] = 1;
                            if(actualIcon == sampleIcon) matrix[fila][columna] =-1;
                            if(actualIcon == sampleIcon2) matrix[fila][columna] =-2;
                            if(actualIcon == sampleIcon3) matrix[fila][columna] =-3;
                            if(actualIcon == sampleIcon4) matrix[fila][columna] =-4;
                        }   
                
                        @Override
                        public void mouseReleased(MouseEvent e) 
                        {
                            insertaObjeto(e);
                            //Codigo Añadido para dar valor a la casilla de la matriz
                            if(actualIcon == obstacleIcon) matrix[fila][columna]= 2;
                            if(actualIcon == motherIcon) matrix[fila][columna] = 1;
                            if(actualIcon == sampleIcon) matrix[fila][columna] =-1;
                            if(actualIcon == sampleIcon2) matrix[fila][columna] =-2;
                            if(actualIcon == sampleIcon3) matrix[fila][columna] =-3;
                            if(actualIcon == sampleIcon4) matrix[fila][columna] =-4;
                            System.out.println("Icono con valor: "+matrix[fila][columna]+" agregado en fila: "+fila+" y columna:"+columna+"\n");
                        }  
                        
                
                    });                 
            } 
    }
        
    private void gestionaObstacle(ItemEvent eventObject)
    {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if(opt.isSelected())
           actualIcon = obstacleIcon;
        else actualIcon = null;        
    }
    
    private void gestionaSample(ItemEvent eventObject)
    {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if(opt.isSelected())
           actualIcon = sampleIcon;
        else actualIcon = null;   
    }

    private void gestionaSample2(ItemEvent eventObject)
    {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if(opt.isSelected())
           actualIcon = sampleIcon2;
        else actualIcon = null;   
    }

    private void gestionaSample3(ItemEvent eventObject)
    {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if(opt.isSelected())
           actualIcon = sampleIcon3;
        else actualIcon = null;   
    }

    private void gestionaSample4(ItemEvent eventObject)
    {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if(opt.isSelected())
           actualIcon = sampleIcon4;
        else actualIcon = null;   
    }
    
    private void gestionaMotherShip(ItemEvent eventObject)
    {
        JRadioButtonMenuItem opt = (JRadioButtonMenuItem) eventObject.getSource();
        if(opt.isSelected())
           actualIcon = motherIcon;
        else actualIcon = null;   
    }
    private void gestionaRun(ActionEvent eventObject)
    {
        if(!wallE.isAlive()) wallE.start();
        if(!eva.isAlive()) eva.start();
        settings.setEnabled(false);
    }
       
    public void insertaObjeto(MouseEvent e)
    {
        JLabel casilla = (JLabel) e.getSource();
        if(actualIcon!=null) casilla.setIcon(actualIcon); 
    }
    
}
