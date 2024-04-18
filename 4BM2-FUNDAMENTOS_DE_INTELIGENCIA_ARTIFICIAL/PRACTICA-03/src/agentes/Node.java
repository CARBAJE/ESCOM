package agentes;
import java.util.*;

public class Node {
    private int x;
    private int y;
    private int g;
    private int h;
    private Node cameFrom;

    public Node(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public int getG() {
        return g;
    }

    public void setG(int g) {
        this.g = g;
    }

    public int getH() {
        return h;
    }

    public void setH(int h) {
        this.h = h;
    }

    public int getF() {
        return g + h;
    }

    public Node getCameFrom() {
        return cameFrom;
    }

    public void setCameFrom(Node cameFrom) {
        this.cameFrom = cameFrom;
    }

    public int distanceTo(Node other) {
        return Math.abs(this.x - other.x) + Math.abs(this.y - other.y);
    }

    public List<Node> getNeighbors(int i, int j, int[][] matrix) {
        List<Node> neighbors = new ArrayList<>();
        int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Movimientos arriba, abajo, izquierda, derecha
        this.x = i;
        this.y = j;
        for (int[] dir : directions) {
            int newX = this.x + dir[0];
            int newY = this.y + dir[1];

            // Verificar que el vecino esté dentro de los límites del mapa
            if (newX >= 0 && newX < matrix.length-2 && newY >= 0 && newY < matrix.length-2) {
                // Verificar que el vecino no sea un obstáculo (con valor diferente de 0)
                if (matrix[newX][newY] == 0) {
                    neighbors.add(new Node(newX, newY));
                }
            }
        }

        return neighbors;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Node node = (Node) obj;
        return x == node.x && y == node.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}