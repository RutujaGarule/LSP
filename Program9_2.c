// Write a program which creates two process.
// Process 1 count number of capital characters from Demo.txt file
// Process 2 count number of small characters from Demo.txt file

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char * argv[])
{
	int Ret1 = 0,Ret2 = 0;
	int cpid1 = 0, cpid2 = 0;
	int Exit_Status1 = 0, Exit_Status2 = 0;
	
	Ret1 = fork();
	if(Ret1 == 0)		// child
	{
		execl("./Small","NULL",NULL);
	}
	
	cpid1 = wait(&Exit_Status1);

	Ret2 = fork();
	if(Ret2 == 0)		// Child
	{
		execl("./Capital","NULL",NULL);
	}
	
	cpid2 = wait(&Exit_Status2);
	
	return 0;
}