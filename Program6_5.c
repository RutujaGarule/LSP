// Write a program which accept file name and offset from user and remove all the data from that offset

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[])
{
	int Ret = 0;
	
	printf("Usage : Executable_Name File_Name Offset\n");
	
	if(argc != 3)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	Ret = truncate(argv[1],atoi(argv[2]));
	if(Ret == -1)
	{
		printf("Unable to remove data\n");
		return -1;
	}
	
	
	return 0;
}