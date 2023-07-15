// Write a program which accept file name and position from user and read 20 bytes from that position

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{
	int fd = 0;
	int NumRead = 0, Bytes = 0, NumWrite = 0;
	char Buff[BLOCKSIZE];
	
	printf("Usage : Executable_Name Position\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to oen the file\n");
		return -1;
	}
	
	Bytes = lseek(fd,atoi(argv[2]),SEEK_SET);
	if(Bytes == -1)
	{
		printf("Unable to change offset\n");
		close(fd);
		return -1;
	}
	
	NumRead = read(fd,Buff,20);
	if(NumRead == -1)
	{
		printf("Unable to read the data\n");
		close(fd);
		return -1;
	}
	
	NumWrite = write(1,Buff,NumRead);
	if(NumWrite == -1)
	{
		printf("Unable to write the data\n");
		close(fd);
		return -1;
	}
	
	printf("\n");
	
	close(fd);
	
	return 0;
}
