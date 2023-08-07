// Write a program which is used to create simple thread by using pthread library

#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    printf("Inside Thread\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int Ret = 0;

    Ret = pthread_create(&TID,NULL,ThreadProc,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created successfully with TID : %d\n",TID);

    pthread_join(TID,NULL);

    printf("End of main\n");


    return 0;
}