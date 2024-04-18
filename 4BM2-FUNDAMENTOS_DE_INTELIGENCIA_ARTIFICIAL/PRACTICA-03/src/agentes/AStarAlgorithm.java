package agentes;

import java.util.*;

public class AStarAlgorithm {
    int i;
    int j;
    int[][] matrix;

    public AStarAlgorithm(int i, int j, int[][] matrix){
        this.i = i;
        this.j = j;
        this.matrix = matrix;
    }
    
    public static List<Node> aStarSearch(Node start, Node goal, int i, int j, int[][] matrix) {
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

            for (Node neighbor : current.getNeighbors(i, j, matrix)) {
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
}