// Write a program which accept file name and mode and that program check whether our process can access that file in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


int main(int argc, char * argv[])
{
	int fd = 0;
	int Mode = 0;
	
	printf("Usage : Executable_Name FileName Mode\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	if(strcmp(argv[2],"read") == 0)
	{
		Mode = O_RDONLY;
	}
	else if(strcmp(argv[2],"write") == 0)
	{
		Mode = O_WRONLY;
	}
	else
	{
		Mode = O_RDWR;
	}
	
	fd = open(argv[1],Mode);
	if(fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}
	
	printf("File opened successfully with fd : %d\n",fd);
	
	close(fd);
	
	
	return 0;
}