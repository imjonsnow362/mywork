//For any application find Single source shortest path using Dijkstra’s algorithm
import java.util.*;
public class Main
{
   
    static final int V = 6; 
    int minDistance(int dist[], Boolean visited[]) 
    { 
        int min = Integer.MAX_VALUE, min_index = -1; 
  
        for (int v = 0; v < V; v++) 
            if (visited[v] == false && dist[v] <= min) { 
                min = dist[v]; 
                min_index = v; 
            } 
  
        return min_index; 
    }
    
     void printSolution(int dist[],int Destination)
    { 
            Scanner scan=new Scanner(System.in);
            int num=dist[Destination];
            System.out.println("Total Distance :" + num); 
            System.out.println("Total Cost : "+num*10 );
            char option;
            System.out.print("Do you Want to book Taxi [y/n]: ");
            option=scan.next().charAt(0);
            if(option=='y' || option=='Y'){
                 System.out.print("Enter your Name : ");
                 scan.nextLine();
                 String name=scan.nextLine();
                System.out.print("Enter your mobile number : ");
                 String mob=scan.next();
                 System.out.println("\n\nThank you for Booking our team will contact you soon!!!");
            }
            else{
               System.out.println("Thank you ");
            }
            
    } 
    
    void dijkstra(int graph[][], int src,int Destination) 
    { 
        int dist[] = new int[V]; 
        Boolean visited[] = new Boolean[V]; 
  
        for (int i = 0; i < V; i++) { 
            dist[i] = Integer.MAX_VALUE; 
            visited[i] = false; 
        } 
  
        dist[src] = 0; 
  
        
        for (int count = 0; count < V - 1; count++) { 
 
            int u = minDistance(dist, visited); 
  
            visited[u] = true; 
 
            for (int v = 0; v < V; v++) 
 
                if (!visited[v] && graph[u][v] != 0 && dist[u] != Integer.MAX_VALUE && dist[u] + graph[u][v] < dist[v]) 
                    dist[v] = dist[u] + graph[u][v]; 
        } 
        printSolution(dist,Destination); 
    } 
  
    
    
    
	public static void main(String[] args) {
	  
	  int graph[][] = new int[][] { { 0,70,0,0,0,0 }, 
                                      { 70, 0,80,0,99,0 }, 
                                      { 0, 8, 0, 75, 0, 45}, 
                                      { 0, 0, 75, 0, 9, 140}, 
                                      { 0, 99, 0, 9, 0, 10}, 
                                      { 0, 0, 45, 140, 105, 0}, 
                                       }; 
	    
	    Scanner sc=new Scanner(System.in);
	    int location;
	    int Destination;
	    System.out.println("Our Taxi Services are Limited for following cities:");
	    System.out.println("\t 0.Shevgaon \n\t 1.Ahmednager \n\t 2.Pune \n\t 3.Aurangabad \n\t 4.Beed \n\t 5.Sangamner ");
	    System.out.print("\n\tEnter the your location eg.0,1,..:");
	    location=sc.nextInt();
	     System.out.print("\n\tEnter the your Destination eg.0,1,..:");
	     Destination=sc.nextInt();
	     Main t=new Main();
	     t.dijkstra(graph,location,Destination);
	    
	}
}
