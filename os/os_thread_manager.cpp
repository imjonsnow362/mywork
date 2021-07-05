#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define size 5
int Mat1[size][size],Mat2[size][size],Mat3[size][size];
int row,col;
int NoOfThreads=size;

void printMatrix(int res[size][size])
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			printf(" %d",res[i][j]);
		}
		printf("\n");
	}
}

void readMatrix()
{
	int i,j;

	//Adding values in Matrix1:
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			Mat1[i][j] = 1;

	//Adding values in Matrix2:
	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			Mat2[i][j] = 1;

	printf("\n Printing Matrix 1 : \n");
	printMatrix(Mat1);
	printf("\n Printing Matrix 2 : \n");
	printMatrix(Mat2); 
}


void *matrixMultiplication(void *args)
{
	long int thread=(long int)args;
	int i,j,k;
//	int from = (thread*row)/NoOfThreads;
//	int to = (thread+1)*row/NoOfThreads;
	int from = (thread*size)/NoOfThreads;
	int to = (thread+1)*size/NoOfThreads;
	for(i=from;i<to;i++)
	{
		for(j=0;j<size;j++)
		{
			Mat3[i][j] =0;
			for(k=0;k<size;k++)
			{
				Mat3[i][j]+=Mat1[i][k]*Mat2[k][j];
			}
		}
	}

	printf("\n Printing result by Thread %ld\n",thread);
	printMatrix(Mat3);
}



int main(void)
{
	pthread_t tid[10];
	long int i,j;
	//code
	readMatrix();

	//create no of threads entered by user
	for(i=0;i<NoOfThreads;i++)
		pthread_create(&tid[i],NULL,matrixMultiplication,(void*)i);

	//Join number of threads
	for(j=0;j<NoOfThreads;j++)
		pthread_join(tid[j],NULL);
		
	return 0;
}

