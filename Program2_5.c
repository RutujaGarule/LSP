// Write a program which accept directory name from user and print name of such a file having largest size.


#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	DIR * dp = NULL;
	struct dirent * entry = NULL;
	char str[256];
	int MaxSize = 0;
	
	
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
		//printf("%s\t",entry->d_name);
		sprintf(str,"%s/%s",argv[1],entry->d_name);
		stat(str,&sobj);
		//printf("%s\t%d\n",entry->d_name,sobj.st_size);
		if(sobj.st_size > MaxSize)
		{
			MaxSize = sobj.st_size;
		}
	}
	
	printf("Maximum FileSize is : %d\n",MaxSize);

	
	closedir(dp);
		
	return 0;
}