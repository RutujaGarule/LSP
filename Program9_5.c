// Write a program which is used to yield our processor by using appropriate system call

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<sched.h>

void * ThreadProc1(void * ptr)
{
	int Ret = 0;
	Ret = sched_yield();
	printf("Inside thread 1\n");

	pthread_exit(NULL);
}

void * ThreadProc2(void * ptr)
{
	printf("Inside thread 2\n");

	pthread_exit(NULL);
}


int main(int argc, char * argv[])
{
	pthread_t TID1, TID2;
	int Ret = 0;

	Ret = pthread_create(&TID1,NULL,ThreadProc1,NULL);
	if(Ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread 1 created succesfully with TID : %lu\n",TID1);

	Ret = pthread_create(&TID2,NULL,ThreadProc2,NULL);
	if(Ret != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}
	printf("Thread 2 created succesfully with TID : %lu\n",TID2);

	pthread_join(TID1,NULL);
	pthread_join(TID2,NULL);

	printf("End of main\n");

	pthread_exit(NULL);
	
	return 0;
}