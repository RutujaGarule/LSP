// Write a program which is used to increase prioriy of process by 5

#include<stdio.h>
#include<sys/resource.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int Ret = 0;
    int Priority = 0;
    int Exit_Status = 0;

    Ret = getpriority(PRIO_PROCESS,getpid());
    printf("Priority of running process is : %d\n",Ret);

    Priority = nice(-5);
    printf("New priority of running process is : %d\n",Priority);

    return 0;
}