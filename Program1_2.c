// Write a program which accept file name and mode from user and open that file in specified mode

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	int fd = 0;
	int mode = 0;
	
	printf("Usage : Executable_Name File_Name Mode\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	if(strcmp(argv[2],"read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcmp(argv[2],"write") == 0)
	{
		mode = O_WRONLY;
	}
	else
	{
		mode = O_RDWR;
	}
	
	fd = open(argv[1],mode);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	printf("File is successfully opened with FD : %d\n",fd);
	
	close(fd);
	
	
	
	
	
	return 0;
}
