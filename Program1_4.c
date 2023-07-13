// Write a program which accepts file name from user and print all information about that file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	int Ret = 0;
	
	printf("Usage : Executable_Name File_name\n");
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	struct stat sobj;
	
	Ret = stat(argv[1],&sobj);
	if(Ret == -1)
	{
		printf("Unable to display information\n");
		return -1;
	}
	
	printf("File Name is : %s\n",argv[1]);
	printf("Mode of File is : %d\n",sobj.st_mode);
	printf("Inode Number is : %d\n",sobj.st_ino);
	printf("Sizeof File is : %d\n",sobj.st_size);
	printf("Link Count is : %d\n",sobj.st_nlink);
	printf("User id of file is : %d\n",sobj.st_uid);
	printf("Group id of file is : %d\n",sobj.st_gid);
	printf("Number of blocks is : %d\n",sobj.st_blocks);
	
	
	
	
	
	
	return 0;
}