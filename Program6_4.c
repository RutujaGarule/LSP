// Write a program which accept directory name from user and delete all such files whose size is greater than 100 bytes

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char * argv[])
{
	DIR * dp = NULL;
	struct dirent * entry = NULL;
	int fd = 0, Ret = 0;
	char str[256];
	
	printf("Usage : Executable_Name Directory_Name\n");
	
	if(argc != 2)
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
	
	struct stat sobj;
	
	while((entry = readdir(dp)) != NULL)
	{
		if(strcmp(entry->d_name,".") == 0)
		{
			entry++;
		}
		else if(strcmp(entry->d_name,"..") == 0)
		{
			entry++;
		}
		else
		{
			sprintf(str,"%s/%s",argv[1],entry->d_name);
			Ret = stat(str,&sobj);

			if(Ret == -1)
			{
				printf("Unable to fetch information of file\n");
				closedir(dp);
				return -1;
			}
			if(sobj.st_size > 100)
			{
				remove(str);
			}
		}
	}
	
	
	closedir(dp);
	
	return 0;
}