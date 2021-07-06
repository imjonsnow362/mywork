//Implement Prim’s/Kruskal algorithm for any application.
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Main {
    static class Edge { //contstructor extend
        int start;
        int end;
        int weight;
//we will have to create two classes edge class and graph class for this mst 
        public Edge(int start, int end, int weight) {
            this.start = start;
            this.end = end;
            this.weight = weight;
        }
    }

    static class Graph {
        int vertices;
        ArrayList<Edge> allEdges = new ArrayList<>();

        Graph(int vertices) {
            this.vertices = vertices;
        }
//to add edge in mst
        public void addEgde(int start, int end, int weight) {
            Edge edge = new Edge(start, end, weight);
            allEdges.add(edge); //add to total edges
        }
        
        public void kruskal(){
            PriorityQueue<Edge> pq = new PriorityQueue<>(allEdges.size(), Comparator.comparingInt(o -> o.weight));

            //adding edges to priorrity queue
            //sort edges 
            for (int i = 0; i <allEdges.size() ; i++) {
                pq.add(allEdges.get(i));
            }

            //create a parent 
            int [] parent = new int[vertices];

            //makeset
            makeSet(parent);

            ArrayList<Edge> mst = new ArrayList<>();

            //processing vertices with only 1 edge 
            int index = 0;
            while(index<vertices-1){
                Edge edge = pq.remove();
                //checking if adding vertices creates a cycle
                int x_set = find(parent, edge.start);
                int y_set = find(parent, edge.end);

                if(x_set==y_set){
                    //this will ignore and create the cycle 
                }else {
                    //add this to the final answer
                    mst.add(edge);
                    index++;
                    union(parent,x_set,y_set);
                }
            }
            //print MST
            System.out.println("KRUSKAL MINIMUM SPANNING TREE ---");
            printGraph(mst);
        }

        public void makeSet(int [] parent){
            //makeSet- creating new element in which parent points to itself.
            for (int i = 0; i <vertices ; i++) {
                parent[i] = i;
            }
        }

        public int find(int [] parent, int vertex){
            //creating a chain of pointers pointing upwards till parent 
            // continue till element whose parent is the parent
            if(parent[vertex]!=vertex)
                return find(parent, parent[vertex]);;
            return vertex;
        }

        public void union(int [] parent, int x, int y){
            int x_set_parent = find(parent, x);
            int y_set_parent = find(parent, y);
            //x will be parent of y 
            parent[y_set_parent] = x_set_parent;
        }

        public void printGraph(ArrayList<Edge> edgeList){
            for (int i = 0; i <edgeList.size() ; i++) {
                Edge edge = edgeList.get(i);
                System.out.println("EDGE --" + i + " START -- " + edge.start +
                        " END--" + edge.end +
                        " WEIGHT-- " + edge.weight);
            }
        }
    }
    public static void main(String[] args) {
            int vertices = 6;
            Graph graph = new Graph(vertices);
            graph.addEgde(0, 1, 4);
            graph.addEgde(0, 2, 3);
            graph.addEgde(1, 2, 1);
            graph.addEgde(1, 3, 2);
            graph.addEgde(2, 3, 4);
            graph.addEgde(3, 4, 2);
            graph.addEgde(4, 5, 6);
            graph.kruskal();
    }
}
