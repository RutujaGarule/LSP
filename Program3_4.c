// Write a program which accepts directory name from user and delete all empty files from that directory.


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	DIR * dp = NULL;
	struct dirent * entry = NULL;
	char str[256] = {'\0'};
	int Ret = 0,uret = 0;
	
	printf("Usage : Executable_Name Directory_Name\n");
	
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
	
	struct stat sobj;
	
	while((entry = readdir(dp)) != NULL)
	{
		sprintf(str,"%s/%s",argv[1],entry->d_name);
		Ret = stat(str,&sobj);
		if(Ret == -1)
		{
			printf("Unable to fetch information\n");
			return -1;
		}
		if(sobj.st_size == 0)
		{
			//printf("%s\n",entry->d_name);
			uret = remove(str);
			if(uret == -1)
			{
				printf("Unable to remove the file\n");
				return -1;
			}
		}
	}
	
	if(uret == 0)
	{
		printf("Files are deleted successfully\n");
	}

	closedir(dp);
	
	
	return 0;
}