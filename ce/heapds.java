//Read the marks obtained by students of second year in an online examination of particular subject. Find out maximum and minimum marks obtained in that subject. Use heap data structure. Analyze the algorithm
import java.util.Scanner;
public class Main {
        public void sort(int arr[])
        {
            int n = arr.length;

            for (int i = n / 2 - 1; i >= 0; i--)
                heapify(arr, n, i);

            for (int i=n-1; i>=0; i--)
            {
                int temp = arr[0];
                arr[0] = arr[i];
                arr[i] = temp;

                heapify(arr, i, 0);
            }
        }

        void heapify(int arr[], int n, int i)
        {
            int largest = i;
            int l = 2*i + 1;
            int r = 2*i + 2;

            if (l < n && arr[l] > arr[largest])
                largest = l;

            if (r < n && arr[r] > arr[largest])
                largest = r;

            if (largest != i)
            {
                int swap = arr[i];
                arr[i] = arr[largest];
                arr[largest] = swap;

                heapify(arr, n, largest);
            }
        }
        static void printMax(int arr[])
        {
            System.out.println(arr[arr.length-1]);
        }

        static void printMin(int arr[])
        {
            System.out.println(arr[0]);
        }
       
        public static void main(String args[]) {
            Scanner sc = new Scanner(System.in);
            System.out.println("ENTER NUMBER OF STUDENTS--");
            int n= sc.nextInt();

            int arr[] = new int[n];
            for (int i=0; i< n; i++){
                System.out.println("ENTER MARKS OF THE STUDENT--");
                arr[i]= sc.nextInt();
            }
            Main ob = new Main();
            ob.sort(arr);
            System.out.println("MAX MARKS--");
            printMax(arr);
            System.out.println("MIN MARKS--");
            printMin(arr);
            }
}
