
package myprolog;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.io.*;
import java.util.*;
import org.jpl7.*;
/**
 *
 * @author Maestro Macario
 */
public class MyProlog extends JFrame implements ActionListener
{
    private final JToolBar tools    	   = new JToolBar();
    private final JMenuBar menuPrincipal   = new JMenuBar();
    private final JMenu file               = new JMenu("File");
    private final JMenuItem cargar         = new JMenuItem("Load");
    private final JMenuItem exit           = new JMenuItem("Exit");
    private final JButton load             = new JButton(new ImageIcon("img/load.jpg"));
    private final JButton query            = new JButton(new ImageIcon("img/query.jpg"));

    private final JEditorPane texto        = new JEditorPane();
    private final JTextArea   resultados   = new JTextArea();
    private final JScrollPane panelResult  = new JScrollPane(resultados);
    private final JScrollPane prologPanel  = new JScrollPane(texto);
    private final JFileChooser abrirArchivo = new JFileChooser();

    // Constructor

    public MyProlog()
    {
	super("MyProlog Engine");                
        this.setBounds(0,0,800,600);
        initComponents();
    }
        
    public final void initComponents()
    {

        JPanel workPanel = new JPanel();
        setLayout(new BorderLayout());
        workPanel.setLayout(new GridLayout(2,1));
        prologPanel.setBorder(new TitledBorder("Source Code"));
        panelResult.setBorder(new TitledBorder("Results"));

        // Propiedades

        texto.setFont(new Font("consolas",Font.PLAIN,14));
        resultados.setFont(new Font("consolas",Font.BOLD,12));
        texto.setEditable(false);
        texto.setForeground(new Color(56,126,127));
        resultados.setBackground(Color.black);
        resultados.setForeground(Color.orange);

        // Barra de herramientas

        tools.add(load);
        tools.add(query);

        // Menus

        this.setJMenuBar(menuPrincipal);
        menuPrincipal.add(file);
        file.add(cargar);
        file.add(exit);

        // Componentes visibles

        this.add(BorderLayout.NORTH,tools);
        this.add(BorderLayout.CENTER,workPanel);
        workPanel.add(prologPanel);
        workPanel.add(panelResult);

	// Establece propiedades de las cajas de texto

	exit.addActionListener(this);
	load.addActionListener(this);
	cargar.addActionListener(this);
	query.addActionListener(this);
	    

        // Clase interna (Inner class)

        class MyWindowAdapter extends WindowAdapter
        {
            @Override	
            public void windowClosing(WindowEvent e)
            {
                despedida();
            }
        }
        addWindowListener(new MyWindowAdapter());

        String home = System.getProperty("user.dir");
        abrirArchivo.setCurrentDirectory(new File(home));
        query.setEnabled(false);

    }

    /****************************************************************
     * IMPLEMENTACION DE LISTENERS
     ****************************************************************/
    @Override
    public void actionPerformed(ActionEvent e)
    {
	Object source = e.getSource();

	if(source == exit) despedida();

	if(source == load || source == cargar) cargarArchivo();

	if(source == query) consultar();

    }

    // Carga el archivo indicado por el usuario

    public void cargarArchivo()
    {

        abrirArchivo.setFileFilter(new FiltroProlog());
        abrirArchivo.showOpenDialog(this);
        File archivo = abrirArchivo.getSelectedFile();

        if(archivo != null && !archivo.isDirectory())
        {
            try
            {
                // Se genera un String con la consulta para carcar el archivo de código Prolog en memoria
                String t1 = "consult('" + archivo.getAbsolutePath().replace("\\","/") + "')";
                texto.setPage(archivo.toURI().toURL()); // Se carga el contenido sel archivo en el panel de texto
                Query q1 = new Query(t1); // Se general el Query con el String de consulta
                System.out.println( t1 + " " + (q1.hasSolution() ? "succeeded" : "failed") ); // se realiza la consulta
                query.setEnabled(true);
            }
            catch(IOException ex)
            {
                ex.printStackTrace(System.out);
            }
        }
    }


    // Realiza las consultas

    public void consultar()
    {

        String consulta;

        // Mientras el usuario haya tecleado algo en el cuadro de dialogo

        while((consulta = JOptionPane.showInputDialog(this,"Enter question ?-")) != null && consulta.length() > 0)
        {
            StringTokenizer st = new StringTokenizer(consulta,"(),"); // Crea un Tokenizer con el string de consulta

            int n = 0;
            String terminos[] = new String[100];

            while(st.hasMoreTokens()) // Recorre el Tokenizer
            {
		String tk = st.nextToken();
		char first = tk.charAt(0);
		if(Character.isUpperCase(first)) // En caso de que el Token inicie con mayuscula (Es una Variable)
		{
		    terminos[n]=tk;
                    n++;
		}
            }

            String results = "?- " + consulta+"\n\n";
            
            try
            {
                System.out.println(consulta);
                Query q2 = new Query(consulta);
                System.out.println( consulta + " is " + (q2.hasSolution() ? "provable" : "not provable") );
            
                if(q2.hasMoreSolutions())
                {
                    Map s2 = q2.nextSolution();
                    for(int i=0;i<n;i++) // Recupera todos los terminos unificados
                    {
                        if(i==(n-1))
                            results+=(" "+terminos[i] + " = " + s2.get(terminos[i]) + ";\n");
                        else
                            results+=(" "+terminos[i] + " = " + s2.get(terminos[i])+ "\n");
                    }
                }
                resultados.setText(results);  
            }
            catch(Exception ex)
            {
                StackTraceElement[] staktrace = ex.getStackTrace(); 
                // muestra staktrace
                results = "Sucedió una excepción:\n" + ex.getMessage();
                for (StackTraceElement element : staktrace) 
                    results +="\n"+element.toString();
                resultados.setText(results);
            }
        }    
    }


    /********************************************************
     * Metodos Utilitarios
     ********************************************************/


    public void despedida()
    {
        String mensaje = "Gracias por utilizar mi programa!!! ";
        javax.swing.JOptionPane.showConfirmDialog(this,mensaje,"Prolog",JOptionPane.DEFAULT_OPTION ,JOptionPane.INFORMATION_MESSAGE );
        System.exit(0);
    }

    // Metodo Main

    public static void main(String args[])
    {
	MyProlog p=new MyProlog();
        p.setVisible(true);
    }
}

class FiltroProlog extends javax.swing.filechooser.FileFilter
{
    @Override
    public boolean accept(File f)
    {
	String ext = (f.getName()).substring(f.getName().lastIndexOf(".")+1);
        ext = ext.toLowerCase();
        return (ext.equals("pl") || f.isDirectory());
    }
    
    @Override
    public String getDescription()
    {
    	return " Archivos de Prolog";
    }    
}
