/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pozole;

import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.Scanner;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;

//Pacheco Sanchez Rodrigo
//Martinez Mendez Diego
//Corona Reyes Mauricio Dassel
//4BM1  - Fundamentos de Inteligencia Artificial

public class Tablero extends JFrame
{
    private final JButton[][] jBoard = new JButton[4][4];   
    private final LinkedHashMap puzzle = new LinkedHashMap();
    private BufferedImage empty;
    private boolean deep = false;
    
    
    //Aqui establecemos las posiciones iniciales del tablero y el resultado deseado
    private final String start = "abcdefghijklmno0";
    private final String goal  = "abcdefgh0jklimno"; 
   
    private final JMenuItem solveB = new JMenuItem("Busqueda en anchura");
    private final JMenuItem solveD = new JMenuItem("Busqueda en profundidad");
    
    private Scanner keyb = new Scanner(System.in);
    private int maxDeep = 100000; // Pata limitar la profundidad del árbol
    
    public Tablero()  // Constructor
    {       
        initComponents();
    }
      
    private void initComponents() 
    {
        this.setTitle("Practica 02 - 4BM1 - 15-Puzzle");
        this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        
        Dimension pantalla = Toolkit.getDefaultToolkit().getScreenSize();
        int width = pantalla.width;
        int height = pantalla.height;
        this.setBounds((width-516)/2,(height-563)/2,516,563);
        
        JMenuBar mainMenu = new JMenuBar();
        JMenu    file = new JMenu("Opciones");
        JMenuItem exit = new JMenuItem("Salir");
        
        mainMenu.add(file);
        file.add(solveB);
        file.add(solveD);
        file.add(exit);
        this.setJMenuBar(mainMenu);
        
        this.setLayout(null);
        this.imagePieces("C:\\Users\\lenovo\\Desktop\\CODIGOS_FUENTES\\4BM2-FUNDAMENTOS_DE_INTELIGENCIA_ARTIFICIAL\\PRACTICAS_OSCAR\\Pozole\\imagenes\\minako.jpg");
        paintPieces();
        exit.addActionListener(evt -> gestionarExit(evt));  
        solveB.addActionListener(evt -> whichMethod(evt)); 
        solveD.addActionListener(evt -> whichMethod(evt));  
               
        // Handle the X-Button 
        class MyWindowAdapter extends WindowAdapter
        {
            @Override
            public void windowClosing(WindowEvent eventObject)
            {
		goodBye();
            }
        }
        addWindowListener(new MyWindowAdapter());       
    }
    
    private void goodBye()
    {
        int respuesta = JOptionPane.showConfirmDialog(rootPane, "Are you sure?","Exit",JOptionPane.YES_NO_OPTION);
        if(respuesta==JOptionPane.YES_OPTION) System.exit(0);
    }
        
    private void gestionarExit(ActionEvent e)
    {
        goodBye();
    }
      
   
    private void imagePieces(String pathName)
    {
        try  
        {      
            BufferedImage buffer= ImageIO.read(new File(pathName));
            BufferedImage subImage;
            int n=0;
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                {
                    subImage = buffer.getSubimage((j)*125, (i)*125, 125, 125);  
                    String k = goal.substring(n,n+1);
                    puzzle.put(k, subImage); 
                    n++;
                }
        }
        catch (Exception ex)
        {
            ex.printStackTrace();
        }
              
    } 
    
    public void paintPieces()
    {
        int n=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                String  k=start.substring(n,n+1);
                BufferedImage subImage = (BufferedImage) puzzle.get(k);   
                jBoard[i][j] = new JButton();
                jBoard[i][j].setBounds(j*125+1, i*125+1,125,125); 
                this.add(jBoard[i][j]);                                                                        
                if(!k.equals("0"))jBoard[i][j].setIcon(new ImageIcon(subImage));
                else empty = subImage;
                n++;                 
            }

    }
    
    
    private void whichMethod(ActionEvent e)
    {
        if(e.getSource()==solveD) deep=true; 
        solve();
    }
    
    
    private void solve()
    {
        boolean success = false;
        int deadEnds = 0;
        int totalNodes = 0;
        State startState = new State(start); // -> Estos hacen referencia a los estados previamente declarados
        State goalState   = new State(goal); // -> Las posiciones iniciales y las posiciones objetivos
        ArrayDeque queue = new ArrayDeque();
        ArrayList<State> first = new ArrayList();
        ArrayList<State> path=null;
        solveB.setEnabled(false);
        solveD.setEnabled(false);
        
        first.add(startState);
        queue.add(first);
                
        int m=0;
        long startTime = System.currentTimeMillis();
        while(!queue.isEmpty() && !success && m < maxDeep )
        {
            int validStates = 0;      
            m++;
            ArrayList<State> l = (ArrayList<State>) queue.getFirst();
    
            State last = (State) l.get(l.size()-1);
            ArrayList<State> next = last.nextStates();  
            totalNodes+=next.size();
            
            queue.removeFirst(); 
 
            for(State ns: next)
            {
                if(!repetido(l,ns)) 
                {
                    validStates++;
                    ArrayList<State> nl = (ArrayList<State>) l.clone();
                    if(ns.goalFunction(goalState))
                    {
                        success = true;
                        path = nl;
                    }
                    nl.add(ns);                   
                    if(deep)
                        queue.addFirst(nl); 
                    else
                        queue.addLast(nl);                  
                }
            }   
            if(validStates==0) deadEnds++;              
        }
                
        if(success) 
        {   
            long elapsed = System.currentTimeMillis()-startTime;
            if(deep) this.setTitle("15-Puzzle (Deep-First Search)");
            else this.setTitle("15-Puzzle (Breadth-First Search)"); 
            JOptionPane.showMessageDialog(rootPane, "EXITO!! \nRecorrido con: "+path.size()+" nodos"+"\nNodos Generados: "+totalNodes+"\nCaminos sin salida: "+ deadEnds+"\n Ciclos: "+m+"\n Tiempo: " + elapsed + " milisegundos", 
                                                    "Practica 02 yeah!!!", JOptionPane.INFORMATION_MESSAGE);
            System.out.println("Success!");
            String thePath="";
            int n=0;
            int i=startState.getI();
            int j=startState.getJ();
            for(State st: path)
            {
              st.show();
              if(n>0)
                thePath = thePath+st.getMovement();                 
              n++;
            }
            Executor exec = new Executor(jBoard,i,j,thePath, empty);
            exec.start();
        }  
        else 
        { 
            JOptionPane.showMessageDialog(rootPane, "Path not found", "Sorry!!!", JOptionPane.WARNING_MESSAGE);
            System.out.println("Path not found");
        }
    }  
    
    public boolean repetido(ArrayList<State> l, State s)
    {
        boolean exist = false;
        for(State ns: l)
        {
            if(ns.isEqual(s)) 
            {
                exist = true;
                break;
            }
        }
        return exist;
    }
}
