// Write a program which accept file name and number of bytes from user and read that number of bytes from file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
	int fd = 0,NumRead = 0;
	char Buff[BLOCKSIZE];
	
	printf("Usage : Executable_Name File_Name No_of_Bytes\n");
	
	if(argc != 3)
	{
		printf("Inavlid Arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	NumRead = read(fd,Buff,atoi(argv[2]));
	if(NumRead == 0)
	{
		printf("Unable to read the data\n");
		close(fd);
		return -1;
	}
	
	printf("Data from the File is : \n");
	write(1,Buff,NumRead);
	
	close(fd);
	
	return 0;
}