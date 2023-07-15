// Write a program which accept two file names from user and check contents of that two files are equal or not

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{
	int fd1 = 0, fd2 = 0;
	int Size1 = 0, Size2 = 0;
	int Ret = 0;
	int Read = 0;
	char Buff1[BLOCKSIZE];
	char Buff2[BLOCKSIZE];
	
	printf("Usage : Executable_Name First_File Second_File\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	struct stat sobj;
	
	Ret = stat(argv[1],&sobj);
	if(Ret == -1)
	{
		printf("stat fails for first file\n");
		return -1;
	}
	Size1 = sobj.st_size;
	
	Ret = stat(argv[2],&sobj);
	if(Ret == -1)
	{
		printf("stat fails for first file\n");
		return -1;
	}
	Size2 = sobj.st_size;
	
	if(Size1 != Size2)
	{
		printf("Files are not identical as sizes are different\n");
		return -1;
	}
	
	fd1 = open(argv[1],O_RDONLY);
	if(fd1 == -1)
	{
		printf("Unable to open first file\n");
		return -1;
	}
	
	fd2 = open(argv[2],O_RDONLY);
	if(fd2 == -1)
	{
		printf("Unable to open second file\n");
		close(fd1);
		return -1;
	}
	
	while((Read = read(fd1,Buff1,sizeof(Buff1))) != 0)
	{
		while((Read = read(fd2,Buff2,sizeof(Buff2))) != 0)
		{
			Ret = memcmp(Buff1,Buff2,Read);
			if(Ret != 0)
			{
				printf("Files are not identical\n");
				break;
			}
		}
	}
	
	if(Ret == 0)
	{
		printf("Files are identical\n");
	}
	
	close(fd1);
	close(fd2);
	
	
	return 0;
}