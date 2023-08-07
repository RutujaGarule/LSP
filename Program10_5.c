// Write a program which is used to get thread id inside its thread function

#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    pthread_t TID;

    TID = pthread_self();

    printf("TID of thread is : %lu\n",TID);
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

    printf("Thread is created successfully with TID : %lu\n",TID);

    pthread_join(TID,NULL);

    printf("End of main\n");


    return 0;
}