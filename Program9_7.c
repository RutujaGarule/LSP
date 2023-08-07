// Write a program which is used to print home directory and login user name
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char * ptr = NULL;
    char Buff[50] = {'\0'};
    ptr = Buff;

    ptr = getenv("HOME");
    printf("Home directory is : %s\n",ptr);

    ptr = getenv("LOGNAME");
    printf("login name is : %s\n",ptr);

    return 0;
}