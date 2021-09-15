/*fintech - unit 1 --use any case study for financials ervices (they are provididng mf , mobile banking etc give example hdfc)
pick any example where fintech is being used - 
Agri-tec
Insurance
Automation/IoT
Real Estate
Banking
Tourism/Travel
Trade
E commerce
food
Government/Administration
Health
Education
Energy
--changing environemtn -- use any case stduy how financial banking have changed from traditional to digitial
--fintech ecosystem - demand attribute(how paytm uses)
use any case study and explain the 4cs of business
what paramters can be added to answer from case study
inline your answers with any finance company or tradiitional banking sectors import java.util.Scanner;
-tokenization (complete process of payment gateway example - google pay so check how it works)
-- for insurance take any case study 
--unit 2 - what type of challenegs are therer , what type of service 
-- explain csutomer relationship management use case studys 
-- explain business process and all the points should have a case srudy attached to it 
-- p2p example is service provider etc 
--in how slide how amazon has applied big data analytics or mobility how banks are using mobile apps in mobility
--business model framework apply case study 
*/
import javax.swing.plaf.metal.MetalBorders.ScrollPaneBorder;

class Bitonic{
    //making a function for binary search because optimal and will give the time complexity required
    //ascending mode
    static int ascBinarySearch(int arr[],int low,int high,int key)
    {
        while(low<=high)
        {
            int mid = low + (high - low) / 2;
            if(arr[mid] == key){
                return mid;
            }
            if(arr[mid] > key){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return -1;
    }
    //same thing in descending mode
    static int descBinarySearch(int arr[],int low,int high,int key)
    {
        while(low<=high)
        {
            int mid = low + (high-low) / 2;
            if(arr[mid] == key)
            {
                return mid;
            }
            if(arr[mid] < key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    } 

    //find bitonic point in this 
    static int findBitonicPoint(int arr[],int n,int l,int r)
    {
        int mid;
        int BitonicPoint = 0;
        mid = (r + 1) / 2;
        if(arr[mid] > arr[mid - 1]&&arr[mid]>arr[mid+1])
        {
            return mid;
        }
        else {
        if (arr[mid] > arr[mid - 1]
                && arr[mid] < arr[mid + 1])
            {
                BitonicPoint = findBitonicPoint(arr, n, mid, r);
            }
            else {
                if (arr[mid] < arr[mid - 1]
                    && arr[mid] > arr[mid + 1])
                {
                    BitonicPoint = findBitonicPoint(arr, n, l, mid);
                }
            }
        }
        return BitonicPoint;
    }

    static int searchBitonicPoint(int arr[], int n,int key, int index)
    {
        if (key > arr[index])
        {
            return -1;
        }
        else if (key == arr[index])
        {
            return index;
        }
        else {
            int temp = ascBinarySearch(arr, 0, index - 1, key);
            if (temp != -1)
            {
                return temp;
            }
 
            // Search in right of k
            return descBinarySearch(arr, index + 1,n - 1, key);
        }
    }

    // final main function
    public static void main(String args[])
    {
        int n, l, r;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements you want to store--");
        n=sc.nextInt();  
        int[] arr = new int[10];
        System.out.println("Enter the elements of the array");
        for(int i=0;i<n;i++)
        {
            arr[i]=sc.nextInt();
        }

        int key = 5;
        
        n = arr.length;
        l = 0;
        r = n - 1;
        int index;
        index = findBitonicPoint(arr, n, l, r);
 
        int x = searchBitonicPoint(arr, n, key, index);
 
        if (x == -1) {
            System.out.println("Element Not Found");
        }
        else {
            System.out.println("Element Found at index "+ x);
        }
    }
}


    






    
