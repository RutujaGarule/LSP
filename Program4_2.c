// Write a program which accept directory name from user and create new directory of that name

#include<stdio.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	int fd = 0;
	
	printf("Usage : Executable_Name Directory_Name\n");
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fd = mkdir(argv[1],0777);
	if(fd == -1)
	{
		printf("Unable to create directory\n");
		return -1;
	}
	
	printf("Directory created successfully\n");
	
	
	return 0;
}
