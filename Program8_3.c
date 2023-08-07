// Write a program which create three different processes internally as process2, process3, process4

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int Ret1 = 0, Ret2 = 0, Ret3 = 0;
	int cpid1 = 0, cpid2 = 0, cpid3 = 0;
	int Exit_Status1 = 0, Exit_Status2 = 0, Exit_Status3 = 0;
	
	
	Ret1 = fork();
	if(Ret1 == 0)
	{
		execl("./Process2","NULL",NULL);
	}
	else
	{
		printf("Parent Process is running with PID : %d\n",getpid());
		printf("PID of Process 2 is : %d\n",Ret1);
		cpid1 = wait(&Exit_Status1);
		printf("PID of terminated child process is : %d\n",cpid1);
	}
	
	Ret2 = fork();
	if(Ret2 == 0)
	{
		execl("./Process3","NULL",NULL);
	}
	else
	{
		printf("Parent Process is running with PID : %d\n",getpid());
		printf("PID of Process 3 is : %d\n",Ret2);
		cpid2 = wait(&Exit_Status2);
		printf("PID of terminated child process is : %d\n",cpid2);
	}
	
	Ret3 = fork();
	if(Ret3 == 0)
	{
		execl("./Process4","NULL",NULL);
	}
	else
	{
		printf("Parent Process is running with PID : %d\n",getpid());
		printf("PID of Process 4 is : %d\n",Ret3);
		cpid3 = wait(&Exit_Status3);
		printf("PID of terminated child process is : %d\n",cpid3);
	}
	
	
	return 0;
}