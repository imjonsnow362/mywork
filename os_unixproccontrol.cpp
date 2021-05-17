#include<stdio.h>
#define MAX 20
void mergesorting(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
void quicksort(int [10],int,int);
void main()
{
    int a[10],i,n,x;

    printf("\n ————————-");
    printf(“ENter the number of elements in the array--”);
    scanf(“%d”,&n);
    printf(“Enter the elements in the array--”);
    for(i=0;i<n;i++)
    scanf(“%d”,&a[i]);

    x=fork();
/* fork() it will create a child process 
. The positive number is the processid of a child.
*/

if(x==0) // Part of a is executed by Child.If the fork returns 0 it is a child process
{
    printf(“\Child Process-- = %d”,getprocessid()); 

    quicksort(a,0,n-1); 
    printf(“\nAfter quick sorting elements are: “);

    for(i=0;i<n;i++)
    printf(” %d”,a[i]);
}
else // Part of a is executed by parent.If it returns a +ve number it is a parent process 
{
    printf(“\nparent process=%d \n”,getprocessid());
    partition(a,0,n-1); 
    printf(“\nAfter merge sorting elements are: “);
    for(i=0;i<n;i++)
    printf(“%d “,a[i]);
}
}

void partition(int arr[],int low,int high) //in merger sort the list is divided into two parts hence partition is created 
{

    int mid;
    if(low<high)
{
    mid=(low+high)/2;
    partition(arr,low,mid);
    partition(arr,mid+1,high);
    mergesorting(arr,low,mid,high);
}
}
//merge sort method 
void mergesorting(int arr[],int low,int mid,int high)
{
    int i,m,k,l,temp[MAX];
    l=low;
    i=low;
    m=mid+1;
while((l<=mid)&&(m<=high))
{
if(arr[l]<=arr[m])
{
    temp[i]=arr[l];
    l++;
}
else
{
    temp[i]=arr[m];
    m++;
}
    i++;
}
if(l>mid)
{
for(k=m;k<=high;k++)
{
    temp[i]=arr[k];
    i++;
}
}
else
{
for(k=l;k<=mid;k++)
{
    temp[i]=arr[k];
    i++;
}
}

for(k=low;k<=high;k++)
{
    arr[k]=temp[k];
}
}
// quick sort method 
void quicksort(int x[10],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
{
    pivot=first;
    i=first;
    j=last;
while(i<j)
{
    while(x[i]<=x[pivot]&&i<last)
    i++;
    while(x[j]>x[pivot])
    j–;
    if(i<j)
{
    temp=x[i];
    x[i]=x[j];
    x[j]=temp;
}
}
    temp=x[pivot];
    x[pivot]=x[j];
    x[j]=temp;
    quicksort(x,first,j-1);
    quicksort(x,j+1,last);
}
}


