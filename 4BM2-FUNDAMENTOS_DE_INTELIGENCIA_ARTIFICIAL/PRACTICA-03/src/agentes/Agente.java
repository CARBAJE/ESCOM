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
    private final ImageIcon rastro;
    
    
    private JLabel casillaAnterior;
    Random aleatorio = new Random(System.currentTimeMillis());
    
    public Agente(String nombre, ImageIcon icon, int[][] matrix, JLabel tablero[][], boolean irBase,ImageIcon rastro)
    {
        this.nombre = nombre;
        this.icon = icon;
        this.matrix = matrix;
        this.tablero = tablero;
        this.irBase = irBase;
        this.rastro = rastro;

        
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
        int aux1I , aux2I = 2;
        int aux1J , aux2J = 2;
        double dx=0, dy=0;
        double distancia = matrix.length*matrix.length;

        while(true)
        {
            casillaAnterior = tablero[i][j];
            /*
            casillaAnterior = tablero[i][j];

            if(i > matrix.length-2 && dirRow == 1) dirRow=-1;
            if(i < 1 && dirRow==-1) dirRow=1;

            if(j > matrix.length-2 && dirCol ==1) dirCol=-1;
            if(j < 1 && dirCol==-1) dirCol=1;
            */
            if(!irBase){

                if(i > matrix.length-2 && dirRow == 1) dirRow=-1;
                if(i < 1 && dirRow==-1) dirRow=1;

                if(j > matrix.length-2 && dirCol ==1) dirCol=-1;
                if(j < 1 && dirCol==-1) dirCol=1;

                decision = (int) (Math.random()*10);

                //Movimiento cuando no se ha recogido una semilla
                if(decision < 5 && matrix[i+dirRow][j] < 1) i+=dirRow;
                if(decision >= 5 && matrix[i][j+dirCol] < 1) j+=dirCol;

                //Se recogio una semilla
                if(matrix[i][j]  < 0){
                    irBase = true;
                    matrix[i][j]++;
                }
            }
            else if(irBase){
                dx = i-aux2I;
                dy = j-aux2J;
                //Movimiento cuando se ha recogido una semilla
                //AStarAlgorithm camino = new AStarAlgorithm(i , j, matrix);

                for(aux1I=i ; aux1I>=0 ; aux1I--){
                    for(aux1J=j ; aux1J>= 0; aux1J--){
                        if(matrix[aux1I][aux1J] == 1){
                            dx = i-aux1I;
                            dy = j-aux1J;
                        
                            if(Math.sqrt( dx*dx +dy*dy) < distancia){
                                System.out.println("Distancia: "+distancia+"\nD2P: "+Math.sqrt( dx*dx +dy*dy));
                                distancia = Math.sqrt( dx*dx + dy*dy);
                                aux2I = aux1I;
                                aux2J = aux1J;
                            }
                            System.out.println("1er Valor de aux2: ["+aux2I+","+aux2J+"]");
                            System.out.println("Valores de dx: "+dx+", dy: "+dy);
                        }
                    }
                }
                for(aux1I=i ; aux1I< matrix.length-2 ; aux1I++){
                    for(aux1J=j ; aux1J< matrix.length-2 ; aux1J++){
                        if(matrix[aux1I][aux1J] == 1){
                            dx = i-aux1I;
                            dy = j-aux1J;                        
                            if(Math.sqrt( dx*dx +dy*dy) < distancia){
                                distancia = Math.sqrt( dx*dx + dy*dy);
                                System.out.println("Distancia: "+distancia+"\nD2P: "+Math.sqrt( dx*dx +dy*dy));
                                aux2I = aux1I;
                                aux2J = aux1J;
                            }
                            System.out.println("2do Valor de aux2: ["+aux2I+","+aux2J+"]");
                            System.out.println("Valores de dx: "+dx+", dy: "+dy);
                        }
                    }
                }
                System.out.println("valores de 'dirRow:': "+dirRow+" y de dirCol:"+dirCol);
                //Codigo añadido en octubre 07
                if(dx==0){ dirRow = 0; System.out.println("OCURRIO 125");}
                else if(Math.abs(dx-1) < Math.abs(dx+1) ){ dirRow = -1; System.out.println("OCURRIO 126");}
                else if(Math.abs(dx-1) > Math.abs(dx+1) ){ dirRow=1; System.out.println("OCURRIO 127");}

                if(dy==0){ dirCol = 0; System.out.println("OCURRIO 129");}
                else if(Math.abs(dy-1) < Math.abs(dy+1) ){ dirCol=-1; System.out.println("OCURRIO 130");}
                else if(Math.abs(dy-1) > Math.abs(dy+1) ){ dirCol=1; System.out.println("OCURRIO 131");}
                //
                if(i > matrix.length-2 && dirRow == 1 ){ dirRow = -1;System.out.println("OCURRIO 133");}
                else if(i < 1 && dirRow==-1 ){ dirRow=1;System.out.println("OCURRIO 134");}

                if(j > matrix.length-2 && dirCol ==1 ){ dirCol=-1; System.out.println("OCURRIO 136");}
                else if(j < 1 && dirCol==-1 ){ dirCol=1; System.out.println("OCURRIO 137");}

                if(Math.abs(dx) > Math.abs(dy) && matrix[i+dirRow][j] == 0) i+=dirRow;
                else if(Math.abs(dx) < Math.abs(dy) && matrix[i][j+dirCol] == 0) j+=dirCol;
                //Codigo añadido en octubre 08
                else if(Math.abs(dx) > Math.abs(dy) && matrix[i+dirRow][j] != 0 && matrix[i][j+dirCol] == 0) j+=dirRow;
                else if(Math.abs(dx) < Math.abs(dy) && matrix[i][j+dirCol] != 0 && matrix[i+dirRow][j] == 0) i+=dirCol;
                //
                if(Math.abs(dx) == Math.abs(dy) && dx != 0 && matrix[i+dirRow][j] == 0) i+=dirRow;
                else if(Math.abs(dx) == Math.abs(dy) && dy != 0 && matrix[i][j+dirRow] == 0) j+=dirCol;
                //Codigo añadido en octubre 08
                else if(Math.abs(dx) == Math.abs(dy) && dy!= 0 && matrix[i+dirRow][j] != 0 && matrix[i][j+dirCol] == 0) j+=dirRow;
                else if(Math.abs(dx) == Math.abs(dy) && dx!= 0 &&  matrix[i][j+dirCol] != 0 && matrix[i+dirRow][j] == 0) i+=dirCol;
                //
                System.out.println("valores actualizados de 'dirRow:': "+dirRow+" y de dirCol:"+dirCol);
                //Validación de recoleccion completa de una semilla
                if((i < 1 && j < 1) && (matrix[i+1][j] == 1 || matrix[i][j+1] == 1)) irBase = false;
                else if((i < 1 && j > matrix.length-1) && (matrix[i+1][j] == 1 || matrix[i][j-1] == 1)) irBase = false;
                else if((i > matrix.length-1 && j < 1) && (matrix[i-1][j] == 1 || matrix[i][j+1] == 1)) irBase = false;
                else if((i > matrix.length-1 && j > matrix.length-1) && (matrix[i+1][j] == 1 || matrix[i][j-1] == 1)) irBase = false;
                else if((i >=1 && i < matrix.length-2) && (j >=1 && j < matrix.length-2)&& (matrix[i+1][j] == 1 || matrix[i-1][j] == 1 || matrix[i][j+1] == 1 || matrix[i][j-1] == 1) )
                    irBase = false;
                if(irBase == false){ dirRow = dirCol = 1;System.out.println("DEJO LA SEMILLA");}
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
        //if(matrix[i][j] >= 1 || (irBase && matrix[i][j] == -1)) System.out.println("\n ERROR ERROR ERROR CON: ");
        
        if(!irBase)casillaAnterior.setIcon(null); // Elimina su figura de la casilla anterior
        if(irBase)casillaAnterior.setIcon(rastro);
        tablero[i][j].setIcon(icon); // Pone su figura en la nueva casilla
        System.out.println(nombre + " in -> Row: " + i + " Col:"+ j+"\n ");              
    }
    
}
