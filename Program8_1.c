// Write a program in which parent process waits till its child process terminates.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int Ret = 0;
	int Exit_Status = 0;
	int cpid = 0;
	
	Ret = fork();
	if(Ret == 0)		// child
	{
		printf("Child is running with PID : %d\n",getpid());
		execl("./ChildProcess","NULL",NULL);
	}
	else				// parent
	{
		printf("Parent is running with PID : %d\n",getpid());
		printf("PID of child process is : %d\n",Ret);
		cpid = wait(&Exit_Status);
		printf("PID of terminated child process is : %d with Exit status is : %d\n",cpid,Exit_Status);
		
	}
	
	
	return 0;
}

