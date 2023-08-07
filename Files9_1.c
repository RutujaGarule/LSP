// Used for Program9_1.c file

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char * argv[])
{
	int fd = 0;
	struct dirent * entry = NULL;
	DIR * dp = NULL;
	char name[50] = {'\0'};
	char * path = "/home/rutuja/Desktop/";
	
	fd = open("Demo.txt",O_RDONLY);
	if(fd > 0)
	{
		printf("File already exists\n");
		return -1;
	}
	else
	{
		fd = creat("Demo.txt",0777);
		if(fd == -1)
		{
			printf("Unable to create new file\n");
			return -1;
		}
	}

	dp = opendir(path);
	if(dp == NULL)
	{
		printf("Unale to open directory\n");
		return -1;
	}

	while((entry = readdir(dp)) != NULL)
	{
		strcpy(name,entry->d_name);
		write(fd,name,strlen(name));
		//printf("\n");
	}

	
	return 0;
}