// Write a program which creates new process which is responsible to write all file names which are present on desktop in demo file which should be created newly.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char * argv[])
{
	int Ret = 0;
	int cpid = 0;
	int Exit_Status = 0;
	
	Ret = fork();
	if(Ret == 0)
	{
		execl("./files","NULL",NULL);
	}
	else
	{
		printf("Parent is running with PID : %d\n",getpid());
		cpid = wait(&Exit_Status);
		printf("Terminated process having PID is : %d with Exit status is : %d\n",cpid,Exit_Status);
	}
	
	return 0;
}