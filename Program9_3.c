// Write a program which is used to print prioriy of process

#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>

int main()
{
    int Ret = 0;

    Ret = getpriority(PRIO_PROCESS,getpid());
    printf("Priority of running process is : %d\n",Ret);


    return 0;
}