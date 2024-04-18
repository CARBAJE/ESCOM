package pozole;
import java.awt.image.BufferedImage;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;

public class Executor extends Thread
{
    private final JButton[][] jBoard;
    private int i;
    private int j;
    private String path;
    private BufferedImage empty;
    
    public Executor(JButton[][] jBoard, int i, int j, String path, BufferedImage empty)
    {
        this.jBoard = jBoard;
        this.i = i;
        this.j = j;
        this.path = path;
        this.empty = empty;
    }
    
    public void run()
    {   
        for(int n=0;n<path.length();n++)
        {
                int newI=i;
                int newJ=j;
                char m=path.charAt(n);
                switch(m)
                {
                    case 'u' -> newI--;
                    case 'd' -> newI++;
                    case 'l' -> newJ--;
                    case 'r' -> newJ++;
                }
                try
                {
                    Thread.sleep((int) (10000/(path.length()-1)));  
                }
                catch(Exception ex){ ex.printStackTrace();} 
                Icon sw = jBoard[newI][newJ].getIcon();
                
                jBoard[newI][newJ].setIcon(null);
                jBoard[i][j].setIcon(sw);
                i=newI;
                j=newJ;

            }
            jBoard[i][j].setIcon(new ImageIcon(empty));
    }
    
}
