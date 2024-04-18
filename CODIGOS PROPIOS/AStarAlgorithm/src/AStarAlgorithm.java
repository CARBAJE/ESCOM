import java.util.*;

public class AStarAlgorithm {
    public static List<Node> aStarSearch(Node start, Node goal) {
        Set<Node> explored = new HashSet<>();
        PriorityQueue<Node> queue = new PriorityQueue<>(Comparator.comparingInt(node -> node.getF()));

        start.setG(0);
        start.setH(manhattanDistance(start, goal));
        queue.add(start);

        while (!queue.isEmpty()) {
            Node current = queue.poll();
            explored.add(current);

            if (current.equals(goal)) {
                return reconstructPath(current);
            }

            for (Node neighbor : current.getNeighbors()) {
                if (explored.contains(neighbor)) {
                    continue;
                }

                int tentativeG = current.getG() + current.distanceTo(neighbor);

                if (!queue.contains(neighbor) || tentativeG < neighbor.getG()) {
                    neighbor.setCameFrom(current);
                    neighbor.setG(tentativeG);
                    neighbor.setH(manhattanDistance(neighbor, goal));

                    if (!queue.contains(neighbor)) {
                        queue.add(neighbor);
                    }
                }
            }
        }

        return null; // No se encontró un camino
    }

    private static List<Node> reconstructPath(Node node) {
        List<Node> path = new ArrayList<>();
        while (node != null) {
            path.add(node);
            node = node.getCameFrom();
        }
        Collections.reverse(path);
        return path;
    }

    private static int manhattanDistance(Node node1, Node node2) {
        return Math.abs(node1.getX() - node2.getX()) + Math.abs(node1.getY() - node2.getY());
    }

    public static void main(String[] args) {
        // Aquí puedes crear tus nodos y definir las conexiones entre ellos.
        // Luego, puedes llamar a aStarSearch con el nodo de inicio y el nodo objetivo.
    }
}

class Node {
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

    public List<Node> getNeighbors() {
        // Devuelve una lista de nodos vecinos (dependiendo de tu grafo).
        return null;
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

