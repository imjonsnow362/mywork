import java.util.Scanner;
class BubbleSort {
	public static void main(String []args) {
		int num, c, d, swap;
		Scanner in = new Scanner(System.in);
		System.out.println("Enter numbers to sort");
		num = in.nextInt();
		int array[] = new int[num];
		System.out.println("Enter " + n + " integers");
		for (c = 0; c < num; c++) 
		      array[c] = in.nextInt();
		for (c = 0; c < ( num - 1 ); c++) {
			for (d = 0; d < num - c - 1; d++) {
				if (array[d] > array[d+1]) 
				 {
					swap       = array[d];
					array[d]   = array[d+1];
					array[d+1] = swap;
				}
			}
		}
		System.out.println("Bubble Sorted list of numbers");
		for (c = 0; c < num; c++) 
		      System.out.println(array[c]);
	}
}
