// write a program which accept file name from user and write string in that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc,char* argv[])
{
	int fd = 0, Numread = 0, NumWrite = 0;
	char Buff[BLOCKSIZE];
	
	printf("Usage : Executable_Name File_Name\n");
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_WRONLY | O_APPEND);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	printf("Enter the string\n");
	
	Numread = read(1,Buff,sizeof(Buff));
	if(Numread == 0)
	{
		printf("Unable to read the data\n");
		close(fd);
		return -1;
	}
	
	NumWrite = write(fd,Buff,Numread);
	if(NumWrite == -1)
	{
		printf("Unable to write the data into file\n");
		close(fd);
		return -1;
	}
	
	close(fd);
	
	
	return 0;
}
