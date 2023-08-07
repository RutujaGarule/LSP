// Write a program which is used to create single thread and we have to pass parameter to that thread from main thread

#include<stdio.h>
#include<pthread.h>

void * ThreadProc(void * ptr)
{
    int i = *(int*) ptr;
    printf("Value from main thread is : %d\n",i);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID;
    int Ret = 0;
    int Value = 11;

    Ret = pthread_create(&TID,NULL,ThreadProc,&Value);
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