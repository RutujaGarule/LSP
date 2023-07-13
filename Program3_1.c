// Write a program which accept two file names from user and copy the contents of an existing file into newly created file
// Implemetation of cp command

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{
	int fdSource = 0, fdDest = 0;
	int NumRead = 0, NumWrite = 0;
	char Buff[BLOCKSIZE];
	
	printf("Usage : Executable_Name Source_File Destination_File\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fdSource = open(argv[1],O_RDONLY);
	if(fdSource == -1)
	{
		printf("Unable to open Source file\n");
		return -1;
	}
	
	fdDest = creat(argv[2],0777);
	if(fdDest == -1)
	{
		printf("Unable to craete Destination File\n");
		close(fdSource);
		return -1;
	}
	
	while((NumRead = read(fdSource,Buff,sizeof(Buff))) != 0)
	{
		NumWrite = write(fdDest,Buff,NumRead);
		memset(Buff,0,sizeof(Buff));
		
		if(NumWrite == -1)
		{
			printf("Unable to write the data\n");
			return -1;
		}
	}
	
	close(fdDest);
	close(fdSource);
	
	
	return 0;
}