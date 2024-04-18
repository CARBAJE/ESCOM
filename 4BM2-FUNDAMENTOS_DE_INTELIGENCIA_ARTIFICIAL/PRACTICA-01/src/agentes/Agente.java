package agentes;

import java.util.Random;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
//
/**
 *
 * @author macario
 */
public class Agente extends Thread
{
    private final String nombre;
    private int i;
    private int j;
    private final ImageIcon icon;
    private final int[][] matrix;
    private final JLabel tablero[][];
    //nuevos elementos;
    private boolean irBase;
    
    private JLabel casillaAnterior;
    Random aleatorio = new Random(System.currentTimeMillis());
    
    public Agente(String nombre, ImageIcon icon, int[][] matrix, JLabel tablero[][], boolean irBase)
    {
        this.nombre = nombre;
        this.icon = icon;
        this.matrix = matrix;
        this.tablero = tablero;
        this.irBase = irBase;

        
        this.i = aleatorio.nextInt(matrix.length);
        this.j = aleatorio.nextInt(matrix.length);
        tablero[i][j].setIcon(icon);        
    }
    
    @Override
    public void run()
    {
        int dirRow=1;
        int dirCol=1;
        //nuevas variables
        int decision;

        while(true)
        {

            casillaAnterior = tablero[i][j];

            if(i > matrix.length-2 && dirRow == 1) dirRow=-1;
            if(i < 1 && dirRow==-1) dirRow=1;

            if(j > matrix.length-2 && dirCol ==1) dirCol=-1;
            if(j < 1 && dirCol==-1) dirCol=1;

            if(!irBase){
                decision = (int) (Math.random()*10);

                //Movimiento cuando no se ha recogido una semilla
                if(decision < 5 && matrix[i+dirRow][j] < 1) i+=dirRow;
                if(decision >= 5 && matrix[i][j+dirCol] < 1) j+=dirCol;

                //Se recogio una semilla
                if(matrix[i][j] == -1){
                    irBase = true;
                    matrix[i][j] = 0;
                }
            }
            else if(irBase){
                decision = (int) (Math.random()*10);

                //Movimiento cuando se ha recogido una semilla
                if((matrix[i][j+dirCol] < 1 && matrix[i][j+dirCol] != -1) && decision < 5) j+=dirCol;
                if((matrix[i+dirRow][j] < 1 && matrix[i+dirRow][j] != -1) && decision >=5) i+=dirRow;
                
                //Validación de recoleccion completa de una semilla
                if((i < 1 && j < 1) && (matrix[i+1][j] == 1 || matrix[i][j+1] == 1)) irBase = false;
                else if((i < 1 && j > matrix.length-1) && (matrix[i+1][j] == 1 || matrix[i][j-1] == 1)) irBase = false;
                else if((i > matrix.length-1 && j < 1) && (matrix[i-1][j] == 1 || matrix[i][j+1] == 1)) irBase = false;
                else if((i > matrix.length-1 && j > matrix.length-1) && (matrix[i+1][j] == 1 || matrix[i][j-1] == 1)) irBase = false;
                else if((i >=1 && i < matrix.length-2) && (j >=1 && j < matrix.length-2)&& (matrix[i+1][j] == 1 || matrix[i-1][j] == 1 || matrix[i][j+1] == 1 || matrix[i][j-1] == 1) )
                    irBase = false;
            }
            actualizarPosicion();

            try
            {
               sleep(100+aleatorio.nextInt(100));
            }
            catch (InterruptedException ex)
            {
                ex.printStackTrace(System.out);
            }
        }         
    }
    
    public synchronized void actualizarPosicion()
    {   
        //Aviso de Error
        if(matrix[i][j] >= 1 || (irBase && matrix[i][j] == -1)) System.out.println("\n ERROR ERROR ERROR CON: ");
        
        casillaAnterior.setIcon(null); // Elimina su figura de la casilla anterior
        tablero[i][j].setIcon(icon); // Pone su figura en la nueva casilla
        System.out.println(nombre + " in -> Row: " + i + " Col:"+ j);              
    }
    
}
