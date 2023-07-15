// Write a program which writes structure in file. Structure should contains information of student

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#pragma pack(1)
struct Student
{
	int Rollno;
	char name[20];
	int Age;
	float Marks;
};

int main(int argc, char * argv[])
{
	int fd = 0,fdCreat = 0;
	int NumWrite = 0;
	
	printf("Usage : Executable_Name File_Name\n");
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fdCreat = creat(argv[1],0777);
	if(fdCreat == -1)
	{
		printf("Unable to create file\n");
		return -1;
	}
	
	struct Student sobj;
	
	sobj.Rollno = 11;
	sobj.Age = 23;
	sobj.Marks = 98.89f;
	strcpy(sobj.name,"Rutuja");
	
	fd = open(argv[1],O_WRONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	NumWrite = write(fd,&sobj,sizeof(sobj));
	if(NumWrite == -1)
	{
		printf("Unable to write data into file\n");
		close(fd);
		return -1;
	}
	
	close(fd);
	
	return 0;
}