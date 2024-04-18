package com.practica3;//modificado

import java.util.HashMap;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

public class Agente extends Thread {

    String nombre;
    int i;
    int j;
    ImageIcon icon;
    ImageIcon Base;
    ImageIcon migaja;
    HashMap< Integer, ImageIcon> cluster = new HashMap<>();
    int[][] matrix;
    JLabel tablero[][];
    int obtenidas;
    int objetivo;
    int entregas;
    Agente companiero;
    int xBase;
    int yBase;
    Boolean irBase = false;

    JLabel casillaAnterior;
    int fila_ant;
    int col_ant;
    Random aleatorio = new Random(System.currentTimeMillis());

    public Agente(String nombre, ImageIcon icon, int[][] matrix, JLabel tablero[][], ImageIcon mother, ImageIcon migaja, HashMap< Integer, ImageIcon> cluster) {
        this.nombre = nombre;
        this.icon = icon;
        this.matrix = matrix;
        this.tablero = tablero;

        this.i = aleatorio.nextInt(matrix.length);
        this.j = aleatorio.nextInt(matrix.length);
        tablero[i][j].setIcon(icon);
        this.Base = mother;
        this.migaja = migaja;
        this.cluster = cluster;
    }

    public void regresarBase() {

        irBase = true;

        while (true) {

            int yDistance = yBase - i;
            int xDistance = xBase - j;

            if (yDistance == 0 && xDistance == 0) {
                matrix[i][j] = 2;
                break;
            }

            while ((yBase - i) > 0) {

                casillaAnterior = tablero[i][j];
                if (matrix[i + 1][j] == 0 || matrix[i + 1][j] == 2 || matrix[i + 1][j] == 4) {

                    fila_ant = i;
                    col_ant = j;
                    i += 1;
                    matrix[i][j] = 4;
                    actualizarPosicion();

                    try {
                        sleep(100 + aleatorio.nextInt(100));
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }

                } else {
                    break;
                }

            }

            while ((xBase - j) > 0) {

                casillaAnterior = tablero[i][j];

                if (matrix[i][j + 1] == 0 || matrix[i][j + 1] == 2 || matrix[i][j + 1] == 4) {

                    fila_ant = i;
                    col_ant = j;
                    j += 1;
                    matrix[i][j] = 4;
                    actualizarPosicion();

                    try {
                        sleep(100 + aleatorio.nextInt(100));
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }

                } else {
                    break;
                }

            }

            while ((yBase - i) < 0) {

                casillaAnterior = tablero[i][j];
                if (matrix[i - 1][j] == 0 || matrix[i - 1][j] == 2 || matrix[i - 1][j] == 4) {

                    fila_ant = i;
                    col_ant = j;
                    i -= 1;
                    matrix[i][j] = 4;
                    actualizarPosicion();

                    try {
                        sleep(100 + aleatorio.nextInt(100));
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }

                } else {
                    break;
                }

            }

            while ((xBase - j) < 0) {

                casillaAnterior = tablero[i][j];
                if (matrix[i][j - 1] == 0 || matrix[i][j - 1] == 2 || matrix[i][j - 1] == 4) {

                    fila_ant = i;
                    col_ant = j;
                    j -= 1;
                    matrix[i][j] = 4;
                    actualizarPosicion();

                    try {
                        sleep(100 + aleatorio.nextInt(100));
                    } catch (Exception ex) {
                        ex.printStackTrace();
                    }

                } else {
                    break;
                }

            }

        }

        entregas++;
        obtenidas--;

    }

