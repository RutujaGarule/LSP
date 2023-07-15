// Write a program which accept directory name from user and combine all contents of file from that directory into one file named as AllCombine.


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{
	DIR * dp = NULL;
	struct dirent * entry = NULL;
	int fd = 0, fdDest = 0;
	char Buff[BLOCKSIZE];
	int NumRead =0, NumWrite = 0;
	char Name[30];
	
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
	
	fdDest = creat("AllCombine.txt",0777);
	if(fdDest == -1)
	{
		printf("Unable to create file\n");
		closedir(dp);
		return -1;
	}
	
	struct stat sobj;
	
	while((entry = readdir(dp)) != NULL)
	{
		fd = 0;
		sprintf(Name,"%s/%s",argv[1],entry->d_name);
		
		stat(Name,&sobj);
		
		if(S_ISREG(sobj.st_mode))
		{
			fd = open(entry->d_name,O_RDONLY);
			if(fd == -1)
			{
				printf("Unable to open the file\n");
				return -1;
			}
			
			while((NumRead = read(fd,Buff,sizeof(Buff))) != 0)
			{
				NumWrite = write(fdDest,Buff,NumRead);
				if(NumWrite == -1)
				{
					printf("Unable to write data into file\n");
					return -1;
				}
			}
			
			close(fd);
		}
	}
	
	closedir(dp);
	close(fd);
	
	return 0;
}