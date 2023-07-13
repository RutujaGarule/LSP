// Write a program which accept file name from user and open that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
	int fd = 0;
	
	printf("Usage : Executable_Name File_Name\n");
	
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
	
	printf("File is opened successfully with FD : %d\n",fd);
	
	close(fd);

	return 0;
}