// Write a program which accept directory name and file name from user and create file in that directory

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>

int main(int argc, char * argv[])
{
	DIR * dp = NULL;
	int fd = 0;
	char str[256];
	
	printf("Usage : Executable_Name Directory_Name File_Name\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Unable to open the directory\n");
		return -1;
	}
	
	sprintf(str,"%s/%s",argv[1],argv[2]);
	
	fd = creat(str,0777);
	if(fd == -1)
	{
		printf("Unable to create file\n");
		closedir(dp);
		return -1;
	}
	
	if(fd != -1)
	{
		printf("File successfully created with FD : %d\n",fd);
	}
	
	closedir(dp);
	
	return 0;
}