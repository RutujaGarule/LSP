// Write a program which accept directory name from user and copy first 10 bytes from all regular files into newly created file named as Demo.txt


#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char * argv[])
{
	DIR * dp = NULL;
	int fd = 0, fdDest = 0;
	struct dirent * entry = NULL;
	char Buff[BLOCKSIZE];
	char str[256];
	int NumRead = 0, NumWrite = 0;
	
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
	
	fdDest = creat("Demo.txt",0777);
	if(fdDest == -1)
	{
		printf("Unable to creat Demo.txt File\n");
		closedir(dp);
		return -1;
	}
	
	fdDest = open("Demo.txt",O_WRONLY);
	if(fdDest == -1)
	{
		printf("Unable to open Demo.txt file\n");
		closedir(dp);
		return -1;
	}
	
	while((entry = readdir(dp)) != NULL)
	{
		//printf("%s\n",entry->d_name);
		
		sprintf(str,"%s/%s",argv[1],entry->d_name);
		
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
			//printf("%s\n",str);
			fd = open(str,O_RDONLY|O_APPEND);
			if(fd == -1)
			{
				printf("Unable to open the file\n");
				close(fdDest);
				closedir(dp);
				return -1;
			}
			
			NumRead = read(fd,Buff,10);
			
			if(NumRead == -1)
			{
				printf("Unable to read the data\n");
				close(fdDest);
				closedir(dp);
				close(fd);
				return -1;
			}
			
			NumWrite = write(fdDest,Buff,NumRead);
			memset(Buff,0,sizeof(Buff));
			if(NumWrite == -1)
			{
				printf("Unable to write data into destination file\n");
				close(fdDest);
				close(fd);
				closedir(dp);
				return -1;
			}
		}
	}
	
	close(fdDest);
	closedir(dp);
	close(fd);
	
	
	return 0;
}