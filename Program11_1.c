// Write a program which creates 4 number of threads and our main thread waits till all the threads terminates

#include<stdio.h>
#include<pthread.h>

void * ThreadProc1(void * ptr)
{
    printf("Inside Thread 1\n");
    pthread_exit(NULL);
}

void * ThreadProc2(void * ptr)
{
    printf("Inside Thread 2\n");
    pthread_exit(NULL);
}

void * ThreadProc3(void * ptr)
{
    printf("Inside Thread 3\n");
    pthread_exit(NULL);
}

void * ThreadProc4(void * ptr)
{
    printf("Inside Thread 4\n");
    pthread_exit(NULL);
}



int main()
{
    pthread_t TID1,TID2,TID3,TID4;
    int Ret = 0;

    Ret = pthread_create(&TID1,NULL,ThreadProc1,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Thread 1 is created with TID : %lu\n",TID1);

    Ret = pthread_create(&TID2,NULL,ThreadProc2,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Thread 2 is created with TID : %lu\n",TID2);

    Ret = pthread_create(&TID3,NULL,ThreadProc3,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Thread 3 is created with TID : %lu\n",TID3);

    Ret = pthread_create(&TID4,NULL,ThreadProc4,NULL);
    if(Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }
    printf("Thread 4 is created with TID : %lu\n",TID4);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);

    printf("End of main thread\n");

    pthread_exit(NULL);

    return 0;
}