// Write a program which accept directory name and file name from user and write information of all regular file in it and then read the contents from that file


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{
	DIR * dp = NULL;
	struct dirent * entry = NULL;
	char name[30];
	int Ret = 0;
	char Buff[BLOCKSIZE];
	int NumRead = 0,NumWrite = 0;
	int fd = 0,fdDest = 0;
	
	printf("Usage : Executable_Name Directory Name File_Name\n");
	
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
	
	fdDest = open(argv[2],O_WRONLY);
	if(fdDest == -1)
	{
		printf("Unable to open file\n");
		closedir(dp);
		return -1;
	}
	
	struct stat sobj;
	
	while((entry = readdir(dp)) != NULL)
	{
		fd = 0;
		
		sprintf(name,"%s/%s",argv[1],entry->d_name);
		
		Ret = stat(name,&sobj);
		if(Ret == -1)
		{
			printf("Unable to fetch information\n");
			closedir(dp);
			return -1;
		}
		if(S_ISREG(sobj.st_mode))
		{
			/*
			printf("File Name is : %s\n",entry->d_name);
			printf("Inode number is : %ld\n",sobj.st_ino);
			printf("File size is : %ld\n",sobj.st_size);
			printf("Link Count is : %ld\n",sobj.st_nlink);
			*/
			
			write(fdDest,&sobj,sizeof(sobj));
			
			
			fd = open(name,O_RDONLY);
			if(fd == -1)
			{
				printf("Unable to open file in directory\n");
				closedir(dp);
				return -1;
			}
			
			while((NumRead = read(fd,Buff,sizeof(Buff))) != 0)
			{
				NumWrite = write(fdDest,Buff,NumRead);
				if(NumWrite == -1)
				{
					printf("Unable to write the data into file\n");
					close(fd);
					close(fdDest);
				}
			}
		}
	}
	
	
	close(fd);
	close(fdDest);
	closedir(dp);
	
	return 0;
}