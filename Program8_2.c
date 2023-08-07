// Write a program which create three level process hierarchy where process 1 creates process 2 and it internally creates process 3

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int Ret = 0;
	int cpid = 0;
	int Exit_Status = 0;
	
	
	Ret = fork();
	if(Ret == 0)
	{
		execl("./Process2","NULL",NULL);
	}
	else
	{
		printf("Process 1 is running with PID : %d\n",getpid());
		printf("PID of Process 2 is : %d\n",Ret);
		cpid = wait(&Exit_Status);
		printf("PID of terminated child process is : %d\n",cpid);
	}
	
	
	return 0;
}