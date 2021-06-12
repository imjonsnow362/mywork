#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define buffsize 5

sem_t empty,full;
pthread_mutex_t mutex;
int buffer[buffsize];
int count = 0;


//Producer Function
void * producer(void * args)
{
	long int num= (long int) args;
	//producer will wait
	sem_wait(&empty);

	//wait condition is false means glass is empty and now producer can fill the glass

	//
	pthread_mutex_lock(&mutex);
	buffer[count]=rand()%50;
	printf("\n producer = %ld produces = %d ",num+1,buffer[count]);
	count++; 
	sleep(1);
	pthread_mutex_unlock(&mutex); 
	sem_post(&full); 
}

//Consumer Function
void * consumer(void * args)
{
	long int num= (long int) args;
	sem_wait(&full);

	//full condition is false means glass is full and now consumer can take teh drink

	pthread_mutex_lock(&mutex);
	count--;
	printf("\n consumer = %ld consumed = %d ",num,buffer[count]);
	sleep(1);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}

int main()
{
	pthread_t Ptid[10],Ctid[10]; //threads for producers and consumers
	int NoOfProducers,NoOfConsumers;
	long int i,j,k,l;

	printf("\n Enter the no of producesrs: ");
	scanf("%d",&NoOfProducers);

	printf("\n Enter the no of consumers: ");
	scanf("%d",&NoOfConsumers);


	//Step 1: Initilaize the semaphore varaibles:
	sem_init(&empty,0,buffsize);  //Varable 1: semaphore variable, 0 = Not shard, buffsize => how many empty buffers(5)
	sem_init(&full,0,0);          //Varable 1: semaphore variable, 0 = Not shard, buffsize => how many buggers full (0)

	//Step 2:Initialize the mutex lock
	pthread_mutex_init(&mutex,NULL);

	//creating no threads equal to producers
	for(i=0;i<NoOfProducers;i++)
		pthread_create(&Ptid[i],NULL,producer,(void *)i);

	//creating no threads equal to consumers
	for(j=0;j<NoOfConsumers;j++)
		pthread_create(&Ctid[j],NULL,consumer,(void *)j);

	//creating no threads equal to producers
	for(k=0;k<NoOfProducers;k++)
		pthread_join(Ptid[k],NULL);

	//creating no threads equal to consumers
	for(l=0;l<NoOfConsumers;l++)
		pthread_join(Ctid[l],NULL);

	printf("\n");	
	return 0;
}




