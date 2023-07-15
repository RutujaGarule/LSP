// Write a program which accept file name from user which contains information of student. We have to read all contents of that file 
// Read the structure


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
	int fd = 0;
	int NumRead = 0;
	
	printf("Usage : Executable_Name File_Name\n");
	
	if(argc != 2)
	{
		printf("Invalid Arguments\n");
		return -1;
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	struct Student sobj;
	
	NumRead = read(fd,&sobj,sizeof(sobj));
	if(NumRead == -1)
	{
		printf("Unable to read data into file\n");
		close(fd);
		return -1;
	}
	
	printf("Student Name : %s\n",sobj.name);
	printf("Student Age : %d\n",sobj.Age);
	printf("Student Marks : %f\n",sobj.Marks);
	printf("Student Rollno : %d\n",sobj.Rollno);
	
	close(fd);
	
	return 0;
}