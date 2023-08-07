// Write a program which is used to display environmet of our running process.

#include<stdio.h>
#include<unistd.h>

extern char ** environ;

int main()
{
    char ** Env = environ;

    printf("Environment of process is : \n");

    while(*Env != NULL)
    {
        printf("%s\n",*Env);
        Env++;
    }

    return 0;
}