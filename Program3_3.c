// Write a program which accepts two directory names from user and move all files from source directory to destination directory

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[])
{
	DIR * dpSource = NULL;
	int dpDest = 0;
	struct dirent * entry = NULL;
	int fdSource = 0, fdDest = 0;
	char str[256] = {'\0'};
	char Buff[BLOCKSIZE];
	int Numread = 0, Numwrite = 0;
	
	printf("Usage : Executable_Name Source_Directory Destination_Directory\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	dpSource = opendir(argv[1]);
	if(dpSource == NULL)
	{
		printf("Unable to open Source_Directory\n");
		return -1;
	}
	
	dpDest = mkdir(argv[2],0777);
	if(dpDest == -1)
	{
		printf("Unable to create Destination_Directory\n");
		closedir(dpSource);
		return -1;
	}
	
	while((entry = readdir(dpSource)) != NULL)
	{
		if(strcmp(entry->d_name,".") == 0)
		{
			entry = entry++;
		}
		else if(strcmp(entry->d_name,"..") == 0)
		{
			entry = entry++;
		}
		else
		{
			sprintf(str,"%s/%s",argv[2],entry->d_name);
			//printf("%s\n",str);
			fdDest = creat(str,0777);
			if(fdDest == -1)
			{
				printf("Unable to create destination file\n");
				closedir(dpDest);
				closedir(dpSource);
				return -1;
			}
			
			fdSource = open(entry->d_name,O_RDONLY);
			if(fdSource == -1)
			{
				printf("Unable to open Source File\n");
				closedir(dpDest);
				closedir(dpSource);
				return -1;
			}
			
			fdDest = open(str,O_WRONLY);
			if(fdDest == -1)
			{
				printf("Unable to open Destination file\n");
				closedir(dpDest);
				closedir(dpSource);
				close(fdSource);
				return -1;
			}
			
			while((Numread = read(fdSource,Buff,sizeof(Buff))) != 0)
			{
				Numwrite = write(fdDest,Buff,Numread);
				if(Numwrite == -1)
				{
					printf("Unable to write data into destination file\n");
					return -1;
				}
			}
		
		}
		
	}
	
	closedir(dpDest);
	closedir(dpSource);
	close(fdSource);
	close(fdDest);
	
	
	return 0;
}