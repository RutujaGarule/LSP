// Write a program which accept directory name from user and print all file names from that directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <dirent.h>

int main(int argc, char * argv[])
{
	
	DIR *dp = NULL;
	struct dirent * entry = NULL;
	
	printf("usage : Executable_Name Directory_Name\n");
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	dp = opendir(argv[1]);
	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		printf("%s\n",entry->d_name);
	}
	
	closedir(dp);
	
	
	
	return 0;
}