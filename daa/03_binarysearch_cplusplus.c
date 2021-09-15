#include<stdio.h>
#include<conio.h>

void main() {
	int arr[100],start,mid,stop,i,n,num;

	printf("\n Enter size of array--");
	scanf("%d",&n);

	printf("\n ENter values in a sorted order--");

	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}



// Need to initialise the beginning and ending value

start = 0;
stop = n-1;

printf("Enter value to be searched in an array--");
scanf("%d",&num);

//we will run a while loop when start is less than stop
mid=((start+stop)/2);
while(start<=stop)
      {
        if(arr[mid]<num)
           start =mid+1;
         //if its in found in middle index just print and leave
        else if(arr[mid]==num)
         {
          printf("%d is found at location %d",num, mid+1);
          break;
         }
          else
           stop=mid-1;
           mid=((start+stop)/2);
      }
      if(start>stop)
      printf("Not found ");
}