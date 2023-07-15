// Write a program which is used to demonsrate concept of I/O redirection

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{
	int fd = 0;
	int NumRead = 0;
	char Buff[BLOCKSIZE];
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	while((NumRead = read(fd,Buff,sizeof(Buff))) != 0)
	{
		write(1,Buff,NumRead);
	}
	
	close(fd);
	
	
	return 0;
}