    public void migajas() {

        matrix[i][j] = 0;

        int last_movement = 0;

        while (true) {

            casillaAnterior = tablero[i][j];
            fila_ant = i;
            col_ant = j;

            if (matrix[i - 1][j] == 4 && i > 0) {

                i--;
                matrix[i][j] = 0;
                actualizarPosicion();
                last_movement = 1;

                try {
                    sleep(100 + aleatorio.nextInt(100));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }

            } else if (matrix[i + 1][j] == 4 && i <= matrix.length - 2) {

                i++;
                matrix[i][j] = 0;
                actualizarPosicion();
                last_movement = 2;

                try {
                    sleep(100 + aleatorio.nextInt(100));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }

            } else if (matrix[i][j + 1] == 4 && j <= matrix.length - 2) {

                j++;
                matrix[i][j] = 0;
                actualizarPosicion();
                last_movement = 3;

                try {
                    sleep(100 + aleatorio.nextInt(100));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }

            } else if (matrix[i][j - 1] == 4 && j > 0) {

                j--;
                matrix[i][j] = 0;
                actualizarPosicion();
                last_movement = 4;

                try {
                    sleep(100 + aleatorio.nextInt(100));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }

            } else {

                if (last_movement == 1) {
                    i--;
                    break;
                } else if (last_movement == 2) {
                    i++;
                    break;
                } else if (last_movement == 3) {
                    j++;
                    break;
                } else if (last_movement == 4) {
                    j--;
                    break;
                }

            }

        }

    }

    public void run() {

        int next_move_row = 0;
        int next_move_col = 0;

        while (true) {

            casillaAnterior = tablero[i][j];
            fila_ant = i;
            col_ant = j;

            int flag = 1;
            while (flag == 1) {
                next_move_row = aleatorio.nextInt((1 - (-1)) + 1) + (-1);
                next_move_col = aleatorio.nextInt((1 - (-1)) + 1) + (-1);
                if ((next_move_col == 0 && (next_move_row == 1 || next_move_row == -1)) || (next_move_row == 0 && (next_move_col == 1 || next_move_col == -1))) {
                    flag = 0;
                }
            }

            if ((i > matrix.length - 2 || matrix[i + 1][j] == 1) && next_move_row == 1) {
                next_move_row = -1;
                next_move_col = 0;
            }

            if ((i < 1 || matrix[i - 1][j] == 1) && next_move_row == -1) {
                next_move_row = 1;
                next_move_col = 0;
            }

            if ((j > matrix.length - 2 || matrix[i][j + 1] == 1) && next_move_col == 1) {
                next_move_col = -1;
                next_move_row = 0;
            }

            if ((j < 1 || matrix[i][j - 1] == 1) && next_move_col == -1) {
                next_move_col = 1;
                next_move_row = 0;
            }

            if ((i < matrix.length - 1 && i > 1) && (matrix[i + 1][j] == 1 && matrix[i - 1][j] == 1)) {
                next_move_row = 0;
            }

            if ((j < matrix.length - 1 && j > 1) && (matrix[i][j + 1] == 1 && matrix[i][j - 1] == 1)) {
                next_move_col = 0;
            }

            if ((i == matrix.length - 1 && matrix[i - 1][j] == 1) || (i == 0 && matrix[i + 1][j] == 1)) {
                next_move_row = 0;
            }
            if ((j == matrix.length - 1 && matrix[i][j - 1] == 1) || (j == 0 && matrix[i][j + 1] == 1)) {
                next_move_col = 0;
            }

            i += next_move_row;
            j += next_move_col;

            if (matrix[i][j] == 4) {

                actualizarPosicion();
                migajas();

            }

            if (matrix[i][j] % 3 == 0 && matrix[i][j] > 0) {
                System.out.println(matrix[i][j]);
                obtenidas++;
                matrix[i][j] -= 3;
                actualizarPosicion();
                regresarBase();
                irBase = false;
            } else {
                actualizarPosicion();
            }

            if ((entregas + companiero.entregas) == objetivo && obtenidas == 0) {
                JOptionPane.showMessageDialog(new JFrame(), "Todas las plantitas han sido recogidas", "Finalizo el juego", JOptionPane.WARNING_MESSAGE);
                break;
            }

            try {
                sleep(100 + aleatorio.nextInt(100));
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    public synchronized void actualizarPosicion() {
        casillaAnterior.setIcon(null);
        if (irBase) {

            casillaAnterior.setIcon(migaja);

        }

        if (matrix[fila_ant][col_ant] == 2) {

            casillaAnterior.setIcon(Base);

        }

        if (matrix[fila_ant][col_ant] % 3 == 0 && matrix[fila_ant][col_ant] > 0) {

            Integer matrix_value = matrix[fila_ant][col_ant];
            casillaAnterior.setIcon(cluster.get(matrix_value));

        }

        tablero[i][j].setIcon(icon);

    }
}
