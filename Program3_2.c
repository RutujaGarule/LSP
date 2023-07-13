// Write a program which accepts directory name and file name from user and check whether that file is present in that directory or not


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char* argv[])
{
	DIR * dp = NULL;
	struct dirent * entry = NULL;
	
	printf("Usage : Executable_Name Directory_Name File_Name\n");
	
	if(argc != 3)
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
		if(strcmp(argv[2],entry->d_name) == 0)
		{
			printf("%s is present in directory\n",argv[2]);
			break;
		}
	}
	
	if(entry == NULL)
	{
		printf("%s is not present in directory\n",argv[2]);
	}
	
	
	closedir(dp);
	
	
	return 0;
}